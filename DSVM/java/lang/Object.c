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
#include "Object.h"


/* =============================================================== */
/*  Instance methods                                               */
/* =============================================================== */

static clsMethod Java_java_lang_Object_ObjectID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6c5e9907, 0, Java_java_lang_Object_Object, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Object_Object(JNIEnv *env, jobject _this) {
}


static clsMethod Java_java_lang_Object_cloneID = {&clsJAVA_LANG_OBJECT, ACC_PROTECTED|ACC_NATIVE, "clone", "()Ljava/lang/Object;", 
	   0x84a9e900, 0, Java_java_lang_Object_clone, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jobject	JNICALL Java_java_lang_Object_clone(JNIEnv *env, jobject _this) {
	return _this;
}


static clsMethod Java_java_lang_Object_equalsID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "equals", "(Ljava/lang/Object;)Z",
	   0xef9a07aa, 0, Java_java_lang_Object_equals, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_Object_equals(JNIEnv *env, jobject _this, jobject obj) {
	return (_this == obj) ? JNI_TRUE : JNI_FALSE;
}


static clsMethod Java_java_lang_Object_getClassID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "getClass", "()Ljava/lang/Class;",
	   0x8c39ede0, 0, Java_java_lang_Object_getClass, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jclass JNICALL Java_java_lang_Object_getClass(JNIEnv *env, jobject _this) {
	return jniGetObjectClass(env, _this);
}


clsMethod Java_java_lang_Object_hashCodeID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "hashCode", "()I",
	   0x8cd3773, 0, Java_java_lang_Object_hashCode, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_Object_hashCode(JNIEnv *env, jobject _this) {
	return (jint)_this;
}


static clsMethod Java_java_lang_Object_notifyID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "notify", "()V",
	   0xc2070c3c, 0, Java_java_lang_Object_notify, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Object_notify(JNIEnv *env, jobject _this) {
	VM_ENTER_CRITICAL_SECTION(((vmJNIEnv*)env)->vm->gcs);
	if (VM_IS_EVENT_CREATED(_this->wait_event)) {
		_this->flags |= VM_OBJECT_NOTIFY_FLAG;
		_this->flags &= ~VM_OBJECT_NOTIFYALL_FLAG;
		VM_SET_EVENT(_this->wait_event);
	}
	VM_LEAVE_CRITICAL_SECTION(((vmJNIEnv*)env)->vm->gcs);
}


static clsMethod Java_java_lang_Object_notifyAllID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "notifyAll", "()V",
	   0x715fa2ed, 0, Java_java_lang_Object_notifyAll, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Object_notifyAll(JNIEnv *env, jobject _this) {
	VM_ENTER_CRITICAL_SECTION(((vmJNIEnv*)env)->vm->gcs);
	if (VM_IS_EVENT_CREATED(_this->wait_event)) {
		_this->flags |= VM_OBJECT_NOTIFYALL_FLAG;
		VM_SET_EVENT(_this->wait_event);
	}
	VM_LEAVE_CRITICAL_SECTION(((vmJNIEnv*)env)->vm->gcs);
}


static clsMethod Java_java_lang_Object_toStringID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "toString", "()Ljava/lang/String;",
	   0xe5d943a7, 0, Java_java_lang_Object_toString, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Object_toString(JNIEnv *env, jobject _this) {
	char buf[VM_MAX_PATH_LEN];
	if (_this == NULL)
		vmStrCpyUTF(buf, "null");
	else {
		clsDefinition *cls = _this->clsdef;
		int isObject = _this->clsdef->name[1] != 0, dim = _this->dim;
		jint hash = jniCallIntMethodV(env, _this, &Java_java_lang_Object_hashCodeID, NULL);
		char *buf2 = buf; while (dim--) *(buf2++) = '[';
		vmSprintfUTF(buf2, "%s%s%s@%08x", 
			isObject ? "L" : "",
			_this->clsdef->name, 
			isObject ? ";" : "",
			hash
		);
		while (*buf2) {
			if (*buf2 == '/') *buf2 = '.';
			buf2++;
		}
	}
	return jniNewStringUTF(env, buf);
}


static clsMethod Java_java_lang_Object_waitID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "wait", "()V",
	   0x370a00, 0, Java_java_lang_Object_wait0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Object_wait0(JNIEnv *env, jobject _this) {
	Java_java_lang_Object_wait2(env, _this, JLONG(0), 0);
}


static clsMethod Java_java_lang_Object_wait1ID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "wait", "(J)V",
	   0x24d89a, 0, Java_java_lang_Object_wait1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1 + VM_STACK_SLOT_LONG_SIZE, 'V'};
void JNICALL Java_java_lang_Object_wait1(JNIEnv *env, jobject _this, jlong timeout) {
	Java_java_lang_Object_wait2(env, _this, timeout, 0);
}


static clsMethod Java_java_lang_Object_wait2ID = {&clsJAVA_LANG_OBJECT, ACC_PUBLIC|ACC_NATIVE, "wait", "(JI)V",
	   0x261f781, 0, Java_java_lang_Object_wait2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 2 + VM_STACK_SLOT_LONG_SIZE, 'V'};
void JNICALL Java_java_lang_Object_wait2(JNIEnv *env, jobject _this, jlong timeout, jint nanos) {
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm;
	if (timeout == 0) timeout = -1;
	/* release monitor */
	jniMonitorExit(env, _this);
	VM_ENTER_CRITICAL_SECTION(vm->gcs);
	while (1) {
		/* create wait event */
		if (!VM_IS_EVENT_CREATED(_this->wait_event))
			VM_CREATE_EVENT(_this->wait_event);
		/* wait */
		VM_LEAVE_CRITICAL_SECTION(vm->gcs);
		if (VM_WAIT_FOR_EVENT(_this->wait_event, timeout))
			goto DONE;	/* error or timeout elapsed */
		VM_ENTER_CRITICAL_SECTION(vm->gcs);
		/* wait for next notify() or notifyAll()? */
		if (_this->flags & VM_OBJECT_NOTIFYALL_FLAG)
			break;	/* object notifyAll() method invoked */
		if (_this->flags & VM_OBJECT_NOTIFY_FLAG) {
			_this->flags &= ~VM_OBJECT_NOTIFY_FLAG;
			break;	/* object notify() method invoked */
		}
	}
	VM_LEAVE_CRITICAL_SECTION(vm->gcs);
DONE:
	/* wait for monitor */
	jniMonitorEnter(env, _this);
}


/* =============================================================== */
/*  Object class definition                                        */
/* =============================================================== */

static clsMethod* instance_methodsS[] = {
	&Java_java_lang_Object_ObjectID,
	&Java_java_lang_Object_cloneID,
	&Java_java_lang_Object_equalsID,
/*	&Java_java_lang_Object_finalizeID, */
	&Java_java_lang_Object_getClassID,
	&Java_java_lang_Object_hashCodeID,
	&Java_java_lang_Object_notifyID,
	&Java_java_lang_Object_notifyAllID,
	&Java_java_lang_Object_toStringID,
	&Java_java_lang_Object_waitID,
	&Java_java_lang_Object_wait1ID,
	&Java_java_lang_Object_wait2ID
};

clsDefinition clsJAVA_LANG_OBJECT = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/Object",            /* name */
	NULL,                          /* super_class */
	0x7C015A33,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC,                    /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(instance_methodsS) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methodsS,             /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  Object[] fields                                                */
/* =============================================================== */

static clsField instance_fieldsA[] = {
	{&clsJAVA_LANG_OBJECT_ARRAY, ACC_PUBLIC | ACC_FINAL, "length", "I", 0xbe0e3aaf, 0, NULL,
		/* VM internal affairs */ 0, NULL}
};


/* =============================================================== */
/*  Object[] class definition                                      */
/* =============================================================== */

clsDefinition clsJAVA_LANG_OBJECT_ARRAY = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"[java/lang/Object",           /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0x2863448E,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	sizeof(instance_fieldsA) / sizeof(clsField), /* instance_fields_count */
	instance_fieldsA,              /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	0,                             /* instance_methods_count */
	NULL,                          /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(JavaLangObjectArrayIData), /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};