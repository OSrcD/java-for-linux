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


#ifndef _JAVA_LANG_OBJECT_H_
#define _JAVA_LANG_OBJECT_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Class.h"
#include "vm.h"
extern clsDefinition clsJAVA_LANG_OBJECT;
extern clsDefinition clsJAVA_LANG_OBJECT_ARRAY;


/* Object methods */
void JNICALL Java_java_lang_Object_Object(JNIEnv *env, jobject _this);
jobject	JNICALL Java_java_lang_Object_clone(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Object_equals(JNIEnv *env, jobject _this, jobject obj);
jclass JNICALL Java_java_lang_Object_getClass(JNIEnv *env, jobject _this);
jint JNICALL Java_java_lang_Object_hashCode(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Object_notify(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Object_notifyAll(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_Object_toString(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Object_wait0(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_Object_wait1(JNIEnv *env, jobject _this, jlong timeout);
void JNICALL Java_java_lang_Object_wait2(JNIEnv *env, jobject _this, jlong timeout, jint nanos);


/* Object[] instance data */
typedef struct _JavaLangObjectArrayIData {
	jint length;           /* array length */
} JavaLangObjectArrayIData;
#define VM_ARRAY_LENGTH(arr) (((JavaLangObjectArrayIData*)((arr)->data))->length)
#define VM_ARRAY_ARRAY(arr)  (((jobject*)((arr)->data)) + 1)


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_OBJECT_H_ */