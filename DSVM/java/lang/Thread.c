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
#include "ClassLoader.h"
#include "Exceptions.h"
#include "String.h"
#include "StringBuffer.h"
#include "System.h"
#include "Thread.h"

#ifndef DSVM_LITE
#include "RuntimePermission.h"
#endif


/* =============================================================== */
/*  fields                                                         */
/* =============================================================== */

static clsField class_fields[] = {
	{&clsJAVA_LANG_THREAD, ACC_PUBLIC | ACC_STATIC | ACC_FINAL, "MAX_PRIORITY", "I", 0x6529e76, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_THREAD, ACC_PUBLIC | ACC_STATIC | ACC_FINAL, "MIN_PRIORITY", "I", 0x2299c958, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_THREAD, ACC_PUBLIC | ACC_STATIC | ACC_FINAL, "NORM_PRIORITY", "I", 0x25a9e68e, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_THREAD, ACC_PUBLIC | ACC_STATIC | ACC_FINAL, "_threads", "Ljava/util/Vector;", 0x7476c046, 0, NULL, 
		/* VM internal affairs */ 0, NULL}
};

static clsField instance_fields[] = {
	{&clsJAVA_LANG_THREAD, ACC_PRIVATE, "_name", "Ljava/lang/String;", 0x5755d860, 0, NULL, 0},
	{&clsJAVA_LANG_THREAD, ACC_PRIVATE, "_runnable", "Ljava/lang/Runnable;", 0x8c15ad02, 0, NULL, sizeof(jstring)},
	{&clsJAVA_LANG_THREAD, ACC_PRIVATE, "_group", "Ljava/lang/ThreadGroup;", 0x47b48a06, 0, NULL, 2 * sizeof(jstring)},
	{&clsJAVA_LANG_THREAD, ACC_PRIVATE, "_cl", "Ljava/lang/ClassLoader;", 0x2f7ba838, 0, NULL, 3 * sizeof(jstring)}
};


/* =============================================================== */
/*  class methods                                                  */
/* =============================================================== */

void JNICALL Java_java_lang_Thread_clinit(JNIEnv *env, jclass clazz);
static clsMethod Java_java_lang_Thread_clinitID = {&clsJAVA_LANG_THREAD, ACC_PRIVATE|ACC_STATIC|ACC_NATIVE, "<clinit>", "()V",
	   0x8C1695DC, 0, Java_java_lang_Thread_clinit, 0, 10, 0, NULL, /* VM internal affairs */ 0, 0, 'V'};
static void JNICALL Java_java_lang_Thread_clinit(JNIEnv *env, jclass clazz) {
	clsField *class_fields = VM_CLASS_DEF(clazz)->class_fields;
	class_fields[0].val.i = THREAD_PRIORITY_TIME_CRITICAL;  /* MAX_PRIORITY */
	class_fields[1].val.i = THREAD_PRIORITY_IDLE;           /* MIN_PRIORITY */
	class_fields[2].val.i = THREAD_PRIORITY_NORMAL;         /* NORM_PRIORITY */
}


static clsMethod Java_java_lang_Thread_currentThreadID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "currentThread", "()Ljava/lang/Thread;",
	   0x12f8da11, 0, Java_java_lang_Thread_currentThread, 0, 1, 0, NULL, /* VM internal affairs */  0, 0, 'L'};
/* see to vm_nat.c file for method implementation */


static clsMethod Java_java_lang_Thread_sleep1ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "sleep", "(J)V",
	   0x6946738, 0, Java_java_lang_Thread_sleep1, 0, 1, 0, NULL, /* VM internal affairs */  1, VM_STACK_SLOT_LONG_SIZE, 'V'};
void JNICALL Java_java_lang_Thread_sleep1(JNIEnv *env, jclass _clazz, jlong msec) {
	Java_java_lang_Thread_sleep2(env, _clazz, msec, 0);
}


static clsMethod Java_java_lang_Thread_sleep2ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "sleep", "(JI)V",
	   0x4D14823, 0, Java_java_lang_Thread_sleep2, 0, 10, 0, NULL, /* VM internal affairs */ 2, 1 + VM_STACK_SLOT_LONG_SIZE, 'V'};
void JNICALL Java_java_lang_Thread_sleep2(JNIEnv *env, jclass _clazz, jlong msec, jint nsec) {
	vmSleep((DWORD)msec);
}


/* =============================================================== */
/*  instance methods                                               */
/* =============================================================== */


void JNICALL Java_java_lang_Thread_finalize(JNIEnv *env, jobject _this);
static clsMethod Java_java_lang_Thread_finalizeID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "finalize", "()V", 
	   0xd764476b, 0, Java_java_lang_Thread_finalize, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
/* see to vm_nat.c file for method implementation */


static clsMethod Java_java_lang_Thread_Thread0ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Thread_Thread0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Thread_Thread0(JNIEnv *env, jobject _this) {
	Java_java_lang_Thread_Thread5(env, _this, NULL, NULL, NULL);
}


static clsMethod Java_java_lang_Thread_Thread1ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/Runnable;)V", 
	   0xc8a23b01, 0, Java_java_lang_Thread_Thread1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Thread_Thread1(JNIEnv *env, jobject _this, jobject target) {
	Java_java_lang_Thread_Thread5(env, _this, NULL, target, NULL);
}


static clsMethod Java_java_lang_Thread_Thread2ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/Runnable;Ljava/lang/String;)V", 
	   0xd8510e0f, 0, Java_java_lang_Thread_Thread2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};
void JNICALL Java_java_lang_Thread_Thread2(JNIEnv *env, jobject _this, jobject target, jstring name) {
	Java_java_lang_Thread_Thread5(env, _this, NULL, target, name);
}


static clsMethod Java_java_lang_Thread_Thread3ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Thread_Thread3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Thread_Thread3(JNIEnv *env, jobject _this, jstring name) {
	Java_java_lang_Thread_Thread5(env, _this, NULL, NULL, name);
}


static clsMethod Java_java_lang_Thread_Thread4ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/ThreadGroup;Ljava/lang/Runnable;)V", 
	   0x3ee4315b, 0, Java_java_lang_Thread_Thread4, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};
void JNICALL Java_java_lang_Thread_Thread4(JNIEnv *env, jobject _this, jobject group, jobject target) {
	Java_java_lang_Thread_Thread5(env, _this, group, target, NULL);
}


static clsMethod Java_java_lang_Thread_Thread5ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/ThreadGroup;Ljava/lang/Runnable;Ljava/lang/String;)V", 
	   0x509c46c1, 0, Java_java_lang_Thread_Thread5, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'V'};
void JNICALL Java_java_lang_Thread_Thread5(JNIEnv *env, jobject _this, jobject group, jobject target, jstring name) {
	JavaLangThreadIData *data = (JavaLangThreadIData*)(_this->data);
	data->jvm = (JavaVM*)((vmJNIEnv*)env)->vm;
	data->group = JNINEWGLOBALREF(env, group);
	data->target = JNINEWGLOBALREF(env, target);
	if (data->name == NULL) {
		static jint thrcnt = 0;
		char buf[128]; vmSprintfUTF(buf, "Thread-%u", ++thrcnt);
		data->name = JNINEWGLOBALREF(env, jniNewStringUTF(env, buf));
		jniDeleteLocalRef(env, data->name);
	} else
		data->name = JNINEWGLOBALREF(env, name);
	Java_java_lang_Thread_checkAccess(env, _this);
}


static clsMethod Java_java_lang_Thread_Thread6ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/ThreadGroup;Ljava/lang/Runnable;Ljava/lang/String;J)V", 
	   0x37d8ca03, 0, Java_java_lang_Thread_Thread6, 0, 0, 0, NULL, /* VM internal affairs */ 4, 4 + VM_STACK_SLOT_LONG_SIZE, 'V'};
void JNICALL Java_java_lang_Thread_Thread6(JNIEnv *env, jobject _this, jobject group, jobject target, jstring name, jlong stackSize) {
	Java_java_lang_Thread_Thread5(env, _this, group, target, name);
	VM_THREAD_DATA(_this)->stacksize = stackSize;
}


static clsMethod Java_java_lang_Thread_Thread7ID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/ThreadGroup;Ljava/lang/String;)V", 
	   0xd84ea347, 0, Java_java_lang_Thread_Thread7, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};
void JNICALL Java_java_lang_Thread_Thread7(JNIEnv *env, jobject _this, jobject group, jstring name) {
	Java_java_lang_Thread_Thread5(env, _this, group, NULL, name);
}


static clsMethod Java_java_lang_Thread_checkAccessID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_FINAL|ACC_NATIVE, "checkAccess", "()V",
	   0xe223bf9, 0, Java_java_lang_Thread_checkAccess, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Thread_checkAccess(JNIEnv *env, jobject _this) {
	JavaLangThreadIData *data = (JavaLangThreadIData*)(_this->data);
	jobject sm = Java_java_lang_System_getSecurityManager(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_SYSTEM, 0));
	if (data->fInterrupt) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_SECURITYEXCEPTION.name), "Thread interrupted");
		return;
	}
	if (sm != NULL)
		jniCallVoidMethod(env, sm, vmGetInstanceMethod(sm->clsdef, "checkAccess", "(Ljava/lang/Thread;)V", JNI_TRUE), _this);
}


static clsMethod Java_java_lang_Thread_countStackFramesID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "countStackFrames", "()I",
	   0x50460fd7, 0, Java_java_lang_Thread_countStackFrames, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_Thread_countStackFrames(JNIEnv *env, jobject _this) {
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION.name), "Thread.countStackFrames()");
	return 0;
}


static clsMethod Java_java_lang_Thread_destroyID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "destroy", "()V",
	   0x5cd3048f, 0, Java_java_lang_Thread_destroy, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Thread_destroy(JNIEnv *env, jobject _this) {
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION.name), "Thread.destroy()");
}


static clsMethod Java_java_lang_Thread_getContextClassLoaderID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "getContextClassLoader", "()Ljava/lang/ClassLoader;",
	   0x75024f7d, 0, Java_java_lang_Thread_getContextClassLoader, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jobject JNICALL Java_java_lang_Thread_getContextClassLoader(JNIEnv *env, jobject _this) {
	JavaLangThreadIData *data = (JavaLangThreadIData*)(_this->data);
	jobject sm = Java_java_lang_System_getSecurityManager(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_SYSTEM, 0));
	jobject caller_loader = NULL; vmFrame *frame = ((vmJNIEnv*)env)->frame;
	if (data->classloader == NULL)
		data->classloader = Java_java_lang_ClassLoader_getSystemClassLoader(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_CLASSLOADER, 0));
	while ((caller_loader == NULL) && (frame != NULL)) {
		if (frame->met != NULL) {
			jclass clazz = vmFindClassByDef((vmJNIEnv*)env, frame->met->clsdef, 0);
			if (clazz != NULL) caller_loader = VM_CLASS_LOADER(clazz);
		}
		frame = frame->prev;
	}
#ifndef DSVM_LITE
	if ((sm != NULL) && (caller_loader != NULL)) {
		while ((caller_loader != NULL) && (caller_loader != data->classloader))
			caller_loader = Java_java_lang_ClassLoader_getParent(env, caller_loader);
		if (caller_loader != data->classloader) {
			jobject perm = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_RUNTIMEPERMISSION, 0));
			jstring name = jniNewStringUTF(env, "getClassLoader");
			if (perm != NULL)
				Java_java_lang_RuntimePermission_RuntimePermission1(env, perm, name);
			jniDeleteLocalRef(env, name);
			jniCallVoidMethod(env, sm, vmGetInstanceMethod(sm->clsdef, "checkPermission", "(Ljava/security/Permission;)V", JNI_TRUE), perm);
			jniDeleteLocalRef(env, perm);
			if (jniExceptionOccurred(env)) return NULL;
		}
	}
#endif /* DSVM_LITE */
	return data->classloader;
}


static clsMethod Java_java_lang_Thread_getNameID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "getName", "()Ljava/lang/String;",
	   0x884DF2CA, 0, Java_java_lang_Thread_getName, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Thread_getName(JNIEnv *env, jobject _this) {
	return VM_THREAD_DATA(_this)->name;
}


static clsMethod Java_java_lang_Thread_interruptID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "interrupt", "()V",
	   0x1dfbb516, 0, Java_java_lang_Thread_interrupt, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Thread_interrupt(JNIEnv *env, jobject _this) {
	VM_THREAD_DATA(_this)->fInterrupt = JNI_TRUE;
}


static clsMethod Java_java_lang_Thread_isAliveID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "isAlive", "()Z",
	   0x7A72DEBA, 0, Java_java_lang_Thread_isAlive, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'Z'};
jboolean JNICALL Java_java_lang_Thread_isAlive(JNIEnv *env, jobject _this) {
	return VM_THREAD_DATA(_this)->env != NULL;
}


clsMethod Java_java_lang_Thread_runID = {&clsJAVA_LANG_THREAD, ACC_PROTECTED|ACC_NATIVE, "run", "()V",
	   0x121FE, 0, Java_java_lang_Thread_run, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Thread_run(JNIEnv *env, jobject _this) {
	if (VM_THREAD_DATA(_this)->target != NULL)
		jniCallVoidMethodA(env, _this, &Java_java_lang_Thread_runID, NULL);
}


static clsMethod Java_java_lang_Thread_startID = {&clsJAVA_LANG_THREAD, ACC_PROTECTED|ACC_NATIVE|ACC_SYNCHRONIZED, "start", "()V",
	   0x68A5F17, 0, Java_java_lang_Thread_start, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
/* see to vm_nat.c file for method implementation */


static clsMethod Java_java_lang_Thread_toStringID = {&clsJAVA_LANG_THREAD, ACC_PUBLIC|ACC_NATIVE, "toString", "()Ljava/lang/String;",
	   0xE5D943A7, 0, Java_java_lang_Thread_toString, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Thread_toString(JNIEnv *env, jobject _this) {
	JavaLangThreadIData *data = VM_THREAD_DATA(_this);
	jstring ret = NULL;
	jobject sb = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_STRINGBUFFER, 0));
	if (sb != NULL) {
		Java_java_lang_StringBuffer_StringBuffer2(env, sb, 256);
		Java_java_lang_StringBuffer_append(env, sb, JSTRING("Thread["), 7);
		if (data->group != NULL) {
			jstring tmp = jniCallObjectMethod(env, data->group, vmGetInstanceMethod(data->group->clsdef, "getName", "()V", JNI_TRUE));
			Java_java_lang_StringBuffer_append10(env, sb, tmp);
		}
		Java_java_lang_StringBuffer_append(env, sb, JSTRING("."), 1);
		Java_java_lang_StringBuffer_append10(env, sb, data->name);
		Java_java_lang_StringBuffer_append(env, sb, JSTRING(","), 1);
#ifndef DSVM_LITE
		Java_java_lang_StringBuffer_append7(env, sb, data->priority);
#endif /* DSVM_LITE */
		Java_java_lang_StringBuffer_append(env, sb, JSTRING("]"), 1);
		ret = Java_java_lang_StringBuffer_toString(env, sb);
		jniDeleteLocalRef(env, sb);
	}
    return ret;
}


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsDefinition* interfaces[] = {
	&clsJAVA_LANG_RUNNABLE
};

static clsMethod* class_methods[] = {
	&Java_java_lang_Thread_clinitID,
	&Java_java_lang_Thread_currentThreadID,
	&Java_java_lang_Thread_sleep1ID,
	&Java_java_lang_Thread_sleep2ID
};

static clsMethod* instance_methods[] = {
	&Java_java_lang_Thread_Thread0ID,
	&Java_java_lang_Thread_Thread1ID,
	&Java_java_lang_Thread_Thread2ID,
	&Java_java_lang_Thread_Thread3ID,
	&Java_java_lang_Thread_Thread4ID,
	&Java_java_lang_Thread_Thread5ID,
	&Java_java_lang_Thread_Thread6ID,
	&Java_java_lang_Thread_Thread7ID,
	&Java_java_lang_Thread_checkAccessID,
	&Java_java_lang_Thread_countStackFramesID,
	&Java_java_lang_Thread_destroyID,
	&Java_java_lang_Thread_getContextClassLoaderID,
	&Java_java_lang_Thread_getNameID,
	&Java_java_lang_Thread_interruptID,
	&Java_java_lang_Thread_isAliveID,
	&Java_java_lang_Thread_runID,
	&Java_java_lang_Thread_startID,
	&Java_java_lang_Thread_toStringID,
	&Java_java_lang_Thread_finalizeID
};

clsDefinition clsJAVA_LANG_THREAD = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/Thread",            /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0x84E1C4FE,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	sizeof(class_fields) / sizeof(clsField), /* class_fields_count */
	class_fields,                  /* class_fields */
	sizeof(instance_fields) / sizeof(clsField), /* instance_fields_count */
	instance_fields,               /* instance_fields */
	sizeof(class_methods) / sizeof(clsMethod*), /* class_methods_count */
	class_methods,                 /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,              /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(JavaLangThreadIData),   /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	&Java_java_lang_Thread_finalizeID /* finalize() method */
};