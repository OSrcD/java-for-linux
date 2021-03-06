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


#ifndef _JAVA_LANG_THREAD_H_
#define _JAVA_LANG_THREAD_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Object.h"
#include "Runnable.h"
extern clsDefinition clsJAVA_LANG_THREAD;


/* instance data */
typedef struct _JavaLangThreadIData {
	jstring name;
	jobject target;
	jobject group;
	jobject classloader;
	JavaVM *jvm;
	vmJNIEnv *env;
	jint priority;
	jboolean fDaemon;
	jboolean fInterrupt;
	jboolean fStartable;
	jboolean fAlive;
	natThreadData nat;
	natThreadID tid;
	natEventData create_event;
	jlong stacksize;
} JavaLangThreadIData;
#define VM_THREAD_DATA(t) ((JavaLangThreadIData*)((t)->data))
extern clsMethod Java_java_lang_Thread_runID;


/* class methods */
jint JNICALL Java_java_lang_Thread_activeCount(JNIEnv *env, jclass _clazz);
jobject JNICALL Java_java_lang_Thread_currentThread(JNIEnv *env, jclass _clazz);
void JNICALL Java_java_lang_Thread_dumpStack(JNIEnv *env, jclass _clazz);
jint JNICALL Java_java_lang_Thread_enumerate(JNIEnv *env, jclass _clazz, jarray threads);
jboolean JNICALL Java_java_lang_Thread_holdsLock(JNIEnv *env, jclass _clazz, jobject obj);
jboolean JNICALL Java_java_lang_Thread_interrupted(JNIEnv *env, jclass _clazz);
void JNICALL Java_java_lang_Thread_sleep1(JNIEnv *env, jclass _clazz, jlong msec);
void JNICALL Java_java_lang_Thread_sleep2(JNIEnv *env, jclass _clazz, jlong msec, jint nsec);
void JNICALL Java_java_lang_Thread_yield(JNIEnv *env, jclass _clazz);


/* instance methods */
void JNICALL Java_java_lang_Thread_Thread0(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_Thread1(JNIEnv *env, jobject _this, jobject target);
void JNICALL Java_java_lang_Thread_Thread2(JNIEnv *env, jobject _this, jobject target, jstring name);
void JNICALL Java_java_lang_Thread_Thread3(JNIEnv *env, jobject _this, jstring name);
void JNICALL Java_java_lang_Thread_Thread4(JNIEnv *env, jobject _this, jobject group, jobject target);
void JNICALL Java_java_lang_Thread_Thread5(JNIEnv *env, jobject _this, jobject group, jobject target, jstring name);
void JNICALL Java_java_lang_Thread_Thread6(JNIEnv *env, jobject _this, jobject group, jobject target, jstring name, jlong stackSize);
void JNICALL Java_java_lang_Thread_Thread7(JNIEnv *env, jobject _this, jobject group, jstring name);
void JNICALL Java_java_lang_Thread_checkAccess(JNIEnv *env, jobject _this);
jint JNICALL Java_java_lang_Thread_countStackFrames(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_destroy(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Thread_getContextClassLoader(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_Thread_getName(JNIEnv *env, jobject _this);
jint JNICALL Java_java_lang_Thread_getPriority(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Thread_getThreadGroup(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_interrupt(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Thread_isAlive(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Thread_isDaemon(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Thread_isInterrupted(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_join1(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_join2(JNIEnv *env, jobject _this, jlong millis);
void JNICALL Java_java_lang_Thread_join3(JNIEnv *env, jobject _this, jlong millis, jint nanos);
void JNICALL Java_java_lang_Thread_resume(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_run(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_setContextClassLoader(JNIEnv *env, jobject _this, jobject cl);
void JNICALL Java_java_lang_Thread_setDaemon(JNIEnv *env, jobject _this, jboolean on);
void JNICALL Java_java_lang_Thread_setName(JNIEnv *env, jobject _this, jstring name);
void JNICALL Java_java_lang_Thread_setPriority(JNIEnv *env, jobject _this, jint newPriority);
void JNICALL Java_java_lang_Thread_start(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_stop1(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Thread_stop2(JNIEnv *env, jobject _this, jobject obj);
void JNICALL Java_java_lang_Thread_suspend(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_Thread_toString(JNIEnv *env, jobject _this);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_THREAD_H_ */
