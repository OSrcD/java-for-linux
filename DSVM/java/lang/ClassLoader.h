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


#ifndef _JAVA_LANG_CLASSLOADER_H_
#define _JAVA_LANG_CLASSLOADER_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Class.h"
extern clsDefinition clsJAVA_LANG_CLASSLOADER;


/* instance data */
typedef struct _JavaLangClassLoaderIData {
	jobject _parent;           /* parent class loader */
} JavaLangClassLoaderIData;
#define VM_CLASSLOADER_PARENT(c) (((JavaLangClassLoaderIData*)((c)->data))->_parent)


/* ClassLoader static methods */
jobject JNICALL Java_java_lang_ClassLoader_getSystemClassLoader(JNIEnv *env, jclass clazz);
jobject JNICALL Java_java_lang_ClassLoader_getSystemResource(JNIEnv *env, jclass clazz, jstring name);
jobject JNICALL Java_java_lang_ClassLoader_getSystemResourceAsStream(JNIEnv *env, jclass clazz, jstring name);
jobject JNICALL Java_java_lang_ClassLoader_getSystemResources(JNIEnv *env, jclass clazz, jstring name);


/* ClassLoader instance methods */
void JNICALL Java_java_lang_ClassLoader_ClassLoader0(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_ClassLoader_ClassLoader1(JNIEnv *env, jobject _this, jobject parent);
jclass JNICALL Java_java_lang_ClassLoader_defineClass3(JNIEnv *env, jobject _this, jarray buf, jint off, jint len);
jclass JNICALL Java_java_lang_ClassLoader_defineClass4(JNIEnv *env, jobject _this, jstring name, jarray buf, jint off, jint len);
jclass JNICALL Java_java_lang_ClassLoader_defineClass5(JNIEnv *env, jobject _this, jstring name, jarray buf, jint off, jint len, jobject protectionDomain);
void JNICALL Java_java_lang_ClassLoader_clearAssertionStatus(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_ClassLoader_getResource(JNIEnv *env, jobject _this, jstring name);
jobject JNICALL Java_java_lang_ClassLoader_getResourceAsStream(JNIEnv *env, jobject _this, jstring name);
jobject JNICALL Java_java_lang_ClassLoader_getResources(JNIEnv *env, jobject _this, jstring name);
jclass JNICALL Java_java_lang_ClassLoader_findClass(JNIEnv *env, jobject _this, jstring name);
jstring JNICALL Java_java_lang_ClassLoader_findLibrary(JNIEnv *env, jobject _this, jstring libname);
jclass JNICALL Java_java_lang_ClassLoader_findLoadedClass(JNIEnv *env, jobject _this, jstring name);
jclass JNICALL Java_java_lang_ClassLoader_findSystemClass(JNIEnv *env, jobject _this, jstring name);
jobject JNICALL Java_java_lang_ClassLoader_getParent(JNIEnv *env, jobject _this);
jclass JNICALL Java_java_lang_ClassLoader_loadClass1(JNIEnv *env, jobject _this, jstring name);
jclass JNICALL Java_java_lang_ClassLoader_loadClass2(JNIEnv *env, jobject _this, jstring name, jboolean resolve);
void JNICALL Java_java_lang_ClassLoader_resolveClass(JNIEnv *env, jobject _this, jclass clazz);


/* SystemClassLoader instance methods */
jclass JNICALL Java_java_lang_SystemClassLoader_findClass(JNIEnv *env, jobject _this, jstring name);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_CLASSLOADER_H_ */
