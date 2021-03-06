/**************************************************************************
* This file has been released into the public domain by:                  *
*             Dusan Stastny <info@developservice.cz>                      *
* and is based on public domain SableVM jni.h file written by:            *
*              Etienne M. Gagnon <egagnon@j-meg.com>                      *
*                                                                         *
* This software is distributed in the hope that it will be useful, but    *
* WITHOUT ANY WARRANTY!                                                   *
**************************************************************************/

/** @file
   The Java Native Interface (JNI) implementation. 
   JNI allows Java code interoperate with C, C++ and assembler code.
   @author Dusan Stastny <info@developservice.cz>
*/

#ifndef SVM_JNI_H
#define SVM_JNI_H

#include <stdio.h>
#include <stdarg.h>


/* system and vm specific types */
#include "jni_nat.h"


#ifdef __cplusplus
extern "C" {
#endif


/* constants */
#define JNI_FALSE        0
#define JNI_TRUE         1

#define JNI_COMMIT       1
#define JNI_ABORT        2

#define JNI_VERSION_1_1  0x00010001
#define JNI_VERSION_1_2  0x00010002

#define JNI_OK           0                 /* success */
#define JNI_ERR          (-1)              /* unknown error */
#define JNI_EDETACHED    (-2)              /* thread detached from the VM */
#define JNI_EVERSION     (-3)              /* JNI version error */
#define JNI_ENOMEM       (-4)              /* not enough memory */
#define JNI_EEXIST       (-5)              /* VM already created */
#define JNI_EINVAL       (-6)              /* invalid arguments */


/* size type */
typedef jint jsize;

/* class types */
typedef _jobject *jobject;
typedef _jarray *jarray;

typedef jobject jclass;
typedef jobject jstring;
typedef jobject jthrowable;
typedef jobject jweak;

typedef jarray jobjectArray;
typedef jarray jbooleanArray;
typedef jarray jbyteArray;
typedef jarray jcharArray;
typedef jarray jshortArray;
typedef jarray jintArray;
typedef jarray jlongArray;
typedef jarray jfloatArray;
typedef jarray jdoubleArray;

/* fieldID and methodID types */
typedef _jfieldID *jfieldID;
typedef _jmethodID *jmethodID;

/** JNI value type */
typedef union {
  jlong j;
  jboolean z;
  jbyte b;
  jchar c;
  jshort s;
  jint i;
  jfloat f;
  jdouble d;
  jobject l;
} jvalue;

/** JNIEnv type */
#ifdef __cplusplus
  struct JNIEnv_;
  typedef JNIEnv_ JNIEnv;
#else
  typedef const struct JNINativeInterface *JNIEnv;
#endif

/** JNI native method definition */
typedef struct {
  char *name;
  char *signature;
  void *fnPtr;
} JNINativeMethod;

/* JavaVM type */
#ifdef __cplusplus
  struct JavaVM_;
  typedef JavaVM_ JavaVM;
#else
  typedef const struct JNIInvokeInterface *JavaVM;
#endif


/*****************************************************************
 * JNINativeInterface type
 *****************************************************************/

/** JNI native interface */
struct JNINativeInterface {
  void *null_0;
  void *null_1;
  void *null_2;
  void *null_3;
  jint (JNICALL *GetVersion) (JNIEnv *env);	/* 4 */
  jclass (JNICALL *DefineClass) (JNIEnv *env, jobject loader, const jbyte *buf, jsize bufLen);	/* 5 */
  jclass (JNICALL *FindClass) (JNIEnv *env, const char *name);	/* 6 */
  jmethodID (JNICALL *FromReflectedMethod) (JNIEnv *env, jobject method);	/* 7 */
  jfieldID (JNICALL *FromReflectedField) (JNIEnv *env, jobject field);	/* 8 */
  jobject (JNICALL *ToReflectedMethod) (JNIEnv *env, jclass cls, jmethodID methodID, jboolean isStatic);	/* 9 */
  jclass (JNICALL *GetSuperclass) (JNIEnv *env, jclass clazz);	/* 10 */
  jboolean (JNICALL *IsAssignableFrom) (JNIEnv *env, jclass clazz1, jclass clazz2);	/* 11 */
  jobject (JNICALL *ToReflectedField) (JNIEnv *env, jclass cls, jfieldID fieldID, jboolean isStatic);	/* 12 */
  jint (JNICALL *Throw) (JNIEnv *env, jthrowable obj);	/* 13 */
  jint (JNICALL *ThrowNew) (JNIEnv *env, jclass clazz, const char *message);	/* 14 */
  jthrowable (JNICALL *ExceptionOccurred) (JNIEnv *env);	/* 15 */
  void (JNICALL *ExceptionDescribe) (JNIEnv *env);	/* 16 */
  void (JNICALL *ExceptionClear) (JNIEnv *env);	/* 17 */
  void (JNICALL *FatalError) (JNIEnv *env, const char *msg);	/* 18 */
  jint (JNICALL *PushLocalFrame) (JNIEnv *env, jint capacity);	/* 19 */
  jobject (JNICALL *PopLocalFrame) (JNIEnv *env, jobject result);	/* 20 */
  jobject (JNICALL *NewGlobalRef) (JNIEnv *env, jobject obj);	/* 21 */
  void (JNICALL *DeleteGlobalRef) (JNIEnv *env, jobject gref);	/* 22 */
  void (JNICALL *DeleteLocalRef) (JNIEnv *env, jobject lref);	/* 23 */
  jboolean (JNICALL *IsSameObject) (JNIEnv *env, jobject ref1, jobject ref2);	/* 24 */
  jobject (JNICALL *NewLocalRef) (JNIEnv *env, jobject ref);	/* 25 */
  jint (JNICALL *EnsureLocalCapacity) (JNIEnv *env, jint capacity);	/* 26 */
  jobject (JNICALL *AllocObject) (JNIEnv *env, jclass clazz);	/* 27 */
  jobject (JNICALL *NewObject) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 28 */
  jobject (JNICALL *NewObjectV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 29 */
  jobject (JNICALL *NewObjectA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 30 */
  jclass (JNICALL *GetObjectClass) (JNIEnv *env, jobject obj);	/* 31 */
  jboolean (JNICALL *IsInstanceOf) (JNIEnv *env, jobject obj, jclass clazz);	/* 32 */
  jmethodID (JNICALL *GetMethodID) (JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 33 */
  jobject (JNICALL *CallObjectMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 34 */
  jobject (JNICALL *CallObjectMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 35 */
  jobject (JNICALL *CallObjectMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 36 */
  jboolean (JNICALL *CallBooleanMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 37 */
  jboolean (JNICALL *CallBooleanMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 38 */
  jboolean (JNICALL *CallBooleanMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 39 */
  jbyte (JNICALL *CallByteMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 40 */
  jbyte (JNICALL *CallByteMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 41 */
  jbyte (JNICALL *CallByteMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 42 */
  jchar (JNICALL *CallCharMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 43 */
  jchar (JNICALL *CallCharMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 44 */
  jchar (JNICALL *CallCharMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 45 */
  jshort (JNICALL *CallShortMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 46 */
  jshort (JNICALL *CallShortMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 47 */
  jshort (JNICALL *CallShortMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 48 */
  jint (JNICALL *CallIntMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 49 */
  jint (JNICALL *CallIntMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 50 */
  jint (JNICALL *CallIntMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 51 */
  jlong (JNICALL *CallLongMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 52 */
  jlong (JNICALL *CallLongMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 53 */
  jlong (JNICALL *CallLongMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 54 */
  jfloat (JNICALL *CallFloatMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 55 */
  jfloat (JNICALL *CallFloatMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 56 */
  jfloat (JNICALL *CallFloatMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 57 */
  jdouble (JNICALL *CallDoubleMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 58 */
  jdouble (JNICALL *CallDoubleMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 59 */
  jdouble (JNICALL *CallDoubleMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 60 */
  void (JNICALL *CallVoidMethod) (JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 61 */
  void (JNICALL *CallVoidMethodV) (JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 62 */
  void (JNICALL *CallVoidMethodA) (JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 63 */
  jobject (JNICALL *CallNonvirtualObjectMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 64 */ 
  jobject (JNICALL *CallNonvirtualObjectMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 65 */
  jobject (JNICALL *CallNonvirtualObjectMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 66 */
  jboolean (JNICALL *CallNonvirtualBooleanMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 67 */
  jboolean (JNICALL *CallNonvirtualBooleanMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 68 */
  jboolean (JNICALL *CallNonvirtualBooleanMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 69 */
  jbyte (JNICALL *CallNonvirtualByteMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 70 */
  jbyte (JNICALL *CallNonvirtualByteMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 71 */
  jbyte (JNICALL *CallNonvirtualByteMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 72 */
  jchar (JNICALL *CallNonvirtualCharMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 73 */
  jchar (JNICALL *CallNonvirtualCharMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 74 */
  jchar (JNICALL *CallNonvirtualCharMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 75 */
  jshort (JNICALL *CallNonvirtualShortMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 76 */
  jshort (JNICALL *CallNonvirtualShortMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 77 */
  jshort (JNICALL *CallNonvirtualShortMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 78 */
  jint (JNICALL *CallNonvirtualIntMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 79 */ 
  jint (JNICALL *CallNonvirtualIntMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 80 */ 
  jint (JNICALL *CallNonvirtualIntMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 81 */
  jlong (JNICALL *CallNonvirtualLongMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 82 */
  jlong (JNICALL *CallNonvirtualLongMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 83 */
  jlong (JNICALL *CallNonvirtualLongMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 84 */
  jfloat (JNICALL *CallNonvirtualFloatMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 85 */
  jfloat (JNICALL *CallNonvirtualFloatMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 86 */
  jfloat (JNICALL *CallNonvirtualFloatMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 87 */
  jdouble (JNICALL *CallNonvirtualDoubleMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 88 */
  jdouble (JNICALL *CallNonvirtualDoubleMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 89 */
  jdouble (JNICALL *CallNonvirtualDoubleMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 90 */
  void (JNICALL *CallNonvirtualVoidMethod) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 91 */
  void (JNICALL *CallNonvirtualVoidMethodV) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 92 */
  void (JNICALL *CallNonvirtualVoidMethodA) (JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 93 */
  jfieldID (JNICALL *GetFieldID) (JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 94 */
  jobject (JNICALL *GetObjectField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 95 */
  jboolean (JNICALL *GetBooleanField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 96 */
  jbyte (JNICALL *GetByteField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 97 */
  jchar (JNICALL *GetCharField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 98 */
  jshort (JNICALL *GetShortField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 99 */
  jint (JNICALL *GetIntField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 100 */
  jlong (JNICALL *GetLongField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 101 */
  jfloat (JNICALL *GetFloatField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 102 */
  jdouble (JNICALL *GetDoubleField) (JNIEnv *env, jobject obj, jfieldID fieldID);	/* 103 */
  void (JNICALL *SetObjectField) (JNIEnv *env, jobject obj, jfieldID fieldID, jobject value);	/* 104 */
  void (JNICALL *SetBooleanField) (JNIEnv *env, jobject obj, jfieldID fieldID, jboolean value);	/* 105 */
  void (JNICALL *SetByteField) (JNIEnv *env, jobject obj, jfieldID fieldID, jbyte value);	/* 106 */
  void (JNICALL *SetCharField) (JNIEnv *env, jobject obj, jfieldID fieldID, jchar value);	/* 107 */
  void (JNICALL *SetShortField) (JNIEnv *env, jobject obj, jfieldID fieldID, jshort value);	/* 108 */ 
  void (JNICALL *SetIntField) (JNIEnv *env, jobject obj, jfieldID fieldID, jint value);	/* 109 */
  void (JNICALL *SetLongField) (JNIEnv *env, jobject obj, jfieldID fieldID, jlong value);	/* 110 */
  void (JNICALL *SetFloatField) (JNIEnv *env, jobject obj, jfieldID fieldID, jfloat value);	/* 111 */
  void (JNICALL *SetDoubleField) (JNIEnv *env, jobject obj, jfieldID fieldID, jdouble value);	/* 112 */
  jmethodID (JNICALL *GetStaticMethodID) (JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 113 */
  jobject (JNICALL *CallStaticObjectMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 114 */
  jobject (JNICALL *CallStaticObjectMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 115 */
  jobject (JNICALL *CallStaticObjectMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 116 */
  jboolean (JNICALL *CallStaticBooleanMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 117 */
  jboolean (JNICALL *CallStaticBooleanMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 118 */
  jboolean (JNICALL *CallStaticBooleanMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 119 */
  jbyte (JNICALL *CallStaticByteMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 120 */
  jbyte (JNICALL *CallStaticByteMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 121 */
  jbyte (JNICALL *CallStaticByteMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 122 */
  jchar (JNICALL *CallStaticCharMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 123 */
  jchar (JNICALL *CallStaticCharMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 124 */
  jchar (JNICALL *CallStaticCharMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 125 */
  jshort (JNICALL *CallStaticShortMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 126 */
  jshort (JNICALL *CallStaticShortMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 127 */
  jshort (JNICALL *CallStaticShortMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 128 */
  jint (JNICALL *CallStaticIntMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 129 */
  jint (JNICALL *CallStaticIntMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 130 */
  jint (JNICALL *CallStaticIntMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 131 */
  jlong (JNICALL *CallStaticLongMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 132 */
  jlong (JNICALL *CallStaticLongMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 133 */
  jlong (JNICALL *CallStaticLongMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 134 */
  jfloat (JNICALL *CallStaticFloatMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 135 */
  jfloat (JNICALL *CallStaticFloatMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 136 */
  jfloat (JNICALL *CallStaticFloatMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 137 */
  jdouble (JNICALL *CallStaticDoubleMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 138 */
  jdouble (JNICALL *CallStaticDoubleMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 139 */
  jdouble (JNICALL *CallStaticDoubleMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 140 */
  void (JNICALL *CallStaticVoidMethod) (JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 141 */
  void (JNICALL *CallStaticVoidMethodV) (JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 142 */
  void (JNICALL *CallStaticVoidMethodA) (JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 143 */
  jfieldID (JNICALL *GetStaticFieldID) (JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 144 */
  jobject (JNICALL *GetStaticObjectField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 145 */
  jboolean (JNICALL *GetStaticBooleanField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 146 */
  jbyte (JNICALL *GetStaticByteField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 147 */
  jchar (JNICALL *GetStaticCharField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 148 */
  jshort (JNICALL *GetStaticShortField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 149 */
  jint (JNICALL *GetStaticIntField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 150 */
  jlong (JNICALL *GetStaticLongField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 151 */
  jfloat (JNICALL *GetStaticFloatField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 152 */
  jdouble (JNICALL *GetStaticDoubleField) (JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 153 */
  void (JNICALL *SetStaticObjectField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jobject value);	/* 154 */
  void (JNICALL *SetStaticBooleanField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jboolean value);	/* 155 */
  void (JNICALL *SetStaticByteField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jbyte value);	/* 156 */
  void (JNICALL *SetStaticCharField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jchar value);	/* 157 */
  void (JNICALL *SetStaticShortField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jshort value);	/* 158 */
  void (JNICALL *SetStaticIntField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jint value);	/* 159 */
  void (JNICALL *SetStaticLongField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jlong value);	/* 160 */
  void (JNICALL *SetStaticFloatField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jfloat value);	/* 161 */
  void (JNICALL *SetStaticDoubleField) (JNIEnv *env, jclass clazz, jfieldID fieldID, jdouble value);	/* 162 */
  jstring (JNICALL *NewString) (JNIEnv *env, const jchar *uChars, jsize len);	/* 163 */
  jsize (JNICALL *GetStringLength) (JNIEnv *env, jstring string);	/* 164 */
  const jchar *(JNICALL *GetStringChars) (JNIEnv *env, jstring string, jboolean *isCopy);	/* 165 */
  void (JNICALL *ReleaseStringChars) (JNIEnv *env, jstring string, const jchar *chars);	/* 166 */
  jstring (JNICALL *NewStringUTF) (JNIEnv *env, const char *bytes);	/* 167 */
  jsize (JNICALL *GetStringUTFLength) (JNIEnv *env, jstring string);	/* 168 */
  const jbyte *(JNICALL *GetStringUTFChars) (JNIEnv *env, jstring string, jboolean *isCopy);	/* 169 */
  void (JNICALL *ReleaseStringUTFChars) (JNIEnv *env, jstring string, const char *utf);	/* 170 */
  jsize (JNICALL *GetArrayLength) (JNIEnv *env, jarray array);	/* 171 */
  jarray (JNICALL *NewObjectArray) (JNIEnv *env, jsize length, jclass elementType, jobject initialElement);	/* 172 */
  jobject (JNICALL *GetObjectArrayElement) (JNIEnv *env, jobjectArray array, jsize index);	/* 173 */
  void (JNICALL *SetObjectArrayElement) (JNIEnv *env, jobjectArray array, jsize index, jobject value);	/* 174 */
  jbooleanArray (JNICALL *NewBooleanArray) (JNIEnv *env, jsize length);	/* 175 */
  jbyteArray (JNICALL *NewByteArray) (JNIEnv *env, jsize length);	/* 176 */
  jcharArray (JNICALL *NewCharArray) (JNIEnv *env, jsize length);	/* 177 */
  jshortArray (JNICALL *NewShortArray) (JNIEnv *env, jsize length);	/* 178 */
  jintArray (JNICALL *NewIntArray) (JNIEnv *env, jsize length);	/* 179 */
  jlongArray (JNICALL *NewLongArray) (JNIEnv *env, jsize length);	/* 180 */
  jfloatArray (JNICALL *NewFloatArray) (JNIEnv *env, jsize length);	/* 181 */
  jdoubleArray (JNICALL *NewDoubleArray) (JNIEnv *env, jsize length);	/* 182 */
  jboolean *(JNICALL *GetBooleanArrayElements) (JNIEnv *env, jbooleanArray array, jboolean *isCopy);	/* 183 */
  jbyte *(JNICALL *GetByteArrayElements) (JNIEnv *env, jbyteArray array, jboolean *isCopy);	/* 184 */
  jchar *(JNICALL *GetCharArrayElements) (JNIEnv *env, jcharArray array, jboolean *isCopy);	/* 185 */
  jshort *(JNICALL *GetShortArrayElements) (JNIEnv *env, jshortArray array, jboolean *isCopy);	/* 186 */
  jint *(JNICALL *GetIntArrayElements) (JNIEnv *env, jintArray array, jboolean *isCopy);	/* 187 */
  jlong *(JNICALL *GetLongArrayElements) (JNIEnv *env, jlongArray array, jboolean *isCopy);	/* 188 */
  jfloat *(JNICALL *GetFloatArrayElements) (JNIEnv *env, jfloatArray array, jboolean *isCopy);	/* 189 */
  jdouble *(JNICALL *GetDoubleArrayElements) (JNIEnv *env, jdoubleArray array, jboolean *isCopy);	/* 190 */
  void (JNICALL *ReleaseBooleanArrayElements) (JNIEnv *env, jbooleanArray array, jboolean *elems, jint mode);	/* 191 */
  void (JNICALL *ReleaseByteArrayElements) (JNIEnv *env, jbyteArray array, jbyte *elems, jint mode);	/* 192 */
  void (JNICALL *ReleaseCharArrayElements) (JNIEnv *env, jcharArray array, jchar *elems, jint mode);	/* 193 */
  void (JNICALL *ReleaseShortArrayElements) (JNIEnv *env, jshortArray array, jshort *elems, jint mode);	/* 194 */
  void (JNICALL *ReleaseIntArrayElements) (JNIEnv *env, jintArray array, jint *elems, jint mode);	/* 195 */
  void (JNICALL *ReleaseLongArrayElements) (JNIEnv *env, jlongArray array, jlong *elems, jint mode);	/* 196 */
  void (JNICALL *ReleaseFloatArrayElements) (JNIEnv *env, jfloatArray array, jfloat *elems, jint mode);	/* 197 */
  void (JNICALL *ReleaseDoubleArrayElements) (JNIEnv *env, jdoubleArray array, jdouble *elems, jint mode);	/* 198 */
  void (JNICALL *GetBooleanArrayRegion) (JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf);	/* 199 */
  void (JNICALL *GetByteArrayRegion) (JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf);	/* 200 */
  void (JNICALL *GetCharArrayRegion) (JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf);	/* 201 */
  void (JNICALL *GetShortArrayRegion) (JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf);	/* 202 */
  void (JNICALL *GetIntArrayRegion) (JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf);	/* 203 */
  void (JNICALL *GetLongArrayRegion) (JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf);	/* 204 */
  void (JNICALL *GetFloatArrayRegion) (JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf);	/* 205 */
  void (JNICALL *GetDoubleArrayRegion) (JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf);	/* 206 */
  void (JNICALL *SetBooleanArrayRegion) (JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf);	/* 207 */
  void (JNICALL *SetByteArrayRegion) (JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf);	/* 208 */
  void (JNICALL *SetCharArrayRegion) (JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf);	/* 209 */
  void (JNICALL *SetShortArrayRegion) (JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf);	/* 210 */
  void (JNICALL *SetIntArrayRegion) (JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf);	/* 211 */
  void (JNICALL *SetLongArrayRegion) (JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf);	/* 212 */
  void (JNICALL *SetFloatArrayRegion) (JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf);	/* 213 */
  void (JNICALL *SetDoubleArrayRegion) (JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf);	/* 214 */
  jint (JNICALL *RegisterNatives) (JNIEnv *env, jclass clazz, const JNINativeMethod *methods, jint nMethods);	/* 215 */
  jint (JNICALL *UnregisterNatives) (JNIEnv *env, jclass clazz);	/* 216 */
  jint (JNICALL *MonitorEnter) (JNIEnv *env, jobject obj);	/* 217 */
  jint (JNICALL *MonitorExit) (JNIEnv *env, jobject obj);	/* 218 */
  jint (JNICALL *GetJavaVM) (JNIEnv *env, JavaVM **vm);	/* 219 */
  void (JNICALL *GetStringRegion) (JNIEnv *env, jstring str, jsize start, jsize len, jchar *buf);	/* 220 */
  void (JNICALL *GetStringUTFRegion) (JNIEnv *env, jstring str, jsize start, jsize len, char *buf);	/* 221 */
  void *(JNICALL *GetPrimitiveArrayCritical) (JNIEnv *env, jarray array, jboolean *isCopy);	/* 222 */
  void (JNICALL *ReleasePrimitiveArrayCritical) (JNIEnv *env, jarray array, void *carray, jint mode);	/* 223 */
  const jchar *(JNICALL *GetStringCritical) (JNIEnv *env, jstring string, jboolean *isCopy);	/* 224 */
  void (JNICALL *ReleaseStringCritical) (JNIEnv *env, jstring string, const jchar *carray);	/* 225 */
  jweak (JNICALL *NewWeakGlobalRef) (JNIEnv *env, jobject obj);	/* 226 */
  void (JNICALL *DeleteWeakGlobalRef) (JNIEnv *env, jweak wref);	/* 227 */
  jboolean (JNICALL *ExceptionCheck) (JNIEnv *env);	/* 228 */
};

#ifdef __cplusplus
struct JNIEnv_ {
  const struct JNINativeInterface *nif;
  jint GetVersion() { return nif->GetVersion(this); }
  jclass DefineClass(jobject loader, const jbyte *buf, jsize bufLen) { return nif->DefineClass(this, loader, buf, bufLen); }
  jclass FindClass(const char *name) { return nif->FindClass(this, name); }
  jmethodID FromReflectedMethod(jobject method) { return nif->FromReflectedMethod(this, method); }
  jfieldID FromReflectedField(jobject field) { return nif->FromReflectedField(this, field); }
  jobject ToReflectedMethod(jclass cls, jmethodID methodID, jboolean isStatic) { return nif->ToReflectedMethod(this, cls, methodID, isStatic); }
  jclass GetSuperclass(jclass clazz) { return nif->GetSuperclass(this, clazz); }
  jboolean IsAssignableFrom(jclass clazz1, jclass clazz2) { return nif->IsAssignableFrom(this, clazz1, clazz2); }
  jobject ToReflectedField(jclass cls, jfieldID fieldID, jboolean isStatic) { return nif->ToReflectedField(this,cls,fieldID,isStatic); }
  jint Throw(jthrowable obj) { return nif->Throw(this, obj); }
  jint ThrowNew(jclass clazz, const char *message) { return nif->ThrowNew(this, clazz, message); }
  jthrowable ExceptionOccurred() { return nif->ExceptionOccurred(this); }
  void ExceptionDescribe() { nif->ExceptionDescribe(this); }
  void ExceptionClear() { nif->ExceptionClear(this); }
  void FatalError(const char *msg) { nif->FatalError(this, msg); }
  jint PushLocalFrame(jint capacity) { return nif->PushLocalFrame(this, capacity); }
  jobject PopLocalFrame(jobject result) { return nif->PopLocalFrame(this, result); }
  jobject NewGlobalRef(jobject obj) { return nif->NewGlobalRef(this, obj); }
  void DeleteGlobalRef(jobject gref) { nif->DeleteGlobalRef(this, gref); }
  void DeleteLocalRef(jobject lref) { nif->DeleteLocalRef(this, lref); }
  jboolean IsSameObject(jobject ref1, jobject ref2) { return nif->IsSameObject(this, ref1, ref2); }
  jobject NewLocalRef(jobject ref) { return nif->NewLocalRef(this, ref); }
  jint EnsureLocalCapacity(jint capacity) { return nif->EnsureLocalCapacity(this, capacity); }
  jobject AllocObject(jclass clazz) { return nif->AllocObject(this, clazz); }
  jobject NewObject(jclass clazz, jmethodID methodID, ...) { va_list args; jobject ret; va_start(args, methodID); ret = nif->NewObjectV(this, clazz, methodID, args); va_end(args); return ret; }
  jobject NewObjectV(jclass clazz, jmethodID methodID, va_list args) { return nif->NewObjectV(this, clazz, methodID, args); }
  jobject NewObjectA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->NewObjectA(this, clazz, methodID, args); }
  jclass GetObjectClass(jobject obj) { return nif->GetObjectClass(this, obj); }
  jboolean IsInstanceOf(jobject obj, jclass clazz) { return nif->IsInstanceOf(this, obj, clazz); }
  jmethodID GetMethodID(jclass clazz, const char *name, const char *sig) { return nif->GetMethodID(this, clazz, name, sig); }
  jobject CallObjectMethod(jobject obj, jmethodID methodID, ...) { va_list args; jobject ret; va_start(args, methodID); ret = nif->CallObjectMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jobject CallObjectMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallObjectMethodV(this, obj, methodID, args); }
  jobject CallObjectMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallObjectMethodA(this, obj, methodID, args); }
  jboolean CallBooleanMethod(jobject obj, jmethodID methodID, ...) { va_list args; jboolean ret; va_start(args, methodID); ret = nif->CallBooleanMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jboolean CallBooleanMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallBooleanMethodV(this, obj, methodID, args); } 
  jboolean CallBooleanMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallBooleanMethodA(this, obj, methodID, args); }
  jbyte CallByteMethod(jobject obj, jmethodID methodID, ...) { va_list args; jbyte ret; va_start(args, methodID); ret = nif->CallByteMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jbyte CallByteMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallByteMethodV(this, obj, methodID, args); }
  jbyte CallByteMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallByteMethodA(this, obj, methodID, args); }
  jchar CallCharMethod(jobject obj, jmethodID methodID, ...) { va_list args; jchar ret; va_start(args, methodID); ret = nif->CallCharMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jchar CallCharMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallCharMethodV(this, obj, methodID, args); }
  jchar CallCharMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallCharMethodA(this, obj, methodID, args); }
  jshort CallShortMethod(jobject obj, jmethodID methodID, ...) { va_list args; jshort ret; va_start(args, methodID); ret = nif->CallShortMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jshort CallShortMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallShortMethodV(this, obj, methodID, args); }
  jshort CallShortMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallShortMethodA(this, obj, methodID, args); }
  jint CallIntMethod(jobject obj, jmethodID methodID, ...) { va_list args; jint ret; va_start(args, methodID); ret = nif->CallIntMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jint CallIntMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallIntMethodV(this, obj, methodID, args); }
  jint CallIntMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallIntMethodA(this,obj,methodID,args); }
  jlong CallLongMethod(jobject obj, jmethodID methodID, ...) { va_list args; jlong ret; va_start(args, methodID); ret = nif->CallLongMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jlong CallLongMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallLongMethodV(this, obj, methodID, args); }
  jlong CallLongMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallLongMethodA(this, obj, methodID, args); }
  jfloat CallFloatMethod(jobject obj, jmethodID methodID, ...) { va_list args; jfloat ret; va_start(args, methodID); ret = nif->CallFloatMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jfloat CallFloatMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallFloatMethodV(this, obj, methodID, args); }
  jfloat CallFloatMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallFloatMethodA(this, obj, methodID, args); }
  jdouble CallDoubleMethod(jobject obj, jmethodID methodID, ...) { va_list args; jdouble ret; va_start(args, methodID); ret = nif->CallDoubleMethodV(this, obj, methodID, args); va_end(args); return ret; }
  jdouble CallDoubleMethodV(jobject obj, jmethodID methodID, va_list args) { return nif->CallDoubleMethodV(this, obj, methodID, args); }
  jdouble CallDoubleMethodA(jobject obj, jmethodID methodID, jvalue *args) { return nif->CallDoubleMethodA(this, obj, methodID, args); }
  void CallVoidMethod(jobject obj, jmethodID methodID, ...) { va_list args; va_start(args, methodID); nif->CallVoidMethodV(this, obj, methodID, args); va_end(args); }
  void CallVoidMethodV(jobject obj, jmethodID methodID, va_list args) { nif->CallVoidMethodV(this,obj,methodID,args); }
  void CallVoidMethodA(jobject obj, jmethodID methodID, jvalue *args) { nif->CallVoidMethodA(this,obj,methodID,args); }
  jobject CallNonvirtualObjectMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jobject ret; va_start(args, methodID); ret = nif->CallNonvirtualObjectMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jobject CallNonvirtualObjectMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualObjectMethodV(this, obj, clazz, methodID, args); } 
  jobject CallNonvirtualObjectMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualObjectMethodA(this, obj, clazz, methodID, args); }
  jboolean CallNonvirtualBooleanMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jboolean ret; va_start(args, methodID); ret = nif->CallNonvirtualBooleanMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jboolean CallNonvirtualBooleanMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualBooleanMethodV(this, obj, clazz, methodID, args); }
  jboolean CallNonvirtualBooleanMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualBooleanMethodA(this, obj, clazz, methodID, args); }
  jbyte CallNonvirtualByteMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jbyte ret; va_start(args,methodID); ret = nif->CallNonvirtualByteMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jbyte CallNonvirtualByteMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualByteMethodV(this, obj, clazz, methodID, args); }
  jbyte CallNonvirtualByteMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualByteMethodA(this, obj, clazz, methodID, args); } 
  jchar CallNonvirtualCharMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jchar ret; va_start(args, methodID); ret = nif->CallNonvirtualCharMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jchar CallNonvirtualCharMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualCharMethodV(this, obj, clazz, methodID, args); }
  jchar CallNonvirtualCharMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualCharMethodA(this, obj, clazz, methodID, args); }
  jshort CallNonvirtualShortMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jshort ret; va_start(args, methodID); ret = nif->CallNonvirtualShortMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jshort CallNonvirtualShortMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualShortMethodV(this, obj, clazz, methodID, args); }
  jshort CallNonvirtualShortMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualShortMethodA(this, obj, clazz, methodID, args); }
  jint CallNonvirtualIntMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jint ret; va_start(args, methodID); ret = nif->CallNonvirtualIntMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jint CallNonvirtualIntMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualIntMethodV(this, obj, clazz, methodID, args); }
  jint CallNonvirtualIntMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualIntMethodA(this, obj, clazz, methodID, args); }
  jlong CallNonvirtualLongMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jlong ret; va_start(args, methodID); ret = nif->CallNonvirtualLongMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jlong CallNonvirtualLongMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualLongMethodV(this, obj, clazz, methodID, args); }
  jlong CallNonvirtualLongMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualLongMethodA(this, obj, clazz, methodID, args); }
  jfloat CallNonvirtualFloatMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jfloat ret; va_start(args, methodID); ret = nif->CallNonvirtualFloatMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jfloat CallNonvirtualFloatMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualFloatMethodV(this, obj, clazz, methodID, args); }
  jfloat CallNonvirtualFloatMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualFloatMethodA(this, obj, clazz, methodID, args); }
  jdouble CallNonvirtualDoubleMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; jdouble ret; va_start(args, methodID); ret = nif->CallNonvirtualDoubleMethodV(this, obj, clazz, methodID, args); va_end(args); return ret; }
  jdouble CallNonvirtualDoubleMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { return nif->CallNonvirtualDoubleMethodV(this, obj, clazz, methodID, args); }
  jdouble CallNonvirtualDoubleMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallNonvirtualDoubleMethodA(this, obj, clazz, methodID, args); }
  void CallNonvirtualVoidMethod(jobject obj, jclass clazz, jmethodID methodID, ...) { va_list args; va_start(args, methodID); nif->CallNonvirtualVoidMethodV(this, obj, clazz, methodID, args); va_end(args); }
  void CallNonvirtualVoidMethodV(jobject obj, jclass clazz, jmethodID methodID, va_list args) { nif->CallNonvirtualVoidMethodV(this, obj, clazz, methodID, args); }
  void CallNonvirtualVoidMethodA(jobject obj, jclass clazz, jmethodID methodID, jvalue *args) { nif->CallNonvirtualVoidMethodA(this, obj, clazz, methodID, args); }
  jfieldID GetFieldID(jclass clazz, const char *name, const char *sig) { return nif->GetFieldID(this, clazz, name, sig); }
  jobject GetObjectField(jobject obj, jfieldID fieldID) { return nif->GetObjectField(this, obj, fieldID); }
  jboolean GetBooleanField(jobject obj, jfieldID fieldID) { return nif->GetBooleanField(this, obj, fieldID); }
  jbyte GetByteField(jobject obj, jfieldID fieldID) { return nif->GetByteField(this, obj, fieldID); }
  jchar GetCharField(jobject obj, jfieldID fieldID) { return nif->GetCharField(this, obj, fieldID); }
  jshort GetShortField(jobject obj, jfieldID fieldID) { return nif->GetShortField(this, obj, fieldID); }
  jint GetIntField(jobject obj, jfieldID fieldID) { return nif->GetIntField(this, obj, fieldID); }
  jlong GetLongField(jobject obj, jfieldID fieldID) { return nif->GetLongField(this, obj, fieldID); }
  jfloat GetFloatField(jobject obj, jfieldID fieldID) { return nif->GetFloatField(this, obj, fieldID); }
  jdouble GetDoubleField(jobject obj, jfieldID fieldID) { return nif->GetDoubleField(this, obj, fieldID); }
  void SetObjectField(jobject obj, jfieldID fieldID, jobject value) { nif->SetObjectField(this, obj, fieldID, value); }
  void SetBooleanField(jobject obj, jfieldID fieldID, jboolean value) { nif->SetBooleanField(this, obj, fieldID, value); }
  void SetByteField(jobject obj, jfieldID fieldID, jbyte value) { nif->SetByteField(this, obj, fieldID, value); }
  void SetCharField(jobject obj, jfieldID fieldID, jchar value) { nif->SetCharField(this, obj, fieldID, value); }
  void SetShortField(jobject obj, jfieldID fieldID, jshort value) { nif->SetShortField(this, obj, fieldID, value); }
  void SetIntField(jobject obj, jfieldID fieldID, jint value) { nif->SetIntField(this, obj, fieldID, value); }
  void SetLongField(jobject obj, jfieldID fieldID, jlong value) { nif->SetLongField(this, obj, fieldID, value); }
  void SetFloatField(jobject obj, jfieldID fieldID, jfloat value) { nif->SetFloatField(this, obj, fieldID, value); }
  void SetDoubleField(jobject obj, jfieldID fieldID, jdouble value) { nif->SetDoubleField(this, obj, fieldID, value); }
  jmethodID GetStaticMethodID(jclass clazz, const char *name, const char *sig) { return nif->GetStaticMethodID(this, clazz, name, sig); }
  jobject CallStaticObjectMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jobject ret; va_start(args,methodID); ret = nif->CallStaticObjectMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jobject CallStaticObjectMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticObjectMethodV(this, clazz, methodID, args); }
  jobject CallStaticObjectMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticObjectMethodA(this, clazz, methodID, args); }
  jboolean CallStaticBooleanMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jboolean ret; va_start(args, methodID); ret = nif->CallStaticBooleanMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jboolean CallStaticBooleanMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticBooleanMethodV(this, clazz, methodID, args); }
  jboolean CallStaticBooleanMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticBooleanMethodA(this, clazz, methodID, args); }
  jbyte CallStaticByteMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jbyte ret; va_start(args, methodID); ret = nif->CallStaticByteMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jbyte CallStaticByteMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticByteMethodV(this, clazz, methodID, args); }
  jbyte CallStaticByteMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticByteMethodA(this, clazz, methodID, args); }
  jchar CallStaticCharMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jchar ret; va_start(args,methodID); ret = nif->CallStaticCharMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jchar CallStaticCharMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticCharMethodV(this, clazz, methodID, args); }
  jchar CallStaticCharMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticCharMethodA(this, clazz, methodID, args); }
  jshort CallStaticShortMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jshort ret; va_start(args, methodID); ret = nif->CallStaticShortMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jshort CallStaticShortMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticShortMethodV(this, clazz, methodID, args); }
  jshort CallStaticShortMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticShortMethodA(this,clazz,methodID,args); }
  jint CallStaticIntMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jint ret; va_start(args, methodID); ret = nif->CallStaticIntMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jint CallStaticIntMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticIntMethodV(this, clazz, methodID, args); }
  jint CallStaticIntMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticIntMethodA(this, clazz, methodID, args); }
  jlong CallStaticLongMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jlong ret; va_start(args, methodID); ret = nif->CallStaticLongMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jlong CallStaticLongMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticLongMethodV(this, clazz, methodID, args); }
  jlong CallStaticLongMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticLongMethodA(this, clazz, methodID, args); }
  jfloat CallStaticFloatMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jfloat ret; va_start(args, methodID); ret = nif->CallStaticFloatMethodV(this, clazz, methodID, args); va_end(args); return ret; }
  jfloat CallStaticFloatMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticFloatMethodV(this, clazz, methodID, args); }
  jfloat CallStaticFloatMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticFloatMethodA(this, clazz, methodID, args); }
  jdouble CallStaticDoubleMethod(jclass clazz, jmethodID methodID, ...) { va_list args; jdouble ret; va_start(args, methodID); ret = nif->CallStaticDoubleMethodV(this,clazz, methodID, args); va_end(args); return ret; }
  jdouble CallStaticDoubleMethodV(jclass clazz, jmethodID methodID, va_list args) { return nif->CallStaticDoubleMethodV(this, clazz, methodID, args); }
  jdouble CallStaticDoubleMethodA(jclass clazz, jmethodID methodID, jvalue *args) { return nif->CallStaticDoubleMethodA(this, clazz, methodID, args); }
  void CallStaticVoidMethod(jclass clazz, jmethodID methodID, ...) { va_list args; va_start(args, methodID); nif->CallStaticVoidMethodV(this, clazz, methodID, args); va_end(args); }
  void CallStaticVoidMethodV(jclass clazz, jmethodID methodID, va_list args) { nif->CallStaticVoidMethodV(this, clazz, methodID, args); }
  void CallStaticVoidMethodA(jclass clazz, jmethodID methodID, jvalue * args) { nif->CallStaticVoidMethodA(this, clazz, methodID, args); }
  jfieldID GetStaticFieldID(jclass clazz, const char *name, const char *sig) { return nif->GetStaticFieldID(this, clazz, name, sig); }
  jobject GetStaticObjectField(jclass clazz, jfieldID fieldID) { return nif->GetStaticObjectField(this, clazz, fieldID); }
  jboolean GetStaticBooleanField(jclass clazz, jfieldID fieldID) { return nif->GetStaticBooleanField(this, clazz, fieldID); }
  jbyte GetStaticByteField(jclass clazz, jfieldID fieldID) { return nif->GetStaticByteField(this, clazz, fieldID); }
  jchar GetStaticCharField(jclass clazz, jfieldID fieldID) { return nif->GetStaticCharField(this, clazz, fieldID); }
  jshort GetStaticShortField(jclass clazz, jfieldID fieldID) { return nif->GetStaticShortField(this, clazz, fieldID); }
  jint GetStaticIntField(jclass clazz, jfieldID fieldID) { return nif->GetStaticIntField(this, clazz, fieldID); }
  jlong GetStaticLongField(jclass clazz, jfieldID fieldID) { return nif->GetStaticLongField(this, clazz, fieldID); }
  jfloat GetStaticFloatField(jclass clazz, jfieldID fieldID) { return nif->GetStaticFloatField(this, clazz, fieldID); }
  jdouble GetStaticDoubleField(jclass clazz, jfieldID fieldID) { return nif->GetStaticDoubleField(this, clazz, fieldID); }
  void SetStaticObjectField(jclass clazz, jfieldID fieldID, jobject value) { nif->SetStaticObjectField(this, clazz, fieldID, value); }
  void SetStaticBooleanField(jclass clazz, jfieldID fieldID, jboolean value) { nif->SetStaticBooleanField(this, clazz, fieldID, value); }
  void SetStaticByteField(jclass clazz, jfieldID fieldID, jbyte value) { nif->SetStaticByteField(this, clazz, fieldID, value); }
  void SetStaticCharField(jclass clazz, jfieldID fieldID, jchar value) { nif->SetStaticCharField(this, clazz, fieldID, value); }
  void SetStaticShortField(jclass clazz, jfieldID fieldID, jshort value) { nif->SetStaticShortField(this, clazz, fieldID, value); }
  void SetStaticIntField(jclass clazz, jfieldID fieldID, jint value) { nif->SetStaticIntField(this, clazz, fieldID, value); }
  void SetStaticLongField(jclass clazz, jfieldID fieldID, jlong value) { nif->SetStaticLongField(this, clazz, fieldID, value); }
  void SetStaticFloatField(jclass clazz, jfieldID fieldID, jfloat value) { nif->SetStaticFloatField(this, clazz, fieldID, value); }
  void SetStaticDoubleField(jclass clazz, jfieldID fieldID, jdouble value) { nif->SetStaticDoubleField(this, clazz, fieldID, value); }
  jstring NewString(const jchar *uChars, jsize len) { return nif->NewString(this, uChars, len); }
  jsize GetStringLength(jstring str) { return nif->GetStringLength(this, str); }
  const jchar *GetStringChars(jstring string, jboolean *isCopy) { return nif->GetStringChars(this, string, isCopy); }
  void ReleaseStringChars(jstring string, const jchar *chars) { nif->ReleaseStringChars(this, string, chars); }
  jstring NewStringUTF(const char *bytes) { return nif->NewStringUTF(this, bytes); }
  jsize GetStringUTFLength(jstring string) { return nif->GetStringUTFLength(this, string); }
  const jbyte *GetStringUTFChars(jstring string, jboolean *isCopy) { return nif->GetStringUTFChars(this, string, isCopy); }
  void ReleaseStringUTFChars(jstring string, const char *utf) { nif->ReleaseStringUTFChars(this, string, utf); }
  jsize GetArrayLength(jarray array) { return nif->GetArrayLength(this, array); }
  jobjectArray NewObjectArray(jsize length, jclass elementType, jobject initialElement) { return nif->NewObjectArray(this, length, elementType, initialElement); }
  jobject GetObjectArrayElement(jobjectArray array, jsize index) { return nif->GetObjectArrayElement(this, array, index); }
  void SetObjectArrayElement(jobjectArray array, jsize index, jobject value) { nif->SetObjectArrayElement(this, array, index, value); }
  jbooleanArray NewBooleanArray(jsize length) { return nif->NewBooleanArray(this,length); }
  jbyteArray NewByteArray(jsize length) { return nif->NewByteArray(this, length); }
  jcharArray NewCharArray(jsize length) { return nif->NewCharArray(this, length); }
  jshortArray NewShortArray(jsize length) { return nif->NewShortArray(this, length); }
  jintArray NewIntArray(jsize length) { return nif->NewIntArray(this, length); }
  jlongArray NewLongArray(jsize length) { return nif->NewLongArray(this, length); }
  jfloatArray NewFloatArray(jsize length) { return nif->NewFloatArray(this, length); }
  jdoubleArray NewDoubleArray(jsize length) { return nif->NewDoubleArray(this, length); }
  jboolean *GetBooleanArrayElements(jbooleanArray array, jboolean *isCopy) { return nif->GetBooleanArrayElements(this, array, isCopy); }
  jbyte *GetByteArrayElements(jbyteArray array, jboolean *isCopy) { return nif->GetByteArrayElements(this, array, isCopy); }
  jchar *GetCharArrayElements(jcharArray array, jboolean *isCopy) { return nif->GetCharArrayElements(this, array, isCopy); }
  jshort *GetShortArrayElements(jshortArray array, jboolean *isCopy) { return nif->GetShortArrayElements(this, array, isCopy); }
  jint *GetIntArrayElements(jintArray array, jboolean *isCopy) { return nif->GetIntArrayElements(this, array, isCopy); }
  jlong *GetLongArrayElements(jlongArray array, jboolean *isCopy) { return nif->GetLongArrayElements(this, array, isCopy); }
  jfloat *GetFloatArrayElements(jfloatArray array, jboolean *isCopy) { return nif->GetFloatArrayElements(this, array, isCopy); }
  jdouble *GetDoubleArrayElements(jdoubleArray array, jboolean *isCopy) { return nif->GetDoubleArrayElements(this, array, isCopy); }
  void ReleaseBooleanArrayElements(jbooleanArray array, jboolean *elems, jint mode) { nif->ReleaseBooleanArrayElements(this, array, elems, mode); }
  void ReleaseByteArrayElements(jbyteArray array, jbyte *elems, jint mode) { nif->ReleaseByteArrayElements(this, array, elems, mode); }
  void ReleaseCharArrayElements(jcharArray array, jchar *elems, jint mode) { nif->ReleaseCharArrayElements(this, array, elems, mode); }
  void ReleaseShortArrayElements(jshortArray array, jshort *elems, jint mode) { nif->ReleaseShortArrayElements(this, array, elems, mode); }
  void ReleaseIntArrayElements(jintArray array, jint *elems, jint mode) { nif->ReleaseIntArrayElements(this, array, elems, mode); }
  void ReleaseLongArrayElements(jlongArray array, jlong *elems, jint mode) { nif->ReleaseLongArrayElements(this, array, elems, mode); }
  void ReleaseFloatArrayElements(jfloatArray array, jfloat *elems, jint mode) { nif->ReleaseFloatArrayElements(this, array, elems, mode); }
  void ReleaseDoubleArrayElements(jdoubleArray array, jdouble *elems, jint mode) { nif->ReleaseDoubleArrayElements(this, array, elems, mode); }
  void GetBooleanArrayRegion(jbooleanArray array, jsize start, jsize len, jboolean *buf) { nif->GetBooleanArrayRegion(this, array, start, len, buf); }
  void GetByteArrayRegion(jbyteArray array, jsize start, jsize len, jbyte *buf) { nif->GetByteArrayRegion(this, array, start, len, buf); }
  void GetCharArrayRegion(jcharArray array, jsize start, jsize len, jchar *buf) { nif->GetCharArrayRegion(this, array, start, len, buf); }
  void GetShortArrayRegion(jshortArray array, jsize start, jsize len, jshort *buf) { nif->GetShortArrayRegion(this, array, start, len, buf); }
  void GetIntArrayRegion(jintArray array, jsize start, jsize len, jint *buf) { nif->GetIntArrayRegion(this, array, start,len, buf); }
  void GetLongArrayRegion(jlongArray array, jsize start, jsize len, jlong *buf) { nif->GetLongArrayRegion(this, array, start, len, buf); }
  void GetFloatArrayRegion(jfloatArray array, jsize start, jsize len, jfloat *buf) { nif->GetFloatArrayRegion(this, array, start, len, buf); }
  void GetDoubleArrayRegion(jdoubleArray array, jsize start, jsize len, jdouble *buf) { nif->GetDoubleArrayRegion(this, array, start, len, buf); }
  void SetBooleanArrayRegion(jbooleanArray array, jsize start, jsize len, jboolean *buf) { nif->SetBooleanArrayRegion(this, array, start, len, buf); }
  void SetByteArrayRegion(jbyteArray array, jsize start, jsize len, jbyte *buf) { nif->SetByteArrayRegion(this, array, start, len, buf); }
  void SetCharArrayRegion(jcharArray array, jsize start, jsize len, jchar *buf) { nif->SetCharArrayRegion(this, array, start, len, buf); }
  void SetShortArrayRegion(jshortArray array, jsize start, jsize len, jshort *buf) { nif->SetShortArrayRegion(this, array, start, len, buf); }
  void SetIntArrayRegion(jintArray array, jsize start, jsize len, jint *buf) { nif->SetIntArrayRegion(this, array, start, len, buf); }
  void SetLongArrayRegion(jlongArray array, jsize start, jsize len, jlong *buf) { nif->SetLongArrayRegion(this, array, start, len, buf); }
  void SetFloatArrayRegion(jfloatArray array, jsize start, jsize len, jfloat *buf) { nif->SetFloatArrayRegion(this, array, start, len, buf); }
  void SetDoubleArrayRegion(jdoubleArray array, jsize start, jsize len, jdouble *buf) { nif->SetDoubleArrayRegion(this, array, start, len, buf); }
  jint RegisterNatives(jclass clazz, const JNINativeMethod *methods, jint nMethods) { return nif->RegisterNatives(this, clazz, methods, nMethods); }
  jint UnregisterNatives(jclass clazz) { return nif->UnregisterNatives(this, clazz); }
  jint MonitorEnter(jobject obj) { return nif->MonitorEnter(this, obj); }
  jint MonitorExit(jobject obj) { return nif->MonitorExit(this, obj); }
  jint GetJavaVM(JavaVM **vm) { return nif->GetJavaVM(this, vm); }
  void GetStringRegion(jstring str, jsize start, jsize len, jchar *buf) { nif->GetStringRegion(this, str, start, len, buf); }
  void GetStringUTFRegion(jstring str, jsize start, jsize len, char *buf) { nif->GetStringUTFRegion(this, str, start, len, buf); }
  void *GetPrimitiveArrayCritical(jarray array, jboolean *isCopy) { return nif->GetPrimitiveArrayCritical(this, array, isCopy); }
  void ReleasePrimitiveArrayCritical(jarray array, void *carray, jint mode) { nif->ReleasePrimitiveArrayCritical(this, array, carray, mode); }
  const jchar *GetStringCritical(jstring string, jboolean *isCopy) { return nif->GetStringCritical(this, string, isCopy); }
  void ReleaseStringCritical(jstring string, const jchar *carray) { nif->ReleaseStringCritical(this, string, carray); }
  jweak NewWeakGlobalRef(jobject obj) { return nif->NewWeakGlobalRef(this, obj); }
  void DeleteWeakGlobalRef(jweak wref) { nif->DeleteWeakGlobalRef(this, wref); }
  jboolean ExceptionCheck() { return nif->ExceptionCheck(this); }
};
#endif /* __cplusplus */


/*****************************************************************
 * JNIInvokeInterface type
 *****************************************************************/

/** JNI invoke interface */
struct JNIInvokeInterface {
  void *null_0;
  void *null_1;
  void *null_2;
  jint (JNICALL *DestroyJavaVM) (JavaVM *vm);	/* 3 */
  jint (JNICALL *AttachCurrentThread) (JavaVM *vm, JNIEnv **penv, void *args);	/* 4 */
  jint (JNICALL *DetachCurrentThread) (JavaVM *vm);	/* 5 */
  jint (JNICALL *GetEnv) (JavaVM *vm, void **penv, jint interface_id);	/* 6 */
};

#ifdef __cplusplus
struct JavaVM_ {
  const struct JNIInvokeInterface *iif;
  jint DestroyJavaVM() { return iif->DestroyJavaVM(this); }
  jint AttachCurrentThread(void **penv, void *args) { return iif->AttachCurrentThread(this, penv, args); }
  jint DetachCurrentThread() { return iif->DetachCurrentThread(this); }
  jint GetEnv(void **penv, jint interface_id) { return iif->GetEnv(this, penv, interface_id); }
};
#endif /* __cplusplus */


/*****************************************************************
 * Invocation API
 *****************************************************************/

#ifdef EXPORT_INVOCATION_API
JNIEXPORT jint JNICALL JNI_GetDefaultJavaVMInitArgs(void *vm_args);
JNIEXPORT jint JNICALL JNI_GetCreatedJavaVMs(JavaVM **vmBuf, jsize bufLen, jsize *nVMs);
JNIEXPORT jint JNICALL JNI_CreateJavaVM(JavaVM **pvm, JNIEnv **penv, void *vm_args);
#else
jint JNICALL JNI_GetDefaultJavaVMInitArgs(void *vm_args);
jint JNICALL JNI_GetCreatedJavaVMs(JavaVM **vmBuf, jsize bufLen, jsize *nVMs);
jint JNICALL JNI_CreateJavaVM(JavaVM **pvm, JNIEnv **penv, void *vm_args);
#endif


/*****************************************************************
 * Library and version management
 *****************************************************************/

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved);
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved);


/*****************************************************************
 * initialization structures
 *****************************************************************/

/** JDK 2 virtual machine configuration option */
typedef struct {
  char *optionString;
  void *extraInfo;
} JavaVMOption;

/** JDK 2 virtual machine configuration */
typedef struct {
  /** JDK version (must be JNI_VERSION_1_2) */
  jint version;
  /** Number of the options */
  jint nOptions;
  /** Pointer to the option array */
  JavaVMOption *options;
  /** If it is JNI_TRUE, then VM ignores unrecognized VM specific options (option strings that begin with "-X" or "_") */
  jboolean ignoreUnrecognized;
} JavaVMInitArgs;

/** JDK 2 thread attachment additional information */
typedef struct {
  /** JDK version (must be JNI_VERSION_1_2) */
  jint version;
  /** thread name or NULL */
  char *name;
  /** ThreadGroup object or NULL */
  jobject group;
} JavaVMAttachArgs;


/*****************************************************************
 * VM-specific structures
 *****************************************************************/

/** JDK 1.1 virtual machine configuration */
typedef struct {
  /** JDK version (must be JNI_VERSION_1_1) */
  jint version;
  /** Number of the options */
  jint nOptions;
  /** Pointer to the option array */
  JavaVMOption *options;
  /** If it is JNI_TRUE, then VM ignores unrecognized VM specific options (option strings that begin with "-X" or "_") */
  jboolean ignoreUnrecognized;
  /** Maximum native stack size of Java-created threads */
  jint nativeStackSize;
  /** Maximum Java stack size */
  jint javaStackSize;
  /** Initial heap size */
  jint minHeapSize;
  /** Maximum heap size */
  jint maxHeapSize;
  /** The local directory path for class loading */
  const char *classpath;
} JDK1_1InitArgs;


#ifdef __cplusplus
}
#endif

#endif	/* NOT SVM_JNI_H */

