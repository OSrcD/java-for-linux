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


#ifndef _JAVA_LANG_RUNTIME_H_
#define _JAVA_LANG_RUNTIME_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Object.h"
extern clsDefinition clsJAVA_LANG_RUNTIME;


/* class methods */
jobject JNICALL Java_java_lang_Runtime_getRuntime(JNIEnv *env, jclass clazz);
void JNICALL Java_java_lang_Runtime_runFinalizersOnExit(JNIEnv *env, jclass clazz, jboolean value);


/* instance methods */
void JNICALL Java_java_lang_Runtime_addShutdownHook(JNIEnv *env, jobject _this, jobject hook);
jint JNICALL Java_java_lang_Runtime_availableProcessors(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Runtime_exec1(JNIEnv *env, jobject _this, jstring command);
jobject JNICALL Java_java_lang_Runtime_exec2(JNIEnv *env, jobject _this, jarray cmdarray);
jobject JNICALL Java_java_lang_Runtime_exec3(JNIEnv *env, jobject _this, jarray cmdarray, jarray envp);
jobject JNICALL Java_java_lang_Runtime_exec4(JNIEnv *env, jobject _this, jarray cmdarray, jarray envp, jobject dir);
jobject JNICALL Java_java_lang_Runtime_exec5(JNIEnv *env, jobject _this, jstring cmd, jarray envp);
jobject JNICALL Java_java_lang_Runtime_exec6(JNIEnv *env, jobject _this, jstring command, jarray envp, jobject dir);
void JNICALL Java_java_lang_Runtime_exit(JNIEnv *env, jobject _this, jint status);
jlong JNICALL Java_java_lang_Runtime_freeMemory(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Runtime_gc(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Runtime_halt(JNIEnv *env, jobject _this, jint status);
void JNICALL Java_java_lang_Runtime_load(JNIEnv *env, jobject _this, jstring filename);
void JNICALL Java_java_lang_Runtime_loadLibrary(JNIEnv *env, jobject _this, jstring libname);
jlong JNICALL Java_java_lang_Runtime_maxMemory(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Runtime_removeShutdownHook(JNIEnv *env, jobject _this, jobject hook);
void JNICALL Java_java_lang_Runtime_runFinalization(JNIEnv *env, jobject _this);
jlong JNICALL Java_java_lang_Runtime_totalMemory(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Runtime_traceInstructions(JNIEnv *env, jobject _this, jboolean on);
void JNICALL Java_java_lang_Runtime_traceMethodCalls(JNIEnv *env, jobject _this, jboolean on);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_RUNTIME_H_ */
