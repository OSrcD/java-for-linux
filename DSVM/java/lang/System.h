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


#ifndef _JAVA_LANG_SYSTEM_H_
#define _JAVA_LANG_SYSTEM_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Object.h"
extern clsDefinition clsJAVA_LANG_SYSTEM;


/* class methods */
void JNICALL Java_java_lang_System_arraycopy(JNIEnv *env, jclass clazz, jobject src, jint srcPos, jobject dest, jint destPos, jint length);
jlong JNICALL Java_java_lang_System_currentTimeMillis(JNIEnv *env, jclass clazz);
void JNICALL Java_java_lang_System_exit(JNIEnv *env, jclass clazz, jint status);
void JNICALL Java_java_lang_System_gc(JNIEnv *env, jclass clazz);
jstring JNICALL Java_java_lang_System_getenv(JNIEnv *env, jclass clazz, jstring name);
jobject JNICALL Java_java_lang_System_getProperties(JNIEnv *env, jclass clazz);
jstring JNICALL Java_java_lang_System_getProperty1(JNIEnv *env, jclass clazz, jstring key);
jstring JNICALL Java_java_lang_System_getProperty2(JNIEnv *env, jclass clazz, jstring key, jstring def);
jobject JNICALL Java_java_lang_System_getSecurityManager(JNIEnv *env, jclass clazz);
jint JNICALL Java_java_lang_System_identityHashCode(JNIEnv *env, jclass clazz, jobject obj);
void JNICALL Java_java_lang_System_load(JNIEnv *env, jclass clazz, jstring filename);
void JNICALL Java_java_lang_System_loadLibrary(JNIEnv *env, jclass clazz, jstring libname);
jstring JNICALL Java_java_lang_System_mapLibraryName(JNIEnv *env, jclass clazz, jstring libname);
void JNICALL Java_java_lang_System_runFinalization(JNIEnv *env, jclass clazz);
void JNICALL Java_java_lang_System_runFinalizersOnExit(JNIEnv *env, jclass clazz, jboolean value);
void JNICALL Java_java_lang_System_setErr(JNIEnv *env, jclass clazz, jobject err);
void JNICALL Java_java_lang_System_setIn(JNIEnv *env, jclass clazz, jobject in);
void JNICALL Java_java_lang_System_setOut(JNIEnv *env, jclass clazz, jobject out);
void JNICALL Java_java_lang_System_setProperties(JNIEnv *env, jclass clazz, jobject props);
jstring JNICALL Java_java_lang_System_setProperty(JNIEnv *env, jclass clazz, jstring key, jstring value);
void JNICALL Java_java_lang_System_setSecurityManager(JNIEnv *env, jclass clazz, jobject sm);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_SYSTEM_H_ */
