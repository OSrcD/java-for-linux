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
#include "Errors.h"
#include "Runtime.h"
#include "String.h"
#include "System.h"


/* =============================================================== */
/*  class fields                                                   */
/* =============================================================== */

static clsField class_fields[] = {
	{&clsJAVA_LANG_RUNTIME, ACC_PRIVATE|ACC_FINAL|ACC_STATIC, "_runtime", "Ljava/lang/Runtime;", 0x550a8c3a, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
};


/* =============================================================== */
/*  class methods                                                  */
/* =============================================================== */

static clsMethod Java_java_lang_Runtime_getRuntimeID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "getRuntime", "()Ljava/lang/Runtime;",
	   0x56e2a7a0, 0, Java_java_lang_Runtime_getRuntime, 0, 0, 0, NULL, /* VM internal affairs */ 0, 0, 'L'};
jobject JNICALL Java_java_lang_Runtime_getRuntime(JNIEnv *env, jclass clazz) {
	jfieldID fld = vmGetClassField(VM_CLASS_DEF(clazz), "_runtime", "Ljava/lang/Runtime;", JNI_TRUE);
	if (fld->val.l == NULL)
		JNINEWGLOBALREF(env, fld->val.l = vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_RUNTIME, 0, 0, 0));
	return fld->val.l;
}


static clsMethod Java_java_lang_Runtime_runFinalizersOnExitID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_STATIC|ACC_NATIVE, "runFinalizersOnExit", "(Z)V",
	   0xd8dfa5f8, 0, Java_java_lang_Runtime_runFinalizersOnExit, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'V'};
void JNICALL Java_java_lang_Runtime_runFinalizersOnExit(JNIEnv *env, jclass clazz, jboolean value) {
}


/* =============================================================== */
/*  instance methods                                               */
/* =============================================================== */

static clsMethod Java_java_lang_Runtime_addShutdownHookID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "addShutdownHook", "(Ljava/lang/Thread;)V", 
	   0xcfed22bc, 0, Java_java_lang_Runtime_addShutdownHook, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Runtime_addShutdownHook(JNIEnv *env, jobject _this, jobject hook) {
}


static clsMethod Java_java_lang_Runtime_availableProcessorsID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "availableProcessors", "()I", 
	   0xf6e91ea2, 0, Java_java_lang_Runtime_availableProcessors, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_Runtime_availableProcessors(JNIEnv *env, jobject _this) {
	return 1;
}


static clsMethod Java_java_lang_Runtime_exec1ID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "exec", "(Ljava/lang/String;)Ljava/lang/Process;", 
	   0x9d51c0c4, 0, Java_java_lang_Runtime_exec1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_Runtime_exec1(JNIEnv *env, jobject _this, jstring command) {
	return NULL;
}


static clsMethod Java_java_lang_Runtime_exec2ID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "exec", "([Ljava/lang/String;)Ljava/lang/Process;", 
	   0x4572e5b1, 0, Java_java_lang_Runtime_exec2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_Runtime_exec2(JNIEnv *env, jobject _this, jarray cmdarray) {
	return NULL;
}


static clsMethod Java_java_lang_Runtime_exec3ID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "exec", "([Ljava/lang/String;[Ljava/lang/String;)Ljava/lang/Process;", 
	   0x3223b6ba, 0, Java_java_lang_Runtime_exec3, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_Runtime_exec3(JNIEnv *env, jobject _this, jarray cmdarray, jarray envp) {
	return NULL;
}


static clsMethod Java_java_lang_Runtime_exec4ID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "exec", "([Ljava/lang/String;[Ljava/lang/String;Ljava/io/File;)Ljava/lang/Process;", 
	   0x7956c7b3, 0, Java_java_lang_Runtime_exec4, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'L'};
jobject JNICALL Java_java_lang_Runtime_exec4(JNIEnv *env, jobject _this, jarray cmdarray, jarray envp, jobject dir) {
	return NULL;
}


static clsMethod Java_java_lang_Runtime_exec5ID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "exec", "(Ljava/lang/String;[Ljava/lang/String;)Ljava/lang/Process;", 
	   0x8247cc47, 0, Java_java_lang_Runtime_exec5, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_Runtime_exec5(JNIEnv *env, jobject _this, jstring cmd, jarray envp) {
	return NULL;
}


static clsMethod Java_java_lang_Runtime_exec6ID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "exec", "(Ljava/lang/String;[Ljava/lang/String;Ljava/io/File;)Ljava/lang/Process;", 
	   0x6a94e61c, 0, Java_java_lang_Runtime_exec6, 0, 0, 0, NULL, /* VM internal affairs */ 3, 4, 'L'};
jobject JNICALL Java_java_lang_Runtime_exec6(JNIEnv *env, jobject _this, jstring command, jarray envp, jobject dir) {
	return NULL;
}


static clsMethod Java_java_lang_Runtime_exitID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "exit", "(I)V", 
	   0x3cff30, 0, Java_java_lang_Runtime_exit, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Runtime_exit(JNIEnv *env, jobject _this, jint status) {

	// zatim, nez bude dodelana tato fce
	Java_java_lang_Runtime_halt(env, _this, status);

}


static clsMethod Java_java_lang_Runtime_freeMemoryID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "freeMemory", "()J", 
	   0xbf90a5e4, 0, Java_java_lang_Runtime_freeMemory, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'J'};
jlong JNICALL Java_java_lang_Runtime_freeMemory(JNIEnv *env, jobject _this) {
	return 0;
}


static clsMethod Java_java_lang_Runtime_gcID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "gc", "()V", 
	   0x97a9, 0, Java_java_lang_Runtime_gc, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Runtime_gc(JNIEnv *env, jobject _this) {
	vmGC(((vmJNIEnv*)env)->vm);
}


static clsMethod Java_java_lang_Runtime_haltID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "halt", "(I)V", 
	   0x23866f, 0, Java_java_lang_Runtime_halt, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Runtime_halt(JNIEnv *env, jobject _this, jint status) {
	exit(status);
}


static clsMethod Java_java_lang_Runtime_loadID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "load", "(Ljava/lang/String;)V", 
	   0xaae17519, 0, Java_java_lang_Runtime_load, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Runtime_load(JNIEnv *env, jobject _this, jstring filename) {
	void *h; vmJavaVM *vm;
	vm = ((vmJNIEnv*)env)->vm;
	if (vm->lib_count >= VM_MAX_LIBRARIES_COUNT) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNSATISFIEDLINKERROR.name), "native library limit exceeded");
		return;
	}
	h = vmLoadLibrary(VM_STRING(filename));
	if (h == NULL) {
		char fname[2*VM_MAX_PATH_LEN];
		toUtf8(fname, VM_STRING(filename), -1);
		vmStrCatUTF(fname, " [not found]");
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNSATISFIEDLINKERROR.name), fname);
	} else {
		jint ver, i;
		jint (JNICALL *JNI_OnLoad)(JavaVM *, void *);

		/* already loaded? */
		for (i = 0; i < vm->lib_count; i++)
			if (vm->lib[i] == h) {
				vmFreeLibrary(h);
				return;
			}

		/* add to native library list */
		JNI_OnLoad = (jint (JNICALL*)(JavaVM *, void *))vmGetProcAddressUTF(h, "_JNI_OnLoad@8");
		ver = (JNI_OnLoad == NULL) ? JNI_VERSION_1_1 : JNI_OnLoad((JavaVM*)vm, NULL);
		if ((ver == JNI_VERSION_1_1) || (ver == JNI_VERSION_1_2)) {
			VM_ENTER_CRITICAL_SECTION(vm->gcs);
			vm->lib[vm->lib_count++] = h;
			VM_LEAVE_CRITICAL_SECTION(vm->gcs);
		} else {
			char fname[2 * VM_MAX_PATH_LEN];
			vmFreeLibrary(h);
			toUtf8(fname, VM_STRING(filename), -1);
			vmStrCatUTF(fname, " [not supported version]");
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_UNSATISFIEDLINKERROR.name), fname);
		}
	}
}


static clsMethod Java_java_lang_Runtime_loadLibraryID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "loadLibrary", "(Ljava/lang/String;)V",
	   0x4184790a, 0, Java_java_lang_Runtime_loadLibrary, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Runtime_loadLibrary(JNIEnv *env, jobject _this, jstring libname) {
	jstring filename = jniCallStaticObjectMethod(env, jniFindClass(env, clsJAVA_LANG_SYSTEM.name), 
		vmGetClassMethod(&clsJAVA_LANG_SYSTEM, "mapLibraryName", "(Ljava/lang/String;)Ljava/lang/String;", JNI_FALSE),
		libname);
	Java_java_lang_Runtime_load(env, _this, filename);
}


static clsMethod Java_java_lang_Runtime_maxMemoryID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "maxMemory", "()J", 
	   0xd28828ec, 0, Java_java_lang_Runtime_maxMemory, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'J'};
jlong JNICALL Java_java_lang_Runtime_maxMemory(JNIEnv *env, jobject _this) {
	return 0;
}


static clsMethod Java_java_lang_Runtime_removeShutdownHookID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "removeShutdownHook", "(Ljava/lang/Thread;)Z", 
	   0xe0baee57, 0, Java_java_lang_Runtime_removeShutdownHook, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_Runtime_removeShutdownHook(JNIEnv *env, jobject _this, jobject hook) {
	return JNI_FALSE;
}


static clsMethod Java_java_lang_Runtime_runFinalizationID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "runFinalization", "()V", 
	   0x6766b32c, 0, Java_java_lang_Runtime_runFinalization, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Runtime_runFinalization(JNIEnv *env, jobject _this) {
}


static clsMethod Java_java_lang_Runtime_totalMemoryID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "totalMemory", "()J", 
	   0xc9169a0c, 0, Java_java_lang_Runtime_totalMemory, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'J'};
jlong JNICALL Java_java_lang_Runtime_totalMemory(JNIEnv *env, jobject _this) {
	return 0;
}


static clsMethod Java_java_lang_Runtime_traceInstructionsID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "traceInstructions", "(Z)V", 
	   0xb564ae75, 0, Java_java_lang_Runtime_traceInstructions, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Runtime_traceInstructions(JNIEnv *env, jobject _this, jboolean on) {
}


static clsMethod Java_java_lang_Runtime_traceMethodCallsID = {&clsJAVA_LANG_RUNTIME, ACC_PUBLIC|ACC_NATIVE, "traceMethodCalls", "(Z)V",
	   0x3f3c9b10, 0, Java_java_lang_Runtime_traceMethodCalls, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Runtime_traceMethodCalls(JNIEnv *env, jobject _this, jboolean on) {
}


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsMethod* class_methods[] = {
	&Java_java_lang_Runtime_getRuntimeID,
	&Java_java_lang_Runtime_runFinalizersOnExitID
};

static clsMethod* instance_methods[] = {
	&Java_java_lang_Runtime_addShutdownHookID,
	&Java_java_lang_Runtime_availableProcessorsID,
	&Java_java_lang_Runtime_exec1ID,
	&Java_java_lang_Runtime_exec2ID,
	&Java_java_lang_Runtime_exec3ID,
	&Java_java_lang_Runtime_exec4ID,
	&Java_java_lang_Runtime_exec5ID,
	&Java_java_lang_Runtime_exec6ID,
	&Java_java_lang_Runtime_exitID,
	&Java_java_lang_Runtime_freeMemoryID,
	&Java_java_lang_Runtime_gcID,
	&Java_java_lang_Runtime_haltID,
	&Java_java_lang_Runtime_loadID,
	&Java_java_lang_Runtime_loadLibraryID,
	&Java_java_lang_Runtime_maxMemoryID,
	&Java_java_lang_Runtime_removeShutdownHookID,
	&Java_java_lang_Runtime_runFinalizationID,
	&Java_java_lang_Runtime_totalMemoryID,
	&Java_java_lang_Runtime_traceInstructionsID,
	&Java_java_lang_Runtime_traceMethodCallsID
};

clsDefinition clsJAVA_LANG_RUNTIME = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/Runtime",           /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0xC387F764,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_FINAL + ACC_SUPER, /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	sizeof(class_fields) / sizeof(clsField), /* class_fields_count */
	class_fields,                  /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	sizeof(class_methods) / sizeof(clsMethod*), /* class_methods_count */
	class_methods,                 /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,              /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};