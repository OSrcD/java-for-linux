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
#include "String.h"
#include "CharSequence.h"
#include "Comparable.h"
#include "Exceptions.h"
#include "StringBuffer.h"
#include "..\io\Exceptions.h"
#include "..\io\Serializable.h"


/* =============================================================== */
/*  class methods                                                  */
/* =============================================================== */

static clsMethod Java_java_lang_String_copyValueOf1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "copyValueOf", "([C)Ljava/lang/String;",
		0x898b9670, 0, Java_java_lang_String_copyValueOf1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_String_copyValueOf1(JNIEnv *env, jclass _clazz, jcharArray data) {
	return Java_java_lang_String_valueOf3(env, _clazz, data);
}


static clsMethod Java_java_lang_String_copyValueOf2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "copyValueOf", "([CII)Ljava/lang/String;",
	   0x3487d790, 0, Java_java_lang_String_copyValueOf2, 0, 0, 0, NULL, /* VM internal affairs */ 3, 3, 'L'};
jstring JNICALL Java_java_lang_String_copyValueOf2(JNIEnv *env, jclass _clazz, jcharArray data, jint start, jint len) {
	return Java_java_lang_String_valueOf4(env, _clazz, data, start, len);
}


#if JAVA_LANG_BOOLEAN_ENABLED
#include "Boolean.h"
static clsMethod Java_java_lang_String_valueOf1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "(Z)Ljava/lang/String;",
	   0xa49f4fa9, 0, Java_java_lang_String_valueOf1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_String_valueOf1(JNIEnv *env, jclass _clazz, jboolean b) {
	return Java_java_lang_Boolean_toString2(env, NULL, b);
}
#endif /* JAVA_LANG_BOOLEAN_ENABLED */


static clsMethod Java_java_lang_String_valueOf2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "(C)Ljava/lang/String;",
	   0xd4090ad0, 0, Java_java_lang_String_valueOf2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_String_valueOf2(JNIEnv *env, jclass _clazz, jchar ch) {
	jchar buf[2]; buf[0] = ch; buf[1] = 0;
	return jniNewString(env, buf, 1);
}


static clsMethod Java_java_lang_String_valueOf3ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "([C)Ljava/lang/String;",
	   0x6ceb18ab, 0, Java_java_lang_String_valueOf3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_String_valueOf3(JNIEnv *env, jclass _clazz, jcharArray data) {
	return Java_java_lang_String_valueOf4(env, _clazz, data, 0, (data != NULL) ? VM_ARRAY_LENGTH(data) : 0);
}


static clsMethod Java_java_lang_String_valueOf4ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "([CII)Ljava/lang/String;",
	   0xd1e7594b, 0, Java_java_lang_String_valueOf4, 0, 0, 0, NULL, /* VM internal affairs */ 3, 3, 'L'};
jstring JNICALL Java_java_lang_String_valueOf4(JNIEnv *env, jclass _clazz, jcharArray data, jint start, jint len) {
	if (data == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL); 
		return NULL; 
	}
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(data))) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, 0), NULL);
		return NULL;
	}
	return jniNewString(env, ((jchar*)VM_ARRAY_ARRAY(data)) + start, len);
}


#if JAVA_LANG_DOUBLE_ENABLED
#include "Double.h"
static clsMethod Java_java_lang_String_valueOf5ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "(D)Ljava/lang/String;",
	   0xcca6e37f, 0, Java_java_lang_String_valueOf5, 0, 0, 0, NULL, /* VM internal affairs */ 1, VM_STACK_SLOT_LONG_SIZE, 'L'};
jstring JNICALL Java_java_lang_String_valueOf5(JNIEnv *env, jclass _clazz, jdouble d) {
	return Java_java_lang_Double_toString3(env, NULL, d);
}
#endif /* JAVA_LANG_DOUBLE_ENABLED */


#if JAVA_LANG_FLOAT_ENABLED
#include "Float.h"
static clsMethod Java_java_lang_String_valueOf6ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "(F)Ljava/lang/String;",
	   0x9d628e3d, 0, Java_java_lang_String_valueOf6, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_String_valueOf6(JNIEnv *env, jclass _clazz, jfloat f) {
	return Java_java_lang_Float_toString3(env, NULL, f);
}
#endif /* JAVA_LANG_FLOAT_ENABLED */


#if JAVA_LANG_INTEGER_ENABLED
#include "Integer.h"
static clsMethod Java_java_lang_String_valueOf7ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "(I)Ljava/lang/String;",
	   0x4a5c131a, 0, Java_java_lang_String_valueOf7, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_String_valueOf7(JNIEnv *env, jclass _clazz, jint i) {
	return Java_java_lang_Integer_toString3(env, NULL, i, 10);
}
#endif /* JAVA_LANG_INTEGER_ENABLED */


#if JAVA_LANG_LONG_ENABLED
#include "Long.h"
static clsMethod Java_java_lang_String_valueOf8ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "(J)Ljava/lang/String;",
	   0x22fde5b9, 0, Java_java_lang_String_valueOf8, 0, 0, 0, NULL, /* VM internal affairs */ 1, VM_STACK_SLOT_LONG_SIZE, 'L'};
jstring JNICALL Java_java_lang_String_valueOf8(JNIEnv *env, jclass _clazz, jlong l) {
	return Java_java_lang_Long_toString3(env, NULL, l, 10);
}
#endif /* JAVA_LANG_LONG_ENABLED */


static clsMethod Java_java_lang_String_valueOf9ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "valueOf", "(Ljava/lang/Object;)Ljava/lang/String;",
	   0x64188387, 0, Java_java_lang_String_valueOf9, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jstring JNICALL Java_java_lang_String_valueOf9(JNIEnv *env, jclass _clazz, jobject obj) {
	if (obj != NULL) {
		jmethodID met = vmGetInstanceMethod(obj->clsdefdim, "toString", "()Ljava/lang/String;", JNI_TRUE);
		return jniCallObjectMethodA(env, obj, met, NULL);
	}
	return jniNewString(env, JSTRING("null"), 4);
}

static clsMethod* class_methods[] = {
	&Java_java_lang_String_copyValueOf1ID,
	&Java_java_lang_String_copyValueOf2ID,
#if JAVA_LANG_BOOLEAN_ENABLED
	&Java_java_lang_String_valueOf1ID,
#endif /* JAVA_LANG_BOOLEAN_ENABLED */
	&Java_java_lang_String_valueOf2ID,
	&Java_java_lang_String_valueOf3ID,
	&Java_java_lang_String_valueOf4ID,
#if JAVA_LANG_DOUBLE_ENABLED
	&Java_java_lang_String_valueOf5ID,
#endif /* JAVA_LANG_DOUBLE_ENABLED */
#if JAVA_LANG_FLOAT_ENABLED
	&Java_java_lang_String_valueOf6ID,
#endif /* JAVA_LANG_FLOAT_ENABLED */
#if JAVA_LANG_INTEGER_ENABLED
	&Java_java_lang_String_valueOf7ID,
#endif /* JAVA_LANG_INTEGER_ENABLED */
#if JAVA_LANG_LONG_ENABLED
	&Java_java_lang_String_valueOf8ID,
#endif /* JAVA_LANG_LONG_ENABLED */
	&Java_java_lang_String_valueOf9ID
};


/* =============================================================== */
/*  instance methods                                               */
/* =============================================================== */

static jboolean Java_java_lang_String_setLength(JNIEnv *env, jstring _this, jint len) {
	JavaLangStringIData *data = vmMemAlloc(((vmJNIEnv*)env)->vm, sizeof(JavaLangStringIData) + len * sizeof(jchar));
	if (data == NULL) {
		jniThrow(env, ((vmJNIEnv*)env)->vm->outofmem);
		return JNI_FALSE;
	}
	data->_hash = 0;
	data->_str[data->_len = len] = 0;
	if (_this->flags & VM_OBJECT_FREEDATA_FLAG) vmMemFree(((vmJNIEnv*)env)->vm, _this->data);
	_this->data = (jbyte*)data;		
	_this->flags |= VM_OBJECT_FREEDATA_FLAG;
	return JNI_TRUE;
}


static clsMethod Java_java_lang_String_String1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V",
	   0x6c5e9907, 0, Java_java_lang_String_String1, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_String_String1(JNIEnv *env, jstring _this) {
}


static clsMethod Java_java_lang_String_String2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([B)V",
	   0x6e00048e, 0, Java_java_lang_String_String2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_String_String2(JNIEnv *env, jstring _this, jbyteArray bytes) {
	Java_java_lang_String_String4(env, _this, bytes, 0, (bytes != NULL) ? VM_ARRAY_LENGTH(bytes) : 0);
}


static clsMethod Java_java_lang_String_String3ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([BI)V",
	   0x253d49f5, 0, Java_java_lang_String_String3, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};
void JNICALL Java_java_lang_String_String3(JNIEnv *env, jstring _this, jbyteArray ascii, jint hibyte) {
	Java_java_lang_String_String5(env, _this, ascii, hibyte, 0, (ascii != NULL) ? VM_ARRAY_LENGTH(ascii) : 0);
}


static clsMethod Java_java_lang_String_String4ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([BII)V",
	   0x8f589a2e, 0, Java_java_lang_String_String4, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'V'};
/* implemented in vm_???.c platform specific file */


static clsMethod Java_java_lang_String_String5ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([BIII)V",
	   0x1192e455, 0, Java_java_lang_String_String5, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'V'};
void JNICALL Java_java_lang_String_String5(JNIEnv *env, jstring _this, jbyteArray ascii, jint hibyte, jint start, jint len) {
	if (ascii == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else
		if ((start < 0) || ((start + len) > VM_ARRAY_LENGTH(ascii))) 
			jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		else
			if (Java_java_lang_String_setLength(env, _this, len)) {
				jbyte *arr = ((jbyte*)VM_ARRAY_ARRAY(ascii)) + start;
				jchar *t = VM_STRING(_this); jint i;
				for (i = 0; i < len; i++)
					t[i] = (jchar)(((hibyte & 0xFF) << 8) | (arr[i] & 0xFF));
			}
}


static clsMethod Java_java_lang_String_String6ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([BIILjava/lang/String;)V",
	   0x6fcee154, 0, Java_java_lang_String_String6, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'V'};
void JNICALL Java_java_lang_String_String6(JNIEnv *env, jstring _this, jbyteArray bytes, jint start, jint len, jstring charsetName) {
	if ((bytes == NULL) || (charsetName == NULL)) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
		return;
	}
	if ((start < 0) || ((start + len) > VM_ARRAY_LENGTH(bytes))) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return;
	}
	jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_IO_UNSUPPORTEDENCODINGEXCEPTION, NULL));
}


static clsMethod Java_java_lang_String_String7ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([BLjava/lang/String;)V",
	   0x37fbebb4, 0, Java_java_lang_String_String7, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};
void JNICALL Java_java_lang_String_String7(JNIEnv *env, jstring _this, jbyteArray bytes, jstring charsetName) {
	Java_java_lang_String_String6(env, _this, bytes, 0, (bytes != NULL) ? VM_ARRAY_LENGTH(bytes) : 0, charsetName);
}


static clsMethod Java_java_lang_String_String8ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([C)V",
	   0x6e0008cf, 0, Java_java_lang_String_String8, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_String_String8(JNIEnv *env, jstring _this, jcharArray chars) {
	Java_java_lang_String_String9(env, _this, chars, 0, (chars != NULL) ? VM_ARRAY_LENGTH(chars) : 0);
}


static clsMethod Java_java_lang_String_String9ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "([CII)V",
	   0x8f4aadaf, 0, Java_java_lang_String_String9, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'V'};
void JNICALL Java_java_lang_String_String9(JNIEnv *env, jstring _this, jcharArray chars, jint start, jint len) {
	if (chars == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else
		if ((start < 0) || ((start + len) > VM_ARRAY_LENGTH(chars))) 
			jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		else
			if (Java_java_lang_String_setLength(env, _this, len))
				vmMemCpy(VM_STRING(_this), ((jchar*)VM_ARRAY_ARRAY(chars)) + start, len * sizeof(jchar));
}


static clsMethod Java_java_lang_String_String10ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V",
	   0xc68db38d, 0, Java_java_lang_String_String10, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_String_String10(JNIEnv *env, jstring _this, jstring str) {
	if (str == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else
		if (Java_java_lang_String_setLength(env, _this, VM_STRING_LEN(str)))
			vmMemCpy(VM_STRING(_this), VM_STRING(str), VM_STRING_LEN(str) * sizeof(jchar));
}


static clsMethod Java_java_lang_String_String11ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/StringBuffer;)V",
	   0xab90522d, 0, Java_java_lang_String_String11, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_String_String11(JNIEnv *env, jstring _this, jobject sb) {
	if (sb == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else
		if (Java_java_lang_String_setLength(env, _this, VM_STRBUF_LEN(sb)))
			vmMemCpy(VM_STRING(_this), VM_STRBUF_STR(sb), VM_STRBUF_LEN(sb) * sizeof(jchar));
}


static clsMethod Java_java_lang_String_charAtID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "charAt", "(I)C",
	   0xaec45832, 0, Java_java_lang_String_charAt, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'C'};
jchar JNICALL Java_java_lang_String_charAt(JNIEnv *env, jstring _this, jint index) {
	if ((index < 0) || (index >= VM_STRING_LEN(_this))) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return 0;
	}
	return VM_STRING(_this)[index];
}


static clsMethod Java_java_lang_String_compareTo1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "compareTo", "(Ljava/lang/Object;)I",
	   0xf699da44, 0, Java_java_lang_String_compareTo1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_String_compareTo1(JNIEnv *env, jstring _this, jobject obj) {
	if ((obj != NULL) && (obj->clsdefdim->name != clsJAVA_LANG_STRING.name)) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_CLASSCASTEXCEPTION, "String.CompareTo()"));
		return -1;
	}
	return Java_java_lang_String_compareTo2(env, _this, obj);
}


static clsMethod Java_java_lang_String_compareTo2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "compareTo", "(Ljava/lang/String;)I",
	   0x11813b2, 0, Java_java_lang_String_compareTo2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_String_compareTo2(JNIEnv *env, jstring _this, jstring str) {
	if (str == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return -1;
	}
	return vmStrCmp(VM_STRING(_this), VM_STRING(str));
}


static clsMethod Java_java_lang_String_compareToIgnoreCaseID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "compareToIgnoreCase", "(Ljava/lang/String;)I",
	   0xed4fd370, 0, Java_java_lang_String_compareToIgnoreCase, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_String_compareToIgnoreCase(JNIEnv *env, jstring _this, jstring str) {
	if (str == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return -1;
	}
	return vmStrCmpi(VM_STRING(_this), VM_STRING(str));
}


static clsMethod Java_java_lang_String_concatID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "concat", "(Ljava/lang/String;)Ljava/lang/String;",
	   0x4651d795, 0, Java_java_lang_String_concat, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jstring JNICALL Java_java_lang_String_concat(JNIEnv *env, jstring _this, jstring str) {
	jstring ret = NULL;
	if (str == NULL)
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL);
	else {
		jint len = VM_STRING_LEN(_this) + VM_STRING_LEN(str);
		ret = jniNewLocalRef(env,
			vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_STRING, 0, 0, len * sizeof(jchar))
		);
		if (ret != NULL) {
			jchar *s = VM_STRING(ret);
			vmMemCpy(s, VM_STRING(_this), VM_STRING_LEN(_this) * sizeof(jchar));
			vmMemCpy(s + VM_STRING_LEN(_this), VM_STRING(str), VM_STRING_LEN(str) * sizeof(jchar));
			s[len] = 0;
			VM_STRING_LEN(ret) = len;
		}
	}
	return ret;
}


static clsMethod Java_java_lang_String_contentEqualsID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "contentEquals", "(Ljava/lang/StringBuffer;)Z",
	   0x13b1f1fb, 0, Java_java_lang_String_contentEquals, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_String_contentEquals(JNIEnv *env, jstring _this, jobject sb) {
	jint len;
	if (sb == NULL) return JNI_FALSE;
	if ((len = VM_STRING_LEN(_this)) != VM_STRBUF_LEN(sb)) return JNI_FALSE;
	return !vmMemCmp(VM_STRING(_this), VM_STRBUF_STR(sb), len * sizeof(jchar));
}


static clsMethod Java_java_lang_String_endsWithID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "endsWith", "(Ljava/lang/String;)Z",
	   0xcd35c9dd, 0, Java_java_lang_String_endsWith, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_String_endsWith(JNIEnv *env, jstring _this, jstring suffix) {
	jchar *str1, *str2; jint len1, len2;
	if (suffix == NULL) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
		return JNI_FALSE;
	}
	str1 = VM_STRING(_this); len1 = VM_STRING_LEN(_this);
	str2 = VM_STRING(suffix); len2 = VM_STRING_LEN(suffix);
	if (len1 < len2) return JNI_FALSE;
	str1 += len1 - len2;
	return !vmMemCmp(str1, str2, len2 * sizeof(jchar));
}


static clsMethod Java_java_lang_String_equalsID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "equals", "(Ljava/lang/Object;)Z",
	   0xef9a07aa, 0, Java_java_lang_String_equals, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_String_equals(JNIEnv *env, jstring _this, jobject obj) {
	if (obj == NULL) return JNI_FALSE;
	if (obj->clsdefdim->name != clsJAVA_LANG_STRING.name) return JNI_FALSE;
	return !vmStrCmp(VM_STRING(_this), VM_STRING(obj)); 
}


static clsMethod Java_java_lang_String_equalsIgnoreCaseID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "equalsIgnoreCase", "(Ljava/lang/String;)Z",
	   0xa58e1f42, 0, Java_java_lang_String_equalsIgnoreCase, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_String_equalsIgnoreCase(JNIEnv *env, jstring _this, jstring str) {
	if (str == NULL) return JNI_FALSE;
	return !vmStrCmpi(VM_STRING(_this), VM_STRING(str)); 
}


static clsMethod Java_java_lang_String_getBytes1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "getBytes", "()[B",
	   0x7429b2bd, 0, Java_java_lang_String_getBytes1, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
/* implemented in vm_???.c platform specific file */


static clsMethod Java_java_lang_String_getBytes2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "getBytes", "(II[BI)V",
	   0xa6b246d2, 0, Java_java_lang_String_getBytes2, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'V'};
void JNICALL Java_java_lang_String_getBytes2(JNIEnv *env, jstring _this, jint srcBegin, jint srcEnd, jbyteArray dst, jint dstBegin) {
	register jchar* s; register jbyte* d; register jint i;
	if (dst == NULL) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
		return;
	}
	if ((srcBegin < 0) || (dstBegin < 0) || (srcBegin > srcEnd) || (srcEnd > VM_STRING_LEN(_this)) || 
			(dstBegin+(srcEnd-srcBegin) < VM_ARRAY_LENGTH(dst))) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return;
	}
	s = VM_STRING(_this) + srcBegin; 
	d = ((jbyte*)VM_ARRAY_ARRAY(dst)) + dstBegin;
	for (i = srcEnd - srcBegin; i--; d++, s++)
		*d = (jbyte)*s;
}


static clsMethod Java_java_lang_String_getBytes3ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "getBytes", "(Ljava/lang/String;)[B",
	   0xdb99e80b, 0, Java_java_lang_String_getBytes3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jbyteArray JNICALL Java_java_lang_String_getBytes3(JNIEnv *env, jstring _this, jstring charsetName) {
	if (charsetName == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_IO_UNSUPPORTEDENCODINGEXCEPTION, NULL));
	return NULL;
}


static clsMethod Java_java_lang_String_getCharsID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "getChars", "(II[CI)V",
	   0xa6c8eae1, 0, Java_java_lang_String_getChars, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'V'};
void JNICALL Java_java_lang_String_getChars(JNIEnv *env, jstring _this, jint srcBegin, jint srcEnd, jcharArray dst, jint dstBegin) {
	if (dst == NULL) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
		return;
	}
	if ((srcBegin < 0) || (dstBegin < 0) || (srcBegin > srcEnd) || (srcEnd > VM_STRING_LEN(_this)) || 
			(dstBegin+(srcEnd-srcBegin) > VM_ARRAY_LENGTH(dst))) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return;
	}
	vmMemCpy(((jchar*)VM_ARRAY_ARRAY(dst)) + dstBegin, VM_STRING(_this) + srcBegin, (srcEnd - srcBegin) * sizeof(jchar));
}


static clsMethod Java_java_lang_String_hashCodeID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "hashCode", "()I",
	   0x8cd3773, 0, Java_java_lang_String_hashCode, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_String_hashCode(JNIEnv *env, jstring _this) {
	jint ret = VM_STRING_HASH(_this);
	if (ret == 0)
		ret = VM_STRING_HASH(_this) = vmStringHashFce(VM_STRING(_this), VM_STRING_LEN(_this));
	return ret;
}


static clsMethod Java_java_lang_String_indexOf1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "indexOf", "(I)I",
	   0x73c70068, 0, Java_java_lang_String_indexOf1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_String_indexOf1(JNIEnv *env, jstring _this, jint ch) {
	return Java_java_lang_String_indexOf2(env, _this, ch, 0);
}


static clsMethod Java_java_lang_String_indexOf2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "indexOf", "(II)I",
	   0x7181b4c1, 0, Java_java_lang_String_indexOf2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'I'};
jint JNICALL Java_java_lang_String_indexOf2(JNIEnv *env, jstring _this, jint ch, jint start) {
	register jint i, len = VM_STRING_LEN(_this);
	register jchar *s = VM_STRING(_this);
	for (i = (start > 0) ? start : 0; i < len; i++)
		if (s[i] == ch) 
			return i;
	return -1;
}


static clsMethod Java_java_lang_String_indexOf3ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "indexOf", "(Ljava/lang/String;)I",
	   0xd907f7bb, 0, Java_java_lang_String_indexOf3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_String_indexOf3(JNIEnv *env, jstring _this, jstring str) {
	return Java_java_lang_String_indexOf4(env, _this, str, 0);
}


static clsMethod Java_java_lang_String_indexOf4ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "indexOf", "(Ljava/lang/String;I)I",
	   0xdc77469e, 0, Java_java_lang_String_indexOf4, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'I'};
jint JNICALL Java_java_lang_String_indexOf4(JNIEnv *env, jstring _this, jstring str, jint start) {
	if (str == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else {
		register jint i, len = VM_STRING_LEN(_this), strlen = VM_STRING_LEN(str);
		jchar *s1 = VM_STRING(_this), *s2 = VM_STRING(str);
		len -= strlen;
		strlen *= sizeof(jchar);
		for (i = (start > 0) ? start : 0; i <= len; i++)
			if (!vmMemCmp(s1 + i, s2, strlen)) 
				return i;
	}
	return -1;
}


static clsMethod Java_java_lang_String_internID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "intern", "()Ljava/lang/String;",
	   0xcabe26d9, 0, Java_java_lang_String_intern, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_String_intern(JNIEnv *env, jstring _this) {
	return _this;
}


static clsMethod Java_java_lang_String_lastIndexOf1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "lastIndexOf", "(I)I",
	   0xe43110f2, 0, Java_java_lang_String_lastIndexOf1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_String_lastIndexOf1(JNIEnv *env, jstring _this, jint ch) {
	return Java_java_lang_String_lastIndexOf2(env, _this, ch, VM_STRING_LEN(_this));
}


static clsMethod Java_java_lang_String_lastIndexOf2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "lastIndexOf", "(II)I",
	   0xe677a45b, 0, Java_java_lang_String_lastIndexOf2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'I'};
jint JNICALL Java_java_lang_String_lastIndexOf2(JNIEnv *env, jstring _this, jint ch, jint start) {
	register jint i, len = VM_STRING_LEN(_this);
	register jchar *s = VM_STRING(_this);
	if (start > len - 1) start = len - 1;
	for (i = start; i >= 0; i--)
		if (s[i] == ch)
			return i;
	return -1;
}


static clsMethod Java_java_lang_String_lastIndexOf3ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "lastIndexOf", "(Ljava/lang/String;)I",
	   0x4ef1e721, 0, Java_java_lang_String_lastIndexOf3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'I'};
jint JNICALL Java_java_lang_String_lastIndexOf3(JNIEnv *env, jstring _this, jstring str) {
	return Java_java_lang_String_lastIndexOf4(env, _this, str, VM_STRING_LEN(_this));
}


static clsMethod Java_java_lang_String_lastIndexOf4ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "lastIndexOf", "(Ljava/lang/String;I)I",
	   0x4b815604, 0, Java_java_lang_String_lastIndexOf4, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'I'};
jint JNICALL Java_java_lang_String_lastIndexOf4(JNIEnv *env, jstring _this, jstring str, jint start) {
	if (str == NULL)
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
	else {
		register jint i, len = VM_STRING_LEN(_this), strlen = VM_STRING_LEN(str);
		jchar *s1 = VM_STRING(_this), *s2 = VM_STRING(str);
		if (start > len - strlen - 1) start = len - strlen - 1; 
		if (len >= strlen) {
			len -= strlen;
			strlen *= sizeof(jchar);
			for (i = start; i >= 0; i++)
				if (!vmMemCpy(s1 + i, s2, strlen)) 
					return i;
		}
	}
	return -1;
}


static clsMethod Java_java_lang_String_lengthID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "length", "()I",
	   0xbe0ea18e, 0, Java_java_lang_String_length, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_String_length(JNIEnv *env, jstring _this) {
	return VM_STRING_LEN(_this);
}


#if JAVA_UTIL_REGEX_ENABLED
static clsMethod Java_java_lang_String_matchesID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "matches", "(Ljava/lang/String;)Z",
	   1, 0, Java_java_lang_String_matches, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_String_matches(JNIEnv *env, jstring _this, jstring regex) {
}


static clsMethod Java_java_lang_String_regionMatches1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "regionMatches", "(ZILjava/lang/String;II)Z",
	   1, 0, Java_java_lang_String_regionMatches1, 0, 0, 0, NULL, /* VM internal affairs */ 5, 6, 'Z'};
jboolean JNICALL Java_java_lang_String_regionMatches1(JNIEnv *env, jstring _this, jboolean ignoreCase, jint start, jstring str, jint offset, jint len) {
}


static clsMethod Java_java_lang_String_regionMatches2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "regionMatches", "(ILjava/lang/String;II)Z",
	   1, 0, Java_java_lang_String_regionMatches2, 0, 0, 0, NULL, /* VM internal affairs */ 4, 5, 'Z'};
jboolean JNICALL Java_java_lang_String_regionMatches2(JNIEnv *env, jstring _this, jint start, jstring str, jint offset, jint len) {
}
#endif /* JAVA_UTIL_REGEX_ENABLED */


static clsMethod Java_java_lang_String_replaceID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "replace", "(CC)Ljava/lang/String;",
	   0x73f2a5df, 0, Java_java_lang_String_replace, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jstring JNICALL Java_java_lang_String_replace(JNIEnv *env, jstring _this, jchar oldch, jchar newch) {
	jstring ret = jniNewString(env, VM_STRING(_this), VM_STRING_LEN(_this));
	if (ret != NULL) {
		register jint i;
		register jchar* p = VM_STRING(ret);
		for (i = VM_STRING_LEN(ret); i--; p++)
			if (*p == oldch)
				*p = newch;
	}
	return ret;
}


#if JAVA_UTIL_REGEX_ENABLED
static clsMethod Java_java_lang_String_replaceAllID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "replaceAll", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
	   1, 0, Java_java_lang_String_replaceAll, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jstring JNICALL Java_java_lang_String_replaceAll(JNIEnv *env, jstring _this, jstring regex, jstring str) {
}


static clsMethod Java_java_lang_String_replaceFirstID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "replaceFirst", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
	   1, 0, Java_java_lang_String_replaceFirst, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jstring JNICALL Java_java_lang_String_replaceFirst(JNIEnv *env, jstring _this, jstring regex, jstring str) {
}


static clsMethod Java_java_lang_String_split1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "split", "(Ljava/lang/String;)[Ljava/lang/String;",
	   1, 0, Java_java_lang_String_split1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_String_split1(JNIEnv *env, jstring _this, jstring regex) {
	return Java_java_lang_String_split2(env, _this, regex, 0);
}


static clsMethod Java_java_lang_String_split2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "split", "(Ljava/lang/String;I)[Ljava/lang/String;",
	   1, 0, Java_java_lang_String_split2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_String_split2(JNIEnv *env, jstring _this, jstring regex, jint limit) {
}
#endif /* JAVA_UTIL_REGEX_ENABLED */


static clsMethod Java_java_lang_String_startsWith1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "startsWith", "(Ljava/lang/String;)Z",
	   0x99beeb4, 0, Java_java_lang_String_startsWith1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_String_startsWith1(JNIEnv *env, jstring _this, jstring prefix) {
	return Java_java_lang_String_startsWith2(env, _this, prefix, 0);
}


static clsMethod Java_java_lang_String_startsWith2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "startsWith", "(Ljava/lang/String;I)Z",
	   0xceb5c5f, 0, Java_java_lang_String_startsWith2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'Z'};
jboolean JNICALL Java_java_lang_String_startsWith2(JNIEnv *env, jstring _this, jstring prefix, jint start) {
	jchar *str1, *str2; jint len1, len2;
	if (prefix == NULL) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL));
		return JNI_FALSE;
	}
	str1 = VM_STRING(_this); len1 = VM_STRING_LEN(_this);
	str2 = VM_STRING(prefix); len2 = VM_STRING_LEN(prefix);
	if (len1 < len2) return JNI_FALSE;
	return !vmMemCmp(str1, str2, len2 * sizeof(jchar));
}


static clsMethod Java_java_lang_String_subSequenceID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "subSequence", "(II)Ljava/lang/CharSequence;",
	   0x1e7147a4, 0, Java_java_lang_String_subSequence, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_String_subSequence(JNIEnv *env, jstring _this, jint start, jint end) {
	return Java_java_lang_String_substring2(env, _this, start, end);
}


static clsMethod Java_java_lang_String_substring1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "substring", "(I)Ljava/lang/String;",
	   0x580d7e63, 0, Java_java_lang_String_substring1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jstring JNICALL Java_java_lang_String_substring1(JNIEnv *env, jstring _this, jint start) {
	JavaLangStringIData *data = (JavaLangStringIData*)((_this)->data);
	if ((start < 0) || (start > data->_len)) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return NULL;
	}
	return jniNewString(env, data->_str + start, data->_len - start);
}


static clsMethod Java_java_lang_String_substring2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "substring", "(II)Ljava/lang/String;",
	   0xf3b1b0fa, 0, Java_java_lang_String_substring2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jstring JNICALL Java_java_lang_String_substring2(JNIEnv *env, jstring _this, jint start, jint end) {
	JavaLangStringIData *data = (JavaLangStringIData*)((_this)->data);
	if ((start < 0) || (end > data->_len) || (start > end)) {
		jniThrow(env, vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, NULL));
		return NULL;
	}
	return jniNewString(env, data->_str + start, end - start);
}


static clsMethod Java_java_lang_String_toCharArrayID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "toCharArray", "()[C",
	   0x36781461, 0, Java_java_lang_String_toCharArray, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jcharArray JNICALL Java_java_lang_String_toCharArray(JNIEnv *env, jstring _this) {
	jcharArray ret = jniNewCharArray(env, VM_STRING_LEN(_this));
	if (ret != NULL)
		vmMemCpy(VM_ARRAY_ARRAY(ret), VM_STRING(_this), VM_STRING_LEN(_this) * sizeof(jchar));
	return ret;
}


static clsMethod Java_java_lang_String_toLowerCase1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "toLowerCase", "()Ljava/lang/String;",
	   0xcffecc5d, 0, Java_java_lang_String_toLowerCase1, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_String_toLowerCase1(JNIEnv *env, jstring _this) {
	return Java_java_lang_String_toLowerCase2(env, _this, NULL);
}


static clsMethod Java_java_lang_String_toLowerCase2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "toLowerCase", "(Ljava/util/Locale;)Ljava/lang/String;",
	   0x61e1820, 0, Java_java_lang_String_toLowerCase2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jstring JNICALL Java_java_lang_String_toLowerCase2(JNIEnv *env, jstring _this, jobject locale) {
	jstring ret = jniNewString(env, VM_STRING(_this), VM_STRING_LEN(_this));
	if (ret != NULL)
		vmStrLwr(VM_STRING(ret));
	return ret;
}


static clsMethod Java_java_lang_String_toStringID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "toString", "()Ljava/lang/String;",
	   0xe5d943a7, 0, Java_java_lang_String_toString, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_String_toString(JNIEnv *env, jstring _this) {
	return _this;
}


static clsMethod Java_java_lang_String_toUpperCase1ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "toUpperCase", "()Ljava/lang/String;",
	   0x9be0437c, 0, Java_java_lang_String_toUpperCase1, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_String_toUpperCase1(JNIEnv *env, jstring _this) {
	return Java_java_lang_String_toUpperCase2(env, _this, NULL);
}


static clsMethod Java_java_lang_String_toUpperCase2ID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "toUpperCase", "(Ljava/util/Locale;)Ljava/lang/String;",
	   0x52009701, 0, Java_java_lang_String_toUpperCase2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jstring JNICALL Java_java_lang_String_toUpperCase2(JNIEnv *env, jstring _this, jobject locale) {
	jstring ret = jniNewString(env, VM_STRING(_this), VM_STRING_LEN(_this));
	if (ret != NULL)
		vmStrUpr(VM_STRING(ret));
	return ret;
}


static clsMethod Java_java_lang_String_trimID = {&clsJAVA_LANG_STRING, ACC_PUBLIC|ACC_NATIVE, "trim", "()Ljava/lang/String;",
	   0x73f965e9, 0, Java_java_lang_String_trim, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_String_trim(JNIEnv *env, jstring _this) {
	jint len = VM_STRING_LEN(_this);
	if (len != 0) {
		jchar *s = VM_STRING(_this);
		jint start = 0, end = len - 1;
		while ((s[start] <= 0x20) && (start < len)) start++;
		while ((s[end] <= 0x20) && (end >= start)) end--;
		if ((start != 0) || (end != len - 1))
			return Java_java_lang_String_substring2(env, _this, start, end + 1);
	}
	return _this;
}

static clsMethod* instance_methods[] = {
	&Java_java_lang_String_String1ID,
	&Java_java_lang_String_String2ID,
	&Java_java_lang_String_String3ID,
	&Java_java_lang_String_String4ID,
	&Java_java_lang_String_String5ID,
	&Java_java_lang_String_String6ID,
	&Java_java_lang_String_String7ID,
	&Java_java_lang_String_String8ID,
	&Java_java_lang_String_String9ID,
	&Java_java_lang_String_String10ID,
	&Java_java_lang_String_String11ID,
	&Java_java_lang_String_charAtID,
	&Java_java_lang_String_compareTo1ID,
	&Java_java_lang_String_compareTo2ID,
	&Java_java_lang_String_compareToIgnoreCaseID,
	&Java_java_lang_String_concatID,
	&Java_java_lang_String_contentEqualsID,
	&Java_java_lang_String_endsWithID,
	&Java_java_lang_String_equalsID,
	&Java_java_lang_String_equalsIgnoreCaseID,
	&Java_java_lang_String_getBytes1ID,
	&Java_java_lang_String_getBytes2ID,
	&Java_java_lang_String_getBytes3ID,
	&Java_java_lang_String_getCharsID,
	&Java_java_lang_String_hashCodeID,
	&Java_java_lang_String_indexOf1ID,
	&Java_java_lang_String_indexOf2ID,
	&Java_java_lang_String_indexOf3ID,
	&Java_java_lang_String_indexOf4ID,
	&Java_java_lang_String_internID,
	&Java_java_lang_String_lastIndexOf1ID,
	&Java_java_lang_String_lastIndexOf2ID,
	&Java_java_lang_String_lastIndexOf3ID,
	&Java_java_lang_String_lastIndexOf4ID,
	&Java_java_lang_String_lengthID,
#if JAVA_UTIL_REGEX_ENABLED
	&Java_java_lang_String_matchesID,
	&Java_java_lang_String_regionMatches1ID,
	&Java_java_lang_String_regionMatches2ID,
#endif /* JAVA_UTIL_REGEX_ENABLED */
	&Java_java_lang_String_replaceID,
#if JAVA_UTIL_REGEX_ENABLED
	&Java_java_lang_String_replaceAllID,
	&Java_java_lang_String_replaceFirstID,
	&Java_java_lang_String_split1ID,
	&Java_java_lang_String_split2ID,
#endif /* JAVA_UTIL_REGEX_ENABLED */
	&Java_java_lang_String_startsWith1ID,
	&Java_java_lang_String_startsWith2ID,
	&Java_java_lang_String_subSequenceID,
	&Java_java_lang_String_substring1ID,
	&Java_java_lang_String_substring2ID,
	&Java_java_lang_String_toCharArrayID,
	&Java_java_lang_String_toLowerCase1ID,
	&Java_java_lang_String_toLowerCase2ID,
	&Java_java_lang_String_toStringID,
	&Java_java_lang_String_toUpperCase1ID,
	&Java_java_lang_String_toUpperCase2ID,
	&Java_java_lang_String_trimID
};


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsDefinition* interfaces[] = {
	&clsJAVA_LANG_CHARSEQUENCE,
	&clsJAVA_LANG_COMPARABLE,
	&clsJAVA_IO_SERIALIZABLE
};

clsDefinition clsJAVA_LANG_STRING = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/String",            /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0x83D61705,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_FINAL + ACC_SUPER, /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	sizeof(class_methods) / sizeof(clsMethod*), /* class_methods_count */
	class_methods,                 /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,             /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(JavaLangStringIData),   /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};