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
#include "Errors.h"
#include "ClassLoader.h"
#include "Exceptions.h"
#include "String.h"
#if JAVA_UTIL_ZIP_ENABLED
#include "..\util\zip\ZipFile.h"
#include "..\util\zip\ZipEntry.h"
#endif

extern clsDefinition clsJAVA_LANG_SYSTEMCLASSLOADER;


/* =============================================================== */
/*  class methods                                                  */
/* =============================================================== */

static clsField class_fields[] = {
	{&clsJAVA_LANG_CLASSLOADER, ACC_PRIVATE|ACC_FINAL|ACC_STATIC, "_systemloader", "Ljava/lang/ClassLoader;", 0xac82b5d1, 0, NULL,
		/* VM internal affairs */ 0, NULL}
};

void JNICALL Java_java_lang_ClassLoader_clinit(JNIEnv *env, jclass clazz);
static clsMethod Java_java_lang_ClassLoader_clinitID = {&clsJAVA_LANG_CLASSLOADER, ACC_PRIVATE|ACC_STATIC|ACC_NATIVE, "<clinit>", "()V",
	   0x8c1695dc, 0, Java_java_lang_ClassLoader_clinit, 0, 10, 0, NULL, /* VM internal affairs */ 0, 0, 'V'};
void JNICALL Java_java_lang_ClassLoader_clinit(JNIEnv *env, jclass clazz) {
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "_systemloader", "Ljava/lang/ClassLoader;", JNI_FALSE);
	vmRegisterClass(((vmJNIEnv*)env)->vm, (vmJNIEnv*)env, &clsJAVA_LANG_SYSTEMCLASSLOADER);
	((vmJNIEnv*)env)->vm->loader = fld->val.l = JNINEWGLOBALREF(env, 
		vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_SYSTEMCLASSLOADER, 0, 0, 0)
	);
}

static clsMethod Java_java_lang_ClassLoader_getSystemClassLoaderID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getSystemClassLoader", "()Ljava/lang/ClassLoader;",
	   0x5d6a6649, 0, Java_java_lang_ClassLoader_getSystemClassLoader, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getSystemClassLoader(JNIEnv *env, jclass clazz) {
	return ((vmJNIEnv*)env)->vm->loader;
}

#if JAVA_NET_ENABLED
#include "..\net\URL.h"
static clsMethod Java_java_lang_ClassLoader_getSystemResourceID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getSystemResource", "(Ljava/lang/String;)Ljava/net/URL;",
	   0xd9632b25, 0, Java_java_lang_ClassLoader_getSystemResource, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getSystemResource(JNIEnv *env, jclass clazz, jstring name) {
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm;
	return Java_java_lang_ClassLoader_getResource(env, vm->loader, name);
}

static clsMethod Java_java_lang_ClassLoader_getSystemResourceAsStreamID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getSystemResourceAsStream", "(Ljava/lang/String;)Ljava/util/InputStream;",
	   0xe7fcdbe3, 0, Java_java_lang_ClassLoader_getSystemResourceAsStream, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getSystemResourceAsStream(JNIEnv *env, jclass clazz, jstring name) {
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm;
	return Java_java_lang_ClassLoader_getResourceAsStream(env, vm->loader, name);
}

static clsMethod Java_java_lang_ClassLoader_getSystemResourcesID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getSystemResources", "(Ljava/lang/String;)Ljava/util/Enumeration;",
	   0x720fefe9, 0, Java_java_lang_ClassLoader_getSystemResources, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getSystemResources(JNIEnv *env, jclass clazz, jstring name) {
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm;
	return Java_java_lang_ClassLoader_getResources(env, vm->loader, name);
}
#endif

static clsMethod* class_methods[] = {
	&Java_java_lang_ClassLoader_clinitID,
	&Java_java_lang_ClassLoader_getSystemClassLoaderID,
#if JAVA_NET_ENABLED
	&Java_java_lang_ClassLoader_getSystemResourceID,
	&Java_java_lang_ClassLoader_getSystemResourceAsStreamID,
	&Java_java_lang_ClassLoader_getSystemResourcesID
#endif
};



/* =============================================================== */
/*  instance methods                                               */
/* =============================================================== */

static clsMethod Java_java_lang_ClassLoader_ClassLoader0ID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_NATIVE, "<init>", "()V", 
	   0x6c5e9907, 0, Java_java_lang_ClassLoader_ClassLoader0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_ClassLoader_ClassLoader0(JNIEnv *env, jobject _this) {
	Java_java_lang_ClassLoader_ClassLoader1(env, _this, NULL);
}


static clsMethod Java_java_lang_ClassLoader_ClassLoader1ID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_NATIVE, "<init>", "(Ljava/lang/ClassLoader;)V", 
	   0x6c5e9907, 0, Java_java_lang_ClassLoader_ClassLoader1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_ClassLoader_ClassLoader1(JNIEnv *env, jobject _this, jobject parent) {
	if (parent != NULL)
		JNINEWGLOBALREF(env, VM_CLASSLOADER_PARENT(_this) = parent);
}


static clsMethod Java_java_lang_ClassLoader_clearAssertionStatusID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_NATIVE, "clearAssertionStatus", "()V", 
	   0x86949cf2, 0, Java_java_lang_ClassLoader_clearAssertionStatus, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_ClassLoader_clearAssertionStatus(JNIEnv *env, jobject _this) {
}


static clsMethod Java_java_lang_ClassLoader_defineClass3ID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_FINAL|ACC_NATIVE, "defineClass", "([BII)Ljava/lang/Class;",
	   0x95574d74, 0, Java_java_lang_ClassLoader_defineClass3, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_defineClass3(JNIEnv *env, jobject _this, jarray buf, jint off, jint len) {
	return Java_java_lang_ClassLoader_defineClass5(env, _this, NULL, buf, off, len, NULL);
}


static clsMethod Java_java_lang_ClassLoader_defineClass4ID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_FINAL|ACC_NATIVE, "defineClass", "(Ljava/lang/String;[BII)Ljava/lang/Class;",
	   0x8028e2ee, 0, Java_java_lang_ClassLoader_defineClass4, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_defineClass4(JNIEnv *env, jobject _this, jstring name, jarray buf, jint off, jint len) {
	return Java_java_lang_ClassLoader_defineClass5(env, _this, name, buf, off, len, NULL);
}


static clsMethod Java_java_lang_ClassLoader_defineClass5ID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_FINAL|ACC_NATIVE, "defineClass", "(Ljava/lang/String;[BIILjava/security/ProtectionDomain;)Ljava/lang/Class;",
	   0x836312fe, 0, Java_java_lang_ClassLoader_defineClass5, 0, 0, 0, NULL, /* VM internal affairs */ 5, 6, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_defineClass5(JNIEnv *env, jobject _this, jstring name, jarray buf, jint off, jint len, jobject protectionDomain) {
	jint buflen; jclass ret; clsDefinition *cls;
	buflen = jniGetArrayLength(env, buf);
	if (jniGetArrayLength(env, buf) < 0)
		goto INDEXERR;
	if ((off < 0) || (len < 0) || ((off + len) > buflen)) {
INDEXERR:
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION.name), NULL);
		return NULL;
	}
	if (name != NULL) {
		jint len = VM_STRING_LEN(name);
		jchar *pname = VM_STRING(name);
		while (len--) {
			if (*(pname++) == '/') {
				jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_SECURITYEXCEPTION.name), "'.' separator expected");
				return NULL;
			}
		}
		if (!vmMemCmp(VM_STRING(name), JSTRING("java."), 5 * sizeof(jstring))) {
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_SECURITYEXCEPTION.name), NULL);
			return NULL;
		}
	}
	
	/* get class definition */
	cls = vmDefineClass((vmJNIEnv*)env, NULL, ((jbyte*)VM_ARRAY_ARRAY(buf)) + off, len);
	if (jniExceptionOccurred(env) != NULL) {
		vmSetObjectVar(env, &VM_THROWABLE_MSG(jniExceptionOccurred(env)), name, clsJAVA_LANG_THROWABLE.instance_fields /* _msg field */);
		return NULL;
	}
	
	/* test for unsupported class version */
	if (cls->major_version > VM_UNSUPPORTED_MAJOR_VERSION)
		goto VERSION_OK;
	if (cls->minor_version > VM_UNSUPPORTED_MINOR_VERSION)
		goto VERSION_OK;
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNSUPPORTEDCLASSVERSIONERROR.name), cls->name);
	vmMemFree(((vmJNIEnv*)env)->vm, cls);
	return NULL;
VERSION_OK:

	/* are names equal? */
	if (name != NULL) {
		char _name[2 * VM_MAX_PATH_LEN + 1], *p = _name;
		toUtf8(_name, VM_STRING(name), VM_MIN(VM_STRING_LEN(name), VM_MAX_PATH_LEN));
		while (*p) { if (*p == '.') *p = '/'; p++; }
		if (vmStrCmpUTF(_name, cls->name)) {
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOCLASSDEFFOUNDERROR.name), cls->name);
			vmMemFree(((vmJNIEnv*)env)->vm, cls);
			return NULL;
		}
	}

	/* OK, return class */
	ret = vmRegisterClass(((vmJNIEnv*)env)->vm, (vmJNIEnv*)env, cls);
	if (ret == NULL)
		vmMemFree(((vmJNIEnv*)env)->vm, cls);
	return ret;
}


static clsMethod Java_java_lang_ClassLoader_findClassID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_NATIVE, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;",
	   0xa9e70b93, 0, Java_java_lang_ClassLoader_findClass, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_findClass(JNIEnv *env, jobject _this, jstring name) {
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION.name), NULL);
	return NULL;
}


static clsMethod Java_java_lang_ClassLoader_findLoadedClassID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_FINAL|ACC_NATIVE, "findLoadedClass", "(Ljava/lang/String;)Ljava/lang/Class;",
	   0xefe1bc56, 0, Java_java_lang_ClassLoader_findLoadedClass, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_findLoadedClass(JNIEnv *env, jobject _this, jstring name) {
	char utfname[2*VM_MAX_PATH_LEN], *pname;
	jint name_len, i; jshort dim;

	if (name == NULL) return NULL;
	toUtf8(utfname, VM_STRING(name), VM_MIN(VM_STRING_LEN(name), sizeof(utfname) - 1));
	
	/* compute dimension */
	dim = 0;
	pname = utfname;
	while (*pname == '[') { dim++; pname++; }
	if (dim > VM_MAX_ARRAY_DIMENSION) return NULL;
	name_len = vmStrLenUTF(pname);
	if ((pname[0] == 'L') && (pname[name_len - 1] == ';')) {
		pname++; name_len -= 2;
	}
	for (i = 0; i < name_len; i++)
		if (pname[i] == '.') pname[i] = '/';

	/* is loaded? */
	return vmFindClassByName((vmJNIEnv*)env, pname, name_len, dim);
}


static clsMethod Java_java_lang_ClassLoader_findLibraryID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_NATIVE, "findLibrary", "(Ljava/lang/String;)Ljava/lang/String;",
	   0xd2d23443, 0, Java_java_lang_ClassLoader_findLibrary, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jstring JNICALL Java_java_lang_ClassLoader_findLibrary(JNIEnv *env, jobject _this, jstring libname) {
	return NULL;
}


static clsMethod Java_java_lang_ClassLoader_findSystemClassID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_FINAL|ACC_NATIVE, "findSystemClass", "(Ljava/lang/String;)Ljava/lang/Class;",
	   0x448305bc, 0, Java_java_lang_ClassLoader_findSystemClass, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_findSystemClass(JNIEnv *env, jobject _this, jstring name) {
	jobject loader; jmethodID met;
	loader = ((vmJNIEnv*)env)->vm->loader;
	met = vmGetInstanceMethod(loader->clsdef, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;", JNI_TRUE);
	return jniCallObjectMethod(env, loader, met, name);
}


static clsMethod Java_java_lang_ClassLoader_getParentID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_NATIVE, "getParent", "()Ljava/lang/ClassLoader;",
	   0x1a84e8af, 0, Java_java_lang_ClassLoader_getParent, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getParent(JNIEnv *env, jobject _this) {
	return VM_CLASSLOADER_PARENT(_this);
}


#if JAVA_NET_ENABLED
static clsMethod Java_java_lang_ClassLoader_getResourceID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_NATIVE, "getResource", "(Ljava/lang/String;)Ljava/net/URL;",
	   0xc1dde2f2, 0, Java_java_lang_ClassLoader_getResource, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getResource(JNIEnv *env, jobject _this, jstring name) {
	FILE *f; const char *classpath; jboolean bExt = JNI_FALSE;
	char path[VM_MAX_PATH_LEN], file[VM_MAX_PATH_LEN], *pc, *ext; jint jarIndex, tmp;
	jobject ret = NULL;
	vmJavaVM *jvm = ((vmJNIEnv*)env)->vm;
	vmFrame *frame = ((vmJNIEnv*)env)->frame;
	if (name == NULL) return NULL;
	toUtf8(file, VM_STRING(name), -1);
	pc = file; ext = NULL; jarIndex = 0;
	while (*pc) { if (*pc == '.') {*pc = '/'; ext = pc; } pc++; }
	if (ext != NULL) *ext = '.';

	/* search the directories and zip files */
	classpath = ((vmJNIEnv*)env)->args->classpath;
	while (*classpath) {
		pc = path;
		while (*classpath && (*classpath != *VM_PATH_SEPARATOR)) *(pc++) = *(classpath++);
		*(pc++) = 0;
		if (*classpath == *VM_PATH_SEPARATOR) classpath++;
		tmp = vmStrLenUTF(path);
		if ((tmp > 4) && !vmStrCmpiUTF(path + tmp - 4, ".jar")) {
			/* find in java archive */
#if JAVA_UTIL_ZIP_ENABLED
			jobject zipEntry = NULL;
			/* load jar archive */
			if (jvm->jar[jarIndex] == NULL) {
				jclass zipClass = vmFindClassByName((vmJNIEnv*)env, "java/util/zip/ZipFile", 21, 0);
				jmethodID met = (zipClass != NULL) ? vmGetInstanceMethod(VM_CLASS_DEF(zipClass), "<init>", "(Ljava/lang/String;)V", JNI_TRUE) : NULL;
				jstring fname = jniNewStringUTF(env, path);
				if (met != NULL)
					jvm->jar[jarIndex] = JNINEWGLOBALREF(env, jniNewObject(env, zipClass, met, fname));
				jniDeleteLocalRef(env, fname);
				jniDeleteLocalRef(env, jvm->jar[jarIndex]);
				if (frame->exception != NULL) frame->exception = NULL;
			}
			/* get zip entry */
			if (jvm->jar[jarIndex] != NULL) {
				jstring fname = jniNewStringUTF(env, file);
				zipEntry = Java_java_util_zip_ZipFile_getEntry(env, jvm->jar[jarIndex], fname);
				jniDeleteLocalRef(env, fname);
				if (frame->exception != NULL) frame->exception = NULL;
			}
			jarIndex++;
			/* exist? */
			if (zipEntry != NULL) {
				jniDeleteLocalRef(env, zipEntry);
				ret = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_NET_URL, 0));
				if (ret != NULL) {
					vmStrCatUTF(path, "#");
					vmStrCatUTF(path, file);
					Java_java_net_URL_URL4(env, ret,
						jniNewStringUTF(env, "file"),
						jniNewStringUTF(env, "localhost"),
						jniNewStringUTF(env, path));
					return !jniExceptionOccurred(env) ? ret : NULL;
				}
			}
			jniDeleteLocalRef(env, zipEntry);
#endif
		} else {
			/* find in file system */
			if ((tmp > 0) && (path[tmp - 1] != '\\') && (path[tmp - 1] != '/'))
				vmStrCatUTF(path, "/");
			vmStrCatUTF(path, file);
			f = fopen(path, "rb");
			if (f != NULL) {
				fclose(f);
				ret = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_NET_URL, 0));
				if (ret != NULL)
					Java_java_net_URL_URL4(env, ret,
						jniNewStringUTF(env, "file"),
						jniNewStringUTF(env, "localhost"),
						jniNewStringUTF(env, path));
				return !jniExceptionOccurred(env) ? ret : NULL;
			}
		}
	}
	return NULL;
}


static clsMethod Java_java_lang_ClassLoader_getResourceAsStreamID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_NATIVE, "getResourceAsStream", "(Ljava/lang/String;)Ljava/util/InputStream;",
	   0x1119a3d0, 0, Java_java_lang_ClassLoader_getResourceAsStream, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getResourceAsStream(JNIEnv *env, jobject _this, jstring name) {
	jobject url = Java_java_lang_ClassLoader_getResource(env, _this, name), ret = NULL;
	if (url != NULL) {
        ret = Java_java_net_URL_openStream(env, url);
		jniDeleteLocalRef(env, url);
	}
	return ret;
}


static clsMethod Java_java_lang_ClassLoader_getResourcesID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_NATIVE, "getResources", "(Ljava/lang/String;)Ljava/util/Enumeration;",
	   0x9cd58206, 0, Java_java_lang_ClassLoader_getResources, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_ClassLoader_getResources(JNIEnv *env, jobject _this, jstring name) {
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION.name), "ClassLoader.getResources()");
	return NULL;
}
#endif


static clsMethod Java_java_lang_ClassLoader_loadClass1ID = {&clsJAVA_LANG_CLASSLOADER, ACC_PUBLIC|ACC_NATIVE, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",
	   0xe0b6709e, 0, Java_java_lang_ClassLoader_loadClass1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_loadClass1(JNIEnv *env, jobject _this, jstring name) {
	return jniCallObjectMethod(env, _this, 
		vmGetInstanceMethod(_this->clsdefdim, "loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", JNI_TRUE), 
		name, JNI_FALSE);
}


static clsMethod Java_java_lang_ClassLoader_loadClass2ID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_NATIVE, "loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;",
	   0x9befd350, 0, Java_java_lang_ClassLoader_loadClass2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jclass JNICALL Java_java_lang_ClassLoader_loadClass2(JNIEnv *env, jobject _this, jstring name, jboolean resolve) {
	jobject par; jclass ret; jmethodID met;
	par = VM_CLASSLOADER_PARENT(_this);

	/* is already loaded? */
	ret = Java_java_lang_ClassLoader_findLoadedClass(env, _this, name); /* final method */

	/* try parent class loader */
	if ((ret == NULL) && (par != NULL)) {
		met = vmGetInstanceMethod(par->clsdef, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;", JNI_TRUE);
		ret = jniCallObjectMethod(env, par, met, name);
		jniExceptionClear(env);
	}

	/* find class */
	if (ret == NULL) {
		met = vmGetInstanceMethod(_this->clsdef, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;", JNI_TRUE);
		ret = jniCallObjectMethod(env, _this, met, name);
		if (jniExceptionOccurred(env) != NULL)
			return ret;
	}

	/* resolve the class? */
	if ((ret != NULL) && resolve)
		Java_java_lang_ClassLoader_resolveClass(env, _this, ret); /* final method */
	return ret;
}


static clsMethod Java_java_lang_ClassLoader_resolveClassID = {&clsJAVA_LANG_CLASSLOADER, ACC_PROTECTED|ACC_FINAL|ACC_NATIVE, "resolveClass", "(Ljava/lang/Class;)V",
	   0xf388fe84, 0, Java_java_lang_ClassLoader_resolveClass, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_ClassLoader_resolveClass(JNIEnv *env, jobject _this, jclass clazz) {
	jint u, i, sz;
	jmethodID clinitID;
	jclass super_clazz;
	clsDefinition *cls, *cls_super;
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm;
	vmFrame *frame = ((vmJNIEnv*)env)->frame;
	
	if (clazz == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return;
	}

	/* already initialized? */
	cls = VM_CLASS_DEF(clazz);
	if (cls->access_flags & ACC_INITED)
		return;

	/* is owned by this VM? */
	if (cls->vm != vm) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNKNOWNERROR.name), cls->name);
		return;
	}

	/* find dependencies ? */
	if (cls->access_flags & ACC_FINDDEP) {
		/* super class */
		char *supername = (char*)cls->super_class;
		class_cache_entry *cce = (class_cache_entry*)vmHashFindEntry_Fce(&vm->clsdef, supername, vmStrLenUTF(supername), vmStringHashFceUTF);
		if (cce == NULL) {
			jstring SuperName = jniNewStringUTF(env, supername);
			jclass superclazz = Java_java_lang_SystemClassLoader_findClass(env, _this, SuperName);
			jniDeleteLocalRef(env, SuperName);
			if (superclazz != NULL)
				cls->super_class = VM_CLASS_DEF(superclazz);
			else {
				/* don't use the class */
				cls->access_flags |= ACC_RESOLVED;
			}
		} else
			cls->super_class = cce->cls;

		/* interfaces */
		for (i = 0; (i < cls->interfaces_count) && !frame->exception; i++) {
			char *name = cls->constant_pool[(jint)cls->interfaces[i]].q;
			jclass intfc = jniFindClass(env, name);
			if (intfc != NULL)
				cls->interfaces[i] = VM_CLASS_DEF(intfc);
			else {
				/* don't use the class */
				cls->access_flags |= ACC_RESOLVED;
				break;
			}
		}

		cls->access_flags &= ~ACC_FINDDEP;
		if (jniExceptionOccurred(env)) {
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSCIRCULARITYERROR.name), cls->name);
			return;
		}
	}

	/* circularity error? */
	cls_super = cls->super_class;
	while (cls_super != NULL) {
		if (cls_super == cls) {
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSCIRCULARITYERROR.name), cls->name);
			return;
		}
		cls_super = cls_super->super_class;
	}

	/* resolve super class */
	cls_super = cls->super_class;
	if (cls_super != NULL) {
		super_clazz = jniFindClass(env, cls_super->name);
		Java_java_lang_ClassLoader_resolveClass(env, _this, super_clazz);
	}
	if (jniExceptionOccurred(env) != NULL)
		return;
	if (cls_super != NULL)
		cls_super = cls->super_class = VM_CLASS_DEF(super_clazz);

	/* resolve interfaces */
	for (i = 0; i < cls->interfaces_count; i++) {
		jclass interface_clazz;
		clsDefinition *ifc = cls->interfaces[i];
		if (ifc == NULL) {
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOCLASSDEFFOUNDERROR.name), "interface not found");
			return;
		}
		interface_clazz = jniFindClass(env, ifc->name);
		Java_java_lang_ClassLoader_resolveClass(env, _this, interface_clazz);
		if (jniExceptionOccurred(env) != NULL)
			return;
	}

	/* already resolved? */
	VM_ENTER_CRITICAL_SECTION(vm->gcs);
	if (cls->access_flags & ACC_RESOLVED) {
		VM_LEAVE_CRITICAL_SECTION(vm->gcs);
		return;
	}
	cls->access_flags |= ACC_RESOLVED;

	/* find finalize() method */
	if (cls->finalizeID == NULL)
		cls->finalizeID = vmGetInstanceMethod(cls, "finalize", "()V", JNI_TRUE);

	/* calculate total_data_size */
	cls_super = cls->super_class;
	if (cls_super != NULL) {
		while ((cls_super->total_data_size == 0) && (cls_super->super_class != NULL))
			cls_super = cls_super->super_class;
		cls->total_data_size = cls->fields_data_size + cls_super->total_data_size;
	} else
		cls->total_data_size = cls->fields_data_size;

	/* calculate data offsets for instance fields */
	for (i = 0, sz = 0; i < cls->instance_fields_count; i++) {
		jfieldID fld; fld = cls->instance_fields + i;
		fld->data_off = ((cls_super != NULL) ? cls_super->total_data_size : 0) + sz;
		if (fld->descriptor[1])
			sz += sizeof(jobject);
		else
			switch (fld->descriptor[0]) {
				case 'Z': sz += sizeof(jboolean); break;
				case 'B': sz += sizeof(jbyte); break;
				case 'C': sz += sizeof(jchar); break;
				case 'S': sz += sizeof(jshort); break;
				case 'J': sz += sizeof(jlong); break;
				case 'F': sz += sizeof(jfloat); break;
				case 'D': sz += sizeof(jdouble); break;
				default:  sz += sizeof(jint); break;
			}
	}
	if (cls->fields_data_size < sz) {
		cls->fields_data_size = sz;
		cls_super = cls->super_class;
		if (cls_super != NULL)
			cls->total_data_size = cls->fields_data_size + cls_super->total_data_size;
		else
			cls->total_data_size = cls->fields_data_size;
	}

	/* create constant pool strings */
	for (u = 1; u < (jint)cls->constant_pool_count; u++) {
		clsConstPool *cp = cls->constant_pool + u;
		if (cp->tag == CONSTANT_String) {
			jint strlen = cls->constant_pool[cp->i].i + 1;
			jstring str = JNINEWGLOBALREF(env, vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_STRING, 0, 0, strlen * sizeof(jchar)));
			if (str == NULL) 
				goto RESOLVE_ERROR;
			VM_STRING_LEN(str) = fromUtf8(VM_STRING(str), cp->q, strlen);
			cp->p = str;
		}
	}

	/* create constant pool classes */
	for (u = 1; u < (jint)cls->constant_pool_count; u++) {
		clsConstPool *cp = cls->constant_pool + u;
		if (cp->tag == CONSTANT_Class)
			if (vmStrCmpUTF(cp->q, cls->name)) {
				if (NULL == (cp->p = jniFindClass(env, cp->q)))
					goto RESOLVE_ERROR;
			} else
				cp->p = clazz;
	}

	/* execute clinit method */
	clinitID = vmGetClassMethod(cls, "<clinit>", "()V", JNI_FALSE);
	cls->access_flags |= ACC_INITED;
	if (clinitID != NULL) {
		jthrowable err = jniExceptionOccurred(env), err2;
		jniCallStaticVoidMethodA(env, clazz, clinitID, NULL);
		err2 = jniExceptionOccurred(env);
		if (err != err2) {
			cls->access_flags &= ~ACC_INITED;
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_EXCEPTIONININITIALIZERERROR.name), cls->name);
		}
	}
	
RESOLVE_ERROR:
	VM_LEAVE_CRITICAL_SECTION(vm->gcs);
	return;
}


static clsMethod* instance_methods[] = {
	&Java_java_lang_ClassLoader_ClassLoader0ID,
	&Java_java_lang_ClassLoader_ClassLoader0ID,
	&Java_java_lang_ClassLoader_clearAssertionStatusID,
	&Java_java_lang_ClassLoader_defineClass3ID,
	&Java_java_lang_ClassLoader_defineClass4ID,
	&Java_java_lang_ClassLoader_defineClass5ID,
	&Java_java_lang_ClassLoader_findClassID,
	&Java_java_lang_ClassLoader_findLoadedClassID,
	&Java_java_lang_ClassLoader_findLibraryID,
	&Java_java_lang_ClassLoader_findSystemClassID,
	&Java_java_lang_ClassLoader_getParentID,
#if JAVA_NET_ENABLED
	&Java_java_lang_ClassLoader_getResourceID,
	&Java_java_lang_ClassLoader_getResourceAsStreamID,
	&Java_java_lang_ClassLoader_getResourcesID,
#endif
	&Java_java_lang_ClassLoader_loadClass1ID,
	&Java_java_lang_ClassLoader_loadClass2ID,
	&Java_java_lang_ClassLoader_resolveClassID
};



/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsField instance_fields[] = {
	{&clsJAVA_LANG_CLASSLOADER, ACC_PRIVATE, "_parent", "Ljava/lang/ClassLoader;", 0x4961dcf9, 0, NULL, 
		/* VM internal affairs */ 0, NULL}
};

clsDefinition clsJAVA_LANG_CLASSLOADER = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ClassLoader",       /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0xE0484D37,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC | ACC_SUPER | ACC_ABSTRACT, /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	sizeof(class_fields) / sizeof(clsField), /* class_fields_count */
	class_fields,                  /* class_fields */
	sizeof(instance_fields) / sizeof(clsField), /* instance_fields_count */
	instance_fields,               /* instance_fields */
	sizeof(class_methods) / sizeof(clsMethod*), /* class_methods_count */
	class_methods,                 /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,              /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(JavaLangClassLoaderIData), /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/*************************************************************************************************/


static clsMethod Java_java_lang_SystemClassLoader_findClassID = {&clsJAVA_LANG_SYSTEMCLASSLOADER, ACC_PROTECTED|ACC_NATIVE, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;",
	   0xa9e70b93, 0, Java_java_lang_SystemClassLoader_findClass, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jclass JNICALL Java_java_lang_SystemClassLoader_findClass(JNIEnv *env, jobject _this, jstring name) {
	FILE *f; const char *classpath; vmJavaVM *jvm; vmFrame *frame; jint jarIndex, tmp, dim;
	char path[VM_MAX_PATH_LEN], file[VM_MAX_PATH_LEN], *pc, *supername, _name[VM_MAX_PATH_LEN];
	const jchar *oname; class_cache_entry *cce; jushort i; unsigned long len; jbyte *buf;
	jclass ret = NULL; clsDefinition *cls;
	jvm = ((vmJNIEnv*)env)->vm;
	frame = ((vmJNIEnv*)env)->frame;
	oname = VM_STRING(name);
	dim = 0; while (*oname == '[') { dim++; oname++; }
	toUtf8(file, oname, -1); vmStrCpyUTF(_name, file);
	pc = file; jarIndex = 0;
	while (*pc) { if (*pc == '.') *pc = '/'; pc++; }
	vmStrCatUTF(file, ".class");

	/* search the directories and zip files */
	classpath = ((vmJNIEnv*)env)->args->classpath;
	while (*classpath) {
		pc = path;
		while (*classpath && (*classpath != *VM_PATH_SEPARATOR)) *(pc++) = *(classpath++);
		*(pc++) = 0;
		if (*classpath == *VM_PATH_SEPARATOR) classpath++;
		tmp = vmStrLenUTF(path);
		if ((tmp > 4) && !vmStrCmpiUTF(path + tmp - 4, ".jar")) {
			/* find in java archive */
#if JAVA_UTIL_ZIP_ENABLED
			jobject zipEntry = NULL; jbyteArray buf = NULL;
			/* load jar archive */
			if (jvm->jar[jarIndex] == NULL) {
				jclass zipClass = vmFindClassByName((vmJNIEnv*)env, "java/util/zip/ZipFile", 21, 0);
				jmethodID met = (zipClass != NULL) ? vmGetInstanceMethod(VM_CLASS_DEF(zipClass), "<init>", "(Ljava/lang/String;)V", JNI_TRUE) : NULL;
				jstring fname = jniNewStringUTF(env, path);
				if (met != NULL)
					jvm->jar[jarIndex] = JNINEWGLOBALREF(env, jniNewObject(env, zipClass, met, fname));
				jniDeleteLocalRef(env, fname);
				jniDeleteLocalRef(env, jvm->jar[jarIndex]);
				if (frame->exception != NULL) frame->exception = NULL;
			}
			/* get zip entry */
			if (jvm->jar[jarIndex] != NULL) {
				jstring fname = jniNewStringUTF(env, file);
				zipEntry = Java_java_util_zip_ZipFile_getEntry(env, jvm->jar[jarIndex], fname);
				jniDeleteLocalRef(env, fname);
				if (frame->exception != NULL) frame->exception = NULL;
			}
			/* create byte buffer */
			if (zipEntry != NULL) {
				jint size = (jint)Java_java_util_zip_ZipEntry_getSize(env, zipEntry);
				if (size > 0)
					buf = jniNewByteArray(env, size);
			}
			/* load class to buffer */
			if (buf != NULL) {
				jobject stream = Java_java_util_zip_ZipFile_getInputStream(env, jvm->jar[jarIndex], zipEntry);
				if (stream != NULL) {
					jmethodID met = vmGetInstanceMethod(stream->clsdefdim, "read", "([B)I", JNI_TRUE);
					if (met != NULL)
						tmp = jniCallIntMethod(env, stream, met, buf);
					if ((met == NULL) || (tmp != VM_ARRAY_LENGTH(buf))) {
						jniDeleteLocalRef(env, stream);
						goto JAR_DONE;
					}
				} else
					goto JAR_DONE;
				jniDeleteLocalRef(env, stream);
				if (frame->exception != NULL) goto JAR_DONE;
			}
			jarIndex++;
			/* define class */
			if (buf != NULL) {
				ret = jniDefineClass(env, ((vmJNIEnv*)env)->vm->loader, (jbyte*)VM_ARRAY_ARRAY(buf), VM_ARRAY_LENGTH(buf));
				jniDeleteLocalRef(env, buf);
				jniDeleteLocalRef(env, zipEntry);
				goto CLASS_FOUND;
			}
JAR_DONE:	if (frame->exception != NULL) frame->exception = NULL;
			jniDeleteLocalRef(env, buf);
			jniDeleteLocalRef(env, zipEntry);
#endif
		} else {
			/* find in file system */
			if ((tmp > 0) && (path[tmp - 1] != '\\') && (path[tmp - 1] != '/'))
				vmStrCatUTF(path, "/");
			vmStrCatUTF(path, file);
			f = fopen(path, "rb");
			if (f != NULL) {
				len = 0; buf = NULL;
				if (0 == fseek(f, 0, SEEK_END)) {
					len = ftell(f);
					fseek(f, 0, SEEK_SET);
					buf = vmMemAlloc(((vmJNIEnv*)env)->vm, len);
					if (buf != NULL)
						if (len != fread(buf, 1, len, f)) {
							vmMemFree(((vmJNIEnv*)env)->vm, buf); 
							buf = NULL;
						}
				}
				fclose(f);
				if (buf != 0) {
					/* define class */
					ret = jniDefineClass(env, ((vmJNIEnv*)env)->vm->loader, buf, len);
					vmMemFree(((vmJNIEnv*)env)->vm, buf);
CLASS_FOUND:		if (ret == NULL) goto CLASS_NOT_FOUND;
					cls = VM_CLASS_DEF(ret);
					vmSetObjectVar(env, &VM_CLASS_LOADER(ret), _this, 
						vmGetInstanceField(&clsJAVA_LANG_CLASS, "_classloader", "Ljava/lang/ClassLoader;", JNI_FALSE));
					cls->access_flags &= ~ACC_FINDDEP;

					/* super class */
					supername = (char*)cls->super_class;
					cce = (class_cache_entry*)vmHashFindEntry_Fce(&jvm->clsdef, supername, vmStrLenUTF(supername), vmStringHashFceUTF);
					if (cce == NULL) {
						jstring SuperName = jniNewStringUTF(env, supername);
						jclass superclazz = Java_java_lang_SystemClassLoader_findClass(env, _this, SuperName);
						jniDeleteLocalRef(env, SuperName);
						if (superclazz != NULL)
							cls->super_class = VM_CLASS_DEF(superclazz);
						else {
							/* don't use the class */
							cls->access_flags |= ACC_RESOLVED;
							goto CLASS_NOT_FOUND;
						}
					} else
						cls->super_class = cce->cls;

					/* interfaces */
					for (i = 0; (i < cls->interfaces_count) && !frame->exception; i++) {
						char *name = cls->constant_pool[(jint)cls->interfaces[i]].q;
						jclass intfc = jniFindClass(env, name);
						if (intfc != NULL)
							cls->interfaces[i] = VM_CLASS_DEF(intfc);
						else {
							/* don't use the class */
							cls->access_flags |= ACC_RESOLVED;
							goto CLASS_NOT_FOUND;
						}
					}
	
					/* create class object */
					ret = vmFindClassByDef((vmJNIEnv*)env, cls, dim);
				}
				if ((ret == NULL) && (frame->exception == NULL)) goto CLASS_NOT_FOUND;
				return ret;
			}
		}
	}

	/* class not found */
CLASS_NOT_FOUND:
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOCLASSDEFFOUNDERROR.name), NULL);
	if (jniExceptionOccurred(env) != NULL)
		JNINEWGLOBALREF(env, VM_THROWABLE_MSG(jniExceptionOccurred(env)) = name);
	else
		jniThrow(env, jvm->outofmem);
	return NULL;
}


static clsMethod* systemloader_instance_methods[] = {
	&Java_java_lang_SystemClassLoader_findClassID
};


clsDefinition clsJAVA_LANG_SYSTEMCLASSLOADER = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/SystemClassLoader", /* name */
	&clsJAVA_LANG_CLASSLOADER,     /* super_class */
	0x62DB4688,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC | ACC_SUPER,        /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(systemloader_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	systemloader_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};
