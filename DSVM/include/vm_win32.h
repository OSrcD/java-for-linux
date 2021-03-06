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

#ifndef _VM_WIN32_H_
#define _VM_WIN32_H_

#include "jni.h"
#include <windows.h>


/* platform specific thread&synchronization support */
typedef	CRITICAL_SECTION              natSynchronizeData;
#define VM_INIT_CRITICAL_SECTION(gcs) InitializeCriticalSection(gcs)
#define VM_UNINIT_CRITICAL_SECTION(gcs) DeleteCriticalSection(gcs)
#define VM_ENTER_CRITICAL_SECTION(gcs) EnterCriticalSection(gcs)
#define VM_LEAVE_CRITICAL_SECTION(gcs) LeaveCriticalSection(gcs)
#define vmGetCurrentThreadId          GetCurrentThreadId
#define vmSleep                       Sleep
#define VM_INIT_EVENT(event)          (event) = NULL
#define VM_IS_EVENT_CREATED(event)    ((event) != NULL)
#define VM_CREATE_EVENT(event)        (event) = CreateEvent(NULL, FALSE, FALSE, NULL)
#define VM_WAIT_FOR_EVENT(event, t)   (WAIT_OBJECT_0 != WaitForSingleObject(event, ((t) < 0) ? INFINITE : (DWORD)(t)))
#define VM_SET_EVENT(event)           SetEvent(event)
#define VM_RESET_EVENT(event)         ResetEvent(event)
#define VM_DELETE_EVENT(event)        CloseHandle(event)
int vmThreadInitPlatformSpecific();
int vmThreadUninitPlatformSpecific();
int vmVMInitPlatformSpecific();
int vmVMUninitPlatformSpecific();


/* library support */
#define VM_DEFAULT_CLASSPATH          "."
#define VM_LIBRARY_EXT                ".dll"
#define VM_LINE_SEPARATOR             "\n"
#define VM_FILE_SEPARATOR             "\\"
#define VM_PATH_SEPARATOR             ";"
#define VM_MAX_PATH_LEN               (MAX_PATH + 1)
#define vmLoadLibrary                 LoadLibraryW
#define vmFreeLibrary                 FreeLibrary
#define vmGetProcAddressUTF           GetProcAddress
typedef HANDLE                        natPackageInfo;
extern natPackageInfo                 _dsvm_package;


/* low/system level memory management:
 *   vmMemHandle ... memory handle type
 *   vmMemHandle vmMemSystemAlloc(jint size) ... allocates the specified number of bytes from system virtual memory
 *   void vmMemSystemFree(vmMemHandle h) ... frees the specified block of system virtual memory
 *   void *vmMemSystemLock(vmMemHandle h) ... locks page in physical memory
 *   void vmMemSystemUnlock(vmMemHandle h, void *p) ... unlocks page
 */
#ifdef _DEBUG
  vmMemHandle vmMemSystemAlloc(jint size);
  void vmMemSystemFree(vmMemHandle);
#else
  #define vmMemSystemAlloc(sz)        GlobalAlloc(GMEM_FIXED|GMEM_ZEROINIT, sz)
  #define vmMemSystemFree             GlobalFree
#endif
#define vmMemSystemLock               GlobalLock
#define vmMemSystemUnlock(h, p)       GlobalUnlock(h)


/* memory management
 *   void *_vmMemAlloc(jint size) ... allocates uncollected memory block, must be released by _vmMemFree
 *   void _vmMemFree(void *p) ... frees uncollected memory block
 */
#ifdef _DEBUG
  void* _vmMemAlloc(jint);
  void  _vmMemFree(void*);
  void  vmMemPrintUnalloc();
#else
  #define _vmMemAlloc                 malloc
  #define _vmMemFree(p)               free((void*)p)
#endif
#define vmMemCmp                      memcmp
#define vmMemCpy                      MoveMemory
#define vmMemSet(dest,ch,len)         FillMemory(dest,len,ch)
#define vmMemSetZero                  ZeroMemory


/* jchar string management (UNICODE) */
#define vmStrCat                      lstrcatW
#define vmStrCmp                      lstrcmpW
#define vmStrnCmp                     wcsncmp
#define vmStrCmpi                     lstrcmpiW
#define vmStrCpy                      lstrcpyW
#define vmStrnCpy                     wcsncpy
#define vmStrLen                      lstrlenW
#define vmSprintf                     swprintf
#define vmStrLwr                      CharLowerW
#define vmStrUpr                      CharUpperW
#define CONST_COLLATOR_US             MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);
#define CONST_COLLATOR_UK             MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_UK), SORT_DEFAULT);
#define CONST_COLLATOR_GE             MAKELCID(MAKELANGID(LANG_FRENCH, SUBLANG_FRENCH), SORT_DEFAULT);
#define CONST_COLLATOR_FR             MAKELCID(MAKELANGID(LANG_GERMAN, SUBLANG_GERMAN), SORT_DEFAULT);
#define CONST_COLLATOR_CZ             MAKELCID(MAKELANGID(LANG_CZECH, SUBLANG_DEFAULT), SORT_DEFAULT);
#define CONST_COLLATOR_SK             MAKELCID(MAKELANGID(LANG_SLOVAK, SUBLANG_DEFAULT), SORT_DEFAULT);
jint vmCompareString(jint lng, jint strength, jchar *s1, jint len1, jchar *s2, jint len2);


/* UTF-8 string management */
#define vmStrCatUTF                   lstrcatA
#define vmStrCmpUTF                   lstrcmpA
#define vmStrnCmpUTF                  strncmp
#define vmStrCmpiUTF                  lstrcmpiA
#define vmStrCpyUTF                   lstrcpyA
#define vmStrnCpyUTF                  strncpy
#define vmStrLenUTF                   lstrlenA
#define vmSprintfUTF                  sprintf


/* error management */
void vmDisplayInfo(const char *msg, const char *title);
void vmDisplayWarning(const char *msg, const char *title);
void vmDisplayError(const char *msg, const char *title);


/* I/O management */
#define VM_INVALID_FILEHANDLE         NULL
#define VM_FILE_IS_CASE_SENSITIVE     JNI_FALSE
#define vmCloseFileHandle(h)          CloseHandle(h)
#define vmCreateDirectory(path)       (0 != CreateDirectoryW(path, 0))
#define vmDeleteFile                  DeleteFileW
#define vmDeleteDirectory             RemoveDirectoryW
#define vmFileExists(path)            (GetFileAttributesW(path) != INVALID_FILE_ATTRIBUTES)
#define vmFileRename(destpath, srcpath) (0 != MoveFileW(srcpath, destpath))
void *vmGetErrStdHandle();
void *vmGetInStdHandle();
void *vmGetOutStdHandle();
jboolean vmCanWrite(jchar *path);
void *vmCreateFile(JNIEnv *env, jstring name, jboolean w, jboolean s, jboolean d);
jint vmGetLastErrorUTF(char *buf, jsize buflen);
char* vmGetTempDirUTF();
jlong vmGetFileLastModified(jchar *path);
jlong vmGetFileLength(JNIEnv *env, void *h);
jlong vmGetFilePointer(JNIEnv *env, void *h);
jarray vmGetFileList(JNIEnv *env, jchar *path);
void vmFlushFile(JNIEnv *env, void *h, jboolean createException);
jboolean vmIsDirectory(jchar *path);
jboolean vmIsFileHidden(jchar *path);
jboolean vmSetFileLastModified(jchar *path, jlong time);
jboolean vmSetFileReadOnly(jchar *path);
void vmSetFilePointer(JNIEnv *env, void *h, jlong pos);
void vmSetFileLength(JNIEnv *env, void *h, jlong len);
jint vmReadFile(JNIEnv *env, void *h, void *buf, jint len);
jint vmWriteFile(JNIEnv *env, void *h, void *buf, jint len);


/* properties */
const jchar *vmGetOsArch(jchar *buf, int buflen);
const jchar *vmGetOsName(jchar *buf, int buflen);
const jchar *vmGetOsVersion(jchar *buf, int buflen);
const jchar *vmGetDefaultTimeZone(jchar *buf, int buflen);
const jchar *vmGetUserName(jchar *buf, int buflen);
const jchar *vmGetUserCountry(jchar *buf, int buflen);
const jchar *vmGetUserLanguage(jchar *buf, int buflen);
const jchar *vmGetUserDir(jchar *buf, int buflen);
const jchar *vmGetUserHome(jchar *buf, int buflen);
const jchar *vmGetTempDir(jchar *buf, int buflen);
const jchar *vmGetPackageInfo(jchar *buf, int buflen, natPackageInfo* pi, jint type);


/* =============================================================== */
/*  IA32 platform depended                                         */
/* =============================================================== */

/* push a value to native stack */
#define VM_NATIVE_PUSH_BOOLEAN(z) { \
		__asm { mov cl, z }; \
		__asm { push ecx }; }
#define VM_NATIVE_PUSH_BYTE \
	VM_NATIVE_PUSH_BOOLEAN
#define VM_NATIVE_PUSH_CHAR(c) { \
		__asm { mov cx, c }; \
		__asm { push ecx }; }
#define VM_NATIVE_PUSH_SHORT \
	VM_NATIVE_PUSH_CHAR
#define VM_NATIVE_PUSH_INT(i) { \
		__asm { mov ecx, i }; \
		__asm { push ecx }; }
#define VM_NATIVE_PUSH_FLOAT \
	VM_NATIVE_PUSH_INT
#define VM_NATIVE_PUSH_OBJECT \
	VM_NATIVE_PUSH_INT
#define VM_NATIVE_PUSH_LONG(j) { \
		__asm { lea edx, j }; \
		__asm { mov ecx, dword ptr [edx+4] }; \
		__asm { push ecx }; \
		__asm { mov ecx, dword ptr [edx] }; \
		__asm { push ecx }; }
#define VM_NATIVE_PUSH_DOUBLE \
	VM_NATIVE_PUSH_LONG

/* push values from java stack to native stack */
#define	VM_NATIVE_PUSH_PARAMS(frame, met) { \
		void *adr = met->code; \
		jshort cnt = met->parameters_stack_size; \
		jint stack_top = frame->stack_top; \
		while (cnt-- > 0) { \
			jobject obj = *((stack_top > 0) ? (frame->stack + (--stack_top)) : (VM_STACK_SLOT_TYPE*)vmFatalError(frame->env, "Stack underflow")); \
			VM_NATIVE_PUSH_OBJECT(obj); \
		}

/* call procedure and store return value to java stack */
#define VM_NATIVE_CALL(frame, retval, ret_type) \
		__asm { call adr }; \
		__asm { lea esi, retval }; \
		__asm { mov bl, ret_type }; \
		__asm { cmp bl, 'D' }; \
		__asm { jne NOTD_C }; \
		__asm { fstp qword ptr [esi] }; \
		goto DONE_C; \
NOTD_C:	__asm { cmp bl, 'F' }; \
		__asm { jne NOTF_C }; \
		__asm { fstp dword ptr [esi] }; \
		goto DONE_C; \
NOTF_C:	__asm { mov [esi], eax }; \
		__asm { mov [esi + 4], edx }; \
DONE_C: ; }


#endif	/* NOT _VM_WIN32_H_ */
