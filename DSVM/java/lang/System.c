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


#include "config.h"
#include "Exceptions.h"
#include "System.h"
#include "String.h"
#include "Runtime.h"

#ifndef DSVM_LITE
#include "..\io\FileDescriptor.h"
#include "..\io\FileInputStream.h"
#include "..\io\FileOutputStream.h"
#include "..\io\PrintStream.h"
#include "..\io\PrintStream.h"
#include "..\util\Properties.h"
#else
extern clsDefinition clsJAVA_IO_PRINTSTREAM;
#endif /* DSVM_LITE */


/* =============================================================== */
/*  class fields                                                   */
/* =============================================================== */

static clsField class_fields[] = {
	{&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_FINAL|ACC_STATIC, "err", "Ljava/io/PrintStream;", 0x5f8d6d73, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_FINAL|ACC_STATIC, "in", "Ljava/io/InputStream;", 0x91ffb97c, 0, NULL,
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_FINAL|ACC_STATIC, "out", "Ljava/io/PrintStream;", 0x5f8d4b58, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_SYSTEM, ACC_PRIVATE|ACC_FINAL|ACC_STATIC, "_secmng", "Ljava/lang/SecurityManager;", 0x1bf02ada, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_SYSTEM, ACC_PRIVATE|ACC_STATIC, "_prop", "Ljava/util/Properties;", 0x37f5be7e, 0, NULL, 
		/* VM internal affairs */ 0, NULL}
};


/* =============================================================== */
/*  class methods                                                  */
/* =============================================================== */

void JNICALL Java_java_lang_System_clinit(JNIEnv *env, jclass clazz);
static clsMethod Java_java_lang_System_clinitID = {&clsJAVA_LANG_SYSTEM, ACC_STATIC|ACC_NATIVE, "<clinit>", "()V",
	   0x8C1695DC, 0, Java_java_lang_System_clinit, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'V'};
static void JNICALL Java_java_lang_System_clinit(JNIEnv *env, jclass clazz) {
#ifdef DSVM_LITE
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "out", "Ljava/io/PrintStream;", JNI_FALSE);
	jniNewGlobalRef(env, fld->val.l = vmCreateObject((vmJNIEnv*)env, &clsJAVA_IO_PRINTSTREAM, 0, 0, 0));
#else
	clsField *class_fields = VM_CLASS_DEF(clazz)->class_fields;
	jobject tmp, pom;
	jclass cFileInputStream = vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_FILEINPUTSTREAM, 0);
	jclass cFileOutputStream = vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_FILEOUTPUTSTREAM, 0);
	jclass cFileDescriptor = vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_FILEDESCRIPTOR, 0);

	/* err */
	pom = jniAllocObject(env, cFileOutputStream);
	tmp = (pom == NULL) ? NULL : jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_PRINTSTREAM, 0));
	class_fields[0].val.l = JNINEWGLOBALREF(env, tmp);
	jniDeleteLocalRef(env, tmp);
	if (tmp != NULL) {
		Java_java_io_FileOutputStream_FileOutputStream3(env, pom,
            jniGetStaticObjectField(env, cFileDescriptor, vmGetClassField(&clsJAVA_IO_FILEDESCRIPTOR, "err", "Ljava/io/FileDescriptor;", JNI_TRUE))
		);
		Java_java_io_PrintStream_PrintStream2(env, tmp, pom, JNI_TRUE);
	}
	jniDeleteLocalRef(env, pom);

	/* in */
	tmp = jniAllocObject(env, cFileInputStream);
	class_fields[1].val.l = JNINEWGLOBALREF(env, tmp);
	jniDeleteLocalRef(env, tmp);
	if (tmp != NULL) {
		Java_java_io_FileInputStream_FileInputStream2(env, tmp,
            jniGetStaticObjectField(env, cFileDescriptor, vmGetClassField(&clsJAVA_IO_FILEDESCRIPTOR, "in", "Ljava/io/FileDescriptor;", JNI_TRUE))
		);
	}

	/* out */
	pom = jniAllocObject(env, cFileOutputStream);
	tmp = (pom == NULL) ? NULL : jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_IO_PRINTSTREAM, 0));
	class_fields[2].val.l = JNINEWGLOBALREF(env, tmp);
	jniDeleteLocalRef(env, tmp);
	if (tmp != NULL) {
		Java_java_io_FileOutputStream_FileOutputStream3(env, pom,
            jniGetStaticObjectField(env, cFileDescriptor, vmGetClassField(&clsJAVA_IO_FILEDESCRIPTOR, "out", "Ljava/io/FileDescriptor;", JNI_TRUE))
		);
		Java_java_io_PrintStream_PrintStream2(env, tmp, pom, JNI_TRUE);
	}
	jniDeleteLocalRef(env, pom);
#endif /* DSVM_LITE */
}


static clsMethod Java_java_lang_System_arraycopyID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "arraycopy", "(Ljava/lang/Object;ILjava/lang/Object;II)V",
	   0x536bc400, 0, Java_java_lang_System_arraycopy, 0, 0, 0, NULL, /* VM internal affairs */ 5, 5, 'V'};
void JNICALL Java_java_lang_System_arraycopy(JNIEnv *env, jclass clazz, jobject src, jint srcPos, jobject dest, jint destPos, jint length) {
	jint i;
	if (!src || !dest) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
		return;
	}
	if ((src->dim <= 0) || (src->dim != dest->dim)) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_ARRAYSTOREEXCEPTION, "Different dimensions"));
		return;
	}
	if (src->clsdef != dest->clsdef)
		if ((src->clsdef->name[1] == 0) || !vmIsAssignableFrom(dest->clsdef, src->clsdef)) {
			jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_ARRAYSTOREEXCEPTION, "Different types"));
			return;
		}
	if ((srcPos < 0) || (destPos < 0) || (length < 0) || ((srcPos+length) > VM_ARRAY_LENGTH(src)) || ((destPos+length) > VM_ARRAY_LENGTH(dest))) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return;
	}
	if (src->clsdef->name[1] || (src->dim > 1)) {
		jobject *d = ((jobject*)VM_ARRAY_ARRAY(dest)) + destPos;
		jobject *s = ((jobject*)VM_ARRAY_ARRAY(src)) + srcPos;
		if (srcPos < destPos)
			for (i = length - 1; i >= 0; i--) vmSetObjectVar(env, d + i, s[i], NULL);
		else
			for (i = 0; i < length; i++) vmSetObjectVar(env, d + i, s[i], NULL);
	} else {
		int esize = src->clsdef->element_size;
		vmMemCpy(((jbyte*)VM_ARRAY_ARRAY(dest)) + (esize * destPos), ((jbyte*)VM_ARRAY_ARRAY(src)) + (esize * srcPos), esize * length);
	}
}


static clsMethod Java_java_lang_System_currentTimeMillisID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "currentTimeMillis", "()J",
	   0x5CBB3AA5, 0, Java_java_lang_System_currentTimeMillis, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'J'};
/* see to vm_nat.c file for method implementation */


static clsMethod Java_java_lang_System_exitID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "exit", "(I)V",
	   0x3CFF30, 0, Java_java_lang_System_exit, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_exit(JNIEnv *env, jclass clazz, jint status) {
	jobject runtime = jniCallStaticObjectMethod(env, jniFindClass(env, clsJAVA_LANG_RUNTIME.name), 
		vmGetClassMethod(&clsJAVA_LANG_RUNTIME, "getRuntime", "()Ljava/lang/Runtime;", JNI_FALSE));
	jniCallVoidMethod(env, runtime, 
		vmGetInstanceMethod(&clsJAVA_LANG_RUNTIME, "exit", "(I)V", JNI_FALSE),
		status);
}


static clsMethod Java_java_lang_System_gcID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "gc", "()V",
	   0x97A9, 0, Java_java_lang_System_gc, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'V'};
void JNICALL Java_java_lang_System_gc(JNIEnv *env, jclass clazz) {
	jobject runtime = jniCallStaticObjectMethod(env, jniFindClass(env, clsJAVA_LANG_RUNTIME.name), 
		vmGetClassMethod(&clsJAVA_LANG_RUNTIME, "getRuntime", "()Ljava/lang/Runtime;", JNI_FALSE));
	jniCallVoidMethod(env, runtime, 
		vmGetInstanceMethod(&clsJAVA_LANG_RUNTIME, "gc", "()V", JNI_FALSE));
}


static clsMethod Java_java_lang_System_getenvID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getenv", "(Ljava/lang/String;)Ljava/lang/String;",
	   0x5CE61156, 0, Java_java_lang_System_getenv, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_System_getenv(JNIEnv *env, jclass clazz, jstring name) {
	if (name != NULL) {
		jchar* ret = _wgetenv(VM_STRING(name));
		if (ret != NULL)
			return jniNewString(env, ret, -1);
	}
	return NULL;
}


static clsMethod Java_java_lang_System_getPropertiesID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getProperties", "()Ljava/util/Properties;",
	   0xC3C48554, 0, Java_java_lang_System_getProperties, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'L'};
jobject JNICALL Java_java_lang_System_getProperties(JNIEnv *env, jclass clazz) {
#ifdef DSVM_LITE
	return NULL;
#else
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "_prop", "Ljava/util/Properties;", JNI_FALSE);
	if (fld->val.l == NULL) {
		jchar buf[1024]; jstring val; jint i;
		JDK1_1InitArgs *args = ((vmJNIEnv*)env)->args;
		/* create default set of system properties */
		jobject props = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_UTIL_PROPERTIES, 0));
		if (props == NULL) return NULL;
		Java_java_util_Properties_Properties1(env, props);
		fld->val.l = JNINEWGLOBALREF(env, props);
		jniDeleteLocalRef(env, props);
		jniPushLocalFrame(env, 128);
		val = jniNewString(env, vmGetPackageInfo(buf, sizeof(buf) / sizeof(jchar), &_dsvm_package, 3), -1);
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.version"), val);
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.vm.version"), val);
		val = jniNewString(env, vmGetPackageInfo(buf, sizeof(buf) / sizeof(jchar), &_dsvm_package, 2), -1);
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.vendor"), val);
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.vm.vendor"), val);
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.vendor.url"), jniNewString(env, JSTRING(PROP_JAVA_VENDOR_URL), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.home"), jniNewString(env, vmGetUserDir(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.specification.version"), jniNewString(env, JSTRING("1.0"), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.vm.specification.version"), jniNewString(env, JSTRING("1.0"), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.vm.name"), jniNewString(env, vmGetPackageInfo(buf, sizeof(buf) / sizeof(jchar), &_dsvm_package, 1), -1));
		vmSprintf(buf, JSTRING("%u.%u"), VM_CLASS_MAJOR_VERSION, VM_CLASS_MINOR_VERSION);
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.class.version"), jniNewString(env, buf, -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.class.path"), jniNewStringUTF(env, ((vmJNIEnv*)env)->args->classpath));
		val = Java_java_lang_System_getenv(env, clazz, jniNewStringUTF(env, "PATH"));
		if (val == NULL) val = jniNewStringUTF(env, "");
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.library.path"), val);
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.io.tmpdir"), jniNewString(env, vmGetTempDir(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "java.ext.dirs"), jniNewString(env, JSTRING(""), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "os.name"), jniNewString(env, vmGetOsName(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "os.arch"), jniNewString(env, vmGetOsArch(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "os.version"), jniNewString(env, vmGetOsVersion(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "file.separator"), jniNewString(env, JSTRING(VM_FILE_SEPARATOR), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "path.separator"), jniNewString(env, JSTRING(VM_PATH_SEPARATOR), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "line.separator"), jniNewString(env, JSTRING(VM_LINE_SEPARATOR), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "user.timezone"), jniNewString(env, vmGetDefaultTimeZone(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "user.country"), jniNewString(env, vmGetUserCountry(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "user.language"), jniNewString(env, vmGetUserLanguage(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "user.name"), jniNewString(env, vmGetUserName(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "user.home"), jniNewString(env, vmGetUserHome(buf, sizeof(buf) / sizeof(jchar)), -1));
		Java_java_util_Properties_setProperty(env, props, jniNewStringUTF(env, "user.dir"), jniNewString(env, vmGetUserDir(buf, sizeof(buf) / sizeof(jchar)), -1));
		/* insert user custom properties */
		if (args->version == JNI_VERSION_1_2)
			for (i = 0; i < args->nOptions; i++) {
				char *os = args->options[i].optionString, *p;
				if (!strncmp(os, "-Djava.class.path=", 18))
					continue;
				if (os[0] != '-') continue;
				if (os[1] != 'D') continue;
				os += 2; p = os;
				while (*p && (*p != '=')) p++;
				if (*p && (*p == '=')) {
                    char *cbuf = (char*)buf;
					jint len = sizeof(buf) - 1; if ((p - os) < len) len = p - os;
					vmMemSetZero(buf, sizeof(buf));
					vmStrnCpyUTF(cbuf, os, len);
					Java_java_util_Properties_setProperty(env, props, 
						jniNewStringUTF(env, cbuf), 
						jniNewStringUTF(env, p + 1));
				}
			}
		jniPopLocalFrame(env, NULL);
	}
	return fld->val.l;
#endif /* DSVM_LITE */
}


static clsMethod Java_java_lang_System_getProperty1ID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;",
	   0xA9C6BBCA, 0, Java_java_lang_System_getProperty1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_System_getProperty1(JNIEnv *env, jclass clazz, jstring key) {
	jobject props = Java_java_lang_System_getProperties(env, clazz);
	if (key == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), "System.getProperty()");
		return NULL;
	}
	if (VM_STRING_LEN(key) == 0) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION, 0), "System.getProperty()");
		return NULL;
	}
#ifndef DSVM_LITE
	if (props != NULL)
		return Java_java_util_Properties_getProperty2(env, props, key, NULL);
#endif /* DSVM_LITE */
	return NULL;
}


static clsMethod Java_java_lang_System_getProperty2ID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
	   0xCE0036FC, 0, Java_java_lang_System_getProperty2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 2, 'L'};
jstring JNICALL Java_java_lang_System_getProperty2(JNIEnv *env, jclass clazz, jstring key, jstring def) {
	jstring ret = Java_java_lang_System_getProperty1(env, clazz, key);
	return (ret != NULL) ? ret : def;
}


static clsMethod Java_java_lang_System_getSecurityManagerID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getSecurityManager", "()Ljava/lang/SecurityManager;",
	   0xA28A93A, 0, Java_java_lang_System_getSecurityManager, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'L'};
jobject JNICALL Java_java_lang_System_getSecurityManager(JNIEnv *env, jclass clazz) {
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "_secmng", "Ljava/lang/SecurityManager;", JNI_FALSE);
	return fld->val.l;
}


extern clsMethod Java_java_lang_Object_hashCodeID;
static clsMethod Java_java_lang_System_identityHashCodeID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "identityHashCode", "(Ljava/lang/Object;)I",
	   0xCAB89AFD, 0, Java_java_lang_System_identityHashCode, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'I'};
jint JNICALL Java_java_lang_System_identityHashCode(JNIEnv *env, jclass clazz, jobject obj) {
	return jniCallIntMethod(env, obj, &Java_java_lang_Object_hashCodeID);
}


static clsMethod Java_java_lang_System_loadID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "load", "(Ljava/lang/String;)V",
	   0xAAE17519, 0, Java_java_lang_System_load, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_load(JNIEnv *env, jclass clazz, jstring filename) {
	jobject runtime = jniCallStaticObjectMethod(env, jniFindClass(env, clsJAVA_LANG_RUNTIME.name), 
		vmGetClassMethod(&clsJAVA_LANG_RUNTIME, "getRuntime", "()Ljava/lang/Runtime;", JNI_FALSE));
	jniCallVoidMethod(env, runtime, 
		vmGetInstanceMethod(&clsJAVA_LANG_RUNTIME, "load", "(Ljava/lang/String;)V", JNI_FALSE), 
		filename);
}


static clsMethod Java_java_lang_System_loadLibraryID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "loadLibrary", "(Ljava/lang/String;)V",
	   0x4184790A, 0, Java_java_lang_System_loadLibrary, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_loadLibrary(JNIEnv *env, jclass clazz, jstring libname) {
	jobject runtime = jniCallStaticObjectMethod(env, jniFindClass(env, clsJAVA_LANG_RUNTIME.name), 
		vmGetClassMethod(&clsJAVA_LANG_RUNTIME, "getRuntime", "()Ljava/lang/Runtime;", JNI_FALSE));
	jniCallVoidMethod(env, runtime, 
		vmGetInstanceMethod(&clsJAVA_LANG_RUNTIME, "loadLibrary", "(Ljava/lang/String;)V", JNI_FALSE), 
		libname);
}


static clsMethod Java_java_lang_System_mapLibraryNameID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "mapLibraryName", "(Ljava/lang/String;)Ljava/lang/String;",
	   0xCEB22E6B, 0, Java_java_lang_System_mapLibraryName, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_System_mapLibraryName(JNIEnv *env, jclass clazz, jstring libname) {
	jstring ret = NULL;
	if (libname != NULL) {
		jniNewLocalRef(env, ret = vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_STRING, 0, 0, 
			(vmStrLen(VM_STRING(libname)) + 10) * sizeof(jchar)));
		if (ret != NULL) {
			vmStrCpy(VM_STRING(ret), VM_STRING(libname));
			vmStrCat(VM_STRING(ret), JSTRING(VM_LIBRARY_EXT));
		}
	}
	return ret;
}


static clsMethod Java_java_lang_System_runFinalizationID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "runFinalization", "()V",
	   0x6766B32C, 0, Java_java_lang_System_runFinalization, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'V'};
void JNICALL Java_java_lang_System_runFinalization(JNIEnv *env, jclass clazz) {
	jobject runtime = jniCallStaticObjectMethod(env, jniFindClass(env, clsJAVA_LANG_RUNTIME.name), 
		vmGetClassMethod(&clsJAVA_LANG_RUNTIME, "getRuntime", "()Ljava/lang/Runtime;", JNI_FALSE));
	jniCallVoidMethod(env, runtime, 
		vmGetInstanceMethod(&clsJAVA_LANG_RUNTIME, "runFinalization", "()V", JNI_FALSE));
}


static clsMethod Java_java_lang_System_runFinalizersOnExitID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "runFinalizersOnExit", "(Z)V",
	   0xD8DFA5F8, 0, Java_java_lang_System_runFinalizersOnExit, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_runFinalizersOnExit(JNIEnv *env, jclass clazz, jboolean value) {
	jobject runtime = jniCallStaticObjectMethod(env, jniFindClass(env, clsJAVA_LANG_RUNTIME.name), 
		vmGetClassMethod(&clsJAVA_LANG_RUNTIME, "getRuntime", "()Ljava/lang/Runtime;", JNI_FALSE));
	jniCallVoidMethod(env, runtime, 
		vmGetInstanceMethod(&clsJAVA_LANG_RUNTIME, "runFinalizersOnExit", "(Z)V", JNI_FALSE), 
		value);
}


static clsMethod Java_java_lang_System_setErrID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "setErr", "(Ljava/io/PrintStream;)V",
	   0xDA20EF18, 0, Java_java_lang_System_setErr, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_setErr(JNIEnv *env, jclass clazz, jobject err) {
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "err", "Ljava/io/PrintStream;", JNI_FALSE);
	vmSetObjectVar(env, &(fld->val.l), err, fld);
}


static clsMethod Java_java_lang_System_setInID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "setIn", "(Ljava/io/InputStream;)V",
	   0x77A66F19, 0, Java_java_lang_System_setIn, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_setIn(JNIEnv *env, jclass clazz, jobject in) {
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "in", "Ljava/io/InputStream;", JNI_FALSE);
	vmSetObjectVar(env, &(fld->val.l), in, fld);
}


static clsMethod Java_java_lang_System_setOutID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "setOut", "(Ljava/io/PrintStream;)V",
	   0xDA200937, 0, Java_java_lang_System_setOut, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_setOut(JNIEnv *env, jclass clazz, jobject out) {
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "out", "Ljava/io/PrintStream;", JNI_FALSE);
	vmSetObjectVar(env, &(fld->val.l), out, fld);
}


static clsMethod Java_java_lang_System_setPropertiesID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "setProperties", "(Ljava/util/Properties;)V",
	   0x7BC5C384, 0, Java_java_lang_System_setProperties, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_setProperties(JNIEnv *env, jclass clazz, jobject props) {
	jniSetStaticObjectField(env, clazz, vmGetClassField(VM_CLASS_DEF_DIM(clazz), "_prop", "Ljava/util/Properties;", JNI_FALSE), props);
}


static clsMethod Java_java_lang_System_setPropertyID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "setProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
	   0xb5c851e0, 0, Java_java_lang_System_setProperty, 0, 0, 0, NULL, /* VM internal affairs */ 2, 2, 'L'};
jstring JNICALL Java_java_lang_System_setProperty(JNIEnv *env, jclass clazz, jstring key, jstring value) {
#ifndef DSVM_LITE
	jobject props = Java_java_lang_System_getProperties(env, clazz);
	if (props != NULL)
		return Java_java_util_Properties_setProperty(env, props, key, value);
#endif /* DSVM_LITE */
	return NULL;
}


static clsMethod Java_java_lang_System_setSecurityManagerID = {&clsJAVA_LANG_SYSTEM, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "setSecurityManager", "(Ljava/lang/SecurityManager;)V",
	   0x629A18F8, 0, Java_java_lang_System_setSecurityManager, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_System_setSecurityManager(JNIEnv *env, jclass clazz, jobject sm) {
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "_secmng", "Ljava/lang/SecurityManager;", JNI_FALSE);
	vmSetObjectVar(env, &(fld->val.l), sm, fld);
}


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsMethod* class_methods[] = {
	&Java_java_lang_System_arraycopyID,
	&Java_java_lang_System_currentTimeMillisID,
	&Java_java_lang_System_exitID,
	&Java_java_lang_System_gcID,
	&Java_java_lang_System_getenvID,
	&Java_java_lang_System_getPropertiesID,
	&Java_java_lang_System_getProperty1ID,
	&Java_java_lang_System_getProperty2ID,
	&Java_java_lang_System_getSecurityManagerID,
	&Java_java_lang_System_identityHashCodeID,
	&Java_java_lang_System_loadID,
	&Java_java_lang_System_loadLibraryID,
	&Java_java_lang_System_mapLibraryNameID,
	&Java_java_lang_System_runFinalizationID,
	&Java_java_lang_System_runFinalizersOnExitID,
	&Java_java_lang_System_setErrID,
	&Java_java_lang_System_setInID,
	&Java_java_lang_System_setOutID,
	&Java_java_lang_System_setPropertiesID,
	&Java_java_lang_System_setPropertyID,
	&Java_java_lang_System_setSecurityManagerID,
	&Java_java_lang_System_clinitID
};


clsDefinition clsJAVA_LANG_SYSTEM = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/System",            /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0x841D2923,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_FINAL + ACC_SUPER, /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	sizeof(class_fields) / sizeof(clsField), /* class_fields_count */
	class_fields,                  /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	sizeof(class_methods) / sizeof(clsMethod*), /* class_methods_count */
	class_methods,                 /* class_methods */
	0,                             /* instance_methods_count */
	NULL,                          /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};