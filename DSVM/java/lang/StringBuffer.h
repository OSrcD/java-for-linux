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


#ifndef _JAVA_LANG_STRINGBUFFER_H_
#define _JAVA_LANG_STRINGBUFFER_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Object.h"
extern clsDefinition clsJAVA_LANG_STRINGBUFFER;


/* append a string */
jobject JNICALL Java_java_lang_StringBuffer_append(JNIEnv *env, jobject _this, jchar *str, jint str_len);


/* instance data */
typedef struct _JavaLangStringBufferIData {
	jint   _len;
	jint   _capacity;
	jchar  _str[1];
} JavaLangStringBufferIData;
#define VM_STRBUF_LEN(s) (((JavaLangStringBufferIData*)((s)->data))->_len)
#define VM_STRBUF_CAP(s) (((JavaLangStringBufferIData*)((s)->data))->_capacity)
#define VM_STRBUF_STR(s) (((JavaLangStringBufferIData*)((s)->data))->_str)


/* instance methods */
void JNICALL Java_java_lang_StringBuffer_StringBuffer1(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_StringBuffer_StringBuffer2(JNIEnv *env, jobject _this, jint mincap);
void JNICALL Java_java_lang_StringBuffer_StringBuffer3(JNIEnv *env, jobject _this, jstring str);
jobject JNICALL Java_java_lang_StringBuffer_append1(JNIEnv *env, jobject _this, jboolean b);
jobject JNICALL Java_java_lang_StringBuffer_append2(JNIEnv *env, jobject _this, jchar ch);
jobject JNICALL Java_java_lang_StringBuffer_append3(JNIEnv *env, jobject _this, jcharArray data);
jobject JNICALL Java_java_lang_StringBuffer_append4(JNIEnv *env, jobject _this, jcharArray data, jint offset, jint len);
jobject JNICALL Java_java_lang_StringBuffer_append5(JNIEnv *env, jobject _this, jdouble d);
jobject JNICALL Java_java_lang_StringBuffer_append6(JNIEnv *env, jobject _this, jfloat f);
jobject JNICALL Java_java_lang_StringBuffer_append7(JNIEnv *env, jobject _this, jint i);
jobject JNICALL Java_java_lang_StringBuffer_append8(JNIEnv *env, jobject _this, jlong l);
jobject JNICALL Java_java_lang_StringBuffer_append9(JNIEnv *env, jobject _this, jobject obj);
jobject JNICALL Java_java_lang_StringBuffer_append10(JNIEnv *env, jobject _this, jstring str);
jobject JNICALL Java_java_lang_StringBuffer_append11(JNIEnv *env, jobject _this, jobject sb);
jint JNICALL Java_java_lang_StringBuffer_capacity(JNIEnv *env, jobject _this);
jchar JNICALL Java_java_lang_StringBuffer_charAt(JNIEnv *env, jobject _this, jint index);
jobject JNICALL Java_java_lang_StringBuffer_delete(JNIEnv *env, jobject _this, jint start, jint end);
jobject JNICALL Java_java_lang_StringBuffer_deleteCharAt(JNIEnv *env, jobject _this, jint index);
void JNICALL Java_java_lang_StringBuffer_ensureCapacity(JNIEnv *env, jobject _this, jint mincap);
void JNICALL Java_java_lang_StringBuffer_getChars(JNIEnv *env, jobject _this, jint start, jint end, jcharArray dst, jint dstStart);
jint JNICALL Java_java_lang_StringBuffer_indexOf1(JNIEnv *env, jobject _this, jstring str);
jint JNICALL Java_java_lang_StringBuffer_indexOf2(JNIEnv *env, jobject _this, jstring str, jint fromIndex);
jobject JNICALL Java_java_lang_StringBuffer_insert1(JNIEnv *env, jobject _this, jint offset, jboolean b);
jobject JNICALL Java_java_lang_StringBuffer_insert2(JNIEnv *env, jobject _this, jint offset, jchar ch);
jobject JNICALL Java_java_lang_StringBuffer_insert3(JNIEnv *env, jobject _this, jint offset, jcharArray data);
jobject JNICALL Java_java_lang_StringBuffer_insert4(JNIEnv *env, jobject _this, jint offset, jcharArray data, jint start, jint len);
jobject JNICALL Java_java_lang_StringBuffer_insert5(JNIEnv *env, jobject _this, jint offset, jdouble d);
jobject JNICALL Java_java_lang_StringBuffer_insert6(JNIEnv *env, jobject _this, jint offset, jfloat f);
jobject JNICALL Java_java_lang_StringBuffer_insert7(JNIEnv *env, jobject _this, jint offset, jint i);
jobject JNICALL Java_java_lang_StringBuffer_insert8(JNIEnv *env, jobject _this, jint offset, jlong l);
jobject JNICALL Java_java_lang_StringBuffer_insert9(JNIEnv *env, jobject _this, jint offset, jobject obj);
jobject JNICALL Java_java_lang_StringBuffer_insert10(JNIEnv *env, jobject _this, jint offset, jstring str);
jint JNICALL Java_java_lang_StringBuffer_lastIndexOf1(JNIEnv *env, jobject _this, jstring str);
jint JNICALL Java_java_lang_StringBuffer_lastIndexOf2(JNIEnv *env, jobject _this, jstring str, jint fromIndex);
jint JNICALL Java_java_lang_StringBuffer_length(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_StringBuffer_replace(JNIEnv *env, jobject _this, jint start, jint end, jstring str);
jobject JNICALL Java_java_lang_StringBuffer_reverse(JNIEnv *env, jobject _this);
void JNICALL Java_java_lang_StringBuffer_setCharAt(JNIEnv *env, jobject _this, jint index, jchar ch);
void JNICALL Java_java_lang_StringBuffer_setLength(JNIEnv *env, jobject _this, jint length);
jobject JNICALL Java_java_lang_StringBuffer_subSequence(JNIEnv *env, jobject _this, jint start, jint end);
jstring JNICALL Java_java_lang_StringBuffer_substring1(JNIEnv *env, jobject _this, jint start);
jstring JNICALL Java_java_lang_StringBuffer_substring2(JNIEnv *env, jobject _this, jint start, jint end);
jstring JNICALL Java_java_lang_StringBuffer_toString(JNIEnv *env, jobject _this);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_STRINGBUFFER_H_ */
