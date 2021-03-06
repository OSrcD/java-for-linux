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


#ifndef _JAVA_LANG_THROWABLE_H_
#define _JAVA_LANG_THROWABLE_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Object.h"
#include "..\io\Serializable.h"
extern clsDefinition clsJAVA_LANG_THROWABLE;
extern clsMethod Java_java_lang_Throwable_printStackTrace0ID;


/* Stores the detail message string of this throwable to buffer. */
jint Java_java_lang_Throwable_toString_c(JNIEnv *env, jthrowable _this, char *buf);
jint Java_java_lang_Throwable_toStackTrace_c(JNIEnv *env, jthrowable _this, char *buf, jthrowable prev);


/* instance data */
typedef struct _JavaLangThrowableIData {
	jstring _msg;
	jthrowable _cause;
	jint _stack_trace_count;  /* count of the stack traces */ 
	void *_stack_trace;
} JavaLangThrowableIData;
#define VM_THROWABLE_MSG(t)   (((JavaLangThrowableIData*)((t)->data))->_msg)
#define VM_THROWABLE_CAUSE(t) (((JavaLangThrowableIData*)((t)->data))->_cause)
#define VM_THROWABLE_STACK_COUNT(t) (((JavaLangThrowableIData*)((t)->data))->_stack_trace_count)
#define VM_THROWABLE_STACK(t) (((JavaLangThrowableIData*)((t)->data))->_stack_trace)


/* methods */
void JNICALL Java_java_lang_Throwable_Throwable0(JNIEnv *env, jthrowable _this);
void JNICALL Java_java_lang_Throwable_Throwable1(JNIEnv *env, jthrowable _this, jstring msg);
void JNICALL Java_java_lang_Throwable_Throwable2(JNIEnv *env, jthrowable _this, jstring msg, jthrowable cause);
void JNICALL Java_java_lang_Throwable_Throwable3(JNIEnv *env, jthrowable _this, jthrowable cause);
jthrowable JNICALL Java_java_lang_Throwable_fillInStackTrace(JNIEnv *env, jthrowable _this);
jthrowable JNICALL Java_java_lang_Throwable_getCause(JNIEnv *env, jthrowable _this);
jstring JNICALL Java_java_lang_Throwable_getLocalizedMessage(JNIEnv *env, jthrowable _this);
jstring JNICALL Java_java_lang_Throwable_getMessage(JNIEnv *env, jthrowable _this);
jthrowable JNICALL Java_java_lang_Throwable_initCause(JNIEnv *env, jthrowable _this, jthrowable cause);
void JNICALL Java_java_lang_Throwable_printStackTrace0(JNIEnv *env, jthrowable _this);
void JNICALL Java_java_lang_Throwable_printStackTrace1(JNIEnv *env, jthrowable _this, jobject ps);
void JNICALL Java_java_lang_Throwable_printStackTrace2(JNIEnv *env, jthrowable _this, jobject pw);
jstring JNICALL Java_java_lang_Throwable_toString(JNIEnv *env, jthrowable _this);

/* stack trace support */
jint Java_java_lang_Throwable_fillInStackTrace_count(JNIEnv *env);
void Java_java_lang_Throwable_fillInStackTrace_fill(JNIEnv *env, jthrowable _this);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_THROWABLE_H_ */
