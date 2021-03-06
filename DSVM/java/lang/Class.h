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


#ifndef _JAVA_LANG_CLASS_H_
#define _JAVA_LANG_CLASS_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "jni.h"


/* access flags */
#define ACC_PUBLIC        0x0001    /* may be accessed from outside its package */
#define ACC_PRIVATE       0x0002    /* usable only within the defining class */
#define ACC_PROTECTED     0x0004    /* may be accessed within subclasses */
#define ACC_STATIC        0x0008    /* declared static */
#define ACC_FINAL         0x0010    /* no subclasses allowed (class)
								       no further assignment after initialization (field) */
#define ACC_SUPER         0x0020    /* treat superclass methods specially when invoked by the invokespecial instruction */
#define ACC_SYNCHRONIZED  0x0020    /* invocation is wrapped in a monitor lock (method) */
#define ACC_VOLATILE      0x0040    /* cannot be cached */
#define ACC_TRANSIENT     0x0080    /* not written or read by a persistent object manager */
#define ACC_NATIVE        0x0100    /* implemented in a language other than Java */
#define ACC_INTERFACE     0x0200    /* is an interface, not a class */
#define ACC_ABSTRACT      0x0400    /* may not be instantiated (class)
                                       no implementation is provided (method) */
#define ACC_STRICT        0x0800    /* floating-point mode is FP-strict */

/* VM specific */
#define ACC_FREEMEM      0x10000    /* release memory occupied by class definition (class) */
                                    /* release memory occupied by object data (object) */
#define ACC_RESOLVED     0x20000    /* is resolved? (class) */
#define ACC_INITED       0x40000    /* is initialized? (class) */
#define ACC_PROXY        0x80000    /* is proxy? (class) */
#define ACC_FINDDEP     0x100000    /* dependencies must be found (class) */

/* constant pool tag meaning */
#define CONSTANT_Utf8                 1
#define CONSTANT_Integer              3
#define CONSTANT_Float                4
#define CONSTANT_Long                 5
#define CONSTANT_Double               6
#define CONSTANT_Class                7
#define CONSTANT_String               8
#define CONSTANT_FieldRef             9
#define CONSTANT_MethodRef           10
#define CONSTANT_InterfaceMethodRef  11
#define CONSTANT_NameAndType         12


/* constant pool definition structure */
typedef struct _clsConstPool {
	jbyte tag;
	void *p, *q;
	jint i, j;
} clsConstPool;


/* attribute definition structure */
typedef struct _clsAttribute {
	char *name;                    /* name UTF-8 string */
	jint len;                      /* data length */
	jbyte *data;
} clsAttribute;


/* field definition structure */
struct _clsDefinition;
typedef struct _jfieldID_struct {
	struct _clsDefinition *clsdef;
	jushort access_flags;
	char *name;                    /* name UTF-8 string */
	char *descriptor;              /* descriptor UTF-8 string */
	jint hash;                     /* name hash */
	jushort attributes_count;
	clsAttribute *attributes;
	/* VM internal affairs */
	jint data_off;                 /* field data offset */
	jclass vartype;                /* field value class */
	jvalue val;                    /* current static field value buffer */
} clsField;

typedef struct _exception_table {
	jushort start_pc;
    jushort end_pc;
	jushort handler_pc;
	jushort catch_type;
} exception_table;

typedef struct _line_number_table {
	jushort start_pc;	     
	jushort line_number;	     
} line_number_table;

/* method definition structure */
typedef struct _methodID_struct {
	struct _clsDefinition *clsdef;
	jushort access_flags;
	char *name;                    /* name UTF-8 string */
	char *descriptor;              /* descriptor UTF-8 string */
	jint hash;                     /* name hash */
	jint code_len;                 /* Java byte-code length */
	void *code;                    /* Java byte-code or native function */
	jushort vars_count;            /* number of the local variables */
	jushort max_operand_stack;     /* maximum operand stack */
	jushort attributes_count;
	clsAttribute *attributes;
	/* VM internal affairs */
	jshort parameters_count;       /* number of the parameters */
	jshort parameters_stack_size;  /* parameters stack size [VM_STACK_SLOT_TYPE] */
	char return_type;              /* return value type */
	/* bytecode specific */
	jint exceptions_count;         /* number of the method exception handlers */
	exception_table *exceptions;   /* method exception handlers table */
	jint lines_count;              /* number of the method line numbers */
	line_number_table *lines;      /* method line numbers table */
} clsMethod;


/* class definition structure */
struct _vmJavaVM;
typedef struct _clsDefinition {
	jushort minor_version;
	jushort major_version;
	char *name;                    /* name UTF-8 string */
	struct _clsDefinition *super_class;
	jint hash;                     /* name hash */
	jushort constant_pool_count;
	clsConstPool *constant_pool;
	jint access_flags;
	jushort interfaces_count;
	struct _clsDefinition **interfaces;
	jushort class_fields_count;
	clsField *class_fields;        /* static fields */
	jushort instance_fields_count;
	clsField *instance_fields;     /* instance fields */
	jushort class_methods_count;
	clsMethod **class_methods;     /* static methods */
	jushort instance_methods_count;
	clsMethod **instance_methods;  /* instance methods */
	jushort attributes_count;
	clsAttribute *attributes;
	jint fields_data_size;         /* data size of this class only */
	jint total_data_size;          /* total data size (with super classes) */
	jmethodID finalizeID;          /* finalize() method */
	/* VM internal affairs */
	jushort element_size;          /* primitive array element size */
	struct _vmJavaVM *vm;          /* owner of the class definition */
} clsDefinition;


extern clsDefinition clsJAVA_LANG_CLASS;
#include "vm.h"


/* instance data */
typedef struct _JavaLangClassIData {
	clsDefinition* _clsdef;        /* class definition */
	jobject _classloader;          /* class loader for the class */
	jshort _dim;                   /* array dimension */
} JavaLangClassIData;
#define VM_CLASS_DEF(c) (*((clsDefinition**)(c)->data))
#define VM_CLASS_LOADER(c) (((JavaLangClassIData*)((c)->data))->_classloader)
#define VM_CLASS_DIM(c) (((JavaLangClassIData*)((c)->data))->_dim)
/* class definition dependent upon class dimension */
#define VM_CLASS_DEF_DIM(c) ((VM_CLASS_DIM(c) == 0) ? VM_CLASS_DEF(c) : &clsJAVA_LANG_OBJECT_ARRAY)


/* static methods */
jclass JNICALL Java_java_lang_Class_forName1(JNIEnv *env, jclass _clazz, jstring name);
jclass JNICALL Java_java_lang_Class_forName2(JNIEnv *env, jclass _clazz, jstring name, jboolean init, jobject loader);


/* instance methods */
jboolean JNICALL Java_java_lang_Class_desiredAssertionStatus(JNIEnv *env, jobject _this);
jarray JNICALL Java_java_lang_Class_getClasses(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getClassLoader(JNIEnv *env, jobject _this);
jclass JNICALL Java_java_lang_Class_getComponentType(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getConstructor(JNIEnv *env, jobject _this, jarray argTypes);
jarray JNICALL Java_java_lang_Class_getConstructors(JNIEnv *env, jobject _this);
jarray JNICALL Java_java_lang_Class_getDeclaredClasses(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getDeclaredConstructor(JNIEnv *env, jobject _this, jarray argTypes);
jarray JNICALL Java_java_lang_Class_getDeclaredConstructors(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getDeclaredField(JNIEnv *env, jobject _this, jstring name);
jarray JNICALL Java_java_lang_Class_getDeclaredFields(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getDeclaredMethod(JNIEnv *env, jobject _this, jstring name, jarray argTypes);
jarray JNICALL Java_java_lang_Class_getDeclaredMethods(JNIEnv *env, jobject _this);
jclass JNICALL Java_java_lang_Class_getDeclaringClass(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getField(JNIEnv *env, jobject _this, jstring name);
jarray JNICALL Java_java_lang_Class_getFields(JNIEnv *env, jobject _this);
jarray JNICALL Java_java_lang_Class_getInterfaces(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getMethod(JNIEnv *env, jobject _this, jstring name, jarray argTypes);
jarray JNICALL Java_java_lang_Class_getMethods(JNIEnv *env, jobject _this);
jint JNICALL Java_java_lang_Class_getModifiers(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_Class_getName(JNIEnv *env, jclass _this);
jobject JNICALL Java_java_lang_Class_getPackage(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getProtectionDomain(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_getResource(JNIEnv *env, jobject _this, jstring name);
jobject JNICALL Java_java_lang_Class_getResourceAsStream(JNIEnv *env, jobject _this, jstring name);
jarray JNICALL Java_java_lang_Class_getSigners(JNIEnv *env, jobject _this);
jclass JNICALL Java_java_lang_Class_getSuperclass(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Class_isArray(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Class_isAssignableFrom(JNIEnv *env, jobject _this, jclass cls);
jboolean JNICALL Java_java_lang_Class_isInstance(JNIEnv *env, jobject _this, jobject obj);
jboolean JNICALL Java_java_lang_Class_isInterface(JNIEnv *env, jobject _this);
jboolean JNICALL Java_java_lang_Class_isPrimitive(JNIEnv *env, jobject _this);
jobject JNICALL Java_java_lang_Class_newInstance(JNIEnv *env, jobject _this);
jstring JNICALL Java_java_lang_Class_toString(JNIEnv *env, jobject _this);


/* support methods */
jstring JNICALL Java_java_lang_Class_getCanonicalName(JNIEnv *env, jclass _this);
jstring JNICALL Java_java_lang_Class_getSimpleName(JNIEnv *env, jclass _this);


/* primitive types */
extern clsDefinition clsVOID;
extern clsDefinition clsBOOLEAN;
extern clsDefinition clsBYTE;
extern clsDefinition clsCHAR;
extern clsDefinition clsSHORT;
extern clsDefinition clsINT;
extern clsDefinition clsLONG;
extern clsDefinition clsFLOAT;
extern clsDefinition clsDOUBLE;


/* java.lang.reflect.Member constants */
#define CONST_MEMBER_PUBLIC     0
#define CONST_MEMBER_DECLARED   1


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_CLASS_H_ */
