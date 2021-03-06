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


#ifndef _JAVA_LANG_STRING_H_
#define _JAVA_LANG_STRING_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Object.h"
extern clsDefinition clsJAVA_LANG_STRING;


/* instance data */
typedef struct _JavaLangStringIData {
	jint   _len;
	jint   _hash;	/* caches the result of hashCode() */
	jchar  _str[1];
} JavaLangStringIData;
#define VM_STRING(s)      (((JavaLangStringIData*)((s)->data))->_str)
#define VM_STRING_LEN(s)  (((JavaLangStringIData*)((s)->data))->_len)
#define VM_STRING_HASH(s) (((JavaLangStringIData*)((s)->data))->_hash)


/* class methods */
jstring JNICALL Java_java_lang_String_copyValueOf1(JNIEnv *env, jclass _clazz, jcharArray data);
jstring JNICALL Java_java_lang_String_copyValueOf2(JNIEnv *env, jclass _clazz, jcharArray data, jint start, jint len);
jstring JNICALL Java_java_lang_String_valueOf1(JNIEnv *env, jclass _clazz, jboolean b);
jstring JNICALL Java_java_lang_String_valueOf2(JNIEnv *env, jclass _clazz, jchar ch);
jstring JNICALL Java_java_lang_String_valueOf3(JNIEnv *env, jclass _clazz, jcharArray data);
jstring JNICALL Java_java_lang_String_valueOf4(JNIEnv *env, jclass _clazz, jcharArray data, jint start, jint len);
jstring JNICALL Java_java_lang_String_valueOf5(JNIEnv *env, jclass _clazz, jdouble d);
jstring JNICALL Java_java_lang_String_valueOf6(JNIEnv *env, jclass _clazz, jfloat f);
jstring JNICALL Java_java_lang_String_valueOf7(JNIEnv *env, jclass _clazz, jint i);
jstring JNICALL Java_java_lang_String_valueOf8(JNIEnv *env, jclass _clazz, jlong l);
jstring JNICALL Java_java_lang_String_valueOf9(JNIEnv *env, jclass _clazz, jobject obj);


/* instance methods */
void JNICALL Java_java_lang_String_String1(JNIEnv *env, jstring _this);
void JNICALL Java_java_lang_String_String2(JNIEnv *env, jstring _this, jbyteArray bytes);
void JNICALL Java_java_lang_String_String3(JNIEnv *env, jstring _this, jbyteArray ascii, jint hibyte);
void JNICALL Java_java_lang_String_String4(JNIEnv *env, jstring _this, jbyteArray bytes, jint start, jint len);
void JNICALL Java_java_lang_String_String5(JNIEnv *env, jstring _this, jbyteArray ascii, jint hibyte, jint start, jint len);
void JNICALL Java_java_lang_String_String6(JNIEnv *env, jstring _this, jbyteArray bytes, jint start, jint len, jstring charsetName);
void JNICALL Java_java_lang_String_String7(JNIEnv *env, jstring _this, jbyteArray bytes, jstring charsetName);
void JNICALL Java_java_lang_String_String8(JNIEnv *env, jstring _this, jcharArray chars);
void JNICALL Java_java_lang_String_String9(JNIEnv *env, jstring _this, jcharArray chars, jint start, jint len);
void JNICALL Java_java_lang_String_String10(JNIEnv *env, jstring _this, jstring str);
void JNICALL Java_java_lang_String_String11(JNIEnv *env, jstring _this, jobject sb);
jchar JNICALL Java_java_lang_String_charAt(JNIEnv *env, jstring _this, jint index);
jint JNICALL Java_java_lang_String_compareTo1(JNIEnv *env, jstring _this, jobject obj);
jint JNICALL Java_java_lang_String_compareTo2(JNIEnv *env, jstring _this, jstring str);
jint JNICALL Java_java_lang_String_compareToIgnoreCase(JNIEnv *env, jstring _this, jstring str);
jstring JNICALL Java_java_lang_String_concat(JNIEnv *env, jstring _this, jstring str);
jboolean JNICALL Java_java_lang_String_contentEquals(JNIEnv *env, jstring _this, jobject sb);
jboolean JNICALL Java_java_lang_String_endsWith(JNIEnv *env, jstring _this, jstring suffix);
jboolean JNICALL Java_java_lang_String_equals(JNIEnv *env, jstring _this, jobject obj);
jboolean JNICALL Java_java_lang_String_equalsIgnoreCase(JNIEnv *env, jstring _this, jstring str);
jbyteArray JNICALL Java_java_lang_String_getBytes1(JNIEnv *env, jstring _this);
void JNICALL Java_java_lang_String_getBytes2(JNIEnv *env, jstring _this, jint srcBegin, jint srcEnd, jbyteArray dst, jint dstBegin);
jbyteArray JNICALL Java_java_lang_String_getBytes3(JNIEnv *env, jstring _this, jstring charsetName);
void JNICALL Java_java_lang_String_getChars(JNIEnv *env, jstring _this, jint srcBegin, jint srcEnd, jcharArray dst, jint dstBegin);
jint JNICALL Java_java_lang_String_hashCode(JNIEnv *env, jstring _this);
jint JNICALL Java_java_lang_String_indexOf1(JNIEnv *env, jstring _this, jint ch);
jint JNICALL Java_java_lang_String_indexOf2(JNIEnv *env, jstring _this, jint ch, jint start);
jint JNICALL Java_java_lang_String_indexOf3(JNIEnv *env, jstring _this, jstring str);
jint JNICALL Java_java_lang_String_indexOf4(JNIEnv *env, jstring _this, jstring str, jint start);
jstring JNICALL Java_java_lang_String_intern(JNIEnv *env, jstring _this);
jint JNICALL Java_java_lang_String_lastIndexOf1(JNIEnv *env, jstring _this, jint ch);
jint JNICALL Java_java_lang_String_lastIndexOf2(JNIEnv *env, jstring _this, jint ch, jint start);
jint JNICALL Java_java_lang_String_lastIndexOf3(JNIEnv *env, jstring _this, jstring str);
jint JNICALL Java_java_lang_String_lastIndexOf4(JNIEnv *env, jstring _this, jstring str, jint start);
jint JNICALL Java_java_lang_String_length(JNIEnv *env, jstring _this);
jboolean JNICALL Java_java_lang_String_matches(JNIEnv *env, jstring _this, jstring regex);
jboolean JNICALL Java_java_lang_String_regionMatches1(JNIEnv *env, jstring _this, jboolean ignoreCase, jint start, jstring str, jint offset, jint len);
jboolean JNICALL Java_java_lang_String_regionMatches2(JNIEnv *env, jstring _this, jint start, jstring str, jint offset, jint len);
jstring JNICALL Java_java_lang_String_replace(JNIEnv *env, jstring _this, jchar oldch, jchar newch);
jstring JNICALL Java_java_lang_String_replaceAll(JNIEnv *env, jstring _this, jstring regex, jstring str);
jstring JNICALL Java_java_lang_String_replaceFirst(JNIEnv *env, jstring _this, jstring regex, jstring str);
jobject JNICALL Java_java_lang_String_split1(JNIEnv *env, jstring _this, jstring regex);
jobject JNICALL Java_java_lang_String_split2(JNIEnv *env, jstring _this, jstring regex, jint limit);
jboolean JNICALL Java_java_lang_String_startsWith1(JNIEnv *env, jstring _this, jstring prefix);
jboolean JNICALL Java_java_lang_String_startsWith2(JNIEnv *env, jstring _this, jstring prefix, jint start);
jobject JNICALL Java_java_lang_String_subSequence(JNIEnv *env, jstring _this, jint start, jint end);
jstring JNICALL Java_java_lang_String_substring1(JNIEnv *env, jstring _this, jint start);
jstring JNICALL Java_java_lang_String_substring2(JNIEnv *env, jstring _this, jint start, jint end);
jcharArray JNICALL Java_java_lang_String_toCharArray(JNIEnv *env, jstring _this);
jstring JNICALL Java_java_lang_String_toLowerCase1(JNIEnv *env, jstring _this);
jstring JNICALL Java_java_lang_String_toLowerCase2(JNIEnv *env, jstring _this, jobject locale);
jstring JNICALL Java_java_lang_String_toString(JNIEnv *env, jstring _this);
jstring JNICALL Java_java_lang_String_toUpperCase1(JNIEnv *env, jstring _this);
jstring JNICALL Java_java_lang_String_toUpperCase2(JNIEnv *env, jstring _this, jobject locale);
jstring JNICALL Java_java_lang_String_trim(JNIEnv *env, jstring _this);


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_STRING_H_ */
