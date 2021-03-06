/**************************************************************************
* Copyright (c) 2006-2007 Dusan Stastny. All rights reserved.             *
*                                                                         *
* This software is free software; you can redistribute it and/or modify   *
* it under the terms of the GNU General Public License Version 2 as       *
* published by the Free Software Foundation.                              *
*                                                                         *
* This software is distributed in the hope that it will be useful, but    *
* WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
* General Public License for more details.                                *
*                                                                         *
* You should have received a copy of the GNU General Public License       *
* along with DS Virtual Machine; see the file COPYING. If not, write to   *
* the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, *
* MA 02111-1307 USA.                                                      *
*                                                                         *
*   Dusan Stastny                                                         *
*   Jizni Svahy 804                  info@developservice.cz               *
*   330 27 Vejprnice                 http://www.developservice.cz         *
*   Czech Republic - EUROPE                                               *
**************************************************************************/

/** @file
   The Win32 platform specific DS virtual machine support.
   @author Dusan Stastny <info@developservice.cz>
*/

#include "config.h"
#include <stdlib.h>
#include <shlobj.h>
#include <time.h>
#include "java\lang\_all.h"
#include "java\io\Exceptions.h"

#ifndef DSVM_LITE
#include "java\io\File.h"
#include "java\util\Date.h"
#include "java\util\Vector.h"
#include "java\util\ArrayList.h"
#endif /* DSVM_LITE */


jint vmCompareString(jint lng, jint strength, jchar *s1, jint len1, jchar *s2, jint len2) {
	DWORD flags = ((strength < 2) ? NORM_IGNORECASE : 0) | ((strength < 1) ? NORM_IGNORESYMBOLS : 0);
	register int ret = CompareStringW(lng, flags, s1, len1, s2, len2);
	if (ret == CSTR_EQUAL) return 0;
	return (ret == CSTR_LESS_THAN) ? -1 : 1;
}


/***********************************************************************************
 * java.lang.String
 ***********************************************************************************/

void JNICALL Java_java_lang_String_String4(JNIEnv *env, jstring _this, jbyteArray bytes, jint start, jint len) {
	if (bytes == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else {
		jint len = VM_ARRAY_LENGTH(bytes);
		if (len != 0) {
			JavaLangStringIData *data = vmMemAlloc(((vmJNIEnv*)env)->vm, sizeof(JavaLangStringIData) + len * sizeof(jchar));
			if (data == NULL) {
				jniThrow(env, ((vmJNIEnv*)env)->vm->outofmem);
				return;
			}
			if (_this->flags & VM_OBJECT_FREEDATA_FLAG) vmMemFree(((vmJNIEnv*)env)->vm, _this->data);
			_this->data = (jbyte*)data;
			_this->flags |= VM_OBJECT_FREEDATA_FLAG;
			len = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, (LPCTSTR)VM_ARRAY_ARRAY(bytes), len, data->_str, len);
			data->_str[data->_len = len] = 0;
			data->_hash = 0;
		}
	}
}

jbyteArray JNICALL Java_java_lang_String_getBytes1(JNIEnv *env, jstring _this) {
	jint len = VM_STRING_LEN(_this);
	jbyteArray ret = jniNewByteArray(env, 2 * len);
	if (ret != NULL) {
		len = VM_ARRAY_LENGTH(ret) = WideCharToMultiByte(CP_ACP, 0, VM_STRING(_this), len, (LPSTR)VM_ARRAY_ARRAY(ret), 2 * len, NULL, NULL);
		((jbyte*)VM_ARRAY_ARRAY(ret))[len] = 0;
	}
	return ret;
}


/***********************************************************************************
 * java.lang.System
 ***********************************************************************************/

jlong JNICALL Java_java_lang_System_currentTimeMillis(JNIEnv *env, jclass clazz) {
	SYSTEMTIME ttm;
	GetSystemTime(&ttm);
#ifdef DSVM_LITE
	return JLONG(0);
#else
	return Java_java_util_Date_UTC(env, NULL, ttm.wYear-1900, ttm.wMonth-1, ttm.wDay, ttm.wHour, ttm.wMinute, ttm.wSecond) + ttm.wMilliseconds;
#endif /* DSVM_LITE */

}


/***********************************************************************************
 * java.lang.Thread
 ***********************************************************************************/

jint JNICALL jniAttachCurrentThread(JavaVM *vm, JNIEnv **penv, void *args);
jint JNICALL jniDetachCurrentThread(JavaVM *vm);


int vmThreadInitPlatformSpecific() {
	srand(time(NULL));
	return 0;
}

int vmThreadUninitPlatformSpecific() {
	return 0;
}


static int _platform_counter = 0;
natPackageInfo _dsvm_package = NULL;
int vmVMInitPlatformSpecific() {
	_dsvm_package = GetModuleHandle(NULL);
	vmThreadInitPlatformSpecific();
	if (_platform_counter++ == 0) {
		/* platform specific initialization */
	}
	return 0;
}


int vmVMUninitPlatformSpecific() {
	vmThreadUninitPlatformSpecific();
	if (_platform_counter > 0)
		if (--_platform_counter == 0) {
			/* platform specific uninitialization */
		}
	return 0;
}


#ifndef DSVM_LITE
static DWORD WINAPI vmNewThreadProc(LPVOID lpParameter) {
	JNIEnv *env; 
	jobject _this = lpParameter;
	JavaVM *jvm = VM_THREAD_DATA(_this)->jvm;
	
	if (JNI_OK == jniAttachCurrentThread(jvm, &env, NULL)) {
		clsField *class_fields; 
		jobject threads;
		jniNewLocalRef(env, _this);
		VM_THREAD_DATA(_this)->env = (vmJNIEnv*)env;
		VM_SET_EVENT(VM_THREAD_DATA(_this)->create_event);

		VM_ENTER_CRITICAL_SECTION(((vmJavaVM*)jvm)->gcs);
		class_fields = VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_THREAD, 0))->class_fields;
		threads = class_fields[3].val.l;
		if (threads == NULL) {
			threads = JNINEWGLOBALREF(env,
				jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_UTIL_VECTOR, 0))
			);
			jniDeleteLocalRef(env, threads);
			Java_java_util_Vector_Vector1(env, threads);
			class_fields[3].val.l = threads;
		}
		VM_LEAVE_CRITICAL_SECTION(((vmJavaVM*)jvm)->gcs);

		/* wait for thread handle, ID */
		jniMonitorEnter(env, _this);
		jniMonitorExit(env, _this);

		/* add to list */
		if (threads != NULL)
		if (JNI_OK == jniMonitorEnter(env, threads)) {
			JavaLangThreadIData *data = VM_THREAD_DATA(_this);
			data->fStartable = JNI_FALSE;
			data->priority = GetThreadPriority(data->nat);
			data->fAlive = JNI_TRUE;
			Java_java_util_Vector_addElement(env, threads, _this);
			jniMonitorExit(env, threads);
		}

#ifdef __cplusplus
		try {
#endif
		jniCallVoidMethodA(env, _this, &Java_java_lang_Thread_runID, NULL);
#ifdef __cplusplus
		} catch(...) {};
#endif

		/* remove from list */
		if (threads != NULL)
		if (JNI_OK == jniMonitorEnter(env, threads)) {
			JavaLangThreadIData *data = VM_THREAD_DATA(_this);
			Java_java_util_Vector_removeElement(env, threads, _this);
			data->fAlive = JNI_FALSE;
			jniMonitorExit(env, threads);
		}

		VM_THREAD_DATA(_this)->env = NULL;
		if (VM_THREAD_DATA(_this)->nat != 0) CloseHandle(VM_THREAD_DATA(_this)->nat);
		VM_THREAD_DATA(_this)->nat = NULL;
		jniDetachCurrentThread(jvm);
	} else
		VM_SET_EVENT(VM_THREAD_DATA(_this)->create_event);
	return 0;
}
#endif /* DSVM_LITE */


jobject JNICALL Java_java_lang_Thread_currentThread(JNIEnv *env, jclass _clazz) {
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm;
	clsField *class_fields = VM_CLASS_DEF(_clazz)->class_fields;
	natThreadID tid = vmGetCurrentThreadId();
	jobject threads = class_fields[3].val.l, ret;
#ifndef DSVM_LITE
	jint i, n;

	VM_ENTER_CRITICAL_SECTION(vm->gcs);
	if (threads == NULL) {
		threads = JNINEWGLOBALREF(env,
			jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_UTIL_VECTOR, 0))
		);
		jniDeleteLocalRef(env, threads);
		Java_java_util_Vector_Vector1(env, threads);
		class_fields[3].val.l = threads;
	}
	VM_LEAVE_CRITICAL_SECTION(vm->gcs);
	
	/* already exist? */
	if (JNI_OK != jniMonitorEnter(env, threads)) return NULL;
	n = Java_java_util_Vector_size(env, threads);
	for (i = 0; i < n; i++) {
		jobject thread = Java_java_util_Vector_get(env, threads, i);
		if (VM_THREAD_DATA(thread)->tid == tid) {
			jniMonitorExit(env, threads);
			return thread;
		}
	}
#endif /* DSVM_LITE */

	/* create new thread */
	ret = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_THREAD, 0));
	if (ret != NULL) {
		JavaLangThreadIData *data = VM_THREAD_DATA(ret);
		data->name = JNINEWGLOBALREF(env, jniNewStringUTF(env, "main"));
		data->fStartable = JNI_FALSE;
		data->tid = tid;
		data->nat = OpenThread(THREAD_ALL_ACCESS, TRUE, tid);
		data->priority = GetThreadPriority(GetCurrentThread());
		data->fAlive = JNI_TRUE;
#ifndef DSVM_LITE
		Java_java_util_Vector_addElement(env, threads, ret);
#endif /* DSVM_LITE */
	}
	jniMonitorExit(env, threads);
	return ret;
}


void JNICALL Java_java_lang_Thread_start(JNIEnv *env, jobject _this) {
	JavaLangThreadIData *data = VM_THREAD_DATA(_this);
	if (data->tid != 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALTHREADSTATEEXCEPTION.name), "Thread.start()");
		return;
	}

#ifdef DSVM_LITE
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), "Thread.start() not supported in lite version");
#else
	/* create new thread */
	VM_CREATE_EVENT(data->create_event);
	data->nat = CreateThread(NULL, 0, vmNewThreadProc, _this, 0, &(data->tid));

	/* wait for thread initialization */
	if (data->nat)
		VM_WAIT_FOR_EVENT(data->create_event, 5000);
	VM_DELETE_EVENT(data->create_event);
#endif
}


void JNICALL Java_java_lang_Thread_finalize(JNIEnv *env, jobject _this) {
	JavaLangThreadIData *data = VM_THREAD_DATA(_this);
	if (data->nat != NULL)
		CloseHandle(data->nat);
}


/***********************************************************************************
 * error management
 ***********************************************************************************/

/**
   Prints an information message. 
*/
void vmDisplayInfo(const char *msg, const char *title) {
	jchar jmsg[8096] = JSTRING("");
	if (msg != NULL) fromUtf8(jmsg, msg, sizeof(jmsg));
#ifdef _CONSOLE
	wprintf(jmsg);
#else
	{
		jchar jtitle[256]; if (title != NULL) fromUtf8(jtitle, title, sizeof(jtitle);
		MessageBoxW(0, jmsg, title ? jtitle : NULL, MB_ICONINFORMATION | MB_TASKMODAL);
	}
#endif
}


/**
   Prints a warning message. 
*/
void vmDisplayWarning(const char *msg, const char *title) {
	jchar jmsg[8096] = JSTRING("");
	if (msg != NULL) fromUtf8(jmsg, msg, sizeof(jmsg));
#ifdef _CONSOLE
	wprintf(jmsg);
#else
	{
		jchar jtitle[256]; if (title != NULL) fromUtf8(jtitle, title, sizeof(jtitle);
		MessageBoxW(0, jmsg, title ? jtitle : NULL, MB_ICONWARNING | MB_TASKMODAL);
	}
#endif
}


/**
   Prints an error message. 
*/
void vmDisplayError(const char *msg, const char *title) {
	jchar jmsg[8096] = JSTRING("");
	if (msg != NULL) fromUtf8(jmsg, msg, sizeof(jmsg));
#ifdef _CONSOLE
	wprintf(jmsg);
#else
	{
		jchar jtitle[256]; if (title != NULL) fromUtf8(jtitle, title, sizeof(jtitle);
		MessageBoxW(0, jmsg, title ? jtitle : NULL, MB_ICONERROR | MB_TASKMODAL);
	}
#endif
}


/***********************************************************************************
 * I/O management
 ***********************************************************************************/

#ifndef DSVM_LITE

void *vmGetErrStdHandle() {
	void *ret = GetStdHandle(STD_ERROR_HANDLE);
	return (ret != INVALID_HANDLE_VALUE) ? ret : VM_INVALID_FILEHANDLE;
}


void *vmGetInStdHandle() {
	void *ret = GetStdHandle(STD_INPUT_HANDLE);
	return (ret != INVALID_HANDLE_VALUE) ? ret : VM_INVALID_FILEHANDLE;
}


void *vmGetOutStdHandle() {
	void *ret = GetStdHandle(STD_OUTPUT_HANDLE);
	return (ret != INVALID_HANDLE_VALUE) ? ret : VM_INVALID_FILEHANDLE;
}


char* vmGetTempDirUTF() {
	static char ret[VM_MAX_PATH_LEN] = "";
	if (ret[0] == 0)
		if (GetTempPath(VM_MAX_PATH_LEN, ret) == 0)
				*ret = 0;
	return ret;
}


void JNICALL Java_java_io_File_setPath(JNIEnv *env, jobject _this, jstring path) {
	JavaIoFileIData *data = (JavaIoFileIData*)(_this->data);
	jstring separator = _this->clsdef->class_fields[2].val.l;
	jchar buf[2048], _path[2048], *name;
	if (path == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), "File.File()");
		return;
	}
	vmStrCpy(_path, VM_STRING(path));
	if (VM_STRING_LEN(path) > (VM_STRING_LEN(separator) + 1))
		if (Java_java_lang_String_endsWith(env, path, separator))
			if (_path[VM_STRING_LEN(path) - VM_STRING_LEN(separator) - 1] != (jchar)':')
				_path[VM_STRING_LEN(path) - VM_STRING_LEN(separator)] = 0;
	JNIDELETEGLOBALREF(env, data->path);
	JNIDELETEGLOBALREF(env, data->fname);
	if (GetFullPathNameW(_path, 2048, buf, &name) > 0) {
		data->path = JNINEWGLOBALREF(env, jniNewString(env, buf, -1));
		jniDeleteLocalRef(env, data->path);
		if (name == NULL) name = JSTRING("");
		data->fname = JNINEWGLOBALREF(env, jniNewString(env, name, -1));
		jniDeleteLocalRef(env, data->fname);
	} else {
		data->fname = JNINEWGLOBALREF(env, path);
		data->path = JNINEWGLOBALREF(env, path);
	}
}


jarray JNICALL Java_java_io_File_listRoots(JNIEnv *env, jclass clazz) {
	jstring ret = NULL; jint i;	char p[] = "A:\\";
	vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jobject sm = Java_java_lang_System_getSecurityManager(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_SYSTEM, 0));
	jmethodID metCheckRead = (sm != NULL) ? vmGetInstanceMethod(sm->clsdef, "checkRead", "(Ljava/lang/String;)V", JNI_TRUE) : NULL;
	jobject list = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_UTIL_ARRAYLIST, 0));
	DWORD drives = GetLogicalDrives(), mask = 1;
	if (list == NULL)
		return NULL;
	Java_java_util_ArrayList_ArrayList3(env, list, 30);
	for (i = 0; (i < 26) && !frame->exception; i++) {
		if (drives & mask) {
			jstring pp = jniNewStringUTF(env, p);
			if ((metCheckRead != NULL) && !frame->exception)
                jniCallVoidMethod(env, sm, metCheckRead, pp);
			if (!frame->exception) {
				jobject f = jniAllocObject(env, clazz);
				if (f != NULL) {
					Java_java_io_File_File2(env, f, pp);
					if (!frame->exception)
						Java_java_util_ArrayList_add1(env, list, f);
				}
				jniDeleteLocalRef(env, f);
			}
			jniDeleteLocalRef(env, pp);
		}
		mask <<= 1; p[0]++;
	}
	ret = Java_java_util_ArrayList_toArray1(env, list);
	jniDeleteLocalRef(env, list);
	return ret;
}


jint vmGetLastErrorUTF(char *buf, jsize buflen) {
	DWORD code = GetLastError();
	if (buf != NULL) {
		char pom[64];
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buf, buflen, NULL);
		vmSprintfUTF(pom, " [0x%08x]", code);
		if ((vmStrLenUTF(buf) + vmStrLenUTF(pom) + 2) < buflen)
			vmStrCatUTF(buf, pom);
	}
	return (jint)code;
}


void *vmCreateFile(JNIEnv *env, jstring name, jboolean w, jboolean s, jboolean d) {
	void *h = CreateFileW(VM_STRING(name), GENERIC_READ | (w ? GENERIC_WRITE : 0),
			FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, (w ? OPEN_ALWAYS : OPEN_EXISTING), 
			FILE_ATTRIBUTE_NORMAL | (d ? FILE_FLAG_NO_BUFFERING : 0), NULL);
	if (h == INVALID_HANDLE_VALUE) {
		char buf[4096], err[2048], cname[1024];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		toUtf8(cname, VM_STRING(name), VM_MIN(VM_STRING_LEN(name), sizeof(cname)/2));
		vmSprintfUTF(buf, (code == ERROR_FILE_NOT_FOUND) ? "File '%s' not found"
			: "Can't open file '%s' (%s)", cname, err);
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, (code == ERROR_FILE_NOT_FOUND)
			? &clsJAVA_IO_FILENOTFOUNDEXCEPTION : &clsJAVA_IO_IOEXCEPTION, 0), buf);
		return VM_INVALID_FILEHANDLE;
	}
	return h;
}


jboolean vmCanWrite(jchar *path) {
	DWORD atr = GetFileAttributesW(path);
	return (atr != INVALID_FILE_ATTRIBUTES) && !(atr & FILE_ATTRIBUTE_DIRECTORY)
		&& !(atr & FILE_ATTRIBUTE_READONLY) && !(atr & FILE_ATTRIBUTE_OFFLINE);
}


jboolean vmIsDirectory(jchar *path) {
	DWORD atr = GetFileAttributesW(path);
	return (atr != INVALID_FILE_ATTRIBUTES) && (atr & FILE_ATTRIBUTE_DIRECTORY);
}


jboolean vmIsFileHidden(jchar *path) {
	DWORD atr = GetFileAttributesW(path);
	return (atr != INVALID_FILE_ATTRIBUTES) && (atr & FILE_ATTRIBUTE_HIDDEN);
}


jlong vmGetFileLastModified(jchar *path) {
	jlong ret = JLONG(0);
	HANDLE f = CreateFileW(path, FILE_READ_ATTRIBUTES, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (f != INVALID_HANDLE_VALUE) {
		BY_HANDLE_FILE_INFORMATION hfi;
		if (GetFileInformationByHandle(f, &hfi)) {
			SYSTEMTIME t; JavaUtilDateIData data;
			FileTimeToSystemTime(&hfi.ftLastWriteTime, &t);
			data.year = t.wYear; data.month = t.wMonth; data.day = t.wDay;
			data.hour = t.wHour; data.min = t.wMinute; data.sec = t.wSecond; data.msec = 0;
			Java_java_util_Date_fromCache(&data);
			ret = (jlong)((data.val - VM_DATE_1970) * 86400000.0); 
		}
		CloseHandle(f);
	}
	return ret;
}


jlong vmGetFileLength(JNIEnv *env, void *h) {
	BY_HANDLE_FILE_INFORMATION hfi;
	if (!GetFileInformationByHandle(h, &hfi)) {
		char buf[4096], err[2048];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		vmSprintfUTF(buf, "Can't get the file length (%s)", err);
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_IOEXCEPTION, 0), buf);
		return JLONG(0);
	}
	return (((jlong)hfi.nFileSizeHigh) << 32) + (jlong)hfi.nFileSizeLow;
}


void vmSetFileLength(JNIEnv *env, void *h, jlong len) {
	LARGE_INTEGER cur, p; cur.HighPart = 0; p.QuadPart = len;
	cur.LowPart = SetFilePointer(h, 0, &cur.HighPart, FILE_CURRENT);
	if (INVALID_SET_FILE_POINTER == SetFilePointer(h, p.LowPart, &p.HighPart, FILE_BEGIN)) {
		char buf[4096], err[2048];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		vmSprintfUTF(buf, "Can't set new file length [1] (%s)", err);
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_IOEXCEPTION, 0), buf);
	}
	if (!SetEndOfFile(h)) {
		char buf[4096], err[2048];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		vmSprintfUTF(buf, "Can't set new file length [2] (%s)", err);
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_IOEXCEPTION, 0), buf);
		SetFilePointer(h, cur.LowPart, &cur.HighPart, FILE_BEGIN);
	}
	if (cur.QuadPart < p.QuadPart)
		if (INVALID_SET_FILE_POINTER == SetFilePointer(h, cur.LowPart, &cur.HighPart, FILE_BEGIN)) {
			char buf[4096], err[2048];
			jint code = vmGetLastErrorUTF(err, sizeof(err));
			vmSprintfUTF(buf, "Can't set new file length [3] (%s)", err);
			jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_IOEXCEPTION, 0), buf);
		}
}


jlong vmGetFilePointer(JNIEnv *env, void *h) {
	LARGE_INTEGER cur; cur.HighPart = 0;
	cur.LowPart = SetFilePointer(h, 0, &cur.HighPart, FILE_CURRENT);
	if (cur.LowPart == INVALID_SET_FILE_POINTER) {
		char buf[4096], err[2048];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		vmSprintfUTF(buf, "Can't get the file pointer (%s)", err);
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_IOEXCEPTION, 0), buf);
		return JLONG(0);
	}
	return cur.QuadPart;
}


void vmSetFilePointer(JNIEnv *env, void *h, jlong pos) {
	LARGE_INTEGER p; p.QuadPart = pos;
	if (INVALID_SET_FILE_POINTER == SetFilePointer(h, p.LowPart, &p.HighPart, FILE_BEGIN)) {
		char buf[4096], err[2048];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		vmSprintfUTF(buf, "Can't set the file pointer (%s)", err);
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_IOEXCEPTION, 0), buf);
	}
}


jarray vmGetFileList(JNIEnv *env, jchar *path) {
	jarray ret = NULL; WIN32_FIND_DATAW ffd; HANDLE h; jchar buf[4096]; jint cnt = 0;
	jobject list = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_UTIL_ARRAYLIST, 0));
	if (list == NULL) return NULL;
	Java_java_util_ArrayList_ArrayList3(env, list, 2048);
	vmStrCpy(buf, path); vmStrCat(buf, JSTRING("\\*"));
	h = FindFirstFileW(buf, &ffd);
	if (h != INVALID_HANDLE_VALUE) {
		do {
			WCHAR ch0 = ffd.cFileName[0], ch1 = ffd.cFileName[1], ch2 = ffd.cFileName[2];
			if ((ch0 != '.') || !(!ch1 || ((ch1 == '.') && !ch2))) {
				jstring name = jniNewString(env, ffd.cFileName, -1);
				Java_java_util_ArrayList_add1(env, list, name);
				jniDeleteLocalRef(env, name);
				cnt++;
			}
		} while (FindNextFileW(h, &ffd));
		FindClose(h);
	}
	if (cnt > 0)
		ret = Java_java_util_ArrayList_toArray1(env, list);
	jniDeleteLocalRef(env, list);
	return ret;
}


jboolean vmSetFileLastModified(jchar *path, jlong time) {
	jboolean ret = JNI_FALSE;
	HANDLE f = CreateFileW(path, FILE_WRITE_ATTRIBUTES, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (f != INVALID_HANDLE_VALUE) {
		SYSTEMTIME st; FILETIME t; JavaUtilDateIData data;
		data.val = VM_DATE_1970 + (jdouble)time / 86400000.0;	
		Java_java_util_Date_toCache(&data);		
		vmMemSetZero(&st, sizeof(st));
		st.wYear = data.year; st.wMonth = data.month; st.wDay = data.day;
		st.wHour = data.hour; st.wMinute = data.min; st.wSecond = data.sec;		
		SystemTimeToFileTime(&st, &t);
		ret = (0 != SetFileTime(f, NULL, &t, &t));
		CloseHandle(f);
	}
	return ret;
}


jboolean vmSetFileReadOnly(jchar *path) {
	DWORD atr = GetFileAttributesW(path);
	if (atr != INVALID_FILE_ATTRIBUTES)
		return (0 != SetFileAttributesW(path, atr | FILE_ATTRIBUTE_READONLY));
	return JNI_FALSE;
}


void vmFlushFile(JNIEnv *env, void *h, jboolean createException) {
	if (!FlushFileBuffers(h))
		if (createException) {
			char buf[4096], err[2048];
			jint code = vmGetLastErrorUTF(err, sizeof(err));
			vmSprintfUTF(buf, "Can't flush the file (%s)", err);
			jniThrowNew(env, jniFindClass(env, clsJAVA_IO_IOEXCEPTION.name), buf);
		}
}


jint vmReadFile(JNIEnv *env, void *h, void *buf, jint len) {
	DWORD ret;
	if (!ReadFile(h, buf, len, &ret, NULL)) {
		char msg[4096], err[2048];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		if (code == ERROR_NOT_ENOUGH_MEMORY)
			if (ReadFile(h, buf, VM_MIN(16384, len), &ret, NULL))
				return (jint)ret;
		vmSprintfUTF(msg, "Can't read the file (%s)", err);
		jniThrowNew(env, jniFindClass(env, clsJAVA_IO_IOEXCEPTION.name), msg);
		ret = 0;
	}
	return (jint)ret;
}


jint vmWriteFile(JNIEnv *env, void *h, void *buf, jint len) {
	DWORD l;
	if (!WriteFile(h, buf, len, &l, NULL)) {
		char buf[4096], err[2048];
		jint code = vmGetLastErrorUTF(err, sizeof(err));
		vmSprintfUTF(buf, "Can't write to the file (%s)", err);
		jniThrowNew(env, jniFindClass(env, clsJAVA_IO_IOEXCEPTION.name), buf);
		l = (DWORD)len;
	}
	return (jint)l;
}

#endif /* DSVM_LITE */


/***********************************************************************************
 * properties
 ***********************************************************************************/

const jchar *vmGetDefaultTimeZone(jchar *buf, int buflen) {
	switch (GetUserDefaultLangID()) {
		case 0x0405: return JSTRING("Europe/Prague");			// Czech
		case 0x041b: return JSTRING("Europe/Bratislava");		// Slovak
		case 0x0415: return JSTRING("Europe/Warsaw");			// Polish			
		case 0x0407: return JSTRING("Europe/Berlin");			// German (Standard)
		case 0x0807: return JSTRING("Europe/Zurich");			// German (Switzerland)
		case 0x0C07: return JSTRING("Europe/Vienna");			// German (Austria)
		case 0x1007: return JSTRING("Europe/Luxembourg");		// German (Luxembourg)
		case 0x040c: return JSTRING("Europe/Paris");			// French (Standard)
		case 0x0410: return JSTRING("Europe/Rome");				// Italian (Standard)
	}
	return JSTRING("");
}


const jchar *vmGetUserCountry(jchar *buf, int buflen) {
	switch (GetUserDefaultLangID()) {
		case 0x0405: return JSTRING("CZ");			// Czech
		case 0x041b: return JSTRING("SK");			// Slovak
		case 0x0415: return JSTRING("PL");			// Polish			
		case 0x0407: return JSTRING("DE");			// German (Standard)
		case 0x0807: return JSTRING("DE");			// German (Switzerland)
		case 0x0C07: return JSTRING("DE");			// German (Austria)
		case 0x1007: return JSTRING("DE");			// German (Luxembourg)
		case 0x040c: return JSTRING("FR");			// French (Standard)
		case 0x0410: return JSTRING("IT");			// Italian (Standard)
	}
	return JSTRING("EN");
}


const jchar *vmGetUserLanguage(jchar *buf, int buflen) {
	switch (GetUserDefaultLangID()) {
		case 0x0405: return JSTRING("cs");			// Czech
		case 0x041b: return JSTRING("sk");			// Slovak
		case 0x0415: return JSTRING("pl");			// Polish			
		case 0x0407: return JSTRING("de");			// German (Standard)
		case 0x0807: return JSTRING("de");			// German (Switzerland)
		case 0x0C07: return JSTRING("de");			// German (Austria)
		case 0x1007: return JSTRING("de");			// German (Luxembourg)
		case 0x040c: return JSTRING("fr");			// French (Standard)
		case 0x0410: return JSTRING("it");			// Italian (Standard)
	}
	return JSTRING("en");
}


const jchar *vmGetUserName(jchar *buf, int buflen) {
	DWORD len = buflen;
	if (GetUserNameW(buf, &len)) buf[len] = 0; else buf[0] = 0;
	return buf;
}


const jchar *vmGetUserDir(jchar *buf, int buflen) {
	if (!GetCurrentDirectoryW(buflen, buf)) buf[0] = 0;
	return buf;
}


const jchar *vmGetUserHome(jchar *buf, int buflen) {
	if (!FAILED(SHGetSpecialFolderPathW(NULL, buf, CSIDL_PROFILE, FALSE)))
		return buf;
	return vmGetUserDir(buf, buflen);
}


const jchar *vmGetTempDir(jchar *buf, int buflen) {
	if (0 == GetTempPathW(buflen, buf)) buf[0] = 0;
	return buf;
}


const jchar *vmGetOsArch(jchar *buf, int buflen) {
	jchar *ret = _wgetenv(JSTRING("PROCESSOR_ARCHITECTURE"));
	return (ret != NULL) ? ret : JSTRING("x86");
}


const jchar *vmGetOsName(jchar *buf, int buflen) {
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (GetVersionEx(&osvi)) {
		if (osvi.dwMajorVersion == 3) return JSTRING("Windows NT 3.51");
		if (osvi.dwMajorVersion == 4) {
			if (osvi.dwMinorVersion == 0)  
				return (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT) ? JSTRING("Windows NT 4.0") : JSTRING("Windows 95");
			if (osvi.dwMinorVersion == 10) return JSTRING("Windows 98");
			if (osvi.dwMinorVersion == 90) return JSTRING("Windows Me");
		}
		if (osvi.dwMajorVersion == 5) {
			if (osvi.dwMinorVersion == 0) return JSTRING("Windows 2000");
			if (osvi.dwMinorVersion == 1) return JSTRING("Windows XP");
			if (osvi.dwMinorVersion == 2) return JSTRING("Windows 2003");
		}
	}
	return JSTRING("Windows");
}


const jchar *vmGetOsVersion(jchar *buf, int buflen) {
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (GetVersionEx(&osvi))
		vmSprintf(buf, JSTRING("%u.%u"), osvi.dwMajorVersion, osvi.dwMinorVersion);
	else 
		buf[0] = 0;
	return buf;
}


const jchar *vmGetPackageInfo(jchar *buf, int buflen, natPackageInfo* pi, jint type) {
	struct TRANSLATIONSTRUCT {
		WORD wLanguage;
		WORD wCodePage;
	} *lpTranslation;
	jchar fname[1024]; DWORD len = sizeof(fname);
	vmMemSetZero(buf, buflen);
	if (GetModuleFileNameW((HMODULE)*pi, fname, sizeof(fname))) {
		char fbuf[8096];
		if (GetFileVersionInfoW(fname, 0, sizeof(fbuf), fbuf)) {
			VS_FIXEDFILEINFO *fi; UINT len; int i;
			VerQueryValue(fbuf, TEXT("\\"), (LPVOID*)&fi, &len);
			if (!VerQueryValue(fbuf, TEXT("\\VarFileInfo\\Translation"),
					(LPVOID*)&lpTranslation, &len))
				len = 0;
			for (i = 0; i < (int)(len / sizeof(struct TRANSLATIONSTRUCT)); i++) {
				jchar lng[128] = JSTRING(""), *val;
				switch (type) {
					case 1:		/* ImplementationTitle */
						vmSprintf(lng, JSTRING("\\StringFileInfo\\%04x%04x\\ProductName"),
							lpTranslation[i].wLanguage, lpTranslation[i].wCodePage);
						break;
					case 4:		/* SpecificationTitle */
						vmSprintf(lng, JSTRING("\\StringFileInfo\\%04x%04x\\InternalName"),
							lpTranslation[i].wLanguage, lpTranslation[i].wCodePage);
						break;
					case 2:		/* ImplementationVendor */
					case 5:		/* SpecificationVendor */
						vmSprintf(lng, JSTRING("\\StringFileInfo\\%04x%04x\\CompanyName"),
							lpTranslation[i].wLanguage, lpTranslation[i].wCodePage);
						break;
					case 3:		/* ImplementationVersion */
						vmSprintf(lng, JSTRING("\\StringFileInfo\\%04x%04x\\ProductVersion"),
							lpTranslation[i].wLanguage, lpTranslation[i].wCodePage);
						break;
					case 6:		/* SpecificationVersion */
						vmSprintf(lng, JSTRING("\\StringFileInfo\\%04x%04x\\FileVersion"),
							lpTranslation[i].wLanguage, lpTranslation[i].wCodePage);
						break;
					case 7:		/* Copyright */
						vmSprintf(lng, JSTRING("\\StringFileInfo\\%04x%04x\\LegalCopyright"),
							lpTranslation[i].wLanguage, lpTranslation[i].wCodePage);
				}
				len = 0;
				VerQueryValueW(fbuf, lng, (void**)&val, &len);
				if (len > 0) {
					vmStrnCpy(buf, val, buflen - 1);
					break;
				}
			}
		}
	}
	if (!*buf && ((type == 2) || (type == 5))) {
		jchar *p = buf, *p2 = buf; 
		vmGetPackageInfo(buf, buflen, pi, 7);
		while (*p && (*p != ' ')) p++; p++;
		while (*p && (*p != ' ')) p++; p++;
		while (*p && (*p != ' ')) p++; p++;
		while (*p) { *p2 = *p; p++; p2++; }
		*p2 = 0;
	} else
	if ((type == 3) || (type == 6)) {
		jchar *p, *p2 = buf;
		while (p2) {
			p = buf;
			while (*p && (*p != ',')) p++;
			if (*p && (*p == ',')) {
				*p = '.'; p++;
				p2 = p; if (*p && (*p == ' ')) p++;
				while (*p) { *p2 = *p; p++; p2++; }
				*p2 = 0;
			} else
				p2 = NULL;
		}
	}
	return buf;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _DEBUG
int AllocCnt = 0, AllocMaxCnt = 0;
int AllocObjectCnt = 0, AllocObjectMaxCnt = 0;

vmMemHandle vmMemSystemAlloc(int sz) {
	AllocCnt++; AllocMaxCnt++;
	return GlobalAlloc(GMEM_FIXED|GMEM_ZEROINIT, sz);
}
void vmMemSystemFree(vmMemHandle p) {
	AllocCnt--;
	GlobalFree(p);
}

void *pp[10 * 65536];
void* _vmMemAlloc(int sz) {
	void *ret = malloc(sz);
	AllocObjectCnt++;
//	pp[AllocObjectMaxCnt++] = ret;
	return ret;
}
void _vmMemFree(void* p) {
	int i; 
	AllocObjectCnt--;
	free(p);
	for (i = 0; i < AllocObjectMaxCnt; i++)
		if (pp[i] == p) { pp[i] = NULL; break; }
}
void vmMemPrintUnalloc() {
	int i;
	for (i = 0; i < AllocObjectMaxCnt; i++)
		if (pp[i] != NULL)
			printf("Unallocated memory: 0x%08x\n", pp[i]);
}

#endif