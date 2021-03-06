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
#include "StringBuffer.h"
#include "CharSequence.h"
#include "Exceptions.h"
#include "String.h"
#include "..\io\Serializable.h"

#define DEFAULT_CAPACITY      16
#define DEFAULT_CAPACITY_STEP (255 - DEFAULT_CAPACITY)


/* =============================================================== */
/*  instance methods                                               */
/* =============================================================== */

static clsMethod Java_java_lang_StringBuffer_StringBuffer1ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V",
	   0x6c5e9907, 0, Java_java_lang_StringBuffer_StringBuffer1, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_StringBuffer_StringBuffer1(JNIEnv *env, jobject _this) {
	Java_java_lang_StringBuffer_ensureCapacity(env, _this, 0);
}


static clsMethod Java_java_lang_StringBuffer_StringBuffer2ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "<init>", "(I)V",
	   0x6c4d445c, 0, Java_java_lang_StringBuffer_StringBuffer2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_StringBuffer_StringBuffer2(JNIEnv *env, jobject _this, jint mincap) {
	Java_java_lang_StringBuffer_ensureCapacity(env, _this, mincap);
}


static clsMethod Java_java_lang_StringBuffer_StringBuffer3ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V",
	   0xc68db38d, 0, Java_java_lang_StringBuffer_StringBuffer3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_StringBuffer_StringBuffer3(JNIEnv *env, jobject _this, jstring str) {
	if (str != NULL)
		Java_java_lang_StringBuffer_ensureCapacity(env, _this, VM_STRING_LEN(str));
	Java_java_lang_StringBuffer_append10(env, _this, str);
}


#if JAVA_LANG_BOOLEAN_ENABLED
#include "Boolean.h"
static clsMethod Java_java_lang_StringBuffer_append1ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(Z)Ljava/lang/StringBuffer;",
	   0x4208c4bb, 0, Java_java_lang_StringBuffer_append1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append1(JNIEnv *env, jobject _this, jboolean b) {
	jstring str = Java_java_lang_Boolean_toString2(env, NULL, b);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert1ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(IZ)Ljava/lang/StringBuffer;",
	   0x577899e3, 0, Java_java_lang_StringBuffer_insert1, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert1(JNIEnv *env, jobject _this, jint offset, jboolean b) {
	jstring str = Java_java_lang_Boolean_toString2(env, NULL, b);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}
#endif /* JAVA_LANG_BOOLEAN_ENABLED */


static clsMethod Java_java_lang_StringBuffer_append2ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(C)Ljava/lang/StringBuffer;",
	   0x14815cc2, 0, Java_java_lang_StringBuffer_append2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append2(JNIEnv *env, jobject _this, jchar ch) {
	jstring str;
	jchar buf[2]; buf[0] = ch; buf[1] = 0;
	str = jniNewString(env, buf, 1);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_append3ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "([C)Ljava/lang/StringBuffer;",
	   0x60d1de39, 0, Java_java_lang_StringBuffer_append3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append3(JNIEnv *env, jobject _this, jcharArray data) {
	jstring str = Java_java_lang_String_valueOf3(env, NULL, data);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_append4ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "([CII)Ljava/lang/StringBuffer;",
	   0x54e26719, 0, Java_java_lang_StringBuffer_append4, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append4(JNIEnv *env, jobject _this, jcharArray data, jint start, jint len) {
	jstring str = Java_java_lang_String_valueOf4(env, NULL, data, start, len);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


#if JAVA_LANG_DOUBLE_ENABLED
#include "Double.h"
static clsMethod Java_java_lang_StringBuffer_append5ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(D)Ljava/lang/StringBuffer;",
	   0x6ada29ed, 0, Java_java_lang_StringBuffer_append5, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1 + VM_STACK_SLOT_LONG_SIZE, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append5(JNIEnv *env, jobject _this, jdouble d) {
	jstring str = Java_java_lang_Double_toString3(env, NULL, d);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert5ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(ID)Ljava/lang/StringBuffer;",
	   0x7c2bf409, 0, Java_java_lang_StringBuffer_insert5, 0, 0, 0, NULL, /* VM internal affairs */ 2, 2 + VM_STACK_SLOT_LONG_SIZE, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert5(JNIEnv *env, jobject _this, jint offset, jdouble d) {
	jstring str = Java_java_lang_Double_toString3(env, NULL, d);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}
#endif /* JAVA_LANG_DOUBLE_ENABLED */


#if JAVA_LANG_FLOAT_ENABLED
#include "Float.h"
static clsMethod Java_java_lang_StringBuffer_append6ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(F)Ljava/lang/StringBuffer;",
	   0x6f15422f, 0, Java_java_lang_StringBuffer_append6, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append6(JNIEnv *env, jobject _this, jfloat f) {
	jstring str = Java_java_lang_Float_toString3(env, NULL, f);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert6ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(IF)Ljava/lang/StringBuffer;",
	   0x707d1e57, 0, Java_java_lang_StringBuffer_insert6, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert6(JNIEnv *env, jobject _this, jint offset, jfloat f) {
	jstring str = Java_java_lang_Float_toString3(env, NULL, f);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}
#endif /* JAVA_LANG_FLOAT_ENABLED */


#if JAVA_LANG_INTEGER_ENABLED
#include "Integer.h"
static clsMethod Java_java_lang_StringBuffer_append7ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(I)Ljava/lang/StringBuffer;",
	   0x61994988, 0, Java_java_lang_StringBuffer_append7, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append7(JNIEnv *env, jobject _this, jint i) {
	jstring str = Java_java_lang_Integer_toString3(env, NULL, i, 10);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert7ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(II)Ljava/lang/StringBuffer;",
	   0x77e914f2, 0, Java_java_lang_StringBuffer_insert7, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert7(JNIEnv *env, jobject _this, jint offset, jint i) {
	jstring str = Java_java_lang_Integer_toString3(env, NULL, i, 10);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}
#endif /* JAVA_LANG_INTEGER_ENABLED */


#if JAVA_LANG_LONG_ENABLED
#include "Long.h"
static clsMethod Java_java_lang_StringBuffer_append8ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(J)Ljava/lang/StringBuffer;",
	   0x67b216ab, 0, Java_java_lang_StringBuffer_append8, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1 + VM_STACK_SLOT_LONG_SIZE, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append8(JNIEnv *env, jobject _this, jlong l) {
	jstring str = Java_java_lang_Long_toString3(env, NULL, l, 10);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert8ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(IJ)Ljava/lang/StringBuffer;",
	   0x6903ebd3, 0, Java_java_lang_StringBuffer_insert8, 0, 0, 0, NULL, /* VM internal affairs */ 2, 2 + VM_STACK_SLOT_LONG_SIZE, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert8(JNIEnv *env, jobject _this, jint offset, jlong l) {
	jstring str = Java_java_lang_Long_toString3(env, NULL, l, 10);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}
#endif /* JAVA_LANG_LONG_ENABLED */


static clsMethod Java_java_lang_StringBuffer_append9ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(Ljava/lang/Object;)Ljava/lang/StringBuffer;",
	   0x13fc2a55, 0, Java_java_lang_StringBuffer_append9, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append9(JNIEnv *env, jobject _this, jobject obj) {
	jstring str = Java_java_lang_String_valueOf9(env, NULL, obj);
	Java_java_lang_StringBuffer_append10(env, _this, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


jobject JNICALL Java_java_lang_StringBuffer_append(JNIEnv *env, jobject _this, jchar *str, jint str_len) {
	JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
	if (str == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else {
		if (str_len < 0)
			str_len = vmStrLen(str);
		if (data->_len + str_len >= data->_capacity) {
			Java_java_lang_StringBuffer_ensureCapacity(env, _this, data->_len + str_len + DEFAULT_CAPACITY_STEP);
			data = (JavaLangStringBufferIData*)((_this)->data);
		}
		if (!jniExceptionCheck(env)) {
			vmMemCpy(data->_str + data->_len, str, str_len * sizeof(jchar));
			data->_str[data->_len += str_len] = 0;
			return _this;
		}
	}
	return NULL;
}


static clsMethod Java_java_lang_StringBuffer_append10ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(Ljava/lang/String;)Ljava/lang/StringBuffer;",
	   0xc05e90bb, 0, Java_java_lang_StringBuffer_append10, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append10(JNIEnv *env, jobject _this, jstring str) {
	JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
	if (str == NULL) {
		Java_java_lang_StringBuffer_append(env, _this, JSTRING("null"), 4);
		return _this;
	} else {
		jint str_len = VM_STRING_LEN(str);
		if (data->_len + str_len >= data->_capacity) {
			Java_java_lang_StringBuffer_ensureCapacity(env, _this, data->_len + str_len + DEFAULT_CAPACITY_STEP);
			data = (JavaLangStringBufferIData*)((_this)->data);
		}
		if (!jniExceptionCheck(env)) {
			vmMemCpy(data->_str + data->_len, VM_STRING(str), str_len * sizeof(jchar));
			data->_str[data->_len += str_len] = 0;
			return _this;
		}
	}
	return NULL;
}


static clsMethod Java_java_lang_StringBuffer_append11ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "append", "(Ljava/lang/StringBuffer;)Ljava/lang/StringBuffer;",
	   0x67a75a5b, 0, Java_java_lang_StringBuffer_append11, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_append11(JNIEnv *env, jobject _this, jobject sb) {
	JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
	if (sb == NULL) {
		Java_java_lang_StringBuffer_append(env, _this, JSTRING("null"), 4);
		return _this;
	} else {
		jint str_len = VM_STRBUF_LEN(sb);
		if (data->_len + str_len >= data->_capacity) {
			Java_java_lang_StringBuffer_ensureCapacity(env, _this, data->_len + str_len + DEFAULT_CAPACITY_STEP);
			data = (JavaLangStringBufferIData*)((_this)->data);
		}
		if (!jniExceptionCheck(env)) {
			vmMemCpy(data->_str + data->_len, VM_STRBUF_STR(sb), str_len * sizeof(jchar));
			data->_str[data->_len += str_len] = 0;
			return _this;
		}
	}
	return NULL;
}


static clsMethod Java_java_lang_StringBuffer_capacityID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "capacity", "()I",
	   0xfbf58fd2, 0, Java_java_lang_StringBuffer_capacity, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_StringBuffer_capacity(JNIEnv *env, jobject _this) {
	return VM_STRBUF_CAP(_this);
}


static clsMethod Java_java_lang_StringBuffer_charAtID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "charAt", "(I)C",
	   0xaec45832, 0, Java_java_lang_StringBuffer_charAt, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'C'};
jchar JNICALL Java_java_lang_StringBuffer_charAt(JNIEnv *env, jobject _this, jint index) {
	if ((index < 0) || (index >= VM_STRBUF_LEN(_this))) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return 0;
	}
	return VM_STRBUF_STR(_this)[index];
}


static clsMethod Java_java_lang_StringBuffer_deleteID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "delete", "(II)Ljava/lang/StringBuffer;",
	   0x7eff53e0, 0, Java_java_lang_StringBuffer_delete, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_delete(JNIEnv *env, jobject _this, jint start, jint end) {
	if ((start < 0) || (end < 0) || (start > end) || (end > VM_STRBUF_LEN(_this)))
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
	else {
		JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
		if (start < data->_len)
			vmMemCpy(data->_str + start, data->_str + end, (data->_len - end) * sizeof(jchar));
		data->_len -= end - start;
		data->_str[data->_len] = 0;
		return _this;
	}
	return NULL;
}


static clsMethod Java_java_lang_StringBuffer_deleteCharAtID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "deleteCharAt", "(I)Ljava/lang/StringBuffer;",
	   0x7cc9e526, 0, Java_java_lang_StringBuffer_deleteCharAt, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_deleteCharAt(JNIEnv *env, jobject _this, jint index) {
	if ((index < 0) || (index >= VM_STRBUF_LEN(_this)))
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
	else {
		JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
		if (index < --(data->_len))
			vmMemCpy(data->_str + index, data->_str + index + 1, (data->_len - index) * sizeof(jchar));
		data->_str[data->_len] = 0;
		return _this;
	}
	return NULL;
}


static clsMethod Java_java_lang_StringBuffer_ensureCapacityID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "ensureCapacity", "(I)V",
	   0x61b0b136, 0, Java_java_lang_StringBuffer_ensureCapacity, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_StringBuffer_ensureCapacity(JNIEnv *env, jobject _this, jint mincap) {
	mincap += DEFAULT_CAPACITY;
	if (VM_STRBUF_CAP(_this) < mincap) {
		JavaLangStringBufferIData *data = vmMemAlloc(((vmJNIEnv*)env)->vm, sizeof(JavaLangStringBufferIData) + mincap * sizeof(jchar));
		if (data == NULL) {
			jniThrow(env, ((vmJNIEnv*)env)->vm->outofmem);
			return;
		}
		data->_capacity = mincap;
		data->_len = VM_STRBUF_LEN(_this);
		vmMemCpy(data->_str, VM_STRBUF_STR(_this), data->_len * sizeof(jchar));
		data->_str[data->_len] = 0;
		if (_this->flags & VM_OBJECT_FREEDATA_FLAG) vmMemFree(((vmJNIEnv*)env)->vm, _this->data);
		_this->data = (jbyte*)data;
		_this->flags |= VM_OBJECT_FREEDATA_FLAG;
	}
}


static clsMethod Java_java_lang_StringBuffer_getCharsID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "getChars", "(II[CI)V",
	   0xa6c8eae1, 0, Java_java_lang_StringBuffer_getChars, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'V'};
void JNICALL Java_java_lang_StringBuffer_getChars(JNIEnv *env, jobject _this, jint start, jint end, jcharArray dst, jint dstStart) {
	if (dst == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else
		if ((start < 0) || (end < 0) || (start > end) || (end > VM_STRBUF_LEN(_this)) || ((start + end - dstStart) > VM_STRBUF_LEN(dst)))
			jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		else
			vmMemCpy(VM_STRBUF_STR(dst) + dstStart, VM_STRBUF_STR(_this) + start, (end - start) * sizeof(jchar));
}


static clsMethod Java_java_lang_StringBuffer_indexOf1ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "indexOf", "(Ljava/lang/String;)I",
	   0xd907f7bb, 0, Java_java_lang_StringBuffer_indexOf1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_StringBuffer_indexOf1(JNIEnv *env, jobject _this, jstring str) {
	return Java_java_lang_StringBuffer_indexOf2(env, _this, str, 0);
}


static clsMethod Java_java_lang_StringBuffer_indexOf2ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "indexOf", "(Ljava/lang/String;I)I",
	   0xdc77469e, 0, Java_java_lang_StringBuffer_indexOf2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'I'};
jint JNICALL Java_java_lang_StringBuffer_indexOf2(JNIEnv *env, jobject _this, jstring str, jint fromIndex) {
	if (fromIndex < 0) fromIndex = 0;
	if (str == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else {
		jint len, strlen, i; jchar *_sb, *_str;
		len = VM_STRBUF_LEN(_this); _sb = VM_STRBUF_STR(_this);
		strlen = VM_STRING_LEN(str); _str = VM_STRING(str);
		if (strlen <= len)
			for (i = fromIndex; i <= len - strlen; i++)
				if (_sb[i] == *_str)
					if (!vmMemCmp(_sb + i, _str, strlen * sizeof(jchar))) 
						return i;
	}
	return -1;
}


static clsMethod Java_java_lang_StringBuffer_insert2ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(IC)Ljava/lang/StringBuffer;",
	   0x7af12128, 0, Java_java_lang_StringBuffer_insert2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert2(JNIEnv *env, jobject _this, jint offset, jchar ch) {
	jstring str;
	jchar buf[2]; buf[0] = ch; buf[1] = 0;
	str = jniNewString(env, buf, 1);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert3ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(I[C)Ljava/lang/StringBuffer;",
	   0xf3d27a33, 0, Java_java_lang_StringBuffer_insert3, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert3(JNIEnv *env, jobject _this, jint offset, jcharArray data) {
	jstring str = Java_java_lang_String_valueOf3(env, NULL, data);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert4ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(I[CII)Ljava/lang/StringBuffer;",
	   0xe0d8d313, 0, Java_java_lang_StringBuffer_insert4, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert4(JNIEnv *env, jobject _this, jint offset, jcharArray data, jint start, jint len) {
	jstring str = Java_java_lang_String_valueOf4(env, NULL, data, start, len);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert9ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(ILjava/lang/Object;)Ljava/lang/StringBuffer;",
	   0xb8c01c0f, 0, Java_java_lang_StringBuffer_insert9, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert9(JNIEnv *env, jobject _this, jint offset, jobject obj) {
	jstring str = Java_java_lang_String_valueOf9(env, NULL, obj);
	Java_java_lang_StringBuffer_insert10(env, _this, offset, str);
	jniDeleteLocalRef(env, str);
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_insert10ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "insert", "(ILjava/lang/String;)Ljava/lang/StringBuffer;",
	   0xc229bb1, 0, Java_java_lang_StringBuffer_insert10, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_insert10(JNIEnv *env, jobject _this, jint offset, jstring str) {
	JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
	if ((offset < 0) || (offset >= data->_len))
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
	else {
		jint str_len = VM_STRING_LEN(str);
		if (data->_len + str_len >= data->_capacity) {
			Java_java_lang_StringBuffer_ensureCapacity(env, _this, data->_len + str_len + DEFAULT_CAPACITY_STEP);
			data = (JavaLangStringBufferIData*)((_this)->data);
		}
		if (!jniExceptionCheck(env)) {
			vmMemCpy(data->_str + offset + str_len, data->_str + offset, (data->_len - offset) * sizeof(jchar));
			vmMemCpy(data->_str + offset, VM_STRING(str), str_len * sizeof(jchar));
			data->_str[data->_len += str_len] = 0;
			return _this;
		}
	}
	return NULL;
}


static clsMethod Java_java_lang_StringBuffer_lastIndexOf1ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "lastIndexOf", "(Ljava/lang/String;)I",
	   0x4ef1e721, 0, Java_java_lang_StringBuffer_lastIndexOf1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_StringBuffer_lastIndexOf1(JNIEnv *env, jobject _this, jstring str) {
	return Java_java_lang_StringBuffer_lastIndexOf2(env, _this, str, VM_STRBUF_LEN(_this));
}


static clsMethod Java_java_lang_StringBuffer_lastIndexOf2ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "lastIndexOf", "(Ljava/lang/String;I)I",
	   0x4b815604, 0, Java_java_lang_StringBuffer_lastIndexOf2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'I'};
jint JNICALL Java_java_lang_StringBuffer_lastIndexOf2(JNIEnv *env, jobject _this, jstring str, jint fromIndex) {
	if (fromIndex < 0) fromIndex = 0;
	if (str == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else {
		jint len, strlen, i; jchar *_sb, *_str;
		len = VM_STRBUF_LEN(_this); _sb = VM_STRBUF_STR(_this);
		strlen = VM_STRING_LEN(str); _str = VM_STRING(str);
		if (strlen <= len) {
			if (fromIndex > len - strlen) fromIndex = len - strlen;
			for (i = fromIndex; i >= 0; i--)
				if (_sb[i] == *_str)
					if (!vmMemCmp(_sb + i, _str, strlen * sizeof(jchar))) 
						return i;
		}
	}
	return -1;
}


static clsMethod Java_java_lang_StringBuffer_lengthID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "length", "()I",
	   0xbe0ea18e, 0, Java_java_lang_StringBuffer_length, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_StringBuffer_length(JNIEnv *env, jobject _this) {
	return VM_STRBUF_LEN(_this);
}


static clsMethod Java_java_lang_StringBuffer_replaceID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "replace", "(IILjava/lang/String;)Ljava/lang/StringBuffer;",
	   0xdf853e35, 0, Java_java_lang_StringBuffer_replace, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_replace(JNIEnv *env, jobject _this, jint start, jint end, jstring str) {
	if (Java_java_lang_StringBuffer_delete(env, _this, start, end))
		return Java_java_lang_StringBuffer_insert10(env, _this, start, str);
	return NULL;
}


static clsMethod Java_java_lang_StringBuffer_reverseID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "reverse", "()Ljava/lang/StringBuffer;",
	   0xd9416389, 0, Java_java_lang_StringBuffer_reverse, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_reverse(JNIEnv *env, jobject _this) {
	jint i, j;
	JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
	jchar *_str = data->_str;
	for (i = data->_len >> 1, j = data->_len - i; --i >= 0; ++j) {
		register jchar ch = _str[i];
		_str[i] = _str[j];
		_str[j] = ch;
	}
	return _this;
}


static clsMethod Java_java_lang_StringBuffer_setCharAtID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "setCharAt", "(IC)V",
	   0x576a924, 0, Java_java_lang_StringBuffer_setCharAt, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};
void JNICALL Java_java_lang_StringBuffer_setCharAt(JNIEnv *env, jobject _this, jint index, jchar ch) {
	if ((index < 0) || (index >= VM_STRBUF_LEN(_this)))
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
	else
		VM_STRBUF_STR(_this)[index] = ch;
}


static clsMethod Java_java_lang_StringBuffer_setLengthID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "setLength", "(I)V",
	   0x1649d7c6, 0, Java_java_lang_StringBuffer_setLength, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_StringBuffer_setLength(JNIEnv *env, jobject _this, jint length) {
	if (length < 0)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
	else {
		JavaLangStringBufferIData *data;
		Java_java_lang_StringBuffer_ensureCapacity(env, _this, length);
		data = (JavaLangStringBufferIData*)((_this)->data);
		if (data->_len < length)
			vmMemSetZero(data->_str + data->_len, (length - data->_len) * sizeof(jchar));
		data->_str[data->_len = length] = 0;
	}
}


static clsMethod Java_java_lang_StringBuffer_subSequenceID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "subSequence", "(II)Ljava/lang/StringBuffer;",
	   0x50538c6a, 0, Java_java_lang_StringBuffer_subSequence, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_StringBuffer_subSequence(JNIEnv *env, jobject _this, jint start, jint end) {
	return Java_java_lang_StringBuffer_substring2(env, _this, start, end);
}


static clsMethod Java_java_lang_StringBuffer_substring1ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "substring", "(I)Ljava/lang/String;",
	   0x580d7e63, 0, Java_java_lang_StringBuffer_substring1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jstring JNICALL Java_java_lang_StringBuffer_substring1(JNIEnv *env, jobject _this, jint start) {
	JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
	if ((start < 0) || (start > data->_len)) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return NULL;
	}
	return jniNewString(env, data->_str + start, data->_len - start);
}


static clsMethod Java_java_lang_StringBuffer_substring2ID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "substring", "(II)Ljava/lang/String;",
	   0xf3b1b0fa, 0, Java_java_lang_StringBuffer_substring2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jstring JNICALL Java_java_lang_StringBuffer_substring2(JNIEnv *env, jobject _this, jint start, jint end) {
	JavaLangStringBufferIData *data = (JavaLangStringBufferIData*)((_this)->data);
	if ((start < 0) || (end > data->_len) || (start > end)) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return NULL;
	}
	return jniNewString(env, data->_str + start, end - start);
}


static clsMethod Java_java_lang_StringBuffer_toStringID = {&clsJAVA_LANG_STRINGBUFFER, ACC_PUBLIC|ACC_NATIVE, "toString", "()Ljava/lang/String;",
	   0xe5d943a7, 0, Java_java_lang_StringBuffer_toString, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_StringBuffer_toString(JNIEnv *env, jstring _this) {
	return jniNewString(env, VM_STRBUF_STR(_this), VM_STRBUF_LEN(_this));
}


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsDefinition* interfaces[] = {
	&clsJAVA_LANG_CHARSEQUENCE,
	&clsJAVA_IO_SERIALIZABLE
};

static clsMethod* instance_methods[] = {
	&Java_java_lang_StringBuffer_StringBuffer1ID,
	&Java_java_lang_StringBuffer_StringBuffer2ID,
	&Java_java_lang_StringBuffer_StringBuffer3ID,
#if JAVA_LANG_BOOLEAN_ENABLED
	&Java_java_lang_StringBuffer_append1ID,
	&Java_java_lang_StringBuffer_insert1ID,
#endif /* JAVA_LANG_BOOLEAN_ENABLED */
	&Java_java_lang_StringBuffer_append2ID,
	&Java_java_lang_StringBuffer_append3ID,
	&Java_java_lang_StringBuffer_append4ID,
#if JAVA_LANG_DOUBLE_ENABLED
	&Java_java_lang_StringBuffer_append5ID,
	&Java_java_lang_StringBuffer_insert5ID,
#endif /* JAVA_LANG_DOUBLE_ENABLED */
#if JAVA_LANG_FLOAT_ENABLED
	&Java_java_lang_StringBuffer_append6ID,
	&Java_java_lang_StringBuffer_insert6ID,
#endif /* JAVA_LANG_FLOAT_ENABLED */
#if JAVA_LANG_INTEGER_ENABLED
	&Java_java_lang_StringBuffer_append7ID,
	&Java_java_lang_StringBuffer_insert7ID,
#endif /* JAVA_LANG_INTEGER_ENABLED */
#if JAVA_LANG_LONG_ENABLED
	&Java_java_lang_StringBuffer_append8ID,
	&Java_java_lang_StringBuffer_insert8ID,
#endif /* JAVA_LANG_LONG_ENABLED */
	&Java_java_lang_StringBuffer_append9ID,
	&Java_java_lang_StringBuffer_append10ID,
	&Java_java_lang_StringBuffer_append11ID,
	&Java_java_lang_StringBuffer_capacityID,
	&Java_java_lang_StringBuffer_charAtID,
	&Java_java_lang_StringBuffer_deleteID,
	&Java_java_lang_StringBuffer_deleteCharAtID,
	&Java_java_lang_StringBuffer_ensureCapacityID,
	&Java_java_lang_StringBuffer_getCharsID,
	&Java_java_lang_StringBuffer_indexOf1ID,
	&Java_java_lang_StringBuffer_indexOf2ID,
	&Java_java_lang_StringBuffer_insert2ID,
	&Java_java_lang_StringBuffer_insert3ID,
	&Java_java_lang_StringBuffer_insert4ID,
	&Java_java_lang_StringBuffer_insert9ID,
	&Java_java_lang_StringBuffer_insert10ID,
	&Java_java_lang_StringBuffer_lastIndexOf1ID,
	&Java_java_lang_StringBuffer_lastIndexOf2ID,
	&Java_java_lang_StringBuffer_lengthID,
	&Java_java_lang_StringBuffer_replaceID,
	&Java_java_lang_StringBuffer_reverseID,
	&Java_java_lang_StringBuffer_setCharAtID,
	&Java_java_lang_StringBuffer_setLengthID,
	&Java_java_lang_StringBuffer_subSequenceID,
	&Java_java_lang_StringBuffer_substring1ID,
	&Java_java_lang_StringBuffer_substring2ID,
	&Java_java_lang_StringBuffer_toStringID
};

clsDefinition clsJAVA_LANG_STRINGBUFFER = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/StringBuffer",      /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0xFA687FA5,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_FINAL + ACC_SUPER, /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,             /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(JavaLangStringBufferIData), /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};