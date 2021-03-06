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

/** @file
   The DS virtual machine core. 
   @author Dusan Stastny <info@developservice.cz>
*/

#include "jni.h"
#define _DSVM_NATIVE_H_
#include "config.h"
#undef _DSVM_NATIVE_H_

#ifndef _DSVM_H_
#define _DSVM_H_


/** DSVM class major version. */
#define VM_CLASS_MAJOR_VERSION 1

/** DSVM class minor version. */
#define VM_CLASS_MINOR_VERSION 0

/** Class major version unsupported by the DSVM. */
#define VM_UNSUPPORTED_MAJOR_VERSION 0

/** Class minor version unsupported by the DSVM. */
#define VM_UNSUPPORTED_MINOR_VERSION 0

/** Reads an integer value from the raw class data buffer */
#define getClassInt(b) (jint)((0xFF&(b)[0])<<24 | (0xFF&(b)[1])<<16 | (0xFF&(b)[2])<<8 | (0xFF&(b)[3]))

/** Reads an unsigned short integer value from the raw class data buffer */
#define getClassUShort(b) (jushort)(((0xFF&(b)[0])<<8) | (0xFF&(b)[1]))

/** Maximal array dimension supported by the DSVM. */
#define VM_MAX_ARRAY_DIMENSION 5

/** Maximal number of the loaded native libraries */
#define VM_MAX_LIBRARIES_COUNT 64

/** Maximal number of the loaded java archives */
#define VM_MAX_JARS_COUNT 64

/** Returns the larger of two values */
#define VM_MAX(a, b) (((a) > (b)) ? (a) : (b))

/** Returns the smaller of two values */
#define VM_MIN(a, b) (((a) < (b)) ? (a) : (b))

/** Returns the main thread JNI interface pointer for the Java VM interface pointer */ 
#define JVM_MAINENV(vm) (((vmJavaVM*)(vm))->envlist)

/** Returns heap capacity for the Java VM interface pointer */ 
#define JVM_HEAP_SIZE(vm) (((vmJavaVM*)(vm))->heap_size)

/** Reference counting? */
#ifndef VM_GC_REFERENCECOUNTING
#define VM_GC_REFERENCECOUNTING 0
#endif
#if VM_GC_REFERENCECOUNTING
#define JNINEWGLOBALREF(env, ref) jniNewGlobalRef(env, ref)
#define JNIDELETEGLOBALREF(env, ref) jniDeleteGlobalRef(env, ref)
#else
#define JNINEWGLOBALREF(env, ref) ref
#define JNIDELETEGLOBALREF(env, ref)
#endif

/** Mark-sweep garbage collector? */
#ifndef VM_GC_MARKSWEEP
#define VM_GC_MARKSWEEP 1
#endif

struct _clsConstPool;
struct _clsDefinition;
struct _vmFrame;
struct _vmJNIEnv;
struct _vmJavaVM;


/*****************************************************************
 * Hash map
 *****************************************************************/

/** Hash function prototype */
typedef jint FASTCALL (*hash_fce)(const void*, juint);

/** Compare function prototype */
typedef jint (*compare_fce)(const void*, const void*, juint, juint);

/** Hash map root */
typedef struct _hash_root {
	/** Java VM interface pointer */
	struct _vmJavaVM *vm;
	/** Current number of the slots */
	juint capacity;
	/** Size of the hash map entry structure plus extra data length */
	juint entry_size;
	/** Slot array */
	jbyte *slot;
	/** Number of the entries when to make next rehash operation */
	juint threshold;
	/** Current number of the entries */
	juint size;
	/** Entry key compare function */
	compare_fce compare;
} hash_root;

/** Hash map entry */
typedef struct _hash_entry {
	/** The hash value for the entry key */
	jint hash;
	/** The entry key */
	const void *key;
	/** The entry key length */
	juint key_len;
	/** A next entry (with equal key) */ 
	struct _hash_entry *next;
	/** The entry data */
	void *data;
} hash_entry;

/* Hash map functions */
jint FASTCALL vmStringHashFce(const jchar *str, juint len);
jint FASTCALL vmStringHashFceUTF(const char *str, juint len);
jint FASTCALL vmZeroStringHashFce(const jchar *str, juint unused);
jint FASTCALL vmZeroStringHashFceUTF(const char *str, juint unused);
jint vmMemCompareFce(const void *str1, const void *str2, juint len1, juint len2);
jint vmZeroStringCompareFce(const void *str1, const void *str2, juint len1, juint len2);
jint vmZeroStringCompareFceUTF(const void *str1, const void *str2, juint len1, juint len2);
void vmHashInit(struct _vmJavaVM *vm, hash_root *root, juint capacity, juint threshold, juint internal_data_len, compare_fce cfce);
void vmHashRelease(hash_root *root);
hash_entry FASTCALL *vmHashInsertEntry_Fce(hash_root *root, void *data, const void *key, juint key_len, hash_fce hfce);
hash_entry *vmHashInsertEntry_Hash(hash_root *root, void *data, const void *key, juint key_len, jint hash);
void FASTCALL **vmHashFindEntry_Fce(hash_root *root, const void *key, juint key_len, hash_fce hfce);
void **vmHashFindEntry_Hash(hash_root *root, const void *key, jint key_len, jint hash);


/*****************************************************************
 * Java stack
 *****************************************************************/

/** Java stack slot type */
typedef jobject VM_STACK_SLOT_TYPE;

/** Default local frame capacity */
#define VM_DEFAULT_LOCAL_REFERENCES_COUNT 16

/** Number of the stack slots for long and double type */
#define VM_STACK_SLOT_LONG_SIZE  (jint)(sizeof(jlong) / sizeof(VM_STACK_SLOT_TYPE))

/** Number of the stack slots for integer type */
#define VM_STACK_SLOT_FRAME_SIZE (jint)(1 + (sizeof(vmFrame) - 1) / sizeof(VM_STACK_SLOT_TYPE))

/* Java stack operations */
#define VM_PUSH1(frame)           ((frame->stack_top < frame->stack_capacity) ? (frame->stack + frame->stack_top++) : (VM_STACK_SLOT_TYPE*)vmFatalError(frame->env, "Stack overflow"))
#define VM_PUSH2(frame)           (((frame->stack_top+VM_STACK_SLOT_LONG_SIZE) <= frame->stack_capacity) ? (frame->stack + (frame->stack_top += VM_STACK_SLOT_LONG_SIZE) - VM_STACK_SLOT_LONG_SIZE) : (VM_STACK_SLOT_TYPE*)vmFatalError(frame->env, "Stack overflow"))
#define VM_PUSH_BOOLEAN(frame, x) VM_PUSH_INT(frame, x)
#define VM_PUSH_BYTE(frame, x)    VM_PUSH_INT(frame, x)
#define VM_PUSH_CHAR(frame, x)    VM_PUSH_INT(frame, x)
#define VM_PUSH_SHORT(frame, x)   VM_PUSH_INT(frame, x)
#define VM_PUSH_INT(frame, x)     *(jint*)VM_PUSH1(frame) = (jint)(x)
#define VM_PUSH_LONG(frame, x)    { jlong tmp = x; *(jlong*)VM_PUSH2(frame) = tmp; }
#define VM_PUSH_FLOAT(frame, x)   { jfloat tmp = x; VM_PUSH_INT(frame, *(jint*)&tmp); }
#define VM_PUSH_DOUBLE(frame, x)  { jdouble tmp2 = x; VM_PUSH_LONG(frame, *(jlong*)&tmp2); }
#define VM_PUSH_OBJECT(frame, x)  *VM_PUSH1(frame) = x
#define VM_PUSH_VALUE(frame,x,tp) switch (tp) { \
	case '[': \
	case 'L': VM_PUSH_OBJECT(frame, (x).l); break; \
	case 'I': VM_PUSH_INT(frame, (x).i); break; \
	case 'D': VM_PUSH_DOUBLE(frame, (x).d); break; \
	case 'C': VM_PUSH_CHAR(frame, (x).c); break; \
	case 'Z': VM_PUSH_BOOLEAN(frame, (x).z); break; \
	case 'B': VM_PUSH_BYTE(frame, (x).b); break; \
	case 'J': VM_PUSH_LONG(frame, (x).j); break; \
	case 'F': VM_PUSH_FLOAT(frame, (x).f); break; \
	case 'S': VM_PUSH_SHORT(frame, (x).s); break; \
	}

#define VM_POP1(frame)            ((frame->stack_top > 0) ? (frame->stack + (--(frame->stack_top))) : (VM_STACK_SLOT_TYPE*)vmFatalError(frame->env, "Stack underflow"))
#define VM_POP2(frame)            (((frame->stack_top-VM_STACK_SLOT_LONG_SIZE) >= 0) ? (frame->stack + (frame->stack_top -= VM_STACK_SLOT_LONG_SIZE)) : (VM_STACK_SLOT_TYPE*)vmFatalError(frame->env, "Stack underflow"))
#define VM_POP_BOOLEAN(frame)     ((jboolean)VM_POP_INT(frame))
#define VM_POP_BYTE(frame)        ((jbyte)VM_POP_INT(frame))
#define VM_POP_CHAR(frame)        ((jchar)VM_POP_INT(frame))
#define VM_POP_SHORT(frame)       ((jshort)VM_POP_INT(frame))
#define VM_POP_INT(frame)         (*(jint*)VM_POP1(frame))
#define VM_POP_LONG(frame)        (*(jlong*)VM_POP2(frame))
#define VM_POP_FLOAT(frame)       (*(jfloat*)VM_POP1(frame))
#define VM_POP_DOUBLE(frame)      (*(jdouble*)VM_POP2(frame))
#define VM_POP_OBJECT(frame)      *VM_POP1(frame)
#define VM_POP_VALUE(frame,x,tp) switch (tp) { \
	case '[': \
	case 'L': (x).l = VM_POP_OBJECT(frame); break; \
	case 'I': (x).i = VM_POP_INT(frame); break; \
	case 'D': (x).d = VM_POP_DOUBLE(frame); break; \
	case 'C': (x).c = VM_POP_CHAR(frame); break; \
	case 'Z': (x).z = VM_POP_BOOLEAN(frame); break; \
	case 'B': (x).b = VM_POP_BYTE(frame); break; \
	case 'J': (x).j = VM_POP_LONG(frame); break; \
	case 'F': (x).f = VM_POP_FLOAT(frame); break; \
	case 'S': (x).s = VM_POP_SHORT(frame); break; \
	}

/** Push method's arguments via va_list */
#define VM_PUSH_VA_LIST(env, met, args) \
{ \
	char *p = met->descriptor; p++; \
	while (*p != ')') { \
		switch (*p) { \
			case 'Z': \
				VM_PUSH_BOOLEAN(env, va_arg(args, jboolean)); \
				break; \
			case 'B': \
				VM_PUSH_BYTE(env, va_arg(args, jbyte)); \
				break; \
			case 'C': \
				VM_PUSH_CHAR(env, va_arg(args, jchar)); \
				break; \
			case 'S': \
				VM_PUSH_SHORT(env, va_arg(args, jshort)); \
				break; \
			case 'I': \
				VM_PUSH_INT(env, va_arg(args, jint)); \
				break; \
			case 'J': \
				VM_PUSH_LONG(env, va_arg(args, jlong)); \
				break; \
			case 'F': \
				VM_PUSH_FLOAT(env, va_arg(args, jfloat)); \
				break; \
			case 'D': \
				VM_PUSH_DOUBLE(env, va_arg(args, jdouble)); \
				break; \
			case '[': \
				p++; \
			case 'L': \
				VM_PUSH_OBJECT(env, va_arg(args, jobject)); \
				if (*p == 'L') while (*p != ';') p++; \
				break; \
		}; \
		p++; \
	} \
}

/** Push method's arguments via jvalue array */
#define VM_PUSH_ARRAY_LIST(env, met, args) \
{ \
	TCHAR *p = met->descriptor; p++; \
	while (*p != (TCHAR)')') { \
		VM_PUSH_VALUE(env, *args, *p); \
		if (*p == (TCHAR)'L') \
			while (*p != (TCHAR)';') p++; \
		args++; p++; \
	} \
}


/*****************************************************************
 * Essential VM structures and definitions
 *****************************************************************/

/** Java VM interface implementation */
typedef struct _vmJavaVM {
	const struct JNIInvokeInterface *iif;
	/** Thread environment list (main thread is first) */
	struct _vmJNIEnv *envlist;
	/** Memory heap */
	jobject *heap;
	/** Object heap capacity */
	jint heap_size;
	/** Last used heap index */
	jint heap_last;
	/** Maximal used heap index */
	jint heap_max;
	/** Class definitions */
	hash_root clsdef;
	/** java.lang.Class class definition */
	struct _clsDefinition *class_clsdef;
	/** java.lang.Object[] class definition */
	struct _clsDefinition *array_clsdef;
	/** System class loader object */
	jobject loader;
	/** Out of memory error object */
	jthrowable outofmem;
	/** VM initialization configuration */
	JDK1_1InitArgs *args;
	/** VM synchronization data */
	void *gcs;
	/** Counter of the loaded native libraries */
	jint lib_count;
	/** List of the loaded native libraries */
	void *lib[VM_MAX_LIBRARIES_COUNT];
	/** List of the loaded java archives */
	jobject jar[VM_MAX_JARS_COUNT];
} vmJavaVM;


/** JNI interface implementation */
typedef struct _vmJNIEnv {
	const struct JNINativeInterface *iif;
	/** VM initialization configuration */
	JDK1_1InitArgs *args;
	/** VM that owns this thread environment */
	struct _vmJavaVM *vm;
	/** Previous thread environment */
	struct _vmJNIEnv *prev;
	/** Next thread environment */
	struct _vmJNIEnv *next;
	/** Java stack */
	VM_STACK_SLOT_TYPE *stack;
	/** Java stack capacity */
	jint stack_capacity;
	/** Frame buffer */
	VM_STACK_SLOT_TYPE *frame_buf;
	/** Frame buffer capacity */
	jint frame_capacity;
	/** Current local frame */
	struct _vmFrame *frame;
	/** Native thread ID */
	natThreadID thread_id;
	/** Handle to a native memory block */
	vmMemHandle hmem;
	/** Flags */
	jint flags;
} vmJNIEnv;

/** Object notifyAll() method invoked? */
#define VM_JNIENV_DESTROYED        0x1


/** Local frame implementation */
typedef struct _vmFrame {
	/** Current thread environment */
	vmJNIEnv *env;
	/** Previous local frame */
	struct _vmFrame *prev;
	/** Capacity of the local references */
	jint refs_capacity;
	/** Local references */
	VM_STACK_SLOT_TYPE *refs;
	/** Counter of the local references */
	jint refs_top;
	/** Capacity of the operand stack */
	jint stack_capacity;
	/** Current operand stack */
	VM_STACK_SLOT_TYPE *stack;
	/** The top of the operand stack */
	jint stack_top;
	/** Currently executed method */
	jmethodID met;
	/** Current class constant pool */
	struct _clsConstPool *constant_pool;
	/** Pointer to current Java instruction */
	jubyte *pc;
	/** Byte code wide flag */
	jboolean wide;
	/** The throwable object that is currently being thrown */
	jthrowable exception;
} vmFrame;


#include "java\lang\Class.h"

/** JNI object implementation */
struct _jobject_struct {
	/** Object flags */
	jshort flags;
	/** Object array dimension */
	jshort dim;
#if VM_GC_REFERENCECOUNTING
	/** Reference counter */
	jint cnt;
#endif
	/** Dimension depended object class definition */
	clsDefinition *clsdefdim;
	/** Object class definition */
	clsDefinition *clsdef;
	/** Object instance fields */
	jbyte *data;
	/** ID of the native thread that owns this object */
	natThreadID thread_id;
	/** Monitor counter */
	jint thread_cnt;
	/** Monitor exit event */
	natEventData exit_event;
	/** Wait native event */
	natEventData wait_event;
	/** Object index in VM heap */
	jint heap_index;
};

/** Invoke object finalize() method? */
#define VM_OBJECT_FINALIZE_FLAG    0x01

/** Object notify() method invoked? */
#define VM_OBJECT_NOTIFY_FLAG      0x02

/** Object notifyAll() method invoked? */
#define VM_OBJECT_NOTIFYALL_FLAG   0x04

/** Free object data? */
#define VM_OBJECT_FREEDATA_FLAG    0x08

/** Mark-sweep garbage collector flag */
#define VM_OBJECT_GCSWEEP_FLAG     0x10


/** Class cache hash map entry */
typedef struct _class_cache_hash_entry {
	/** A class definition */
	clsDefinition* cls;
	/** Class object cache for all supported dimensions */
	jobject obj[VM_MAX_ARRAY_DIMENSION + 1];
} class_cache_entry;

/** Java byte code handler function */
typedef jthrowable (*jInstructionHandler)(vmFrame*);

/** Java byte code handlers */
extern jInstructionHandler jInstructionSet[256];


/*****************************************************************
 * DS virtual machine support
 *****************************************************************/

/* Garbage collector */
void* FASTCALL vmMemAlloc(vmJavaVM *vm, jint size);
#define vmMemFree(vm, p) _vmMemFree(p)
void FASTCALL vmUnmarkObject(jobject obj);
jint vmGC(vmJavaVM *vm);

/* Strings */
int fromUtf8(jchar* str, const char *utf8, unsigned int strsize);
int toUtf8(char *utf8, const jchar *str, int strlen);

/* Errors & Exceptions */
void *vmFatalError(vmJNIEnv *env, const char *msg);
jthrowable vmCreateThrowable(vmJNIEnv *env, clsDefinition *cls, const char *message);

/* Class management */
jint vmRegisterCoreClasses(vmJavaVM *vm, vmJNIEnv *env);
jclass vmRegisterClass(vmJavaVM *vm, vmJNIEnv *env, clsDefinition *cls);
clsDefinition *vmCloneClassDefinition(vmJNIEnv *env, clsDefinition *cls);
clsDefinition *vmDefineClass(vmJNIEnv *env, const char *name, const jbyte *buf, jsize bufLen);
jobject vmCreateObject(vmJNIEnv *env, clsDefinition *cls, jshort dim, jint len, jint extra_data_size);
void vmDestroyObject(vmJNIEnv *env, jobject obj);
jclass vmFindClassByName(vmJNIEnv *env, const char *name, jint name_len, jshort dim);
jclass vmFindClassByDef(vmJNIEnv *env, clsDefinition *cls, jshort dim);

/* Method management */
jmethodID vmGetClassMethod(clsDefinition *cls, const char *name, const char *sig, jboolean recursive);
jmethodID vmGetInstanceMethod(clsDefinition *cls, const char *name, const char *sig, jboolean recursive);
void vmExecuteMethod(vmFrame *frame, jmethodID met, jclass clazz);
void vmInvokeVirtual(vmFrame *frame, jmethodID met);
void vmInvokeSpecial(vmFrame *frame, jmethodID met, jclass clazz);
void vmInvokeStatic(vmFrame *frame, jmethodID met, jclass clazz);
char* vmGetMethodDisplayNameUTF(char *buf, int buflen, clsDefinition *cls, const char *name, const char *sig, jint flags);

/* Field management*/
jboolean vmLocal2GlobalRef(vmFrame *frame, jobject lref);
jboolean vmIsAssignableFrom(clsDefinition *cls1, clsDefinition *cls2);
jboolean FASTCALL vmIsClassAssignableFrom(clsDefinition *cls1, jint dim1, clsDefinition *cls2, jint dim2);
jfieldID vmGetClassField(clsDefinition *cls, const char *name, const char *sig, jboolean recursive);
jfieldID vmGetInstanceField(clsDefinition *cls, const char *name, const char *sig, jboolean recursive);
jboolean vmSetObjectVar(JNIEnv *env, jobject *dest, jobject src, jfieldID fld);
jthrowable vmGetField(vmFrame *frame, jobject obj, jfieldID fld);
jthrowable vmPutField(vmFrame *frame, jfieldID fld);
jthrowable vmGetStatic(vmFrame *frame, jfieldID fld);
jthrowable vmPutStatic(vmFrame *frame, jfieldID fld);
const char *vmGetTypeDisplayNameUTF(char *buf, int buflen, const char *sig);
char* vmGetFieldDisplayNameUTF(char *buf, int buflen, clsDefinition *cls, const char *name, const char *sig, jint flags);

/* JNI implementation */
jint JNICALL jniGetVersion(JNIEnv *env);	/* 4 */
jclass JNICALL jniDefineClass(JNIEnv *env, jobject loader, const jbyte *buf, jsize bufLen);	/* 5 */
jclass JNICALL jniFindClass(JNIEnv *env, const char *name);	/* 6 */
jmethodID JNICALL jniFromReflectedMethod(JNIEnv *env, jobject method);	/* 7 */
jfieldID JNICALL jniFromReflectedField(JNIEnv *env, jobject field);	/* 8 */
jobject JNICALL jniToReflectedMethod(JNIEnv *env, jclass cls, jmethodID methodID, jboolean isStatic);	/* 9 */
jclass JNICALL jniGetSuperclass(JNIEnv *env, jclass clazz);	/* 10 */
jboolean JNICALL jniIsAssignableFrom(JNIEnv *env, jclass clazz1, jclass clazz2);	/* 11 */
jobject JNICALL jniToReflectedField(JNIEnv *env, jclass cls, jfieldID fieldID, jboolean isStatic);	/* 12 */
jint JNICALL jniThrow(JNIEnv *env, jthrowable obj);	/* 13 */
jint JNICALL jniThrowNew(JNIEnv *env, jclass clazz, const char *message);	/* 14 */
jthrowable JNICALL jniExceptionOccurred(JNIEnv *env);	/* 15 */
void JNICALL jniExceptionDescribe(JNIEnv *env);	/* 16 */
void JNICALL jniExceptionClear(JNIEnv *env);	/* 17 */
void JNICALL jniFatalError(JNIEnv *env, const char *msg);	/* 18 */
jint JNICALL jniPushLocalFrame(JNIEnv *env, jint capacity);	/* 19 */
jobject JNICALL jniPopLocalFrame(JNIEnv *env, jobject result);	/* 20 */
jobject JNICALL jniNewGlobalRef(JNIEnv *env, jobject ref);	/* 21 */
void JNICALL jniDeleteGlobalRef(JNIEnv *env, jobject gref);	/* 22 */
void JNICALL jniDeleteLocalRef(JNIEnv *env, jobject lref);	/* 23 */
jboolean JNICALL jniIsSameObject(JNIEnv *env, jobject ref1, jobject ref2);	/* 24 */
jobject JNICALL jniNewLocalRef(JNIEnv *env, jobject ref);	/* 25 */
jint JNICALL jniEnsureLocalCapacity(JNIEnv *env, jint capacity);	/* 26 */
jobject JNICALL jniAllocObject(JNIEnv *env, jclass clazz);	/* 27 */
jobject JNICALL jniNewObject(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 28 */
jobject JNICALL jniNewObjectV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 29 */
jobject JNICALL jniNewObjectA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 30 */
jclass JNICALL jniGetObjectClass(JNIEnv *env, jobject obj);	/* 31 */
jboolean JNICALL jniIsInstanceOf(JNIEnv *env, jobject obj, jclass clazz);	/* 32 */
jmethodID JNICALL jniGetMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 33 */
jobject JNICALL jniCallObjectMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 34 */
jobject JNICALL jniCallObjectMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 35 */
jobject JNICALL jniCallObjectMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 36 */
jboolean JNICALL jniCallBooleanMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 37 */
jboolean JNICALL jniCallBooleanMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 38 */
jboolean JNICALL jniCallBooleanMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 39 */
jbyte JNICALL jniCallByteMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 40 */
jbyte JNICALL jniCallByteMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 41 */
jbyte JNICALL jniCallByteMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 42 */
jchar JNICALL jniCallCharMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 43 */
jchar JNICALL jniCallCharMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 44 */
jchar JNICALL jniCallCharMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 45 */
jshort JNICALL jniCallShortMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 46 */
jshort JNICALL jniCallShortMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 47 */
jshort JNICALL jniCallShortMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 48 */
jint JNICALL jniCallIntMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 49 */
jint JNICALL jniCallIntMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 50 */
jint JNICALL jniCallIntMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 51 */
jlong JNICALL jniCallLongMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 52 */
jlong JNICALL jniCallLongMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 53 */
jlong JNICALL jniCallLongMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 54 */
jfloat JNICALL jniCallFloatMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 55 */
jfloat JNICALL jniCallFloatMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 56 */
jfloat JNICALL jniCallFloatMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 57 */
jdouble JNICALL jniCallDoubleMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 58 */
jdouble JNICALL jniCallDoubleMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 59 */
jdouble JNICALL jniCallDoubleMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 60 */
void JNICALL jniCallVoidMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...);	/* 61 */
void JNICALL jniCallVoidMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);	/* 62 */
void JNICALL jniCallVoidMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args);	/* 63 */
jobject JNICALL jniCallNonvirtualObjectMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 64 */ 
jobject JNICALL jniCallNonvirtualObjectMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 65 */
jobject JNICALL jniCallNonvirtualObjectMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 66 */
jboolean JNICALL jniCallNonvirtualBooleanMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 67 */
jboolean JNICALL jniCallNonvirtualBooleanMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 68 */
jboolean JNICALL jniCallNonvirtualBooleanMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 69 */
jbyte JNICALL jniCallNonvirtualByteMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 70 */
jbyte JNICALL jniCallNonvirtualByteMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 71 */
jbyte JNICALL jniCallNonvirtualByteMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 72 */
jchar JNICALL jniCallNonvirtualCharMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 73 */
jchar JNICALL jniCallNonvirtualCharMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 74 */
jchar JNICALL jniCallNonvirtualCharMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 75 */
jshort JNICALL jniCallNonvirtualShortMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 76 */
jshort JNICALL jniCallNonvirtualShortMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 77 */
jshort JNICALL jniCallNonvirtualShortMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 78 */
jint JNICALL jniCallNonvirtualIntMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 79 */ 
jint JNICALL jniCallNonvirtualIntMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 80 */ 
jint JNICALL jniCallNonvirtualIntMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 81 */
jlong JNICALL jniCallNonvirtualLongMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 82 */
jlong JNICALL jniCallNonvirtualLongMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 83 */
jlong JNICALL jniCallNonvirtualLongMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 84 */
jfloat JNICALL jniCallNonvirtualFloatMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 85 */
jfloat JNICALL jniCallNonvirtualFloatMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 86 */
jfloat JNICALL jniCallNonvirtualFloatMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 87 */
jdouble JNICALL jniCallNonvirtualDoubleMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 88 */
jdouble JNICALL jniCallNonvirtualDoubleMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 89 */
jdouble JNICALL jniCallNonvirtualDoubleMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 90 */
void JNICALL jniCallNonvirtualVoidMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...);	/* 91 */
void JNICALL jniCallNonvirtualVoidMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args);	/* 92 */
void JNICALL jniCallNonvirtualVoidMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args);	/* 93 */
jfieldID JNICALL jniGetFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 94 */
jobject JNICALL jniGetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 95 */
jboolean JNICALL jniGetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 96 */
jbyte JNICALL jniGetByteField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 97 */
jchar JNICALL jniGetCharField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 98 */
jshort JNICALL jniGetShortField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 99 */
jint JNICALL jniGetIntField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 100 */
jlong JNICALL jniGetLongField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 101 */
jfloat JNICALL jniGetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 102 */
jdouble JNICALL jniGetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID);	/* 103 */
void JNICALL jniSetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID, jobject value);	/* 104 */
void JNICALL jniSetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID, jboolean value);	/* 105 */
void JNICALL jniSetByteField(JNIEnv *env, jobject obj, jfieldID fieldID, jbyte value);	/* 106 */
void JNICALL jniSetCharField(JNIEnv *env, jobject obj, jfieldID fieldID, jchar value);	/* 107 */
void JNICALL jniSetShortField(JNIEnv *env, jobject obj, jfieldID fieldID, jshort value);	/* 108 */ 
void JNICALL jniSetIntField(JNIEnv *env, jobject obj, jfieldID fieldID, jint value);	/* 109 */
void JNICALL jniSetLongField(JNIEnv *env, jobject obj, jfieldID fieldID, jlong value);	/* 110 */
void JNICALL jniSetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID, jfloat value);	/* 111 */
void JNICALL jniSetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID, jdouble value);	/* 112 */
jmethodID JNICALL jniGetStaticMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 113 */
jobject JNICALL jniCallStaticObjectMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 114 */
jobject JNICALL jniCallStaticObjectMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 115 */
jobject JNICALL jniCallStaticObjectMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 116 */
jboolean JNICALL jniCallStaticBooleanMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 117 */
jboolean JNICALL jniCallStaticBooleanMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 118 */
jboolean JNICALL jniCallStaticBooleanMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 119 */
jbyte JNICALL jniCallStaticByteMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 120 */
jbyte JNICALL jniCallStaticByteMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 121 */
jbyte JNICALL jniCallStaticByteMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 122 */
jchar JNICALL jniCallStaticCharMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 123 */
jchar JNICALL jniCallStaticCharMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 124 */
jchar JNICALL jniCallStaticCharMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 125 */
jshort JNICALL jniCallStaticShortMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 126 */
jshort JNICALL jniCallStaticShortMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 127 */
jshort JNICALL jniCallStaticShortMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 128 */
jint JNICALL jniCallStaticIntMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 129 */
jint JNICALL jniCallStaticIntMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 130 */
jint JNICALL jniCallStaticIntMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 131 */
jlong JNICALL jniCallStaticLongMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 132 */
jlong JNICALL jniCallStaticLongMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 133 */
jlong JNICALL jniCallStaticLongMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 134 */
jfloat JNICALL jniCallStaticFloatMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 135 */
jfloat JNICALL jniCallStaticFloatMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 136 */
jfloat JNICALL jniCallStaticFloatMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 137 */
jdouble JNICALL jniCallStaticDoubleMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 138 */
jdouble JNICALL jniCallStaticDoubleMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 139 */
jdouble JNICALL jniCallStaticDoubleMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 140 */
void JNICALL jniCallStaticVoidMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...);	/* 141 */
void JNICALL jniCallStaticVoidMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args);	/* 142 */
void JNICALL jniCallStaticVoidMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args);	/* 143 */
jfieldID JNICALL jniGetStaticFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig);	/* 144 */
jobject JNICALL jniGetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 145 */
jboolean JNICALL jniGetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 146 */
jbyte JNICALL jniGetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 147 */
jchar JNICALL jniGetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 148 */
jshort JNICALL jniGetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 149 */
jint JNICALL jniGetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 150 */
jlong JNICALL jniGetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 151 */
jfloat JNICALL jniGetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 152 */
jdouble JNICALL jniGetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID);	/* 153 */
void JNICALL jniSetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID, jobject value);	/* 154 */
void JNICALL jniSetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID, jboolean value);	/* 155 */
void JNICALL jniSetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID, jbyte value);	/* 156 */
void JNICALL jniSetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID, jchar value);	/* 157 */
void JNICALL jniSetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID, jshort value);	/* 158 */
void JNICALL jniSetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID, jint value);	/* 159 */
void JNICALL jniSetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID, jlong value);	/* 160 */
void JNICALL jniSetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID, jfloat value);	/* 161 */
void JNICALL jniSetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID, jdouble value);	/* 162 */
jstring JNICALL jniNewString(JNIEnv *env, const jchar *uChars, jsize len);	/* 163 */
jsize JNICALL jniGetStringLength(JNIEnv *env, jstring string);	/* 164 */
const jchar *JNICALL jniGetStringChars(JNIEnv *env, jstring string, jboolean *isCopy);	/* 165 */
void JNICALL jniReleaseStringChars(JNIEnv *env, jstring string, const jchar *chars);	/* 166 */
jstring JNICALL jniNewStringUTF(JNIEnv *env, const char *bytes);	/* 167 */
jsize JNICALL jniGetStringUTFLength(JNIEnv *env, jstring string);	/* 168 */
const jbyte *JNICALL jniGetStringUTFChars(JNIEnv *env, jstring string, jboolean *isCopy);	/* 169 */
void JNICALL jniReleaseStringUTFChars(JNIEnv *env, jstring string, const char *utf);	/* 170 */
jsize JNICALL jniGetArrayLength(JNIEnv *env, jarray array);	/* 171 */
jarray JNICALL jniNewObjectArray(JNIEnv *env, jsize length, jclass elementType, jobject initialElement);	/* 172 */
jobject JNICALL jniGetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index);	/* 173 */
void JNICALL jniSetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index, jobject value);	/* 174 */
jbooleanArray JNICALL jniNewBooleanArray(JNIEnv *env, jsize length);	/* 175 */
jbyteArray JNICALL jniNewByteArray(JNIEnv *env, jsize length);	/* 176 */
jcharArray JNICALL jniNewCharArray(JNIEnv *env, jsize length);	/* 177 */
jshortArray JNICALL jniNewShortArray(JNIEnv *env, jsize length);	/* 178 */
jintArray JNICALL jniNewIntArray(JNIEnv *env, jsize length);	/* 179 */
jlongArray JNICALL jniNewLongArray(JNIEnv *env, jsize length);	/* 180 */
jfloatArray JNICALL jniNewFloatArray(JNIEnv *env, jsize length);	/* 181 */
jdoubleArray JNICALL jniNewDoubleArray(JNIEnv *env, jsize length);	/* 182 */
jboolean *JNICALL jniGetBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *isCopy);	/* 183 */
jbyte *JNICALL jniGetByteArrayElements(JNIEnv *env, jbyteArray array, jboolean *isCopy);	/* 184 */
jchar *JNICALL jniGetCharArrayElements(JNIEnv *env, jcharArray array, jboolean *isCopy);	/* 185 */
jshort *JNICALL jniGetShortArrayElements(JNIEnv *env, jshortArray array, jboolean *isCopy);	/* 186 */
jint *JNICALL jniGetIntArrayElements(JNIEnv *env, jintArray array, jboolean *isCopy);	/* 187 */
jlong *JNICALL jniGetLongArrayElements(JNIEnv *env, jlongArray array, jboolean *isCopy);	/* 188 */
jfloat *JNICALL jniGetFloatArrayElements(JNIEnv *env, jfloatArray array, jboolean *isCopy);	/* 189 */
jdouble *JNICALL jniGetDoubleArrayElements(JNIEnv *env, jdoubleArray array, jboolean *isCopy);	/* 190 */
void JNICALL jniReleaseBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *elems, jint mode);	/* 191 */
void JNICALL jniReleaseByteArrayElements(JNIEnv *env, jbyteArray array, jbyte *elems, jint mode);	/* 192 */
void JNICALL jniReleaseCharArrayElements(JNIEnv *env, jcharArray array, jchar *elems, jint mode);	/* 193 */
void JNICALL jniReleaseShortArrayElements(JNIEnv *env, jshortArray array, jshort *elems, jint mode);	/* 194 */
void JNICALL jniReleaseIntArrayElements(JNIEnv *env, jintArray array, jint *elems, jint mode);	/* 195 */
void JNICALL jniReleaseLongArrayElements(JNIEnv *env, jlongArray array, jlong *elems, jint mode);	/* 196 */
void JNICALL jniReleaseFloatArrayElements(JNIEnv *env, jfloatArray array, jfloat *elems, jint mode);	/* 197 */
void JNICALL jniReleaseDoubleArrayElements(JNIEnv *env, jdoubleArray array, jdouble *elems, jint mode);	/* 198 */
void JNICALL jniGetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf);	/* 199 */
void JNICALL jniGetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf);	/* 200 */
void JNICALL jniGetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf);	/* 201 */
void JNICALL jniGetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf);	/* 202 */
void JNICALL jniGetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf);	/* 203 */
void JNICALL jniGetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf);	/* 204 */
void JNICALL jniGetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf);	/* 205 */
void JNICALL jniGetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf);	/* 206 */
void JNICALL jniSetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf);	/* 207 */
void JNICALL jniSetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf);	/* 208 */
void JNICALL jniSetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf);	/* 209 */
void JNICALL jniSetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf);	/* 210 */
void JNICALL jniSetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf);	/* 211 */
void JNICALL jniSetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf);	/* 212 */
void JNICALL jniSetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf);	/* 213 */
void JNICALL jniSetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf);	/* 214 */
jint JNICALL jniRegisterNatives(JNIEnv *env, jclass clazz, const JNINativeMethod *methods, jint nMethods);	/* 215 */
jint JNICALL jniUnregisterNatives(JNIEnv *env, jclass clazz);	/* 216 */
jint JNICALL jniMonitorEnter(JNIEnv *env, jobject obj);	/* 217 */
jint JNICALL jniMonitorExit(JNIEnv *env, jobject obj);	/* 218 */
jint JNICALL jniGetJavaVM(JNIEnv *env, JavaVM **vm);	/* 219 */
void JNICALL jniGetStringRegion(JNIEnv *env, jstring str, jsize start, jsize len, jchar *buf);	/* 220 */
void JNICALL jniGetStringUTFRegion(JNIEnv *env, jstring str, jsize start, jsize len, char *buf);	/* 221 */
void *JNICALL jniGetPrimitiveArrayCritical(JNIEnv *env, jarray array, jboolean *isCopy);	/* 222 */
void JNICALL jniReleasePrimitiveArrayCritical(JNIEnv *env, jarray array, void *elems, jint mode);	/* 223 */
const jchar *JNICALL jniGetStringCritical(JNIEnv *env, jstring string, jboolean *isCopy);	/* 224 */
void JNICALL jniReleaseStringCritical(JNIEnv *env, jstring string, const jchar *chars);	/* 225 */
jweak JNICALL jniNewWeakGlobalRef(JNIEnv *env, jobject ref);	/* 226 */
void JNICALL jniDeleteWeakGlobalRef(JNIEnv *env, jweak wref);	/* 227 */
jboolean JNICALL jniExceptionCheck(JNIEnv *env);	/* 228 */


#endif	/* NOT _DSVM_H_ */
