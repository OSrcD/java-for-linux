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
#include "StackTraceElement.h"
#include "..\io\Serializable.h"


/* =============================================================== */
/*  methods                                                        */
/* =============================================================== */

static clsMethod Java_java_lang_StackTraceElement_equalsID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "equals", "(Ljava/lang/Object;)Z",
	   0xEF9A07AA, 0, Java_java_lang_StackTraceElement_equals, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_StackTraceElement_equals(JNIEnv *env, jobject _this, jobject obj) {
	if (_this == obj) return JNI_TRUE;
	if ((_this == NULL) || (_this->clsdef != &clsJAVA_LANG_STACKTRACEELEMENT)) return JNI_FALSE;
	if ((obj == NULL) || (obj->clsdef != &clsJAVA_LANG_STACKTRACEELEMENT)) return JNI_FALSE;
	return Java_java_lang_StackTraceElement_hashCode(env, _this) == Java_java_lang_StackTraceElement_hashCode(env, obj);
}


static clsMethod Java_java_lang_StackTraceElement_getClassNameID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "getClassName", "()Ljava/lang/String;",
	   0x8D199CA6, 0, Java_java_lang_StackTraceElement_getClassName, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_StackTraceElement_getClassName(JNIEnv *env, jobject _this) {
	char buf[VM_MAX_PATH_LEN], *p;
	if (VM_STACK_TRACE(_this)->met == NULL) return NULL;
	vmStrCpyUTF(buf, VM_STACK_TRACE(_this)->met->clsdef->name);
	p = buf; while (*p) { if (*p == '/') *p = '.'; p++; }
	return jniNewStringUTF(env, buf);
}


static clsMethod Java_java_lang_StackTraceElement_getFileNameID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "getFileName", "()Ljava/lang/String;",
	   0x23CF1256, 0, Java_java_lang_StackTraceElement_getFileName, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_StackTraceElement_getFileName(JNIEnv *env, jobject _this) {
	char buf[VM_MAX_PATH_LEN], *p, *fname;
	if (VM_STACK_TRACE(_this)->met == NULL) return NULL;
	fname = VM_STACK_TRACE(_this)->met->clsdef->name;
	p = fname; while (*p) { if (*p == '/') fname = p+1; p++; }
	vmStrCpyUTF(buf, fname);
	vmStrCatUTF(buf, ".java");
	return jniNewStringUTF(env, buf);
}


static clsMethod Java_java_lang_StackTraceElement_getLineNumberID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "getLineNumber", "()I",
	   0xDAA2F33B, 0, Java_java_lang_StackTraceElement_getLineNumber, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_StackTraceElement_getLineNumber(JNIEnv *env, jobject _this) {
	return VM_STACK_TRACE(_this)->line_number;
}


static clsMethod Java_java_lang_StackTraceElement_getMethodNameID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "getMethodName", "()Ljava/lang/String;",
	   0xB0E90EC9, 0, Java_java_lang_StackTraceElement_getMethodName, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_StackTraceElement_getMethodName(JNIEnv *env, jobject _this) {
	return (VM_STACK_TRACE(_this)->met) ? jniNewStringUTF(env, VM_STACK_TRACE(_this)->met->name) : NULL;
}


static clsMethod Java_java_lang_StackTraceElement_hashCodeID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "hashCode", "()I",
	   0x8CD3773, 0, Java_java_lang_StackTraceElement_hashCode, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_StackTraceElement_hashCode(JNIEnv *env, jobject _this) {
	return VM_STACK_TRACE(_this)->line_number ^ (jint)VM_STACK_TRACE(_this)->met;
}


static clsMethod Java_java_lang_StackTraceElement_isNativeMethodID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "isNativeMethod", "()Z",
	   0x56BFC95B, 0, Java_java_lang_StackTraceElement_isNativeMethod, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'Z'};
jboolean JNICALL Java_java_lang_StackTraceElement_isNativeMethod(JNIEnv *env, jobject _this) {
	return (VM_STACK_TRACE(_this)->met) ? (VM_STACK_TRACE(_this)->met->access_flags & ACC_NATIVE) : JNI_FALSE;
}


static clsMethod Java_java_lang_StackTraceElement_toStringID = {&clsJAVA_LANG_STACKTRACEELEMENT, ACC_PUBLIC|ACC_NATIVE, "toString", "()Ljava/lang/String;",
	   0xE5D943A7, 0, Java_java_lang_StackTraceElement_toString, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_StackTraceElement_toString(JNIEnv *env, jobject _this) {
	char buf[VM_MAX_PATH_LEN], *p, *fname;
	if (VM_STACK_TRACE(_this)->met == NULL) return NULL;
	fname = VM_STACK_TRACE(_this)->met->clsdef->name;
	p = fname; while (*p) { if (*p == '/') fname = p+1; p++; }
	vmSprintfUTF(buf, (VM_STACK_TRACE(_this)->met->access_flags & ACC_NATIVE) ? "%s.%s(Native Method)" : "%s.%s(%s:%u)", 
		VM_STACK_TRACE(_this)->met->clsdef->name, VM_STACK_TRACE(_this)->met->name, fname, VM_STACK_TRACE(_this)->line_number);
	p = buf; while (*p) { if (*p == '/') *p = '.'; p++; }
	return jniNewStringUTF(env, buf);
}


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsDefinition* interfaces[] = {
	&clsJAVA_IO_SERIALIZABLE
};

static clsMethod* instance_methods[] = {
	&Java_java_lang_StackTraceElement_equalsID,
	&Java_java_lang_StackTraceElement_getClassNameID,
	&Java_java_lang_StackTraceElement_getFileNameID,
	&Java_java_lang_StackTraceElement_getLineNumberID,
	&Java_java_lang_StackTraceElement_getMethodNameID,
	&Java_java_lang_StackTraceElement_hashCodeID,
	&Java_java_lang_StackTraceElement_isNativeMethodID,
	&Java_java_lang_StackTraceElement_toStringID
};

clsDefinition clsJAVA_LANG_STACKTRACEELEMENT = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/StackTraceElement", /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0x8655712B,                    /* name hash */
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
	sizeof(JavaLangStackTraceIData), /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};