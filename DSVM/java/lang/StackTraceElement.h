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


#ifndef _JAVA_LANG_STACKTRACEELEMENT_H_
#define _JAVA_LANG_STACKTRACEELEMENT_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Object.h"
#include "Throwable.h"
extern clsDefinition clsJAVA_LANG_STACKTRACEELEMENT;


/* instance data */
typedef struct _JavaLangStackTraceIData {
	jmethodID met;
	jint line_number;
} JavaLangStackTraceIData;
#define VM_STACK_TRACE(o) ((JavaLangStackTraceIData*)((o)->data))


/* methods */
jboolean JNICALL Java_java_lang_StackTraceElement_equals(JNIEnv *env, jobject _this, jobject obj);
jstring JNICALL Java_java_lang_StackTraceElement_getClassName(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_StackTraceElement_getFileName(JNIEnv *env, jobject _this);
jint JNICALL Java_java_lang_StackTraceElement_getLineNumber(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_StackTraceElement_getMethodName(JNIEnv *env, jobject _this);
jint JNICALL Java_java_lang_StackTraceElement_hashCode(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_StackTraceElement_isNativeMethod(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_StackTraceElement_toString(JNIEnv *env, jobject _this);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_STACKTRACEELEMENT_H_ */
