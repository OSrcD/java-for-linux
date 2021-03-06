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
   The Java Native Interface (JNI) implementation. 
   JNI allows Java code interoperate with C, C++ and assembler code.
   @author Dusan Stastny <info@developservice.cz>
*/

#include "config.h"
#include "java\lang\_all.h"

#ifndef EXPORT_INVOCATION_API
#undef JNIEXPORT
#define JNIEXPORT
#endif


/* 4 */
/**
   Returns the JNI version. This implementation supports 1.1 and 1.2 version.
   @param env the JNI interface pointer
   @return the JNI version
*/
jint JNICALL jniGetVersion(JNIEnv *env) { 
	if (env && ((vmJNIEnv*)env)->args)
		return ((vmJNIEnv*)env)->args->version;
	return 0;
}


/* 5 */
/**
   Loads a class from the raw class data. For class loading is called @a defineClass()
   method of the java.lang.ClassLoader class.
   After loading is class registered by VM, but is not resolved.
   Class is resolved before its first useing.
   @param env the JNI interface pointer
   @param loader the class loader assigned to the loaded class
   @param buf the raw class data
   @param bufLen length of the raw class data
   @return loaded class or NULL if an error occurs
   @exception java.lang.ClassFormatError produced by an invalid class
   @exception java.lang.OutOfMemoryError if VM runs out of memory
   @exception java.lang.UnsupportedClassVersionError produced by unacceptable class version
*/
jclass JNICALL jniDefineClass(JNIEnv *env, jobject loader, const jbyte *buf, jsize bufLen) {
	jclass ret;
	jbyteArray Buf;
	Buf = jniNewByteArray(env, bufLen);
	if (Buf == NULL)
		return NULL;
	vmMemCpy(VM_ARRAY_ARRAY(Buf), buf, bufLen);
	ret = Java_java_lang_ClassLoader_defineClass4(env, loader, NULL, Buf, 0, bufLen);
	jniDeleteLocalRef(env, Buf);
	return ret;
}


/* 6 */
/**
   Loads a class from file system. If class is already loaded, returns 
   loaded class else searches directories and jar files specified by the
   @a classpath VM initialization argument.
   For class loading is called @a findClass() method of the system class loader.
   After loading is class registered by VM, but is not resolved.
   Class is resolved before its first useing.
   @param env the JNI interface pointer
   @param name the full class name, packages are delimited by '/' character
   @return loaded class or NULL if an error occurs
   @exception java.lang.ClassFormatError produced by a invalid class
   @exception java.lang.NoClassDefFoundError if class definition was not found
   @exception java.lang.OutOfMemoryError if VM runs out of memory
   @exception java.lang.UnsupportedClassVersionError produced by unacceptable class version
*/
jclass JNICALL jniFindClass(JNIEnv *env, const char *name) {	
	jclass ret; jthrowable cause; jstring Name;
	const char *oname; jint name_len; jchar *p; jshort dim;
	
	if (((vmJNIEnv*)env)->frame == NULL)
		return NULL;
	if (name == NULL)
		goto CLASS_NOT_FOUND;
	
	/* compute dimension */ 
	dim = 0;
	oname = name;
	while (*oname == '[') { 
		dim++; 
		oname++; 
	}
	if (dim > VM_MAX_ARRAY_DIMENSION) 
		goto CLASS_NOT_FOUND;
	name_len = vmStrLenUTF(oname);
	if (name_len > 1)
		if ((oname[0] == 'L') && (oname[name_len - 1] == ';')) {
			oname++; 
			name_len -= 2;
		}
	
	/* is already loaded? */
	ret = vmFindClassByName((vmJNIEnv*)env, oname, name_len, dim);
	if (ret != NULL)
		return ret;

	/* find class */
	Name = jniNewStringUTF(env, name);
	if (Name == NULL) 
		goto CLASS_NOT_FOUND;
	p = VM_STRING(Name); 
	while (*p) { 
		if (*p == '/') *p = '.'; 
		p++; 
	}
	ret = Java_java_lang_SystemClassLoader_findClass(env, ((vmJNIEnv*)env)->vm->loader, Name);
	jniDeleteLocalRef(env, Name);
	if (ret != NULL) 
		return ret;

	/* class was not found */
CLASS_NOT_FOUND:
	cause = jniExceptionOccurred(env);
	if ((cause != NULL) && (cause->clsdef->name == clsJAVA_LANG_NOCLASSDEFFOUNDERROR.name))
		return NULL;
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOCLASSDEFFOUNDERROR.name), name);
	if (jniExceptionOccurred(env) == NULL)
		jniThrow(env, ((vmJNIEnv*)env)->vm->outofmem);
	return NULL;
}


/* 7 */
/**
   Converts a java.lang.reflect.Method or java.lang.reflect.Constructor object to a method ID.
   @param env the JNI interface pointer
   @param method a java.lang.reflect.Method or java.lang.reflect.Constructor object
   @return the method ID or NULL if an error occurs
*/
jmethodID JNICALL jniFromReflectedMethod(JNIEnv *env, jobject method) {
	if (method != NULL)
		if (!vmStrCmpUTF(method->clsdef->name, "java/lang/reflect/Method") ||
				!vmStrCmpUTF(method->clsdef->name, "java/lang/reflect/Constructor"))
		{
			struct {
				jboolean flag;
				jmethodID met;
			} *pom = (void*)(method->data);
			return pom->met;
		}
	return NULL;
}


/* 8 */
/**
   Converts a java.lang.reflect.Field to a field ID.
   @param env the JNI interface pointer
   @param field a java.lang.reflect.Field object
   @return the field ID or NULL if an error occurs
*/
jfieldID JNICALL jniFromReflectedField(JNIEnv *env, jobject field) {
	if (field != NULL)
		if (!vmStrCmpUTF(field->clsdef->name, "java/lang/reflect/Field")) {
			struct {
				jboolean flag;
				jfieldID fld;
			} *pom = (void*)(field->data);
			return pom->fld;
		}
	return NULL;
}


/* 9 */
/**
   Converts a method ID derived from cls to a java.lang.reflect.Method or java.lang.reflect.Constructor object.
   @param env the JNI interface pointer
   @param cls a class or interface
   @param methodID a method ID
   @param isStatic whether the method ID refers to a static method 
   @return the java.lang.reflect.Method or java.lang.reflect.Constructor object or NULL if an error occurs
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject JNICALL jniToReflectedMethod(JNIEnv *env, jclass cls, jmethodID methodID, jboolean isStatic) {
	if (methodID != NULL)
		if (isStatic)
			methodID = vmGetClassMethod(VM_CLASS_DEF_DIM(cls), methodID->name, methodID->descriptor, JNI_TRUE);
		else
			methodID = vmGetInstanceMethod(VM_CLASS_DEF_DIM(cls), methodID->name, methodID->descriptor, JNI_TRUE);
	if (methodID != NULL) {
		jclass clazz = jniFindClass(env, !vmStrCmpUTF(methodID->name, "<init>") ?
			"java/lang/reflect/Constructor" : "java/lang/reflect/Method");
		if (clazz != NULL) {
			jobject ret = jniAllocObject(env, clazz);
			if (ret != NULL) {
				struct {
					jboolean flag;
					jmethodID met;
				} *pom = (void*)(ret->data);
				pom->met = methodID;
			}
			return ret;
		}
	}
	return NULL;
}


/* 10 */
/**
   Returns the superclass of the @a clazz. If the @a clazz not has 
   the superclass, then function returns NULL.
   @param env the JNI interface pointer
   @param clazz a class object
   @return the class object or NULL
*/
jclass JNICALL jniGetSuperclass(JNIEnv *env, jclass clazz) {
	if (clazz != NULL) 
		if (clazz->clsdef == ((vmJNIEnv*)env)->vm->class_clsdef) {
			clsDefinition *cls;
			cls = VM_CLASS_DEF(clazz);
			if (cls != NULL) 
				cls = cls->super_class;
			if (cls != NULL)
				return vmFindClassByDef((vmJNIEnv*)env, cls, VM_CLASS_DIM(clazz));
		}
	return NULL;
}


/* 11 */
/**
   Tests whether an object of @a clazz1 can be cast to @a clazz2.
   @param env the JNI interface pointer
   @param clazz1 a class object
   @param clazz2 a class object
   @return JNI_TRUE if an object of @a clazz1 can be cast to @a clazz2
*/
jboolean JNICALL jniIsAssignableFrom(JNIEnv *env, jclass clazz1, jclass clazz2) {
	jint dim1, dim2; clsDefinition *cls1, *cls2;
	if (!clazz1 || !clazz2) 
		return JNI_FALSE;
	if (clazz1->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef)  /* it is class of current JVM? */
		return JNI_FALSE;
	if (clazz2->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef)  /* it is class of current JVM? */
		return JNI_FALSE;
	dim1 = VM_CLASS_DIM(clazz2); dim2 = VM_CLASS_DIM(clazz1);
	cls1 = VM_CLASS_DEF(clazz2); cls2 = VM_CLASS_DEF(clazz1);
	if (dim1 != dim2) 
		if (!((dim1 == 0) && (cls1->hash == 0x7c015a33) && (cls2->name[1] != 0)))  /* java.lang.Object? */
			return JNI_FALSE;
	return vmIsAssignableFrom(cls1, cls2);
}


/* 12 */
/**
   Converts a field ID derived from cls to a java.lang.reflect.Field object.
   @param env the JNI interface pointer
   @param cls a class or interface
   @param fieldID a field ID
   @param isStatic whether the field ID refers to a static field 
   @return the java.lang.reflect.Field object or NULL if an error occurs
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject JNICALL jniToReflectedField(JNIEnv *env, jclass cls, jfieldID fieldID, jboolean isStatic) {
	if (fieldID != NULL)
		if (isStatic)
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(cls), fieldID->name, fieldID->descriptor, JNI_TRUE);
		else
			fieldID = vmGetInstanceField(VM_CLASS_DEF_DIM(cls), fieldID->name, fieldID->descriptor, JNI_TRUE);
	if (fieldID != NULL) {
		jclass clazz = jniFindClass(env, "java/lang/reflect/Field");
		if (clazz != NULL) {
			jobject ret = jniAllocObject(env, clazz);
			if (ret != NULL) {
				struct {
					jboolean flag;
					jfieldID fld;
				} *pom = (void*)(ret->data);
				pom->fld = fieldID;
			}
			return ret;
		}
	}
	return NULL;
}


/* 13 */
/**
   Causes that throwable object to be thrown.
   @param env the JNI interface pointer
   @param obj a throwable object
   @return JNI_OK if object was thrown succesfuly or an error code
*/
jint JNICALL jniThrow(JNIEnv *env, jthrowable obj) {
	if ((obj != NULL) && (obj->dim == 0))
		if (vmIsAssignableFrom(&clsJAVA_LANG_THROWABLE, obj->clsdef)) {
			Java_java_lang_Throwable_initCause(env, obj, jniExceptionOccurred(env));
			/* set throwable object for the current frame */
			((vmJNIEnv*)env)->frame->exception = obj;
			return JNI_OK;
		}
	return JNI_ERR;
}


/* 14 */
/**
   Causes that new throwable object is created and is being thrown.
   @param env the JNI interface pointer
   @param clazz a throwable subclass object
   @param message the detail message
   @return JNI_OK if new throwable object was thrown succesfuly or an error code
*/
jint JNICALL jniThrowNew(JNIEnv *env, jclass clazz, const char *message) {
	if (clazz != NULL) {
		if (clazz->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef)
			return JNI_EINVAL;
		if (VM_CLASS_DIM(clazz) == 0)
			if (vmIsAssignableFrom(&clsJAVA_LANG_THROWABLE, VM_CLASS_DEF(clazz))) {
				jthrowable obj;
				/* create throwable object */
				obj = vmCreateThrowable((vmJNIEnv*)env, VM_CLASS_DEF(clazz), message);
				/* set exception */
				return jniThrow(env, jniNewLocalRef(env, obj));
			}
	}
	return JNI_ERR;
}


/* 15 */
/**
   Tests if a throwable object is being thrown.
   @param env the JNI interface pointer
   @return the throwable object that is currently being thrown or NULL
*/
jthrowable JNICALL jniExceptionOccurred(JNIEnv *env) {
	return ((vmJNIEnv*)env)->frame->exception;
}


/* 16 */
/**
   Prints current throwable object and its stack traces to the error output stream (stderr).
   @param env the JNI interface pointer
*/
void JNICALL jniExceptionDescribe(JNIEnv *env) {
	jthrowable err;
	err = jniExceptionOccurred(env);
	if (err != NULL)
		jniCallVoidMethod(env, err, &Java_java_lang_Throwable_printStackTrace0ID);
}


/* 17 */
/**
   Clears the throwable object that is currently being thrown.
   @param env the JNI interface pointer
*/
void JNICALL jniExceptionClear(JNIEnv *env) {
	((vmJNIEnv*)env)->frame->exception = NULL;
}


/* 18 */
/**
   Displays message and terminates the program. 
   @param env the JNI interface pointer
   @param msg the detail message
*/
void JNICALL jniFatalError(JNIEnv *env, const char *msg) {
	vmFatalError((vmJNIEnv*)env, msg);
}


/* 19 */
/**
   Creates new local frame on top of the stack.
   @param env the JNI interface pointer
   @param capacity a number of the free slots for local references in the newly created local frame
   @return JNI_OK on success or an error code
*/
#ifdef _DEBUG
	static jint _frame_cnt = 0;
#endif
jint JNICALL jniPushLocalFrame(JNIEnv *env, jint capacity) {
	vmFrame *prev, *frame; 
	VM_STACK_SLOT_TYPE *prev_stack;
	jint prev_stack_top, prev_stack_capacity, ret;
	
#if VM_GC_MARKSWEEP
	natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
	VM_ENTER_CRITICAL_SECTION(gcs);
#endif
	ret = JNI_OK;
	if (capacity < 16)
		capacity = 16;
	prev = ((vmJNIEnv*)env)->frame;
	prev_stack = (prev != NULL) ? prev->stack : ((vmJNIEnv*)env)->stack;
	prev_stack_top = (prev != NULL) ? prev->stack_top : 0;
	prev_stack_capacity = (prev != NULL) ? prev->stack_capacity : ((vmJNIEnv*)env)->stack_capacity;
	
	/* alloc new frame */
	if (prev != NULL)
		frame = (vmFrame*)((VM_STACK_SLOT_TYPE*)prev->refs + prev->refs_capacity);
	else
		frame = (vmFrame*)((vmJNIEnv*)env)->frame_buf;
	if ((((VM_STACK_SLOT_TYPE*)frame) + VM_STACK_SLOT_FRAME_SIZE + capacity + 16) > (((vmJNIEnv*)env)->frame_buf + ((vmJNIEnv*)env)->frame_capacity)) {
		ret = JNI_ENOMEM;
		goto DONE;
	}

	/* set new frame */
#ifdef _DEBUG
	vmMemSetZero(frame, (VM_STACK_SLOT_FRAME_SIZE + capacity) * sizeof(VM_STACK_SLOT_TYPE));
#else
	frame->refs_top = frame->stack_top = 0;
	frame->exception = NULL;
	frame->met = NULL;
#endif
	frame->env = (vmJNIEnv*)env;
	frame->prev = prev;
	frame->refs_capacity = capacity;
	frame->refs = ((VM_STACK_SLOT_TYPE*)frame) + VM_STACK_SLOT_FRAME_SIZE;
	frame->stack_capacity = prev_stack_capacity - prev_stack_top;
	frame->stack = prev_stack + prev_stack_top;
	((vmJNIEnv*)env)->frame = frame;

DONE:
#if VM_GC_MARKSWEEP
	VM_LEAVE_CRITICAL_SECTION(gcs);
#endif
	return ret;
}


/* 20 */
/**
   Frees current local frame with all its local references and 
   returns a @a result object local reference in the previous local frame.
   @param env the JNI interface pointer
   @param result an object
   @return the @a result object local reference in the previous local frame
*/
jobject JNICALL jniPopLocalFrame(JNIEnv *env, jobject result) {
	jboolean move_ref;
	vmFrame *frame, *prev;
	jobject exception;

#if VM_GC_MARKSWEEP
	natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
	VM_ENTER_CRITICAL_SECTION(gcs);
#endif
	move_ref = JNI_FALSE;
	frame = ((vmJNIEnv*)env)->frame;
	prev = frame->prev;
	exception = frame->exception;
	
	/* current exception must not be deleted */
	if ((exception != NULL) && (prev != NULL))
		JNINEWGLOBALREF(env, exception);

	/* delete local variables */
 	while (frame->refs_top > 0) {
		jobject lref;
		lref = frame->refs[--(frame->refs_top)];
		if ((lref == result) && !move_ref)
			move_ref = (result != NULL);
		else
			JNIDELETEGLOBALREF(env, lref);
	}
	
	/* set previous frame to environment */
	((vmJNIEnv*)env)->frame = prev;
	if ((exception != NULL) && (prev != NULL)) {
		jniDeleteLocalRef(env, prev->exception);
		jniNewLocalRef(env, exception);
		prev->exception = exception;
		JNIDELETEGLOBALREF(env, exception);
	}
	
	/* returns result in the previous local reference frame */
	if (move_ref != JNI_FALSE) {
		jniNewLocalRef(env, result);
		JNIDELETEGLOBALREF(env, result);
	}

#if VM_GC_MARKSWEEP
	VM_LEAVE_CRITICAL_SECTION(gcs);
#endif
	return result;
}


/* 21 */
/**
   Returns a new global reference to the object.
   Returned reference must be explicitly deleted by the jniDeleteGlobalRef() function.
   @param env the JNI interface pointer
   @param ref a global or local reference
   @return the new global reference
*/
jobject JNICALL jniNewGlobalRef(JNIEnv *env, jobject ref) {
#if VM_GC_REFERENCECOUNTING
	if (ref != NULL) {
		natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
		/* increment object reference counter */
		VM_ENTER_CRITICAL_SECTION(gcs);
		ref->cnt++;
		VM_LEAVE_CRITICAL_SECTION(gcs);
	}
#endif
	return ref;
}


/* 22 */
/**
   Deletes a global reference to the object.
   If this is the last global and local reference to the object, then object is released.
   @param env the JNI interface pointer
   @param gref a global reference
*/
void JNICALL jniDeleteGlobalRef(JNIEnv *env, jobject gref) {
#if VM_GC_REFERENCECOUNTING
	if (gref != NULL) {
		natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
		VM_ENTER_CRITICAL_SECTION(gcs);
		if (!--gref->cnt)
			vmDestroyObject((vmJNIEnv*)env, gref);
		VM_LEAVE_CRITICAL_SECTION(gcs);
	}
#endif
}


/* 23 */
/**
   Deletes a local reference to the object.
   If this is the last global and local reference to the object, then object is released.
   @param env the JNI interface pointer
   @param lref a local reference
*/
void JNICALL jniDeleteLocalRef(JNIEnv *env, jobject lref) {
#if VM_GC_MARKSWEEP
	natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
	VM_ENTER_CRITICAL_SECTION(gcs);
#endif
	if (vmLocal2GlobalRef(((vmJNIEnv*)env)->frame, lref))
		JNIDELETEGLOBALREF(env, lref);
#if VM_GC_MARKSWEEP
	VM_LEAVE_CRITICAL_SECTION(gcs);
#endif
}


/* 24 */
/**
   Tests if @a ref1 and @a ref2 reference to the same object.
   @param env the JNI interface pointer
   @param ref1 a global or local reference
   @param ref2 a global or local reference
   @return JNI_TRUE if @a ref1 and @a ref2 reference to the same object
*/
jboolean JNICALL jniIsSameObject(JNIEnv *env, jobject ref1, jobject ref2) {
	return (ref1 == ref2) ? JNI_TRUE : JNI_FALSE;
}


/* 25 */
/**
   Returns a new local reference to the object.
   Returned reference must be explicitly deleted by the jniDeleteLocalRef() function.
   @param env the JNI interface pointer
   @param ref a global or local reference
   @return the new local reference or NULL if an error occurs
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject JNICALL jniNewLocalRef(JNIEnv *env, jobject ref) {
	if (ref != NULL) {
		vmFrame *frame;
#if VM_GC_MARKSWEEP
	natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
	VM_ENTER_CRITICAL_SECTION(gcs);
#endif
		frame = ((vmJNIEnv*)env)->frame;
		if (frame == NULL) {
			ref = NULL;
			goto DONE;
		}
		if (frame->refs_top >= frame->refs_capacity)
			if (JNI_OK != jniEnsureLocalCapacity(env, frame->refs_capacity + 64))
				if (JNI_OK != jniEnsureLocalCapacity(env, frame->refs_capacity + 8)) {
					ref = NULL;
					goto DONE;
				}
		if (JNINEWGLOBALREF(env, ref) != NULL)
			frame->refs[frame->refs_top++] = ref;
DONE:
#if VM_GC_MARKSWEEP
		VM_LEAVE_CRITICAL_SECTION(gcs);
#endif
	}
	return ref;
}


/* 26 */
/**
   Ensures minimal number of the slots for local references in the current local frame.
   @param env the JNI interface pointer
   @param capacity new minimal number of the slots for local references in the current local frame
   @return JNI_OK on success or an error code
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jint JNICALL jniEnsureLocalCapacity(JNIEnv *env, jint capacity) {
	vmFrame *frame; jint diff, ret;
#if VM_GC_MARKSWEEP
	natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
	VM_ENTER_CRITICAL_SECTION(gcs);
#endif
	ret = JNI_OK;
	frame = ((vmJNIEnv*)env)->frame;
	diff = capacity - frame->refs_capacity;
	if (diff > 0) {
		if ((frame->refs + capacity + 16) > (((vmJNIEnv*)env)->frame_buf + ((vmJNIEnv*)env)->frame_capacity)) {
			jniThrow(env, ((vmJNIEnv*)env)->vm->outofmem);
			ret = JNI_ENOMEM;
			goto DONE;
		}
		frame->refs_capacity += diff;
	}
DONE:
#if VM_GC_MARKSWEEP
	VM_LEAVE_CRITICAL_SECTION(gcs);
#endif
	return ret;
}


/* 27 */
/**
   Returns a new object of the class. This function does not invokes any object's constructor.
   @param env the JNI interface pointer
   @param clazz a class object
   @return a local reference to the new object or NULL if an error occurs
   @exception java.lang.InstantiationException if the @a clazz is an interface or an abstract class
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject JNICALL jniAllocObject(JNIEnv *env, jclass clazz) {
	jobject ret;
	vmJavaVM *vm;
	if (clazz == NULL)
		return NULL;
	vm = ((vmJNIEnv*)env)->vm;
	if (clazz->clsdef != vm->class_clsdef)
		return NULL;
	VM_ENTER_CRITICAL_SECTION(vm->gcs);
	ret = jniNewLocalRef(env, 
		vmCreateObject((vmJNIEnv*)env, VM_CLASS_DEF(clazz), VM_CLASS_DIM(clazz), 0, 0));
	VM_LEAVE_CRITICAL_SECTION(vm->gcs);
	return ret;
}

  
/* 28 */
/**
   Returns a new object of the class. This function invokes an object's constructor.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the constructor ID (constructor is instance method with <I>&lt;init&gt;</I> method name)
   @return a local reference to the new object or NULL if an error occurs
   @exception java.lang.InstantiationException if the @a clazz is an interface or an abstract class
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject JNICALL jniNewObject(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jobject ret;
	va_start(args, methodID);
	ret = jniAllocObject(env, clazz);
	if (ret != NULL)
		jniCallNonvirtualVoidMethodV(env, ret, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 29 */
/**
   Returns a new object of the class. This function invokes an object's constructor.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the constructor ID (constructor is instance method with <I>&lt;init&gt;</I> method name)
   @param args a constructor arguments
   @return a local reference to the new object or NULL if an error occurs
   @exception java.lang.InstantiationException if the @a clazz is an interface or an abstract class
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject JNICALL jniNewObjectV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	jobject ret;
	ret = jniAllocObject(env, clazz);
	if (ret != NULL)
		jniCallNonvirtualVoidMethodV(env, ret, clazz, methodID, args);
	return ret;
}

/* 30 */
/**
   Returns a new object of the class. This function invokes an object's constructor.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the constructor ID (constructor is instance method with <I>&lt;init&gt;</I> method name)
   @param args a constructor arguments
   @return a local reference to the new object or NULL if an error occurs
   @exception java.lang.InstantiationException if the @a clazz is an interface or an abstract class
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject JNICALL jniNewObjectA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	jobject ret;
	ret = jniAllocObject(env, clazz);
	if (ret != NULL)
		jniCallNonvirtualVoidMethodA(env, ret, clazz, methodID, args);
	return ret;
}


/* 31 */
/**
   Returns the class of an object.
   @param env the JNI interface pointer
   @param obj an object
   @return a class object or NULL if class is not found
*/
jclass JNICALL jniGetObjectClass(JNIEnv *env, jobject obj) {
	if (obj != NULL)
		return vmFindClassByDef((vmJNIEnv*)env, obj->clsdef, obj->dim);
	return NULL;
}


/* 32 */
/**
   Tests whether an object can be cast to the class.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @return JNI_TRUE if an object can be cast to the class
*/
jboolean JNICALL jniIsInstanceOf(JNIEnv *env, jobject obj, jclass clazz) {
	jint objdim, clazzdim;
	if (clazz == NULL)
		return JNI_FALSE;
	if (clazz->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef)
		return JNI_FALSE;
	if (obj == NULL)
		return JNI_TRUE;
	objdim = obj->dim; clazzdim = VM_CLASS_DIM(clazz);
	if (vmIsAssignableFrom(VM_CLASS_DEF(clazz), obj->clsdef)) {
		if (clazzdim == objdim) return JNI_TRUE;
		if ((clazzdim == 1) && (objdim > 0)) return JNI_TRUE;
	} else
	/* primitive array to Object? */
	if ((clazzdim <= 1) && (VM_CLASS_DEF(clazz)->name == clsJAVA_LANG_OBJECT.name) &&
			(objdim > 0) && (obj->clsdef->name[1] == 0))
		return JNI_TRUE;
	return JNI_FALSE;
}


/* 33 */
/**
   Searches the instance method of the class, determined by the name and the signature.
   @param env the JNI interface pointer
   @param clazz a class object
   @param name the method name
   @param sig the method signature
   @return the method ID or NULL if the method was not found
*/
jmethodID JNICALL jniGetMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
	if (!env || !clazz || !name || !sig) 
		return NULL;
	if (clazz->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef)
		return NULL;
	return vmGetInstanceMethod(VM_CLASS_DEF_DIM(clazz), name, sig, JNI_TRUE);
}


/* 34 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jobject JNICALL jniCallObjectMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jobject ret;
	va_start(args, methodID);
	ret = jniCallObjectMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 35 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jobject JNICALL jniCallObjectMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0; 
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	/* local reference must remain */
	return VM_POP_OBJECT(frame); 
}


/* 36 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jobject JNICALL jniCallObjectMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0; 
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	/* local reference must remain */
	return VM_POP_OBJECT(frame); 
}


/* 37 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jboolean JNICALL jniCallBooleanMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jboolean ret;
	va_start(args, methodID);
	ret = jniCallBooleanMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 38 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jboolean JNICALL jniCallBooleanMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_BOOLEAN(frame);
}


/* 39 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jboolean JNICALL jniCallBooleanMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0; 
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_BOOLEAN(frame);
}


/* 40 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jbyte JNICALL jniCallByteMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jbyte ret;
	va_start(args, methodID);
	ret = jniCallByteMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 41 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jbyte JNICALL jniCallByteMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_BYTE(frame);
}


/* 42 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jbyte JNICALL jniCallByteMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_BYTE(frame);
}


/* 43 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jchar JNICALL jniCallCharMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jchar ret;
	va_start(args, methodID);
	ret = jniCallCharMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 44 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jchar JNICALL jniCallCharMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_CHAR(frame);
}


/* 45 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jchar JNICALL jniCallCharMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_CHAR(frame);
}


/* 46 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jshort JNICALL jniCallShortMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jshort ret;
	va_start(args, methodID);
	ret = jniCallShortMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 47 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jshort JNICALL jniCallShortMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_SHORT(frame);
}


/* 48 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jshort JNICALL jniCallShortMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_SHORT(frame);
}


/* 49 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jint JNICALL jniCallIntMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jint ret;
	va_start(args, methodID);
	ret = jniCallIntMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 50 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jint JNICALL jniCallIntMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_INT(frame);
}


/* 51 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jint JNICALL jniCallIntMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_INT(frame);
}


/* 52 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jlong JNICALL jniCallLongMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jlong ret;
	va_start(args, methodID);
	ret = jniCallLongMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 53 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jlong JNICALL jniCallLongMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_LONG(frame);
}


/* 54 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jlong JNICALL jniCallLongMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_LONG(frame);
}


/* 55 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jfloat JNICALL jniCallFloatMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jfloat ret;
	va_start(args, methodID);
	ret = jniCallFloatMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 56 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jfloat JNICALL jniCallFloatMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_FLOAT(frame);
}


/* 57 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jfloat JNICALL jniCallFloatMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_FLOAT(frame);
}


/* 58 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jdouble JNICALL jniCallDoubleMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args; jdouble ret;
	va_start(args, methodID);
	ret = jniCallDoubleMethodV(env, obj, methodID, args);
	va_end(args);
	return ret;
}


/* 59 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jdouble JNICALL jniCallDoubleMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_DOUBLE(frame);
}


/* 60 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jdouble JNICALL jniCallDoubleMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL);
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
	return VM_POP_DOUBLE(frame);
}


/* 61 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniCallVoidMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
	va_list args;
	va_start(args, methodID);
	jniCallVoidMethodV(env, obj, methodID, args);
	va_end(args);
}


/* 62 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniCallVoidMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return; 
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
}


/* 63 */
/**
   Calls an instance method based on the object class.
   @param env the JNI interface pointer
   @param obj an object
   @param methodID the instance method ID
   @param args a method arguments
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniCallVoidMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return; 
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeVirtual(frame, methodID);
}


/* 64 */ 
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jobject JNICALL jniCallNonvirtualObjectMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jobject ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualObjectMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 65 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jobject JNICALL jniCallNonvirtualObjectMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	/* local reference must remain */
	return VM_POP_OBJECT(frame); 
}


/* 66 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jobject JNICALL jniCallNonvirtualObjectMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	/* local reference must remain */
	return VM_POP_OBJECT(frame); 
}


/* 67 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jboolean JNICALL jniCallNonvirtualBooleanMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jboolean ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualBooleanMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 68 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jboolean JNICALL jniCallNonvirtualBooleanMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_BOOLEAN(frame);
}


/* 69 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jboolean JNICALL jniCallNonvirtualBooleanMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_BOOLEAN(frame);
}


/* 70 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jbyte JNICALL jniCallNonvirtualByteMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jbyte ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualByteMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 71 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jbyte JNICALL jniCallNonvirtualByteMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_BYTE(frame);
}


/* 72 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jbyte JNICALL jniCallNonvirtualByteMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_BYTE(frame);
}


/* 73 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jchar JNICALL jniCallNonvirtualCharMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jchar ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualCharMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 74 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jchar JNICALL jniCallNonvirtualCharMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_CHAR(frame);
}


/* 75 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jchar JNICALL jniCallNonvirtualCharMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_CHAR(frame);
}


/* 76 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jshort JNICALL jniCallNonvirtualShortMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jshort ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualShortMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 77 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jshort JNICALL jniCallNonvirtualShortMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_SHORT(frame);
}


/* 78 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jshort JNICALL jniCallNonvirtualShortMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_SHORT(frame);
}


/* 79 */ 
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jint JNICALL jniCallNonvirtualIntMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jint ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualIntMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 80 */ 
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jint JNICALL jniCallNonvirtualIntMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_INT(frame);
}


/* 81 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jint JNICALL jniCallNonvirtualIntMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_INT(frame);
}


/* 82 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jlong JNICALL jniCallNonvirtualLongMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jlong ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualLongMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 83 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jlong JNICALL jniCallNonvirtualLongMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_LONG(frame);
}


/* 84 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jlong JNICALL jniCallNonvirtualLongMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_LONG(frame);
}


/* 85 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jfloat JNICALL jniCallNonvirtualFloatMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jfloat ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualFloatMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 86 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jfloat JNICALL jniCallNonvirtualFloatMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_FLOAT(frame);
}


/* 87 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jfloat JNICALL jniCallNonvirtualFloatMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_FLOAT(frame);
}


/* 88 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jdouble JNICALL jniCallNonvirtualDoubleMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args; jdouble ret;
	va_start(args, methodID);
	ret = jniCallNonvirtualDoubleMethodV(env, obj, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 89 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jdouble JNICALL jniCallNonvirtualDoubleMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_DOUBLE(frame);
}


/* 90 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jdouble JNICALL jniCallNonvirtualDoubleMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
	return VM_POP_DOUBLE(frame);
}


/* 91 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniCallNonvirtualVoidMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
	va_list args;
	va_start(args, methodID);
	jniCallNonvirtualVoidMethodV(env, obj, clazz, methodID, args);
	va_end(args);
}


/* 92 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniCallNonvirtualVoidMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
}


/* 93 */
/**
   Calls an instance method based on the @a clazz.
   @param env the JNI interface pointer
   @param obj an object
   @param clazz a class object
   @param methodID the instance method ID
   @param args a method arguments
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if @a obj can not be cast to @a clazz
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniCallNonvirtualVoidMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) { 
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return;
	}
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeSpecial(frame, methodID, clazz);
}


/* 94 */
/**
   Searches the instance field of the class, determined by the name and the signature.
   @param env the JNI interface pointer
   @param clazz a class object
   @param name the field name
   @param sig the field signature
   @return the field ID or NULL if the field was not found
*/
jfieldID JNICALL jniGetFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
	if (!env || !clazz || !name || !sig) return NULL;
	if (clazz->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef)
		return NULL;
	return vmGetInstanceField(VM_CLASS_DEF_DIM(clazz), name, sig, JNI_TRUE);
}


/* 95 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jobject JNICALL jniGetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_OBJECT(frame); 
}


/* 96 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jboolean JNICALL jniGetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_BOOLEAN(frame);
}


/* 97 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jbyte JNICALL jniGetByteField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_BYTE(frame);
}


/* 98 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jchar JNICALL jniGetCharField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_CHAR(frame);
}


/* 99 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jshort JNICALL jniGetShortField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_SHORT(frame);
}


/* 100 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jint JNICALL jniGetIntField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_INT(frame);
}


/* 101 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jlong JNICALL jniGetLongField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_LONG(frame);
}


/* 102 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jfloat JNICALL jniGetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_FLOAT(frame);
}


/* 103 */
/**
   Returns the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @return the field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
jdouble JNICALL jniGetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	err = vmGetField(frame, obj, fieldID);
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_DOUBLE(frame);
}


/* 104 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID, jobject value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_OBJECT(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 105 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID, jboolean value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_BOOLEAN(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 106 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetByteField(JNIEnv *env, jobject obj, jfieldID fieldID, jbyte value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_BYTE(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 107 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetCharField(JNIEnv *env, jobject obj, jfieldID fieldID, jchar value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_CHAR(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 108 */ 
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetShortField(JNIEnv *env, jobject obj, jfieldID fieldID, jshort value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_SHORT(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 109 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetIntField(JNIEnv *env, jobject obj, jfieldID fieldID, jint value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_INT(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 110 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetLongField(JNIEnv *env, jobject obj, jfieldID fieldID, jlong value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_LONG(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 111 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID, jfloat value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_FLOAT(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 112 */
/**
   Sets the instance field value of an object.
   @param env the JNI interface pointer
   @param obj an object
   @param fieldID the instance field ID
   @param value the new field value
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the object is NULL
*/
void JNICALL jniSetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID, jdouble value) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if ((fieldID != NULL) && (fieldID->clsdef->vm != ((vmJNIEnv*)env)->vm))
		fieldID = vmGetInstanceField(VM_CLASS_DEF(vmFindClassByDef((vmJNIEnv*)env, fieldID->clsdef, 0)), fieldID->name, fieldID->descriptor, JNI_FALSE);
	VM_PUSH_OBJECT(frame, obj);
	VM_PUSH_DOUBLE(frame, value);
	err = vmPutField(frame, fieldID);
	if (err != NULL)
		jniThrow(env, err);
}


/* 113 */
/**
   Searches the static method of the class, determined by the name and the signature.
   @param env the JNI interface pointer
   @param clazz a class object
   @param name the method name
   @param sig the method signature
   @return the method ID or NULL if the method was not found
*/
jmethodID JNICALL jniGetStaticMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
	if (!env || !clazz || !name || !sig) 
		return NULL;
	if (clazz->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef) 
		return NULL;
	return vmGetClassMethod(VM_CLASS_DEF_DIM(clazz), name, sig, JNI_TRUE);
}


/* 114 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jobject JNICALL jniCallStaticObjectMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jobject ret;
	va_start(args, methodID);
	ret = jniCallStaticObjectMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 115 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jobject JNICALL jniCallStaticObjectMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_OBJECT(frame); 
}


/* 116 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jobject JNICALL jniCallStaticObjectMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_OBJECT(frame); 
}


/* 117 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jboolean JNICALL jniCallStaticBooleanMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jboolean ret;
	va_start(args, methodID);
	ret = jniCallStaticBooleanMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 118 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jboolean JNICALL jniCallStaticBooleanMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_BOOLEAN(frame);
}


/* 119 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jboolean JNICALL jniCallStaticBooleanMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_BOOLEAN(frame);
}


/* 120 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jbyte JNICALL jniCallStaticByteMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jbyte ret;
	va_start(args, methodID);
	ret = jniCallStaticByteMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 121 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jbyte JNICALL jniCallStaticByteMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_BYTE(frame);
}


/* 122 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jbyte JNICALL jniCallStaticByteMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_BYTE(frame);
}


/* 123 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jchar JNICALL jniCallStaticCharMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jchar ret;
	va_start(args, methodID);
	ret = jniCallStaticCharMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 124 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jchar JNICALL jniCallStaticCharMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_CHAR(frame);
}


/* 125 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jchar JNICALL jniCallStaticCharMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_CHAR(frame);
}


/* 126 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jshort JNICALL jniCallStaticShortMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jshort ret;
	va_start(args, methodID);
	ret = jniCallStaticShortMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 127 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jshort JNICALL jniCallStaticShortMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_SHORT(frame);
}


/* 128 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jshort JNICALL jniCallStaticShortMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_SHORT(frame);
}


/* 129 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jint JNICALL jniCallStaticIntMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jint ret;
	va_start(args, methodID);
	ret = jniCallStaticIntMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 130 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jint JNICALL jniCallStaticIntMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_INT(frame);
}


/* 131 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jint JNICALL jniCallStaticIntMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_INT(frame);
}


/* 132 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jlong JNICALL jniCallStaticLongMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jlong ret;
	va_start(args, methodID);
	ret = jniCallStaticLongMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 133 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jlong JNICALL jniCallStaticLongMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_LONG(frame);
}


/* 134 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jlong JNICALL jniCallStaticLongMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_LONG(frame);
}


/* 135 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jfloat JNICALL jniCallStaticFloatMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jfloat ret;
	va_start(args, methodID);
	ret = jniCallStaticFloatMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 136 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jfloat JNICALL jniCallStaticFloatMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_FLOAT(frame);
}


/* 137 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jfloat JNICALL jniCallStaticFloatMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_FLOAT(frame);
}


/* 138 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jdouble JNICALL jniCallStaticDoubleMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args; jdouble ret;
	va_start(args, methodID);
	ret = jniCallStaticDoubleMethodV(env, clazz, methodID, args);
	va_end(args);
	return ret;
}


/* 139 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jdouble JNICALL jniCallStaticDoubleMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_DOUBLE(frame);
}


/* 140 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @return the result of calling the method
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jdouble JNICALL jniCallStaticDoubleMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return 0;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
	return VM_POP_DOUBLE(frame);
}


/* 141 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniCallStaticVoidMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
	va_list args;
	va_start(args, methodID);
	jniCallStaticVoidMethodV(env, clazz, methodID, args);
	va_end(args);
}


/* 142 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniCallStaticVoidMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return;
	}
	VM_PUSH_VA_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
}


/* 143 */
/**
   Calls a static method of the class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methodID the static method ID
   @param args a method arguments
   @exception an exception raised in the called method
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchMethodException if the method ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniCallStaticVoidMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
	vmFrame *frame;
	frame = ((vmJNIEnv*)env)->frame;
	if (methodID == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
		return;
	}
	VM_PUSH_ARRAY_LIST(frame, methodID, args);
	vmInvokeStatic(frame, methodID, clazz);
}


/* 144 */
/**
   Searches the static field of the class, determined by the name and the signature.
   @param env the JNI interface pointer
   @param clazz a class object
   @param name the field name
   @param sig the field signature
   @return the field ID or NULL if the field was not found
*/
jfieldID JNICALL jniGetStaticFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
	if (!env || !clazz || !name || !sig) 
		return NULL;
	if (clazz->clsdef != ((vmJNIEnv*)env)->vm->class_clsdef) 
		return NULL;
	return vmGetClassField(VM_CLASS_DEF_DIM(clazz), name, sig, JNI_TRUE);
}


/* 145 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jobject JNICALL jniGetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_OBJECT(frame); 
}


/* 146 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jboolean JNICALL jniGetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_BOOLEAN(frame);
}


/* 147 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jbyte JNICALL jniGetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_BYTE(frame);
}


/* 148 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jchar JNICALL jniGetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_CHAR(frame);
}


/* 149 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jshort JNICALL jniGetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_SHORT(frame);
}


/* 150 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jint JNICALL jniGetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_INT(frame);
}


/* 151 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jlong JNICALL jniGetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_LONG(frame);
}


/* 152 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jfloat JNICALL jniGetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_FLOAT(frame);
}


/* 153 */
/**
   Returns the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @return the field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
jdouble JNICALL jniGetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
	vmFrame *frame;
	jthrowable err;
	frame = ((vmJNIEnv*)env)->frame;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		err = vmGetStatic(frame, fieldID);
	}
	if (err != NULL) {
		jniThrow(env, err);
		return 0;
	}
	return VM_POP_DOUBLE(frame);
}


/* 154 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID, jobject value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_OBJECT(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 155 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID, jboolean value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_BOOLEAN(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 156 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID, jbyte value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_BYTE(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 157 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID, jchar value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_CHAR(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 158 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID, jshort value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_SHORT(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 159 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID, jint value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_INT(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 160 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID, jlong value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_LONG(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 161 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID, jfloat value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_FLOAT(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 162 */
/**
   Sets the static field value of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param fieldID the static field ID
   @param value the new field value
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the field ID is NULL
   @exception java.lang.NullPointerException if the class is NULL
*/
void JNICALL jniSetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID, jdouble value) {
	jthrowable err;
	if (clazz == NULL)
		err = vmCreateThrowable((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	else {
		vmFrame *frame;
		frame = ((vmJNIEnv*)env)->frame;
		if (fieldID && (VM_CLASS_DEF_DIM(clazz) != fieldID->clsdef))
			fieldID = vmGetClassField(VM_CLASS_DEF_DIM(clazz), fieldID->name, fieldID->descriptor, JNI_TRUE);
		VM_PUSH_DOUBLE(frame, value);
		err = vmPutStatic(frame, fieldID);
	}
	if (err != NULL)
		jniThrow(env, err);
}


/* 163 */
/**
   Returns a new string object.
   @param env the JNI interface pointer
   @param uChars an Unicode string
   @param len the Unicode string length (if @a len is negative number, then the string length is computed)
   @return a local reference to the new string object or NULL if an error occurs
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jstring JNICALL jniNewString(JNIEnv *env, const jchar *uChars, jsize len) {
	jstring ret;
	if (len < 0)
		len = vmStrLen(uChars);
	ret = jniNewLocalRef(env,
		vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_STRING, 0, 0, len * sizeof(jchar))
	);
	if (ret != NULL) {
		jchar *s = VM_STRING(ret);
		vmMemCpy(s, uChars, len * sizeof(jchar));
		s[len] = 0;
		VM_STRING_LEN(ret) = len;
	}
	return ret;
}


/* 164 */
/**
   Returns the Unicode @a string length.
   @param env the JNI interface pointer
   @param string a string object
   @return the Unicode @a string length
*/
jsize JNICALL jniGetStringLength(JNIEnv *env, jstring string) {
	if (string != NULL)
		if ((string->dim == 0) && (string->clsdef->name == clsJAVA_LANG_STRING.name))
			return VM_STRING_LEN(string);
	return 0;
}


/* 165 */
/**
   Returns a pointer to the Unicode string contained in the string object. 
   Pointer must be always released by the jniReleaseStringChars() function.
   @param env the JNI interface pointer
   @param string a string object
   @param isCopy a pointer to jboolean (always set to JNI_TRUE, because the string is always been copied)
   @return the Unicode string or NULL if an error occurs
   @exception java.lang.ClassCastException if @a string is not a string object
   @exception java.lang.NullPointerException if the @a string is NULL
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
const jchar *JNICALL jniGetStringChars(JNIEnv *env, jstring string, jboolean *isCopy) {
	jchar *ret;
	if (string == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return NULL;
	}
	if ((string->dim != 0) || (string->clsdef->name != clsJAVA_LANG_STRING.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSCASTEXCEPTION.name), NULL);
		return NULL;
	}
	ret = vmMemAlloc(((vmJNIEnv*)env)->vm, (VM_STRING_LEN(string) + 1) * sizeof(jchar));
	if (ret == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_OUTOFMEMORYERROR.name), NULL);
		return NULL;
	}
	vmStrCpy(ret, VM_STRING(string));
	if (isCopy)
		*isCopy = JNI_TRUE;
	return ret;
}


/* 166 */
/**
   Releases the Unicode string returned by the jniGetStringChars() function.
   @param env the JNI interface pointer
   @param string a string object
   @param chars a pointer to Unicode string
*/
void JNICALL jniReleaseStringChars(JNIEnv *env, jstring string, const jchar *chars) {
	if (chars != NULL)
		vmMemFree(((vmJNIEnv*)env)->vm, (void*)chars);
}


/* 167 */
/**
   Returns a new string object.
   @param env the JNI interface pointer
   @param bytes an UTF-8 string
   @return a local reference to the new string object or NULL if an error occurs
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jstring JNICALL jniNewStringUTF(JNIEnv *env, const char *bytes) {
	jint len = vmStrLenUTF(bytes) + 1;
	jstring ret = jniNewLocalRef(env, 
		vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_STRING, 0, 0, len * sizeof(jchar))
	);
	if (ret != NULL)
		VM_STRING_LEN(ret) = fromUtf8(VM_STRING(ret), bytes, len);
	return ret;
}


/* 168 */
/**
   Returns the UTF-8 @a string length.
   @param env the JNI interface pointer
   @param string a string object
   @return the UTF-8 @a string length
*/
jsize JNICALL jniGetStringUTFLength(JNIEnv *env, jstring string) {
	if (string != NULL)
		if ((string->dim == 0) && (string->clsdef->name == clsJAVA_LANG_STRING.name))
			return toUtf8(NULL, VM_STRING(string), VM_STRING_LEN(string));
	return 0;
}


/* 169 */
/**
   Returns a pointer to the UTF-8 string contained in the string object. 
   Pointer must be always released by the jniReleaseStringUTFChars() function.
   @param env the JNI interface pointer
   @param string a string object
   @param isCopy a pointer to jboolean (always set to JNI_TRUE, because the string is always been copied)
   @return the UTF-8 string or NULL if an error occurs
   @exception java.lang.ClassCastException if @a string is not a string object
   @exception java.lang.NullPointerException if the @a string is NULL
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
const jbyte *JNICALL jniGetStringUTFChars(JNIEnv *env, jstring string, jboolean *isCopy) {
	jbyte *ret;
	if (string == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return NULL;
	}
	if ((string->dim != 0) || (string->clsdef->name != clsJAVA_LANG_STRING.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSCASTEXCEPTION.name), NULL);
		return NULL;
	}
	ret = vmMemAlloc(((vmJNIEnv*)env)->vm, toUtf8(NULL, VM_STRING(string), VM_STRING_LEN(string)) + 1);
	if (ret == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_OUTOFMEMORYERROR.name), NULL);
		return NULL;
	}
	toUtf8(ret, VM_STRING(string), VM_STRING_LEN(string));
	if (isCopy)
		*isCopy = JNI_TRUE;
	return ret;
}


/* 170 */
/**
   Releases the UTF-8 string returned by the jniGetStringUTFChars() function.
   @param env the JNI interface pointer
   @param string a string object
   @param utf a pointer to UTF-8 string
*/
void JNICALL jniReleaseStringUTFChars(JNIEnv *env, jstring string, const char *utf) {
	if (utf != NULL)
		vmMemFree(((vmJNIEnv*)env)->vm, (void*)utf);
}


/* 171 */
/**
   Returns the array length.
   @param env the JNI interface pointer
   @param array an array object
   @return the array length
   @exception java.lang.IllegalArgumentException if @a array is not an array object
   @exception java.lang.NullPointerException if the array is NULL
*/
jsize JNICALL jniGetArrayLength(JNIEnv *env, jarray array) {
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return 0;
	}
	if (array->dim <= 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not array");
		return 0;
	}
	return VM_ARRAY_LENGTH(array);
}


/* 172 */
/**
   Returns a new array of the objects of the @a elementType class.
   Each element of the array is set to initialElement.
   @param env the JNI interface pointer
   @param length the array length
   @param elementType a class object
   @param initialElement an object or NULL
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.ArrayStoreException if the @a initialElement object can be not cast to the @a elementType
   @exception java.lang.InstantiationException if the @a elementType is an interface or an abstract class
   @exception java.lang.LinkageError if the @a elementType was not resolved successfully
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.NullPointerException if the @a elementType is NULL
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jarray JNICALL jniNewObjectArray(JNIEnv *env, jsize length, jclass elementType, jobject initialElement) {
	if (elementType == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else {
		if (length < 0)
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		else {
			jarray ret;
			jshort dim = VM_CLASS_DIM(elementType);
			clsDefinition *cls = VM_CLASS_DEF(elementType);
			if (!jniIsInstanceOf(env, initialElement, elementType)) {
				jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYSTOREEXCEPTION.name), NULL);
				return NULL;
			}
			ret = jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, cls, (jshort)(dim + 1), length, 0)
			);
			if ((ret != NULL) && (initialElement != NULL)) {
				jint i;
				jobject *ptr = VM_ARRAY_ARRAY(ret);
				length = VM_ARRAY_LENGTH(ret);
				for (i = 0; i < length; i++)
					ptr[i] = JNINEWGLOBALREF(env, initialElement);
			}
			return ret;
		}
	}
	return NULL;
}


/* 173 */
/**
   Returns an element of the object array.
   @param env the JNI interface pointer
   @param array an array object
   @param index the array index
   @return an element of the object array or NULL if an error occurs
   @exception java.lang.ArrayIndexOutOfBoundsException if the @a index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not an object array
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jobject JNICALL jniGetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index) {
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return NULL;
	}
	if ((array->dim <= 0) || ((array->dim == 1) && (array->clsdef->name[1] == 0))) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not array");
		return NULL;
	}
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
		return NULL;
	}
	return VM_ARRAY_ARRAY(array)[index];
}


/* 174 */
/**
   Sets an element of the object array.
   @param env the JNI interface pointer
   @param array an array object
   @param index the array index
   @param value an object
   @exception java.lang.ArrayIndexOutOfBoundsException if the @a index is out of the array range
   @exception java.lang.ArrayStoreException if the @a value object can be not cast to the array element class
   @exception java.lang.IllegalArgumentException if @a array is not an object array
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index, jobject value) {
	jobject oldval;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return;
	}
	if ((array->dim <= 0) || ((array->dim == 1) && (array->clsdef->name[1] == 0))) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not array");
		return;
	}
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
		return;
	}
	if (value != NULL) {
		jint dim1, dim2; clsDefinition *cls1, *cls2;
		dim2 = value->dim; dim1 = array->dim - 1;
		cls2 = value->clsdef; cls1 = array->clsdef;
		if (!vmIsClassAssignableFrom(cls1, dim1, cls2, dim2)) {
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYSTOREEXCEPTION.name), NULL);
			return;
		}
	}
	oldval = VM_ARRAY_ARRAY(array)[index];
	VM_ARRAY_ARRAY(array)[index] = JNINEWGLOBALREF(env, value);
	JNIDELETEGLOBALREF(env, oldval);
}


/* 175 */
/**
   Returns a new array of the boolean values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jbooleanArray JNICALL jniNewBooleanArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsBOOLEAN, 1, length, 0)
	       );
}


/* 175 */
/**
   Returns a new array of the byte values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jbyteArray JNICALL jniNewByteArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsBYTE, 1, length, 0)
	       );
}


/* 177 */
/**
   Returns a new array of the char values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jcharArray JNICALL jniNewCharArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsCHAR, 1, length, 0)
	       );
}


/* 178 */
/**
   Returns a new array of the short values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jshortArray JNICALL jniNewShortArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsSHORT, 1, length, 0)
	       );
}


/* 179 */
/**
   Returns a new array of the integer values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jintArray JNICALL jniNewIntArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsINT, 1, length, 0)
	       );
}


/* 180 */
/**
   Returns a new array of the long values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jlongArray JNICALL jniNewLongArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsLONG, 1, length, 0)
	       );
}


/* 181 */
/**
   Returns a new array of the float values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jfloatArray JNICALL jniNewFloatArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsFLOAT, 1, length, 0)
	       );
}


/* 182 */
/**
   Returns a new array of the double values.
   @param env the JNI interface pointer
   @param length the array length
   @return a local reference to the new array or NULL if an error occurs
   @exception java.lang.NegativeArraySizeException if the @a length is negative number
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jdoubleArray JNICALL jniNewDoubleArray(JNIEnv *env, jsize length) {
	if (length < 0) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION.name), NULL);
		return NULL;
	}
	return jniNewLocalRef(env, 
				vmCreateObject((vmJNIEnv*)env, &clsDOUBLE, 1, length, 0)
	       );
}


/* 183 */
/**
   Returns a pointer to the boolean elements of an array object.
   The pointer must be released by the jniReleaseBooleanArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not boolean array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jboolean *JNICALL jniGetBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsBOOLEAN.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not boolean array");
		return NULL;
	}
	return (jboolean*)VM_ARRAY_ARRAY(array);
}


/* 184 */
/**
   Returns a pointer to the byte elements of an array object.
   The pointer must be released by the jniReleaseByteArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not byte array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jbyte *JNICALL jniGetByteArrayElements(JNIEnv *env, jbyteArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsBYTE.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not byte array");
		return NULL;
	}
	return (jbyte*)VM_ARRAY_ARRAY(array);
}


/* 185 */
/**
   Returns a pointer to the char elements of an array object.
   The pointer must be released by the jniReleaseCharArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not char array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jchar *JNICALL jniGetCharArrayElements(JNIEnv *env, jcharArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsCHAR.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not char array");
		return NULL;
	}
	return (jchar*)VM_ARRAY_ARRAY(array);
}


/* 186 */
/**
   Returns a pointer to the short elements of an array object.
   The pointer must be released by the jniReleaseShortArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not short array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jshort *JNICALL jniGetShortArrayElements(JNIEnv *env, jshortArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsDOUBLE.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not short array");
		return NULL;
	}
	return (jshort*)VM_ARRAY_ARRAY(array);
}


/* 187 */
/**
   Returns a pointer to the integer elements of an array object.
   The pointer must be released by the jniReleaseIntArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not int array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jint *JNICALL jniGetIntArrayElements(JNIEnv *env, jintArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsINT.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not int array");
		return NULL;
	}
	return (jint*)VM_ARRAY_ARRAY(array);
}


/* 188 */
/**
   Returns a pointer to the long elements of an array object.
   The pointer must be released by the jniReleaseLongArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not long array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jlong *JNICALL jniGetLongArrayElements(JNIEnv *env, jlongArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsLONG.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not long array");
		return NULL;
	}
	return (jlong*)VM_ARRAY_ARRAY(array);
}


/* 189 */
/**
   Returns a pointer to the float elements of an array object.
   The pointer must be released by the jniReleaseFloatArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not float array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jfloat *JNICALL jniGetFloatArrayElements(JNIEnv *env, jfloatArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsFLOAT.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not float array");
		return NULL;
	}
	return (jfloat*)VM_ARRAY_ARRAY(array);
}


/* 190 */
/**
   Returns a pointer to the double elements of an array object.
   The pointer must be released by the jniReleaseDoubleArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
   @exception java.lang.IllegalArgumentException if @a array is not double array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
jdouble *JNICALL jniGetDoubleArrayElements(JNIEnv *env, jdoubleArray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL); 
		return NULL; 
	}
	if ((array->dim != 1) || (array->clsdef->name != clsDOUBLE.name)) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not double array");
		return NULL;
	}
	return (jdouble*)VM_ARRAY_ARRAY(array);
}


/* 191 */
/**
   Releases the pointer to the array elements returned by the jniGetBooleanArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *elems, jint mode) {
}


/* 192 */
/**
   Releases the pointer to the array elements returned by the jniGetByteArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseByteArrayElements(JNIEnv *env, jbyteArray array, jbyte *elems, jint mode) {
}


/* 193 */
/**
   Releases the pointer to the array elements returned by the jniGetCharArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseCharArrayElements(JNIEnv *env, jcharArray array, jchar *elems, jint mode) {
}


/* 194 */
/**
   Releases the pointer to the array elements returned by the jniGetShortArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseShortArrayElements(JNIEnv *env, jshortArray array, jshort *elems, jint mode) {
}


/* 195 */
/**
   Releases the pointer to the array elements returned by the jniGetIntArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseIntArrayElements(JNIEnv *env, jintArray array, jint *elems, jint mode) {
}


/* 196 */
/**
   Releases the pointer to the array elements returned by the jniGetLongArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseLongArrayElements(JNIEnv *env, jlongArray array, jlong *elems, jint mode) {
}


/* 197 */
/**
   Releases the pointer to the array elements returned by the jniGetFloatArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseFloatArrayElements(JNIEnv *env, jfloatArray array, jfloat *elems, jint mode) {
}


/* 198 */
/**
   Releases the pointer to the array elements returned by the jniGetDoubleArrayElements() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleaseDoubleArrayElements(JNIEnv *env, jdoubleArray array, jdouble *elems, jint mode) {
}


/* 199 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not boolean array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsBOOLEAN.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not boolean array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jboolean*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jboolean));
}


/* 200 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not byte array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsBYTE.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not byte array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jbyte*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jbyte));
}


/* 201 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not char array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsCHAR.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not char array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jchar*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jchar));
}


/* 202 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not short array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsSHORT.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not short array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jshort*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jshort));
}


/* 203 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not int array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsINT.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not int array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jint*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jint));
}


/* 204 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not long array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsLONG.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not long array");
	else
	if ((start < 0) || (len < 0) || ((start + len) >= VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jlong*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jlong));
}


/* 205 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not float array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsFLOAT.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not float array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jfloat*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jfloat));
}


/* 206 */
/**
   Copies a region of the array elements to the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not double array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniGetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsDOUBLE.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not double array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(buf, ((jdouble*)VM_ARRAY_ARRAY(array)) + start, len * sizeof(jdouble));
}


/* 207 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not boolean array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsBOOLEAN.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not boolean array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jboolean*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jboolean));
}


/* 208 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not byte array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsBYTE.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not byte array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jbyte*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jbyte));
}


/* 209 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not char array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsCHAR.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not char array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jchar*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jchar));
}


/* 210 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not short array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsSHORT.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not short array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jshort*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jshort));
}


/* 211 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not int array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsINT.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not int array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jint*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jint));
}


/* 212 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not long array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsLONG.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not long array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jlong*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jlong));
}


/* 213 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not float array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsFLOAT.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not float array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jfloat*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jfloat));
}


/* 214 */
/**
   Copies a region of the array elements from the buffer.
   @param env the JNI interface pointer
   @param array an array object
   @param start the starting index
   @param len the number of elements
   @param buf the buffer
   @exception java.lang.ArrayIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.IllegalArgumentException if @a array is not double array object
   @exception java.lang.NullPointerException if the @a array is NULL
*/
void JNICALL jniSetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf) {
	if (array == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((array->dim != 1) || (array->clsdef->name != clsDOUBLE.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION.name), "Object is not double array");
	else
	if ((start < 0) || (len < 0) || ((start + len) > VM_ARRAY_LENGTH(array)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmMemCpy(((jdouble*)VM_ARRAY_ARRAY(array)) + start, buf, len * sizeof(jdouble));
}


/* 215 */
/**
   Registers native methods for a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @param methods the native methods
   @param nMethods the number of methods
   @return JNI_OK on success or an error code
   @exception java.lang.NoSuchMethodError if a method can't be found or the method isn't native
   @exception java.lang.NullPointerException if the @a clazz is NULL
*/
jint JNICALL jniRegisterNatives(JNIEnv *env, jclass clazz, const JNINativeMethod *methods, jint nMethods) {
	jint mi;
	jmethodID met;
	if (clazz == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return JNI_EINVAL;
	}
	for (mi = 0; mi < nMethods; mi++) {
		met = vmGetInstanceMethod(VM_CLASS_DEF_DIM(clazz), methods[mi].name, methods[mi].signature, JNI_FALSE);
		if (met == NULL)
			met = vmGetClassMethod(VM_CLASS_DEF_DIM(clazz), methods[mi].name, methods[mi].signature, JNI_FALSE);
		if ((met == NULL) || ((met->access_flags & ACC_NATIVE) == 0)) {
			jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODERROR.name), NULL);
			return JNI_ERR;
		}
		met->code = methods[mi].fnPtr;
	}
	return JNI_OK;
}


/* 216 */
/**
   Unregisters native methods of a class.
   @param env the JNI interface pointer
   @param clazz a class object
   @return JNI_OK on success or an error code
   @exception java.lang.NullPointerException if the @a clazz is NULL
*/
jint JNICALL jniUnregisterNatives(JNIEnv *env, jclass clazz) {
	jint i;
	clsDefinition *cls;
	if (clazz == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return JNI_EINVAL;
	}
	cls = VM_CLASS_DEF_DIM(clazz);
	for (i = 0; i < cls->class_methods_count; i++) {
		jmethodID met = cls->class_methods[i];
		if (met->access_flags & ACC_NATIVE)
			met->code = NULL;
	}
	for (i = 0; i < cls->instance_methods_count; i++) {
		jmethodID met = cls->instance_methods[i];
		if (met->access_flags & ACC_NATIVE)
			met->code = NULL;
	}
	return JNI_OK;
}


/* 217 */
/**
   Object monitor owner is set to the current thread. Each object has a monitor. 
   If the monitor is not owned by any thread, monitor owner is set to the current thread.
   If the monitor is owned by the current thread, monitor counter is incremented.
   If the monitor is owned by the another thread, the current thread waits until the monitor is released.
   @param env the JNI interface pointer
   @param obj an object
   @return JNI_OK on success or an error code
   @exception java.lang.NullPointerException if the @a obj is NULL
*/
jint JNICALL jniMonitorEnter(JNIEnv *env, jobject obj) {
	natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
	natThreadID cur_thread_id;
	if (obj == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return JNI_ERR;
	}
	cur_thread_id = ((vmJNIEnv*)env)->thread_id;
	while (1) {
		VM_ENTER_CRITICAL_SECTION(gcs);
		if (obj->thread_cnt == 0)
			obj->thread_id = cur_thread_id;
		if (obj->thread_id == cur_thread_id) {
			obj->thread_cnt++;
			if (VM_IS_EVENT_CREATED(obj->exit_event))
				VM_RESET_EVENT(obj->exit_event);
			VM_LEAVE_CRITICAL_SECTION(gcs);
			break;
		}
		/* wait until the object is unlocked */
		if (!VM_IS_EVENT_CREATED(obj->exit_event))
			VM_CREATE_EVENT(obj->exit_event);
		VM_LEAVE_CRITICAL_SECTION(gcs);
		VM_WAIT_FOR_EVENT(obj->exit_event, -1);
	}
	return JNI_OK;
}


/* 218 */
/**
   Object monitor is released by the current thread. Each object has a monitor. 
   The current thread must be monitor owner. The monitor counter is decremented and if it is zero,
   the object monitor is released by the current thread.
   @param env the JNI interface pointer
   @param obj an object
   @return JNI_OK on success or an error code
   @exception java.lang.NullPointerException if the @a obj is NULL
*/
jint JNICALL jniMonitorExit(JNIEnv *env, jobject obj) {
	natSynchronizeData *gcs = ((vmJNIEnv*)env)->vm->gcs;
	natThreadID cur_thread_id;
	if (obj == NULL) {
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
		return JNI_ERR;
	}
	cur_thread_id = ((vmJNIEnv*)env)->thread_id;
	VM_ENTER_CRITICAL_SECTION(gcs);
	if (obj->thread_cnt == 0) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return JNI_ERR;
	}
	if (obj->thread_id != cur_thread_id) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return JNI_ERR;
	}
	if (--obj->thread_cnt == 0) {
		obj->thread_id = 0;
		if (VM_IS_EVENT_CREATED(obj->exit_event))
			VM_SET_EVENT(obj->exit_event);
	}
	VM_LEAVE_CRITICAL_SECTION(gcs);
	return JNI_OK;
}


/* 219 */
/**
   Returns the Java VM interface for the current thread.
   @param env the JNI interface pointer
   @param vm the Java VM interface pointer
   @return JNI_OK on success or an error code
*/
jint JNICALL jniGetJavaVM(JNIEnv *env, JavaVM **vm) {
	if (!env || !vm)
		return JNI_EINVAL;
	*vm = (JavaVM*)(((vmJNIEnv*)env)->vm);
	return JNI_OK;
}


/* 220 */
/**
   Copies a string region to the buffer.
   @param env the JNI interface pointer
   @param str a string object
   @param start the starting index
   @param len the number of characters
   @param buf the Unicode string buffer
   @exception java.lang.StringIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.ClassCastException if @a str is not a string object
   @exception java.lang.NullPointerException if the @a str is NULL
*/
void JNICALL jniGetStringRegion(JNIEnv *env, jstring str, jsize start, jsize len, jchar *buf) {
	if (str == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((str->dim != 1) || (str->clsdef->name != clsJAVA_LANG_STRING.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSCASTEXCEPTION.name), NULL);
	else
	if ((start < 0) || (len < 0) || ((start + len) >= VM_STRING_LEN(str)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		vmStrnCpy(buf, VM_STRING(str) + start, len);
}


/* 221 */
/**
   Copies a string region to the buffer.
   @param env the JNI interface pointer
   @param str a string object
   @param start the starting index
   @param len the number of characters
   @param buf the UTF-8 string buffer
   @exception java.lang.StringIndexOutOfBoundsException if some region index is out of the array range
   @exception java.lang.ClassCastException if @a str is not a string object
   @exception java.lang.NullPointerException if the @a str is NULL
*/
void JNICALL jniGetStringUTFRegion(JNIEnv *env, jstring str, jsize start, jsize len, char *buf) {
	if (str == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NULLPOINTEREXCEPTION.name), NULL);
	else
	if ((str->dim != 1) || (str->clsdef->name != clsJAVA_LANG_STRING.name))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSCASTEXCEPTION.name), NULL);
	else
	if ((start < 0) || (len < 0) || ((start + len) >= VM_STRING_LEN(str)))
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION.name), NULL);
	else
	if (buf != NULL)
		toUtf8(buf, VM_STRING(str) + start, len);
}


/* 222 */
/**
   Returns a pointer to the primitive elements of an array object.
   The pointer must be released by the jniReleasePrimitiveArrayCritical() function.
   @param env the JNI interface pointer
   @param array an array object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the array elements are not been copied)
   @return a pointer to the array elements or NULL if an error occurs
*/
void *JNICALL jniGetPrimitiveArrayCritical(JNIEnv *env, jarray array, jboolean *isCopy) {
	if (isCopy != NULL)
		*isCopy = JNI_FALSE;
	if (array != NULL)
		return ((array->dim == 1) && (array->clsdef->name[1] == 0)) ? VM_ARRAY_ARRAY(array) : NULL;
	return NULL;
}


/* 223 */
/**
   Releases the pointer to the array elements returned by the jniGetPrimitiveArrayCritical() function.
   @param env the JNI interface pointer
   @param array an array object
   @param elems a pointer to the array elements
   @param mode this function argument has no effect, because the array elements were not been copied
*/
void JNICALL jniReleasePrimitiveArrayCritical(JNIEnv *env, jarray array, void *elems, jint mode) {
}


/* 224 */
/**
   Returns a pointer to the Unicode string contained in the string object. 
   Pointer must be always released by the jniReleaseStringCritical() function.
   @param env the JNI interface pointer
   @param string a string object
   @param isCopy a pointer to jboolean (always set to JNI_FALSE, because the string is not been copied)
   @return the Unicode string or NULL if an error occurs
*/
const jchar *JNICALL jniGetStringCritical(JNIEnv *env, jstring string, jboolean *isCopy) {
	if (isCopy)
		*isCopy = JNI_FALSE;
	if (string != NULL)
		if ((string->dim == 0) && (string->clsdef->name == clsJAVA_LANG_STRING.name))
			return VM_STRING(string);
	return NULL;
}


/* 225 */
/**
   Releases the pointer to the string returned by the jniGetStringCritical() function.
   @param env the JNI interface pointer
   @param string a string object
   @param chars a pointer to the string
*/
void JNICALL jniReleaseStringCritical(JNIEnv *env, jstring string, const jchar *chars) {
}


/* 226 */
/**
   Returns a new global reference to the object.
   This implementation does not support weak global references, a standard global reference is returned.
   Returned reference must be explicitly deleted by the jniDeleteWeakGlobalRef() function.
   @param env the JNI interface pointer
   @param ref a global or local reference
   @return the new global reference
*/
jweak JNICALL jniNewWeakGlobalRef(JNIEnv *env, jobject ref) {
	return JNINEWGLOBALREF(env, ref);
}


/* 227 */
/**
   Deletes a global reference to the object returned by the jniNewWeakGlobalRef() function.
   If this is the last reference to the object, then the object is released.
   @param env the JNI interface pointer
   @param wref a global reference
*/
void JNICALL jniDeleteWeakGlobalRef(JNIEnv *env, jweak wref) {
	JNIDELETEGLOBALREF(env, wref);
}


/* 228 */
/**
   Tests if a throwable object is being thrown.
   @param env the JNI interface pointer
   @return JNI_TRUE if any throwable object is currently being thrown or JNI_FALSE
*/
jboolean JNICALL jniExceptionCheck(JNIEnv *env) {
	return ((vmJNIEnv*)env)->frame->exception != NULL;
}



static struct JNINativeInterface DEFAULT_NATIVE_INTERFACE = {
	NULL,
	NULL,
	NULL,
	NULL,
	jniGetVersion,                          /* 4 */
	jniDefineClass,                         /* 5 */
	jniFindClass,                           /* 6 */
	jniFromReflectedMethod,                 /* 7 */
	jniFromReflectedField,                  /* 8 */
	jniToReflectedMethod,                   /* 9 */
	jniGetSuperclass,                       /* 10 */
	jniIsAssignableFrom,                    /* 11 */
	jniToReflectedField,                    /* 12 */
	jniThrow,                               /* 13 */
	jniThrowNew,                            /* 14 */
	jniExceptionOccurred,                   /* 15 */
	jniExceptionDescribe,                   /* 16 */
	jniExceptionClear,                      /* 17 */
	jniFatalError,                          /* 18 */
	jniPushLocalFrame,                      /* 19 */
	jniPopLocalFrame,                       /* 20 */
	jniNewGlobalRef,                        /* 21 */
	jniDeleteGlobalRef,                     /* 22 */
	jniDeleteLocalRef,                      /* 23 */
	jniIsSameObject,                        /* 24 */
	jniNewLocalRef,                         /* 25 */
	jniEnsureLocalCapacity,                 /* 26 */
	jniAllocObject,                         /* 27 */
	jniNewObject,                           /* 28 */
	jniNewObjectV,                          /* 29 */
	jniNewObjectA,                          /* 30 */
	jniGetObjectClass,                      /* 31 */
	jniIsInstanceOf,                        /* 32 */
	jniGetMethodID,                         /* 33 */
	jniCallObjectMethod,                    /* 34 */
	jniCallObjectMethodV,                   /* 35 */
	jniCallObjectMethodA,                   /* 36 */
	jniCallBooleanMethod,                   /* 37 */
	jniCallBooleanMethodV,                  /* 38 */
	jniCallBooleanMethodA,                  /* 39 */
	jniCallByteMethod,                      /* 40 */
	jniCallByteMethodV,                     /* 41 */
	jniCallByteMethodA,                     /* 42 */
	jniCallCharMethod,                      /* 43 */
	jniCallCharMethodV,                     /* 44 */
	jniCallCharMethodA,                     /* 45 */
	jniCallShortMethod,                     /* 46 */
	jniCallShortMethodV,                    /* 47 */
	jniCallShortMethodA,                    /* 48 */
	jniCallIntMethod,                       /* 49 */
	jniCallIntMethodV,                      /* 50 */
	jniCallIntMethodA,                      /* 51 */
	jniCallLongMethod,                      /* 52 */
	jniCallLongMethodV,                     /* 53 */
	jniCallLongMethodA,                     /* 54 */
	jniCallFloatMethod,                     /* 55 */
	jniCallFloatMethodV,                    /* 56 */
	jniCallFloatMethodA,                    /* 57 */
	jniCallDoubleMethod,                    /* 58 */
	jniCallDoubleMethodV,                   /* 59 */
	jniCallDoubleMethodA,                   /* 60 */
	jniCallVoidMethod,                      /* 61 */
	jniCallVoidMethodV,                     /* 62 */
	jniCallVoidMethodA,                     /* 63 */
	jniCallNonvirtualObjectMethod,          /* 64 */
	jniCallNonvirtualObjectMethodV,         /* 65 */
	jniCallNonvirtualObjectMethodA,         /* 66 */
	jniCallNonvirtualBooleanMethod,         /* 67 */
	jniCallNonvirtualBooleanMethodV,        /* 68 */
	jniCallNonvirtualBooleanMethodA,        /* 69 */
	jniCallNonvirtualByteMethod,            /* 70 */
	jniCallNonvirtualByteMethodV,           /* 71 */
	jniCallNonvirtualByteMethodA,           /* 72 */
	jniCallNonvirtualCharMethod,            /* 73 */
	jniCallNonvirtualCharMethodV,           /* 74 */
	jniCallNonvirtualCharMethodA,           /* 75 */
	jniCallNonvirtualShortMethod,           /* 76 */
	jniCallNonvirtualShortMethodV,          /* 77 */
	jniCallNonvirtualShortMethodA,          /* 78 */
	jniCallNonvirtualIntMethod,             /* 79 */
	jniCallNonvirtualIntMethodV,            /* 80 */
	jniCallNonvirtualIntMethodA,            /* 81 */
	jniCallNonvirtualLongMethod,            /* 82 */
	jniCallNonvirtualLongMethodV,           /* 83 */
	jniCallNonvirtualLongMethodA,           /* 84 */
	jniCallNonvirtualFloatMethod,           /* 85 */
	jniCallNonvirtualFloatMethodV,          /* 86 */
	jniCallNonvirtualFloatMethodA,          /* 87 */
	jniCallNonvirtualDoubleMethod,          /* 88 */
	jniCallNonvirtualDoubleMethodV,         /* 89 */
	jniCallNonvirtualDoubleMethodA,         /* 90 */
	jniCallNonvirtualVoidMethod,            /* 91 */
	jniCallNonvirtualVoidMethodV,           /* 92 */
	jniCallNonvirtualVoidMethodA,           /* 93 */
	jniGetFieldID,                          /* 94 */
	jniGetObjectField,                      /* 95 */
	jniGetBooleanField,                     /* 96 */
	jniGetByteField,                        /* 97 */
	jniGetCharField,                        /* 98 */
	jniGetShortField,                       /* 99 */
	jniGetIntField,                         /* 100 */
	jniGetLongField,                        /* 101 */
	jniGetFloatField,                       /* 102 */
	jniGetDoubleField,                      /* 103 */
	jniSetObjectField,                      /* 104 */
	jniSetBooleanField,                     /* 105 */
	jniSetByteField,                        /* 106 */
	jniSetCharField,                        /* 107 */
	jniSetShortField,                       /* 108 */
	jniSetIntField,                         /* 109 */
	jniSetLongField,                        /* 110 */
	jniSetFloatField,                       /* 111 */
	jniSetDoubleField,                      /* 112 */
	jniGetStaticMethodID,                   /* 113 */
	jniCallStaticObjectMethod,              /* 114 */
	jniCallStaticObjectMethodV,             /* 115 */
	jniCallStaticObjectMethodA,             /* 116 */
	jniCallStaticBooleanMethod,             /* 117 */
	jniCallStaticBooleanMethodV,            /* 118 */
	jniCallStaticBooleanMethodA,            /* 119 */
	jniCallStaticByteMethod,                /* 120 */
	jniCallStaticByteMethodV,               /* 121 */
	jniCallStaticByteMethodA,               /* 122 */
	jniCallStaticCharMethod,                /* 123 */
	jniCallStaticCharMethodV,               /* 124 */
	jniCallStaticCharMethodA,               /* 125 */
	jniCallStaticShortMethod,               /* 126 */
	jniCallStaticShortMethodV,              /* 127 */
	jniCallStaticShortMethodA,              /* 128 */
	jniCallStaticIntMethod,                 /* 129 */
	jniCallStaticIntMethodV,                /* 130 */
	jniCallStaticIntMethodA,                /* 131 */
	jniCallStaticLongMethod,                /* 132 */
	jniCallStaticLongMethodV,               /* 133 */
	jniCallStaticLongMethodA,               /* 134 */
	jniCallStaticFloatMethod,               /* 135 */
	jniCallStaticFloatMethodV,              /* 136 */
	jniCallStaticFloatMethodA,              /* 137 */
	jniCallStaticDoubleMethod,              /* 138 */
	jniCallStaticDoubleMethodV,             /* 139 */
	jniCallStaticDoubleMethodA,             /* 140 */
	jniCallStaticVoidMethod,                /* 141 */
	jniCallStaticVoidMethodV,               /* 142 */
	jniCallStaticVoidMethodA,               /* 143 */
	jniGetStaticFieldID,                    /* 144 */
	jniGetStaticObjectField,                /* 145 */
	jniGetStaticBooleanField,               /* 146 */
	jniGetStaticByteField,                  /* 147 */
	jniGetStaticCharField,                  /* 148 */
	jniGetStaticShortField,                 /* 149 */
	jniGetStaticIntField,                   /* 150 */
	jniGetStaticLongField,                  /* 151 */
	jniGetStaticFloatField,                 /* 152 */
	jniGetStaticDoubleField,                /* 153 */
	jniSetStaticObjectField,                /* 154 */
	jniSetStaticBooleanField,               /* 155 */
	jniSetStaticByteField,                  /* 156 */
	jniSetStaticCharField,                  /* 157 */
	jniSetStaticShortField,                 /* 158 */
	jniSetStaticIntField,                   /* 159 */
	jniSetStaticLongField,                  /* 160 */
	jniSetStaticFloatField,                 /* 161 */
	jniSetStaticDoubleField,                /* 162 */
	jniNewString,                           /* 163 */
	jniGetStringLength,                     /* 164 */
	jniGetStringChars,                      /* 165 */
	jniReleaseStringChars,                  /* 166 */
	jniNewStringUTF,                        /* 167 */
	jniGetStringUTFLength,                  /* 168 */
	jniGetStringUTFChars,                   /* 169 */
	jniReleaseStringUTFChars,               /* 170 */
	jniGetArrayLength,                      /* 171 */
	jniNewObjectArray,                      /* 172 */
	jniGetObjectArrayElement,               /* 173 */
	jniSetObjectArrayElement,               /* 174 */
	jniNewBooleanArray,                     /* 175 */
	jniNewByteArray,                        /* 176 */
	jniNewCharArray,                        /* 177 */
	jniNewShortArray,                       /* 178 */
	jniNewIntArray,                         /* 179 */
	jniNewLongArray,                        /* 180 */
	jniNewFloatArray,                       /* 181 */
	jniNewDoubleArray,                      /* 182 */
	jniGetBooleanArrayElements,             /* 183 */
	jniGetByteArrayElements,                /* 184 */
	jniGetCharArrayElements,                /* 185 */
	jniGetShortArrayElements,               /* 186 */
	jniGetIntArrayElements,                 /* 187 */
	jniGetLongArrayElements,                /* 188 */
	jniGetFloatArrayElements,               /* 189 */
	jniGetDoubleArrayElements,              /* 190 */
	jniReleaseBooleanArrayElements,         /* 191 */
	jniReleaseByteArrayElements,            /* 192 */
	jniReleaseCharArrayElements,            /* 193 */
	jniReleaseShortArrayElements,           /* 194 */
	jniReleaseIntArrayElements,             /* 195 */
	jniReleaseLongArrayElements,            /* 196 */
	jniReleaseFloatArrayElements,           /* 197 */
	jniReleaseDoubleArrayElements,          /* 198 */
	jniGetBooleanArrayRegion,               /* 199 */
	jniGetByteArrayRegion,                  /* 200 */
	jniGetCharArrayRegion,                  /* 201 */
	jniGetShortArrayRegion,                 /* 202 */
	jniGetIntArrayRegion,                   /* 203 */
	jniGetLongArrayRegion,                  /* 204 */
	jniGetFloatArrayRegion,                 /* 205 */
	jniGetDoubleArrayRegion,                /* 206 */
	jniSetBooleanArrayRegion,               /* 207 */
	jniSetByteArrayRegion,                  /* 208 */
	jniSetCharArrayRegion,                  /* 209 */
	jniSetShortArrayRegion,                 /* 210 */
	jniSetIntArrayRegion,                   /* 211 */
	jniSetLongArrayRegion,                  /* 212 */
	jniSetFloatArrayRegion,                 /* 213 */
	jniSetDoubleArrayRegion,                /* 214 */
	jniRegisterNatives,                     /* 215 */
	jniUnregisterNatives,                   /* 216 */
	jniMonitorEnter,                        /* 217 */
	jniMonitorExit,                         /* 218 */
	jniGetJavaVM,                           /* 219 */
	jniGetStringRegion,                     /* 220 */
	jniGetStringUTFRegion,                  /* 221 */
	jniGetPrimitiveArrayCritical,           /* 222 */
	jniReleasePrimitiveArrayCritical,       /* 223 */
	jniGetStringCritical,                   /* 224 */
	jniReleaseStringCritical,               /* 225 */
	jniNewWeakGlobalRef,                    /* 226 */
	jniDeleteWeakGlobalRef,                 /* 227 */
	jniExceptionCheck                       /* 228 */
};


/*****************************************************************
 * JNIInvokeInterface implementation 
 *****************************************************************/

/* virtual machine list */
struct JavaVM_listitem {
	JavaVM *pvm;
	struct JavaVM_listitem *prev;
	struct JavaVM_listitem *next;
};
static struct JavaVM_listitem *jvms = NULL;


/* 228 */
/**
   Returns a JNI interface pointer for the current thread.
   @param vm the Java VM interface pointer
   @param penv a pointer to the location where the JNI interface pointer is returned
   @param interface_id the JNI version (must be JNI_VERSION_1_1 or JNI_VERSION_1_2)
   @return JNI_OK on success or an error code
*/
jint JNICALL jniGetEnv(JavaVM *vm, void **penv, jint interface_id) {
	jint ret; vmJNIEnv *env;
	natThreadID thread_id;

	if (!vm || !penv)
		return JNI_EINVAL;
	if (interface_id != JNI_VERSION_1_1)
		if (interface_id != JNI_VERSION_1_2)
			return JNI_EVERSION;
	ret = JNI_EDETACHED;
	thread_id = vmGetCurrentThreadId();
	
	/* find the JNI interface pointer */
	VM_ENTER_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	env = JVM_MAINENV(vm);
	while (env != NULL) {
		if (thread_id == env->thread_id) { 
			*penv = env;
			ret = JNI_OK;
			break;
		}
		env = env->next;
	}
	VM_LEAVE_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	return ret;
}


/**
   Attaches the current thread to the virtual machine.
   The thread must be detached by the jniDetachCurrentThread()
   function, before the virtual machine can be destroyed.
   @param vm the Java VM interface pointer
   @param penv a pointer to the location where the JNI interface pointer is returned
   @param args not supported, must be NULL
   @return JNI_OK on success or an error code
*/
jint JNICALL jniAttachCurrentThread(JavaVM *vm, JNIEnv **penv, void *args) {
	vmMemHandle hmem;
	char *p; jint len, ret; natThreadID thread_id;
	vmJNIEnv *env, *last_env; JDK1_1InitArgs *iargs;
	ret = JNI_ERR;

	/* valid arguments? */
	if (!vm || !penv || (args != NULL))
		return JNI_EINVAL;
	iargs = ((vmJavaVM*)vm)->args;
	thread_id = vmGetCurrentThreadId();
	VM_ENTER_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);

	/* already exist? */
	env = JVM_MAINENV(vm);
	while (env != NULL) {
		if (thread_id == env->thread_id)
			goto DONE;
		last_env = env; 
		env = env->next;
	}

	/* platform specific initialization */
	if (vmThreadInitPlatformSpecific() != 0)
		return JNI_ERR;

	/* alloc memory */
	len = sizeof(vmJNIEnv) + sizeof(struct JNINativeInterface) + (2 * iargs->javaStackSize);
	hmem = vmMemSystemAlloc(len);
	if (hmem == NULL) {
		ret = JNI_ENOMEM;
		goto DONE;
	}
	p = vmMemSystemLock(hmem);
	if (p == NULL) {
		vmMemSystemFree(hmem);
		ret = JNI_ENOMEM;
		goto DONE;
	}

	/* create thread environment */
	env = (vmJNIEnv*)*penv = (vmJNIEnv*)p; p += sizeof(vmJNIEnv);
	env->iif = (void*)p; p += sizeof(struct JNINativeInterface);
	vmMemCpy((void*)env->iif, &DEFAULT_NATIVE_INTERFACE, sizeof(struct JNINativeInterface));
	env->vm = (vmJavaVM*)vm;
	env->args = iargs;
	env->stack_capacity = iargs->javaStackSize / sizeof(VM_STACK_SLOT_TYPE);
	env->stack = (VM_STACK_SLOT_TYPE*)p; p += iargs->javaStackSize;
	env->frame_capacity = iargs->javaStackSize / sizeof(VM_STACK_SLOT_TYPE);
	env->frame_buf = (VM_STACK_SLOT_TYPE*)p;
	env->thread_id = thread_id;
	env->hmem = hmem;

	/* put the environment to list */
	last_env->next = env; 
	env->prev = last_env;

	jniPushLocalFrame(*penv, VM_DEFAULT_LOCAL_REFERENCES_COUNT);
	ret = JNI_OK;
DONE:
	VM_LEAVE_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	return ret;
}


/**
   Detaches the current thread from the virtual machine.
   @param vm the Java VM interface pointer
   @return JNI_OK on success or an error code
*/
jint JNICALL jniDetachCurrentThread(JavaVM *vm) {
	vmJNIEnv *env; vmMemHandle hmem;
	if (vm == NULL)
		return JNI_EINVAL;

	/* the main thread can not be detached */
	if (JNI_OK != jniGetEnv(vm, (void**)&env, JNI_VERSION_1_1))
		return JNI_ERR;
	if ((void*)env == (void*)JVM_MAINENV(vm))
		return JNI_ERR;
	VM_ENTER_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	hmem = env->hmem;

	/* free thread stack */
	while (env->frame != NULL)
		jniPopLocalFrame((JNIEnv*)env, NULL);

	/* detach thread */
	if (env->next != NULL) env->next->prev = env->prev;
	if (env->prev != NULL) env->prev->next = env->next;

	/* release memory */
	vmMemSystemUnlock(hmem, (void*)vm);
	vmMemSystemFree(hmem);

	/* platform specific uninitialization */
	vmThreadUninitPlatformSpecific();

	VM_LEAVE_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	return JNI_OK;
}


/**
   Destroyes the virtual machine.
   @param vm the Java VM interface pointer
   @return JNI_OK on success or an error code
*/
jint JNICALL jniDestroyJavaVM(JavaVM *vm) {
	vmMemHandle hmem;
	JNIEnv *env; vmJNIEnv *main_env; jobject *heap;
	struct JavaVM_listitem *pvmi;
	jint i, size, entry_size, ret, max_heap_index;

	if (vm == NULL)
		return JNI_EINVAL;
	ret = JNI_ERR;
	main_env = JVM_MAINENV(vm);

	/* only the main thread can unload the VM */
	if (JNI_OK != jniGetEnv(vm, (void**)&env, JNI_VERSION_1_1))
		return JNI_ERR;
	if ((void*)env != (void*)main_env)
		return JNI_ERR;

	/* wait until the main thread is only remaining thread */
	VM_ENTER_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	while (main_env->next != NULL) {
		VM_LEAVE_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
		vmSleep(50);
		VM_ENTER_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	}
	hmem = main_env->hmem;
	heap = ((vmJavaVM*)vm)->heap;
	max_heap_index = ((vmJavaVM*)vm)->heap_max;
	size = ((vmJavaVM*)vm)->clsdef.capacity;
	entry_size = ((vmJavaVM*)vm)->clsdef.entry_size;

	/* remove the JVM from JavaVM list */
	pvmi = jvms;
	while (pvmi && (pvmi->pvm != vm))
		pvmi = pvmi->next;
	if (pvmi == NULL)
		goto DONE;
	if (jvms == pvmi)
		jvms = pvmi->next;
	if (pvmi->next)
		pvmi->next->prev = pvmi->prev;
	if (pvmi->prev)
		pvmi->prev->next = pvmi->next;

	/* unloade native libraries */
	for (i = 0; i < ((vmJavaVM*)vm)->lib_count; i++) {
		void *h;
		void (JNICALL *JNI_OnUnload)(JavaVM *, void *);
		h = ((vmJavaVM*)vm)->lib[i];
		JNI_OnUnload = (void (JNICALL*)(JavaVM *, void *))vmGetProcAddressUTF(h, "_JNI_OnUnload@8");
		if (JNI_OnUnload != NULL)
            JNI_OnUnload(vm, NULL);
	}

	/* clear thread stack */
	while (((vmJNIEnv*)env)->frame != NULL)
		jniPopLocalFrame(env, NULL);
	((vmJNIEnv*)env)->flags |= VM_JNIENV_DESTROYED;	/* no new object! */
	jniPushLocalFrame(env, VM_DEFAULT_LOCAL_REFERENCES_COUNT);

	/* call all finalizers */
	for (i = 0; i <= max_heap_index; i++) {
		jobject obj = heap[i];
		if (obj != NULL) {
			if (obj->flags & VM_OBJECT_FINALIZE_FLAG) {
				vmFrame *frame = ((vmJNIEnv*)env)->frame;
				VM_PUSH_OBJECT(frame, obj);
				vmExecuteMethod(frame, obj->clsdef->finalizeID, NULL);
			}
		}
	}

	/* free thread stack */
	while (((vmJNIEnv*)env)->frame != NULL)
		jniPopLocalFrame(env, NULL);

	/* free all objects */
	for (i = 0; i <= max_heap_index; i++) {
		jobject obj = heap[i];
		if (obj != NULL) {
			if (obj->flags & VM_OBJECT_FREEDATA_FLAG) _vmMemFree(obj->data);
			_vmMemFree(obj);			
		}
	}

	/* free class definitions */
	for (i = 0; i < size; i++) {
		hash_entry *e = (hash_entry*)(((vmJavaVM*)vm)->clsdef.slot + i * entry_size);
		while (e != NULL) {
			if (e->data != NULL) {
				class_cache_entry *cce = (class_cache_entry*)&(e->data);
				clsDefinition *cls = cce->cls;
				if (cls->access_flags & ACC_FREEMEM)
					_vmMemFree(cls);
			}
			e = e->next;
		}
	}

	/* release classes hash map */
	vmHashRelease(&((vmJavaVM*)vm)->clsdef);

	/* release native libraries */
	for (i = 0; i < ((vmJavaVM*)vm)->lib_count; i++)
		vmFreeLibrary(((vmJavaVM*)vm)->lib[i]);

	/* release system memory */
	VM_LEAVE_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	VM_UNINIT_CRITICAL_SECTION(((vmJavaVM*)vm)->gcs);
	vmMemSystemUnlock(hmem, (void*)vm);
	vmMemSystemFree(hmem);

	/* platform specific uninitialization */
	vmVMUninitPlatformSpecific();
	ret = JNI_OK;

DONE:
	return ret;
}


static struct JNIInvokeInterface DEFAULT_INVOKE_INTERFACE = {
	NULL,
	NULL,
	NULL,
	jniDestroyJavaVM,
	jniAttachCurrentThread,
	jniDetachCurrentThread,
	jniGetEnv
};


/*****************************************************************
 * Invocation API 
 *****************************************************************/

/**
   Returns a default VM configuration. The vm_args->version field must be set to the JNI_VERSION_1_1
   or the JNI_VERSION_1_2 before calling this function.
   @param vm_args a pointer to the VM configuration
          (for JNI_VERSION_1_1 must be a pointer to the JDK1_1InitArgs structure,
		   for JNI_VERSION_1_2 must be a pointer to the JavaVMInitArgs structure)
   @return JNI_OK on success or an error code
   @see the JDK1_1InitArgs structure
*/
JNIEXPORT jint JNICALL JNI_GetDefaultJavaVMInitArgs(void *vm_args) {
	JDK1_1InitArgs *arg;
	arg = (JDK1_1InitArgs*)vm_args;
	if (vm_args == NULL)
		return JNI_EINVAL;
	if ((arg->version != JNI_VERSION_1_1) && (arg->version != JNI_VERSION_1_2))
		return JNI_EVERSION;
	arg->nOptions = 0;
	arg->options = NULL;
	arg->ignoreUnrecognized = JNI_TRUE;
	if (arg->version == JNI_VERSION_1_1) {
		arg->nativeStackSize = VM_DEFAULT_NATIVE_STACK_SIZE;
		arg->javaStackSize = VM_DEFAULT_JAVA_STACK_SIZE;
		arg->minHeapSize = VM_DEFAULT_MIN_HEAP_SIZE;
		arg->maxHeapSize = VM_DEFAULT_MAX_HEAP_SIZE;
		arg->classpath = VM_DEFAULT_CLASSPATH;
	}
	return JNI_OK;
}


/**
   Returns all created virtual machines.
   @param vmBuf a pointer to the buffer
   @param bufLen the buffer length
   @param nVMs a pointer to an integer (the number of the returned VMs)
   @return JNI_OK on success or an error code
*/
JNIEXPORT jint JNICALL JNI_GetCreatedJavaVMs(JavaVM **vmBuf, jsize bufLen, jsize *nVMs) {
	jint cnt;
	struct JavaVM_listitem *pvmi;
	cnt = 0;
	pvmi = jvms;
	if (!vmBuf || (bufLen <= 0) || !nVMs) 
		return JNI_EINVAL;
	while (pvmi != NULL) {
		if (cnt >= bufLen)
			return JNI_ENOMEM;
		vmBuf[cnt++] = pvmi->pvm;
		pvmi->next;
	}
	*nVMs = cnt;
	return JNI_OK;
}


/**
   Creates new virtual machine.
   @param pvm a pointer to the location where the Java VM interface pointer is returned
   @param penv a pointer to the location where the main thread JNI interface pointer is returned
   @param args a pointer to the initial VM configuration 
          (for JNI_VERSION_1_1 must be a pointer to the JDK1_1InitArgs structure,
		   for JNI_VERSION_1_2 must be a pointer to the JavaVMInitArgs structure)
		   or NULL (the default configuration is used)
   @return JNI_OK on success or an error code
*/
JNIEXPORT jint JNICALL JNI_CreateJavaVM(JavaVM **pvm, JNIEnv **penv, void *args) {
	char *p; jint len, ret;
	struct JavaVM_listitem *pvmi; vmJNIEnv *env;
	JDK1_1InitArgs l_args, *p_args; vmMemHandle hmem;

	/* valid arguments? */
	if (!pvm || !penv)
		return JNI_EINVAL;
	if (args == NULL) {
		l_args.version = JNI_VERSION_1_1;
		if (JNI_OK != JNI_GetDefaultJavaVMInitArgs(&l_args))
			return JNI_ERR;
		args = &l_args;
	}
	if (((JDK1_1InitArgs*)args)->version != JNI_VERSION_1_1)
		if (((JDK1_1InitArgs*)args)->version != JNI_VERSION_1_2)
			return JNI_EVERSION;

	/* transform JDK 2 initial configuration to the JDK 1.1 configuration */
	if (((JDK1_1InitArgs*)args)->version == JNI_VERSION_1_2) {
		jint i;
		l_args.version = JNI_VERSION_1_1;
		if (JNI_OK != JNI_GetDefaultJavaVMInitArgs(&l_args))
			return JNI_ERR;
		l_args.version = JNI_VERSION_1_2;
		l_args.nOptions = ((JavaVMInitArgs*)args)->nOptions;
		l_args.options = ((JavaVMInitArgs*)args)->options;
		l_args.ignoreUnrecognized = ((JavaVMInitArgs*)args)->ignoreUnrecognized;
		args = &l_args;
		for (i = 0; i < l_args.nOptions; i++) {
			char *os = l_args.options[i].optionString;
			if (!strncmp(os, "-Djava.class.path=", 18))
				l_args.classpath = os + 18;
			if (!strncmp(os, "-Xoss=", 6)) {
				int x = 0; char r = 0;
				if (sscanf(os + 6, "%u%c", &x, &r)) {
					if (r == 'm') x *= 1048576;
					if (r == 'k') x *= 1024;
					if (x > 512) l_args.javaStackSize = x;
				}
			}
			if (!strncmp(os, "-Xnss=", 6)) {
				int x = 0; char r = 0;
				if (sscanf(os + 6, "%u%c", &x, &r)) {
					if (r == 'm') x *= 1048576;
					if (r == 'k') x *= 1024;
					if (x > 512) l_args.nativeStackSize = x;
				}
			}
			if (!strncmp(os, "-Xms=", 5)) {
				int x = 0; char r = 0;
				if (sscanf(os + 5, "%u%c", &x, &r)) {
					if (r == 'm') x *= 1048576;
					if (r == 'k') x *= 1024;
					if (x > 512) l_args.minHeapSize = x;
				}
			}
			if (!strncmp(os, "-Xmx=", 5)) {
				int x = 0; char r = 0;
				if (sscanf(os + 5, "%u%c", &x, &r)) {
					if (r == 'm') x *= 1048576;
					if (r == 'k') x *= 1024;
					if (x > 512) l_args.maxHeapSize = x;
				}
			}

		}
	}

	/* platform specific initialization */
	if (vmVMInitPlatformSpecific() != 0)
		return JNI_ERR;

	/* alloc memory */
	len = sizeof(vmJavaVM) + sizeof(natSynchronizeData) + sizeof(struct JavaVM_listitem) +
		sizeof(struct JNIInvokeInterface) +	(((JDK1_1InitArgs*)args)->maxHeapSize >> 5) +
		sizeof(JDK1_1InitArgs) + sizeof(vmJNIEnv) + sizeof(struct JNINativeInterface) +
		(2 * ((JDK1_1InitArgs*)args)->javaStackSize);
	hmem = vmMemSystemAlloc(len);
	if (hmem == NULL)
		return JNI_ENOMEM;
	p = vmMemSystemLock(hmem);
	if (p == NULL) {
		vmMemSystemFree(hmem);
		return JNI_ENOMEM;
	}

	/* create JavaVM */
	*pvm = (JavaVM*)p; p += sizeof(vmJavaVM);
	((vmJavaVM*)(*pvm))->gcs = (natSynchronizeData*)p; p += sizeof(natSynchronizeData);
	pvmi = (void*)p; p += sizeof(struct JavaVM_listitem);
	**pvm = (void*)p; p += sizeof(struct JNIInvokeInterface);
	vmMemCpy((void*)**pvm, &DEFAULT_INVOKE_INTERFACE, sizeof(struct JNIInvokeInterface));
	((vmJavaVM*)(*pvm))->heap = (void*)p; p += ((JDK1_1InitArgs*)args)->maxHeapSize >> 5;
	JVM_HEAP_SIZE(*pvm) = (((JDK1_1InitArgs*)args)->maxHeapSize >> 5) / sizeof(jobject*);
	(((vmJavaVM*)(*pvm))->heap_last) = JVM_HEAP_SIZE(*pvm) - 1;

	/* create init args */
	vmMemCpy(p, args, sizeof(JDK1_1InitArgs));
	p_args = (void*)p; p += sizeof(JDK1_1InitArgs);

	/* create main thread environment */
	env = (vmJNIEnv*)*penv = (void*)JVM_MAINENV(*pvm) = (vmJNIEnv*)p; p += sizeof(vmJNIEnv);
	env->iif = (void*)p; p += sizeof(struct JNINativeInterface);
	vmMemCpy((void*)env->iif, &DEFAULT_NATIVE_INTERFACE, sizeof(struct JNINativeInterface));
	env->vm = (vmJavaVM*)*pvm;
	env->args = env->vm->args = p_args;
	env->stack_capacity = ((JDK1_1InitArgs*)args)->javaStackSize / sizeof(VM_STACK_SLOT_TYPE);
	env->stack = (VM_STACK_SLOT_TYPE*)p; p += ((JDK1_1InitArgs*)args)->javaStackSize;
	env->frame_capacity = ((JDK1_1InitArgs*)args)->javaStackSize / sizeof(VM_STACK_SLOT_TYPE);
	env->frame_buf = (VM_STACK_SLOT_TYPE*)p;
	env->thread_id = vmGetCurrentThreadId();
	env->hmem = hmem;

	/* put the JVM to JavaVM list */
	pvmi->pvm = *pvm;
	pvmi->prev = NULL;
	pvmi->next = NULL;
	if (jvms != NULL) {
		struct JavaVM_listitem *last;
		last = jvms;
		while (last && last->next)
			last = last->next;
		pvmi->prev = last;
		last->next = pvmi;
	} else
		jvms = pvmi;

	/* JVM initialization */
	VM_INIT_CRITICAL_SECTION(((vmJavaVM*)*pvm)->gcs);
	jniPushLocalFrame(*penv, VM_DEFAULT_LOCAL_REFERENCES_COUNT);
	ret = vmRegisterCoreClasses((vmJavaVM*)*pvm, env);

	if (ret != JNI_OK) {
		vmMemSystemUnlock(hmem, NULL);
		vmMemSystemFree(hmem);
	}
	return ret;
}
