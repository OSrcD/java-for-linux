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
#include "Class.h"
#include "ClassLoader.h"
#include "Exceptions.h"
#include "String.h"
#include "StringBuffer.h"
#include "System.h"

#ifndef DSVM_LITE
#include "RuntimePermission.h"
#endif


jboolean JNICALL Java_java_lang_Class_checkMemberAccess(JNIEnv *env, jobject _this, jint access) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jobject sm = Java_java_lang_System_getSecurityManager(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_SYSTEM, 0));
	if (sm != NULL) {
		char *p = cls->name; while (*p && (*p != '/')) p++;
		jniCallVoidMethod(env, sm, vmGetInstanceMethod(sm->clsdef, "checkMemberAccess", "(Ljava/lang/Class;I)V", JNI_TRUE), _this, access);
		/* is class in a package? */
		if (jniExceptionOccurred(env) == NULL)
		if (*p == '/') {
			jstring pkg = jniNewStringUTF(env, cls->name);
			jchar *p = VM_STRING(pkg), *q = NULL;
			while (*p) { if (*p == '/') q = p; p++; }
			if (q != NULL) *q = 0; VM_STRING_LEN(pkg) = vmStrLen(VM_STRING(pkg));
			jniCallVoidMethod(env, sm, vmGetInstanceMethod(sm->clsdef, "checkPackageAccess", "(Ljava/lang/String;)V", JNI_TRUE), pkg);
			jniDeleteLocalRef(env, pkg);
		}
	}
	return (jniExceptionOccurred(env) != NULL);
}


/* =============================================================== */
/*  static methods                                                 */
/* =============================================================== */

static clsMethod Java_java_lang_Class_forName1ID = {&clsJAVA_LANG_CLASS, ACC_STATIC|ACC_NATIVE, "forName", "(Ljava/lang/String;)Ljava/lang/Class;",
	   0x66638a58, 0, Java_java_lang_Class_forName1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 1, 'L'};
jclass JNICALL Java_java_lang_Class_forName1(JNIEnv *env, jclass _clazz, jstring name) {
	return Java_java_lang_Class_forName2(env, _clazz, name, JNI_TRUE, NULL);
}


static clsMethod Java_java_lang_Class_forName2ID = {&clsJAVA_LANG_CLASS, ACC_STATIC|ACC_NATIVE, "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class",
	   0xc79a246d, 0, Java_java_lang_Class_forName2, 0, 0, 0, NULL, /* VM internal affairs */ 3, 3, 'L'};
jclass JNICALL Java_java_lang_Class_forName2(JNIEnv *env, jclass _clazz, jstring name, jboolean init, jobject loader) {
	if (loader == NULL)
		loader = ((vmJNIEnv*)env)->vm->loader;
	return jniCallObjectMethod(env, loader, 
		vmGetInstanceMethod(loader->clsdefdim, "loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", JNI_TRUE), 
		name, init);
}


static clsMethod* class_methods[] = {
	&Java_java_lang_Class_forName1ID,
	&Java_java_lang_Class_forName2ID
};


/* =============================================================== */
/*  instance methods                                               */
/* =============================================================== */


static clsMethod Java_java_lang_Class_desiredAssertionStatusID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "desiredAssertionStatus", "()Z", 
	   0x45d40e3, 0, Java_java_lang_Class_desiredAssertionStatus, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'Z'};
jboolean JNICALL Java_java_lang_Class_desiredAssertionStatus(JNIEnv *env, jobject _this) {
	return JNI_FALSE;
}


static clsMethod Java_java_lang_Class_getClassesID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getClasses", "()[Ljava/lang/Class;", 
	   0x2b42df39, 0, Java_java_lang_Class_getClasses, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getClasses(JNIEnv *env, jobject _this) {
	jarray ret = NULL; jobject list = NULL;	jint size, entry_size, i, chars; char buf[1024];
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm; jmethodID addmet;
	jclass listclass = jniFindClass(env, "java/util/ArrayList");
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	vmStrCpyUTF(buf, VM_CLASS_DEF(_this)->name); vmStrCatUTF(buf, "$"); chars = vmStrLenUTF(buf);
	size = vm->clsdef.capacity; entry_size = vm->clsdef.entry_size;
	for (i = 0; i < size; i++) {
		hash_entry *e = (hash_entry*)(vm->clsdef.slot + i * entry_size);
		while (e != NULL) {
			if (e->data != NULL) {
				class_cache_entry *cce = (class_cache_entry*)&(e->data);
				clsDefinition *cls = cce->cls;
				if ((cls->access_flags & ACC_PUBLIC) && !vmMemCmp(cls->name, buf, chars)) {
					if (list == NULL)
						list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
					if (list == NULL) 
						return NULL;
					jniCallBooleanMethod(env, list, addmet, cce->obj[0]);
				}
			}
			e = e->next;
		}
	}
	if (list != NULL) {
		ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
		jniDeleteLocalRef(env, list);
	}
	return ret;
}


static clsMethod Java_java_lang_Class_getComponentTypeID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getComponentType", "()Ljava/lang/Class;", 
	   0xdb6cb403, 0, Java_java_lang_Class_getComponentType, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jclass JNICALL Java_java_lang_Class_getComponentType(JNIEnv *env, jobject _this) {
	if (VM_CLASS_DIM(_this) > 0)
		return vmFindClassByDef((vmJNIEnv*)env, VM_CLASS_DEF(_this), VM_CLASS_DIM(_this) - 1);
	return NULL;
}


#if JAVA_LANG_REFLECT_ENABLED
static clsMethod Java_java_lang_Class_getConstructorID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", 
	   0xd0fa6d7e, 0, Java_java_lang_Class_getConstructor, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_Class_getConstructor(JNIEnv *env, jobject _this, jarray argTypes) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this); jmethodID met;
	jobject ret = NULL;	char name[] = "<init>", sig[8192] = "()V";
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	if (argTypes != NULL) {
		jint len = VM_ARRAY_LENGTH(argTypes), i; jclass *type = (jclass*)VM_ARRAY_ARRAY(argTypes);
		char *p = sig + 1; *p = 0;
		for (i = 0; i < len; i++) {
			clsDefinition *cls = VM_CLASS_DEF(type[i]); jint dim = VM_CLASS_DIM(type[i]), j;
			jboolean prim = (cls->name[1] == 0) && (dim == 0);
			for (j = 0; j < dim; j++) vmStrCatUTF(p, "[");
			if (!prim) vmStrCatUTF(p, "L");
			vmStrCatUTF(p, cls->name);
			if (!prim) vmStrCatUTF(p, ";");
			while (*p) p++;
		}
		vmStrCpyUTF(p, ")V");
	}
	met = vmGetInstanceMethod(cls, name, sig, JNI_FALSE);
	if (met != NULL)
		if (met->access_flags & ACC_PUBLIC)
			ret = jniToReflectedMethod(env, _this, met, JNI_FALSE);
	if (ret == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
	return ret;
}


static clsMethod Java_java_lang_Class_getConstructorsID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getConstructors", "()[Ljava/lang/reflect/Constructor;",
	   0x137d1836, 0, Java_java_lang_Class_getConstructors, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getConstructors(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jobject ret = NULL, list; jint i; vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jclass listclass = jniFindClass(env, "java/util/ArrayList"); jmethodID addmet;
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
	if (list == NULL) return NULL;
	for (i = 0; (i < cls->instance_methods_count) && !frame->exception; i++) {
		jmethodID met = cls->instance_methods[i]; jobject m;
		if (vmStrCmpUTF(met->name, "<init>")) continue;
		if (met->access_flags & ACC_PUBLIC) {
			m = jniToReflectedMethod(env, _this, met, JNI_FALSE);
			if (m == NULL) return NULL;
			jniCallBooleanMethod(env, list, addmet, m);
		}
	}
	ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
	jniDeleteLocalRef(env, list);
	return ret;
}


static clsMethod Java_java_lang_Class_getDeclaredConstructorID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getDeclaredConstructor", "([Ljava/lang/Class;)Ljava/lang/reflect/Constructor;", 
	   0xf3931f90, 0, Java_java_lang_Class_getDeclaredConstructor, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_Class_getDeclaredConstructor(JNIEnv *env, jobject _this, jarray argTypes) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this); jmethodID met;
	jobject ret = NULL;	char name[] = "<init>", sig[8192] = "()V";
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_DECLARED)) return NULL;
	if (argTypes != NULL) {
		jint len = VM_ARRAY_LENGTH(argTypes), i; jclass *type = (jclass*)VM_ARRAY_ARRAY(argTypes);
		char *p = sig + 1; *p = 0;
		for (i = 0; i < len; i++) {
			clsDefinition *cls = VM_CLASS_DEF(type[i]); jint dim = VM_CLASS_DIM(type[i]), j;
			jboolean prim = (cls->name[1] == 0) && (dim == 0);
			for (j = 0; j < dim; j++) vmStrCatUTF(p, "[");
			if (!prim) vmStrCatUTF(p, "L");
			vmStrCatUTF(p, cls->name);
			if (!prim) vmStrCatUTF(p, ";");
			while (*p) p++;
		}
		vmStrCpyUTF(p, ")V");
	}
	met = vmGetInstanceMethod(cls, name, sig, JNI_FALSE);
	if (met != NULL)
		ret = jniToReflectedMethod(env, _this, met, JNI_FALSE);
	if (ret == NULL)
		jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
	return ret;
}


static clsMethod Java_java_lang_Class_getDeclaredConstructorsID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getDeclaredConstructors", "()[Ljava/lang/reflect/Constructor;",
	   0x554abb90, 0, Java_java_lang_Class_getDeclaredConstructors, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getDeclaredConstructors(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jobject ret = NULL, list; jint i; vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jclass listclass = jniFindClass(env, "java/util/ArrayList"); jmethodID addmet;
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_DECLARED)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
	if (list == NULL) return NULL;
	for (i = 0; (i < cls->instance_methods_count) && !frame->exception; i++) {
		jmethodID met = cls->instance_methods[i]; jobject m;
		if (vmStrCmpUTF(met->name, "<init>")) continue;
		m = jniToReflectedMethod(env, _this, met, JNI_FALSE);
		if (m == NULL) return NULL;
		jniCallBooleanMethod(env, list, addmet, m);
	}
	ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
	jniDeleteLocalRef(env, list);
	return ret;
}


static clsMethod Java_java_lang_Class_getDeclaredFieldID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getDeclaredField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;", 
	   0x11c3f6d6, 0, Java_java_lang_Class_getDeclaredField, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_Class_getDeclaredField(JNIEnv *env, jobject _this, jstring name) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this); char _name[1024];
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_DECLARED)) return NULL;
	if (name == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL); 
		return NULL; 
	}
	if (toUtf8(_name, VM_STRING(name), VM_STRING_LEN(name)) > 0)
		while (cls != NULL) {
			jfieldID fld; jint i;
			for (i = 0; i < cls->instance_fields_count; i++) {
				fld = cls->instance_fields + i;
				if (!vmStrCmpUTF(fld->name, _name))
					return jniToReflectedField(env, _this, fld, JNI_FALSE);
			}
			for (i = 0; i < cls->class_fields_count; i++) {
				fld = cls->class_fields + i;
				if (!vmStrCmpUTF(fld->name, _name))
					return jniToReflectedField(env, _this, fld, JNI_TRUE);
			}
			cls = cls->super_class;
		}
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
	return NULL;
}


static clsMethod Java_java_lang_Class_getDeclaredFieldsID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getDeclaredFields", "()[Ljava/lang/reflect/Field;",
	   0xe862c790, 0, Java_java_lang_Class_getDeclaredFields, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getDeclaredFields(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jobject ret = NULL, list; jint i; vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jclass listclass = jniFindClass(env, "java/util/ArrayList"); jmethodID addmet;
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_DECLARED)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
	if (list == NULL) return NULL;
	for (i = 0; (i < cls->instance_fields_count) && !frame->exception; i++) {
		jfieldID fld = cls->instance_fields + i; jobject m;
		m = jniToReflectedField(env, _this, fld, JNI_FALSE);
		if (m == NULL) return NULL;
		jniCallBooleanMethod(env, list, addmet, m);
	}
	for (i = 0; (i < cls->class_fields_count) && !frame->exception; i++) {
		jfieldID fld = cls->class_fields + i; jobject m;
		m = jniToReflectedField(env, _this, fld, JNI_TRUE);
		if (m == NULL) return NULL;
		jniCallBooleanMethod(env, list, addmet, m);
	}
	ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
	jniDeleteLocalRef(env, list);
	return ret;
}


static clsMethod Java_java_lang_Class_getDeclaredMethodID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;", 
	   0xeb9a2866, 0, Java_java_lang_Class_getDeclaredMethod, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_Class_getDeclaredMethod(JNIEnv *env, jobject _this, jstring name, jarray argTypes) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	char _name[1024], sig[8192] = "()"; jmethodID met; jint i;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_DECLARED)) return NULL;
	if (name == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL); 
		return NULL; 
	}
	if (argTypes != NULL) {
		jint len = VM_ARRAY_LENGTH(argTypes), i; jclass *type = (jclass*)VM_ARRAY_ARRAY(argTypes);
		char *p = sig + 1; *p = 0;
		for (i = 0; i < len; i++) {
			clsDefinition *cls = VM_CLASS_DEF(type[i]); jint dim = VM_CLASS_DIM(type[i]), j;
			jboolean prim = (cls->name[1] == 0) && (dim == 0);
			for (j = 0; j < dim; j++) vmStrCatUTF(p, "[");
			if (!prim) vmStrCatUTF(p, "L");
			vmStrCatUTF(p, cls->name);
			if (!prim) vmStrCatUTF(p, ";");
			while (*p) p++;
		}
		vmStrCpyUTF(p, ")");
	}
	if (toUtf8(_name, VM_STRING(name), VM_STRING_LEN(name)) > 0)
		if (vmStrCmpUTF(_name, "<init>") && vmStrCmpUTF(_name, "<clinit>"))
			while (cls != NULL) {
				jint len = vmStrLenUTF(sig);
				for (i = 0; i < cls->instance_methods_count; i++) {
					met = cls->instance_methods[i];
					if (!vmStrCmpUTF(met->name, _name)) {
						if (vmStrLenUTF(met->descriptor) <= len) continue;
						if (!vmMemCmp(met->descriptor, sig, len))
							return jniToReflectedMethod(env, _this, met, JNI_FALSE);
					}
				}
				for (i = 0; i < cls->class_methods_count; i++) {
					met = cls->class_methods[i];
					if (!vmStrCmpUTF(met->name, _name)) {
						if (vmStrLenUTF(met->descriptor) <= len) continue;
						if (!vmMemCmp(met->descriptor, sig, len))
							return jniToReflectedMethod(env, _this, met, JNI_TRUE);
					}
				}
				cls = cls->super_class;
			}
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
	return NULL;
}


static clsMethod Java_java_lang_Class_getDeclaredMethodsID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getDeclaredMethods", "()[Ljava/lang/reflect/Method;",
	   0x641be600, 0, Java_java_lang_Class_getDeclaredMethods, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getDeclaredMethods(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jobject ret = NULL, list; jint i; vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jclass listclass = jniFindClass(env, "java/util/ArrayList"); jmethodID addmet;
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_DECLARED)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
	if (list == NULL) return NULL;
	for (i = 0; (i < cls->instance_methods_count) && !frame->exception; i++) {
		jmethodID met = cls->instance_methods[i]; jobject m;
		if (!vmStrCmpUTF(met->name, "<init>")) continue;
		m = jniToReflectedMethod(env, _this, met, JNI_FALSE);
		if (m == NULL) return NULL;
		jniCallBooleanMethod(env, list, addmet, m);
	}
	for (i = 0; (i < cls->class_methods_count) && !frame->exception; i++) {
		jmethodID met = cls->class_methods[i]; jobject m;
		if (!vmStrCmpUTF(met->name, "<clinit>")) continue;
		m = jniToReflectedMethod(env, _this, met, JNI_TRUE);
		if (m == NULL) return NULL;
		jniCallBooleanMethod(env, list, addmet, m);
	}
	ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
	jniDeleteLocalRef(env, list);
	return ret;
}


static clsMethod Java_java_lang_Class_getFieldID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getField", "(Ljava/lang/String;)Ljava/lang/reflect/Field;", 
	   0xf764a8b8, 0, Java_java_lang_Class_getField, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jobject JNICALL Java_java_lang_Class_getField(JNIEnv *env, jobject _this, jstring name) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this); char _name[1024];
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	if (name == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL); 
		return NULL; 
	}
	if (toUtf8(_name, VM_STRING(name), VM_STRING_LEN(name)) > 0)
		while (cls != NULL) {
			jfieldID fld; jint i;
			for (i = 0; i < cls->instance_fields_count; i++) {
				fld = cls->instance_fields + i;
				if ((fld->access_flags & ACC_PUBLIC) && !vmStrCmpUTF(fld->name, _name))
					return jniToReflectedField(env, _this, fld, JNI_FALSE);
			}
			for (i = 0; i < cls->class_fields_count; i++) {
				fld = cls->class_fields + i;
				if ((fld->access_flags & ACC_PUBLIC) && !vmStrCmpUTF(fld->name, _name))
					return jniToReflectedField(env, _this, fld, JNI_TRUE);
			}
			cls = cls->super_class;
		}
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
	return NULL;
}


static clsMethod Java_java_lang_Class_getFieldsID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getFields", "()[Ljava/lang/reflect/Field;",
	   0x37e66ab6, 0, Java_java_lang_Class_getFields, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getFields(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jobject ret = NULL, list; jint i; vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jclass listclass = jniFindClass(env, "java/util/ArrayList"); jmethodID addmet;
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
	if (list == NULL) return NULL;
	for (i = 0; (i < cls->instance_fields_count) && !frame->exception; i++) {
		jfieldID fld = cls->instance_fields + i; jobject m;
		if (fld->access_flags & ACC_PUBLIC) {
			m = jniToReflectedField(env, _this, fld, JNI_FALSE);
			if (m == NULL) return NULL;
			jniCallBooleanMethod(env, list, addmet, m);
		}
	}
	for (i = 0; (i < cls->class_fields_count) && !frame->exception; i++) {
		jfieldID fld = cls->class_fields + i; jobject m;
		if (fld->access_flags & ACC_PUBLIC) {
			m = jniToReflectedField(env, _this, fld, JNI_TRUE);
			if (m == NULL) return NULL;
			jniCallBooleanMethod(env, list, addmet, m);
		}
	}
	ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
	jniDeleteLocalRef(env, list);
	return ret;
}


static clsMethod Java_java_lang_Class_getMethodID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;", 
	   0x1d1e8500, 0, Java_java_lang_Class_getMethod, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};
jobject JNICALL Java_java_lang_Class_getMethod(JNIEnv *env, jobject _this, jstring name, jarray argTypes) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	char _name[1024], sig[8192] = "()"; jmethodID met; jint i;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	if (name == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL); 
		return NULL; 
	}
	if (argTypes != NULL) {
		jint len = VM_ARRAY_LENGTH(argTypes), i; jclass *type = (jclass*)VM_ARRAY_ARRAY(argTypes);
		char *p = sig + 1; *p = 0;
		for (i = 0; i < len; i++) {
			clsDefinition *cls = VM_CLASS_DEF(type[i]); jint dim = VM_CLASS_DIM(type[i]), j;
			jboolean prim = (cls->name[1] == 0) && (dim == 0);
			for (j = 0; j < dim; j++) vmStrCatUTF(p, "[");
			if (!prim) vmStrCatUTF(p, "L");
			vmStrCatUTF(p, cls->name);
			if (!prim) vmStrCatUTF(p, ";");
			while (*p) p++;
		}
		vmStrCpyUTF(p, ")");
	}
	if (toUtf8(_name, VM_STRING(name), VM_STRING_LEN(name)) > 0)
		if (vmStrCmpUTF(_name, "<init>") && vmStrCmpUTF(_name, "<clinit>"))
			while (cls != NULL) {
				jint len = vmStrLenUTF(sig);
				for (i = 0; i < cls->instance_methods_count; i++) {
					met = cls->instance_methods[i];
					if ((met->access_flags & ACC_PUBLIC) && !vmStrCmpUTF(met->name, _name)) {
						if (vmStrLenUTF(met->descriptor) <= len) continue;
						if (!vmMemCmp(met->descriptor, sig, len))
							return jniToReflectedMethod(env, _this, met, JNI_FALSE);
					}
				}
				for (i = 0; i < cls->class_methods_count; i++) {
					met = cls->class_methods[i];
					if ((met->access_flags & ACC_PUBLIC) && !vmStrCmpUTF(met->name, _name)) {
						if (vmStrLenUTF(met->descriptor) <= len) continue;
						if (!vmMemCmp(met->descriptor, sig, len))
							return jniToReflectedMethod(env, _this, met, JNI_TRUE);
					}
				}
				cls = cls->super_class;
			}
	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_NOSUCHMETHODEXCEPTION.name), NULL); 
	return NULL;
}


static clsMethod Java_java_lang_Class_getMethodsID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getMethods", "()[Ljava/lang/reflect/Method;",
	   0x6a69169e, 0, Java_java_lang_Class_getMethods, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getMethods(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jobject ret = NULL, list; jint i; vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jclass listclass = jniFindClass(env, "java/util/ArrayList"); jmethodID addmet;
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
	if (list == NULL) return NULL;
	for (i = 0; (i < cls->instance_methods_count) && !frame->exception; i++) {
		jmethodID met = cls->instance_methods[i]; jobject m;
		if (!vmStrCmpUTF(met->name, "<init>")) continue;
		if (met->access_flags & ACC_PUBLIC) {
			m = jniToReflectedMethod(env, _this, met, JNI_FALSE);
			if (m == NULL) return NULL;
			jniCallBooleanMethod(env, list, addmet, m);
		}
	}
	for (i = 0; (i < cls->class_methods_count) && !frame->exception; i++) {
		jmethodID met = cls->class_methods[i]; jobject m;
		if (!vmStrCmpUTF(met->name, "<clinit>")) continue;
		if (met->access_flags & ACC_PUBLIC) {
			m = jniToReflectedMethod(env, _this, met, JNI_TRUE);
			if (m == NULL) return NULL;
			jniCallBooleanMethod(env, list, addmet, m);
		}
	}
	ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
	jniDeleteLocalRef(env, list);
	return ret;
}
#endif	/* JAVA_LANG_REFLECT_ENABLED */


static clsMethod Java_java_lang_Class_getDeclaredClassesID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getDeclaredClasses", "()[Ljava/lang/Class;",
	   0x294cc89f, 0, Java_java_lang_Class_getDeclaredClasses, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getDeclaredClasses(JNIEnv *env, jobject _this) {
	jarray ret = NULL; jobject list = NULL;	jint size, entry_size, i, chars; char buf[1024];
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm; jmethodID addmet;
	jclass listclass = jniFindClass(env, "java/util/ArrayList");
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_DECLARED)) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	vmStrCpyUTF(buf, VM_CLASS_DEF(_this)->name); vmStrCatUTF(buf, "$"); chars = vmStrLenUTF(buf);
	size = vm->clsdef.capacity;
	entry_size = vm->clsdef.entry_size;
	for (i = 0; i < size; i++) {
		hash_entry *e = (hash_entry*)(vm->clsdef.slot + i * entry_size);
		while (e != NULL) {
			if (e->data != NULL) {
				class_cache_entry *cce = (class_cache_entry*)&(e->data);
				clsDefinition *cls = cce->cls;
				if (!vmMemCmp(cls->name, buf, chars)) {
					if (list == NULL)
						list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
					if (list == NULL)
						return NULL;
					jniCallBooleanMethod(env, list, addmet, cce->obj[0]);
				}
			}
			e = e->next;
		}
	}
	if (list != NULL) {
		ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
		jniDeleteLocalRef(env, list);
	}
	return ret;
}


static clsMethod Java_java_lang_Class_getInterfacesID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getInterfaces", "()[Ljava/lang/Class;",
	   0xd5145e99, 0, Java_java_lang_Class_getInterfaces, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jarray JNICALL Java_java_lang_Class_getInterfaces(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jarray ret = NULL; jobject list = NULL;	jint i;  vmFrame *frame = ((vmJNIEnv*)env)->frame;
	jclass listclass = jniFindClass(env, "java/util/ArrayList"); jmethodID addmet;
	if (listclass == NULL) return NULL;
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	list = jniNewObjectA(env, listclass, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "<init>", "()V", JNI_FALSE), NULL);
	if (list == NULL) return NULL;
	addmet = vmGetInstanceMethod(VM_CLASS_DEF(listclass), "add", "(Ljava/lang/Object;)Z", JNI_TRUE);
	for (i = 0; (i < cls->interfaces_count) && !frame->exception; i++) {
		clsDefinition *itf = cls->interfaces[i];
		jclass clazz = vmFindClassByDef((vmJNIEnv*)env, itf, 0);
		jniCallBooleanMethod(env, list, addmet, clazz);
	}
	if (list != NULL) {
		ret = jniCallObjectMethodA(env, list, vmGetInstanceMethod(VM_CLASS_DEF(listclass), "toArray", "()[Ljava/lang/Object;", JNI_TRUE), NULL);
		jniDeleteLocalRef(env, list);
	}
	return ret;
}


static clsMethod Java_java_lang_Class_getModifiersID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getModifiers", "()I", 
	   0x8e1d52ae, 0, Java_java_lang_Class_getModifiers, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};
jint JNICALL Java_java_lang_Class_getModifiers(JNIEnv *env, jclass _this) {
	return VM_CLASS_DEF(_this)->access_flags;
}


static clsMethod Java_java_lang_Class_getCanonicalNameID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getCanonicalName", "()Ljava/lang/String;",
	   0x482fa422, 0, Java_java_lang_Class_getCanonicalName, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Class_getCanonicalName(JNIEnv *env, jclass _this) {
	jint i; char buf[VM_MAX_PATH_LEN], *p = buf;
	if (Java_java_lang_Class_isPrimitive(env, _this))
		return Java_java_lang_Class_getName(env, _this);
	vmStrCpyUTF(buf, VM_CLASS_DEF(_this)->name);
	while (*p) { if (*p == '/') *p = '.'; p++; }
	for (i = 0; i < VM_CLASS_DIM(_this); i++) vmStrCatUTF(buf, "[]");
	return jniNewStringUTF(env, buf);
}


static clsMethod Java_java_lang_Class_getClassLoaderID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getClassLoader", "()Ljava/lang/ClassLoader;",
	   0x93f9d17a, 0, Java_java_lang_Class_getClassLoader, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jobject JNICALL Java_java_lang_Class_getClassLoader(JNIEnv *env, jobject _this) {
	jobject ret = VM_CLASS_LOADER(_this);
	jobject sm = Java_java_lang_System_getSecurityManager(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_SYSTEM, 0));
	if (Java_java_lang_Class_isPrimitive(env, _this))
		return NULL;
	if ((sm != NULL) && (ret != NULL)) {
		jobject caller_loader = NULL;
		vmFrame *frame = ((vmJNIEnv*)env)->frame;
		while ((caller_loader == NULL) && (frame != NULL)) {
			if (frame->met != NULL) {
				jclass clazz = vmFindClassByDef((vmJNIEnv*)env, frame->met->clsdef, 0);
				if (clazz != NULL) caller_loader = VM_CLASS_LOADER(clazz);
			}
			frame = frame->prev;
		}
#ifndef DSVM_LITE
		if (caller_loader != NULL) {
			jobject perm = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_RUNTIMEPERMISSION, 0));
			jstring name = jniNewStringUTF(env, "getClassLoader");
			if (perm != NULL)
				Java_java_lang_RuntimePermission_RuntimePermission1(env, perm, name);
			jniDeleteLocalRef(env, name);
			jniCallVoidMethod(env, sm, vmGetInstanceMethod(sm->clsdef, "checkPermission", "(Ljava/security/Permission;)V", JNI_TRUE), perm);
			jniDeleteLocalRef(env, perm);
			if (jniExceptionOccurred(env)) return NULL;
			ret = caller_loader;
		}
#endif
	}
	return ret;
}


static clsMethod Java_java_lang_Class_getNameID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getName", "()Ljava/lang/String;",
	   0x884df2ca, 0, Java_java_lang_Class_getName, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Class_getName(JNIEnv *env, jclass _this) {
	jint i, dim = VM_CLASS_DIM(_this);
	char buf[VM_MAX_PATH_LEN], *p = buf, *name = VM_CLASS_DEF(_this)->name;
	buf[0] = 0;
	if (Java_java_lang_Class_isPrimitive(env, _this))
		switch (name[0]) {
			case 'V': vmStrCpyUTF(buf, "void"); goto DONE;
			case 'Z': vmStrCpyUTF(buf, "boolean"); goto DONE;
			case 'B': vmStrCpyUTF(buf, "byte"); goto DONE;
			case 'C': vmStrCpyUTF(buf, "char"); goto DONE;
			case 'S': vmStrCpyUTF(buf, "short"); goto DONE;
			case 'I': vmStrCpyUTF(buf, "int"); goto DONE;
			case 'J': vmStrCpyUTF(buf, "long"); goto DONE;
			case 'F': vmStrCpyUTF(buf, "float"); goto DONE;
			case 'D': vmStrCpyUTF(buf, "double"); goto DONE;
		}
	for (i = 0; i < dim; i++) vmStrCatUTF(buf, "[");
	if ((dim > 0) && (name[1] != 0)) vmStrCatUTF(buf, "L");
	vmStrCatUTF(buf, name);
	if ((dim > 0) && (name[1] != 0)) vmStrCatUTF(buf, ";");
	while (*p) { if (*p == '/') *p = '.'; p++; }
DONE:
	return jniNewStringUTF(env, buf);
}


static clsMethod Java_java_lang_Class_getSimpleNameID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "getSimpleName", "()Ljava/lang/String;",
	   0xeb26be98, 0, Java_java_lang_Class_getSimpleName, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Class_getSimpleName(JNIEnv *env, jclass _this) {
	jint i; char buf[VM_MAX_PATH_LEN], *p = VM_CLASS_DEF(_this)->name, *q = p;
	if (Java_java_lang_Class_isPrimitive(env, _this))
		return Java_java_lang_Class_getName(env, _this);
	while (*p) if (*(p++) == '/') q = p;
	vmStrCpyUTF(buf, q);
	for (i = 0; i < VM_CLASS_DIM(_this); i++) vmStrCatUTF(buf, "[]");
	return jniNewStringUTF(env, buf);
}


static clsMethod Java_java_lang_Class_isArrayID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "isArray", "()Z",
	   0x7a758436, 0, Java_java_lang_Class_isArray, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'Z'};
jboolean JNICALL Java_java_lang_Class_isArray(JNIEnv *env, jobject _this) {
	return VM_CLASS_DIM(_this) > 0;
}


static clsMethod Java_java_lang_Class_isAssignableFromID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "isAssignableFrom", "(Ljava/lang/Class;)Z",
	   0xa442f9b1, 0, Java_java_lang_Class_isAssignableFrom, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_Class_isAssignableFrom(JNIEnv *env, jobject _this, jclass cls) {
	if (cls == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL); 
		return JNI_FALSE; 
	}
	return jniIsAssignableFrom(env, cls, _this);
}


static clsMethod Java_java_lang_Class_isInstanceID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "isInstance", "(Ljava/lang/Object;)Z",
	   0xac9c43ca, 0, Java_java_lang_Class_isInstance, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'Z'};
jboolean JNICALL Java_java_lang_Class_isInstance(JNIEnv *env, jobject _this, jobject obj) {
	if (obj == NULL) {
		jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), NULL); 
		return JNI_FALSE; 
	}
	return jniIsAssignableFrom(env, _this, jniGetObjectClass(env, _this));
}


static clsMethod Java_java_lang_Class_isInterfaceID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "isInterface", "()Z",
	   0x64323456, 0, Java_java_lang_Class_isInterface, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'Z'};
jboolean JNICALL Java_java_lang_Class_isInterface(JNIEnv *env, jclass _this) {
	return VM_CLASS_DEF(_this)->access_flags & ACC_INTERFACE;
}


static clsMethod Java_java_lang_Class_isPrimitiveID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "isPrimitive", "()Z",
	   0xd8e0d5a4, 0, Java_java_lang_Class_isPrimitive, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'Z'};
jboolean JNICALL Java_java_lang_Class_isPrimitive(JNIEnv *env, jclass _this) {
	return (VM_CLASS_DEF(_this)->name[1] == 0) && (VM_CLASS_DIM(_this) == 0);
}


static clsMethod Java_java_lang_Class_newInstanceID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "newInstance", "()Ljava/lang/Object;",
	   0xeaf33608, 0, Java_java_lang_Class_newInstance, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jobject JNICALL Java_java_lang_Class_newInstance(JNIEnv *env, jobject _this) {
	clsDefinition *cls = VM_CLASS_DEF_DIM(_this);
	jmethodID met = vmGetInstanceMethod(cls, "<init>", "()V", JNI_FALSE);
	if (Java_java_lang_Class_checkMemberAccess(env, _this, CONST_MEMBER_PUBLIC)) return NULL;
	if (met == NULL) {
NOMET:	jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_INSTANTIATIONEXCEPTION, 0), NULL); 
		return NULL; 
	}
	if (VM_CLASS_DIM(_this) > 0) goto NOMET;
	if (cls->access_flags & ACC_ABSTRACT) goto NOMET;
	if (cls->access_flags & ACC_INTERFACE) goto NOMET;
	if ((cls->access_flags & ACC_PUBLIC) == 0) {
NOACC:	jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_ILLEGALACCESSEXCEPTION, 0), NULL); 
		return NULL;
	}
	if ((met->access_flags & ACC_PUBLIC) == 0) goto NOACC;
	return jniNewObjectA(env, _this, met, NULL);
}


static clsMethod Java_java_lang_Class_toStringID = {&clsJAVA_LANG_CLASS, ACC_PUBLIC|ACC_NATIVE, "toString", "()Ljava/lang/String;",
	   0xe5d943a7, 0, Java_java_lang_Class_toString, 0, 10, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Class_toString(JNIEnv *env, jobject _this) {
	jstring ret = NULL, tmp;
	clsDefinition *cls = VM_CLASS_DEF(_this);
	jboolean prim = Java_java_lang_Class_isPrimitive(env, _this);
	jobject sb = jniAllocObject(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_STRINGBUFFER, 0));
	if (sb != NULL) {
		jchar *prefix = (cls->access_flags & ACC_INTERFACE) ? JSTRING("interface ") : JSTRING("class ");
		Java_java_lang_StringBuffer_StringBuffer2(env, sb, 256);
		if (!prim)
			Java_java_lang_StringBuffer_append(env, sb, prefix, vmStrLen(prefix));
		tmp = Java_java_lang_Class_getName(env, _this);
		if (tmp != NULL) { 
			Java_java_lang_StringBuffer_append10(env, sb, tmp);
			jniDeleteLocalRef(env, tmp);
		}
		ret = Java_java_lang_StringBuffer_toString(env, sb);
		jniDeleteLocalRef(env, sb);
	}
	return ret;
}


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsField instance_fields[] = {
	{&clsJAVA_LANG_CLASS, ACC_PRIVATE, "_classloader", "Ljava/lang/ClassLoader;", 0xf70ae4fc, 0, NULL,
		/* VM internal affairs */ sizeof(clsDefinition*), NULL}
};

static clsMethod* instance_methods[] = {
	&Java_java_lang_Class_desiredAssertionStatusID,
	&Java_java_lang_Class_getClassesID,
	&Java_java_lang_Class_getClassLoaderID,
	&Java_java_lang_Class_getComponentTypeID,
#if JAVA_LANG_REFLECT_ENABLED
	&Java_java_lang_Class_getConstructorID,
	&Java_java_lang_Class_getConstructorsID,
	&Java_java_lang_Class_getDeclaredConstructorID,
	&Java_java_lang_Class_getDeclaredConstructorsID,
	&Java_java_lang_Class_getDeclaredFieldID,
	&Java_java_lang_Class_getDeclaredFieldsID,
	&Java_java_lang_Class_getDeclaredMethodID,
	&Java_java_lang_Class_getDeclaredMethodsID,
	&Java_java_lang_Class_getFieldID,
	&Java_java_lang_Class_getFieldsID,
	&Java_java_lang_Class_getMethodID,
	&Java_java_lang_Class_getMethodsID,
#endif	/* JAVA_LANG_REFLECT_ENABLED */
	&Java_java_lang_Class_getDeclaredClassesID,
	&Java_java_lang_Class_getInterfacesID,
	&Java_java_lang_Class_getModifiersID,
	&Java_java_lang_Class_getNameID,
	&Java_java_lang_Class_isArrayID,
	&Java_java_lang_Class_isAssignableFromID,
	&Java_java_lang_Class_isInstanceID,
	&Java_java_lang_Class_isInterfaceID,
	&Java_java_lang_Class_isPrimitiveID,
	&Java_java_lang_Class_newInstanceID,
	&Java_java_lang_Class_toStringID,
	/* support methods */
	&Java_java_lang_Class_getCanonicalNameID,
	&Java_java_lang_Class_getSimpleNameID
};

clsDefinition clsJAVA_LANG_CLASS = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/Class",             /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0x76F84404,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC | ACC_SUPER,        /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	0,                             /* class_fields_count */
	NULL,			               /* class_fields */
	sizeof(instance_fields) / sizeof(clsField), /* instance_fields_count */
	instance_fields,               /* instance_fields */
	sizeof(class_methods) / sizeof(clsMethod*), /* class_methods_count */
	class_methods,                 /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,              /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(JavaLangClassIData),    /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  primitive types                                                */
/* =============================================================== */

#define DEFINE_PRIMITIVE_TYPE(TYPE, NAME, HASH, TYPE_SIZE) \
clsDefinition cls##TYPE = { \
	VM_CLASS_MINOR_VERSION,        /* minor_version */ \
	VM_CLASS_MAJOR_VERSION,        /* major_version */ \
	NAME,                          /* name */ \
	NULL,                          /* super_class */ \
	HASH,                          /* name hash */ \
	0,                             /* constant_pool_count */ \
	NULL,                          /* constant_pool */ \
	ACC_PUBLIC + ACC_FINAL,        /* access_flags */ \
	0,                             /* interfaces_count */ \
	NULL,                          /* interfaces */ \
	0,                             /* class_fields_count */ \
	NULL,			               /* class_fields */ \
	0,                             /* instance_fields_count */ \
	NULL,                          /* instance_fields */ \
	0,                             /* class_methods_count */ \
	NULL,			               /* class_methods */ \
	0,                             /* instance_methods_count */ \
	NULL,                          /* instance_methods */ \
	0,                             /* attributes_count */ \
	NULL,                          /* attributes */ \
	sizeof(JavaLangClassIData),    /* data size of this class only */ \
	0,                             /* total data size is computed in vmDefineClass() */ \
	NULL,                          /* finalize() method */ \
	TYPE_SIZE                      /* primitive array element size */ \
};

DEFINE_PRIMITIVE_TYPE(VOID, "V", 0x56, 0);
DEFINE_PRIMITIVE_TYPE(BOOLEAN, "Z", 0x5A, sizeof(jboolean));
DEFINE_PRIMITIVE_TYPE(BYTE, "B", 0x42, sizeof(jbyte));
DEFINE_PRIMITIVE_TYPE(CHAR, "C", 0x43, sizeof(jchar));
DEFINE_PRIMITIVE_TYPE(SHORT, "S", 0x53, sizeof(jshort));
DEFINE_PRIMITIVE_TYPE(INT, "I", 0x49, sizeof(jint));
DEFINE_PRIMITIVE_TYPE(LONG, "J", 0x4A, sizeof(jlong));
DEFINE_PRIMITIVE_TYPE(FLOAT, "F", 0x46, sizeof(jfloat));
DEFINE_PRIMITIVE_TYPE(DOUBLE, "D", 0x44, sizeof(jdouble));
