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

#include "config.h"
#include "java\lang\Class.h"
#include "java\lang\ClassLoader.h"
#include "java\lang\Object.h"
#include "java\lang\String.h"
#include "java\lang\Throwable.h"
#include "java\lang\Errors.h"
#include "java\lang\Exceptions.h"
#include "java\lang\StackTraceElement.h"

void vmRegister_JavaIoPackage(vmJavaVM *vm, vmJNIEnv *env);
void vmRegister_JavaLangPackage(vmJavaVM *vm, vmJNIEnv *env);
#if JAVA_LANG_REFLECT_ENABLED
void vmRegister_JavaLangReflectPackage(vmJavaVM *vm, vmJNIEnv *env);
#endif
#if JAVA_MATH_ENABLED
void vmRegister_JavaMathPackage(vmJavaVM *vm, vmJNIEnv *env);
#endif
#if JAVA_NET_ENABLED
void vmRegister_JavaNetPackage(vmJavaVM *vm, vmJNIEnv *env);
#endif
#if JAVA_TEXT_ENABLED
void vmRegister_JavaTextPackage(vmJavaVM *vm, vmJNIEnv *env);
#endif
#if JAVA_UTIL_ZIP_ENABLED
void vmRegister_JavaUtilZipPackage(vmJavaVM *vm, vmJNIEnv *env);
#endif
#ifndef DSVM_LITE
void vmRegister_JavaSecurityPackage(vmJavaVM *vm, vmJNIEnv *env);
void vmRegister_JavaUtilPackage(vmJavaVM *vm, vmJNIEnv *env);
void vmRegister_JavaBeansPackage(vmJavaVM *vm, vmJNIEnv *env);
#endif


/*****************************************************************
 * Hash map
 *****************************************************************/

/**
   The Unicode zero string hash function.
   @param str a pointer to the Unicode string
   @param unused the unused parameter
   @return the hash value for the Unicode zero string
*/
jint FASTCALL vmZeroStringHashFce(const jchar *str, juint unused) {
	register jint ret;
	ret = 0;
	while (*str)
		ret = (31 * ret) + (jint)(*(str++));
	return ret;
}


/**
   The Unicode string hash function.
   @param str a pointer to the Unicode string
   @param len number of the string characters
   @return the hash value for the Unicode string
*/
jint FASTCALL vmStringHashFce(const jchar *str, juint len) {
	register jint ret;
	ret = 0;
	while (len--) 
		ret = (31 * ret) + (jint)(*(str++));
	return ret;
}


/**
   The UTF-8 zero string hash function.
   @param str a pointer to the UTF-8 zero string
   @param unused the unused parameter
   @return the hash value for the UTF-8 zero string
*/
jint FASTCALL vmZeroStringHashFceUTF(const char *str, juint unused) {
	register jint ret;
	ret = 0;
	while (*str)
		ret = (31 * ret) + (jint)(*(str++));
	return ret;
}


/**
   The UTF-8 string hash function.
   @param str a pointer to the UTF-8 string
   @param len number of the string characters
   @return the hash value for the UTF-8 string
*/
jint FASTCALL vmStringHashFceUTF(const char *str, juint len) {
	register jint ret;
	ret = 0;
	while (len--)
		ret = (31 * ret) + (jint)(*(str++));
	return ret;
}


/**
   The memory compare function.
   @param key1 a pointer to the key
   @param key2 a pointer to the key
   @param len1 length of the @a key1 in bytes
   @param len2 length of the @a key2 in bytes
   @return 0 if @a key1 is identical to @a key2
*/
jint vmMemCompareFce(const void *key1, const void *key2, juint len1, juint len2) {
	if (len1 == len2)
		return vmMemCmp(key1, key2, len1);
	return 1;
}


/**
   The Unicode zero string compare function.
   @param str1 a pointer to the Unicode zero string
   @param str2 a pointer to the Unicode zero string
   @param len1 number of the @a str1 string characters
   @param len2 number of the @a str2 string characters
   @return 0 if string1 is identical to string2
*/
jint vmZeroStringCompareFce(const void *str1, const void *str2, juint len1, juint len2) {
	if (len1 == len2)
		return vmStrCmp(str1, str2);
	if (len1 == 0)
		return vmStrnCmp(str1, str2, len2);
	if (len2 == 0)
		return vmStrnCmp(str1, str2, len1);
	return 1;
}


/**
   The UTF-8 zero string compare function.
   @param str1 a pointer to the UTF-8 zero string
   @param str2 a pointer to the UTF-8 zero string
   @param len1 number of the @a str1 string characters
   @param len2 number of the @a str2 string characters
   @return 0 if string1 is identical to string2
*/
jint vmZeroStringCompareFceUTF(const void *str1, const void *str2, juint len1, juint len2) {
	if (len1 == len2)
		return vmStrCmpUTF(str1, str2);
	if (len1 == 0)
		return vmStrnCmpUTF(str1, str2, len2);
	if (len2 == 0)
		return vmStrnCmpUTF(str1, str2, len1);
	return 1;
}


/**
   Initializes a Hash map.
   @param vm the Java VM interface pointer
   @param root the hash map root
   @param capacity the initial capacity
   @param threshold Number of the entries when to make first rehash operation
   @param internal_data_len an entry internal data length (by default a hash map entry contains
          pointer to an external data, but the entry can to contain data internally too - 
		  then it is possible held hash map entry properties and entry data in only one memory block)
   @param cfce entry key compare function
*/
void vmHashInit(vmJavaVM *vm, hash_root *root, juint capacity, juint threshold, juint internal_data_len, compare_fce cfce) {
	internal_data_len -= (internal_data_len > sizeof(void*)) ? sizeof(void*) : internal_data_len;
	root->vm = vm;
	root->entry_size = sizeof(hash_entry) + internal_data_len;
	root->size = 0;
	root->capacity = VM_MAX(capacity, 16);
	root->threshold = VM_MAX(threshold, 4);
	root->compare = cfce;
	root->slot = vmMemAlloc(vm, root->capacity * root->entry_size);
	vmMemSetZero(root->slot, root->capacity * root->entry_size);
}


/**
   Releases a hash map.
   @param root the hash map root
*/
void vmHashRelease(hash_root *root) {
	juint i;
	VM_ENTER_CRITICAL_SECTION(root->vm->gcs);
	for(i = 0; i < root->capacity; i++) {
		hash_entry *pom, *e = (hash_entry*)(root->slot + i * root->entry_size); 
		e = e->next;
		while (e) {
			pom = e; e = e->next; vmMemFree(root->vm, pom);
		}
	}
	vmMemFree(root->vm, root->slot);
	root->slot = NULL;
	VM_LEAVE_CRITICAL_SECTION(root->vm->gcs);
}


/**
   Inserts new entry to the hash map.
   @param root the hash map root
   @param data a pointer to the data
   @param key a pointer to the key 
   @param key_len the key length
   @param hfce a hash function
   @return the new entry or NULL if an error occurs
*/
hash_entry FASTCALL *vmHashInsertEntry_Fce(hash_root *root, void *data, const void *key, juint key_len, hash_fce hfce) {
	return vmHashInsertEntry_Hash(root, data, key, key_len, hfce(key, key_len));
}

	
/**
   Inserts new entry to the hash map.
   @param root the hash map root
   @param data a pointer to the data
   @param key a pointer to the key 
   @param key_len the key length
   @param hash the key hash value
   @return the new entry or NULL if an error occurs
*/
hash_entry *vmHashInsertEntry_Hash(hash_root *root, void *data, const void *key, juint key_len, jint hash) {
	hash_entry *e;
	VM_ENTER_CRITICAL_SECTION(root->vm->gcs);
	e = (hash_entry*)(root->slot + ((unsigned)hash % root->capacity) * root->entry_size);
	if (e->key != NULL)
		while (e != NULL) {
			if (e->hash == hash)
				if (!root->compare(e->key, key, e->key_len, key_len)) 
					break;
			if (e->next != NULL)
				e = e->next;
			else {
				if (NULL == (e->next = vmMemAlloc(root->vm, root->entry_size)))
                    return NULL;
				vmMemSetZero(e = e->next, root->entry_size);
				break;
			}
		}
	e->key = key;
	e->key_len = key_len;
	e->hash = hash;
	e->data = data;
	VM_LEAVE_CRITICAL_SECTION(root->vm->gcs);
	return e;
}


/**
   Finds an entry with the specified key in the hash map.
   @param root the hash map root
   @param key a pointer to the key 
   @param key_len the key length
   @param hfce a hash function
   @return a pointer to the data of the entry to which the specified key is mapped or NULL if the hash map contains no mapping for this key
*/
void FASTCALL **vmHashFindEntry_Fce(hash_root *root, const void *key, juint key_len, hash_fce hfce) {
	return vmHashFindEntry_Hash(root, key, key_len, hfce(key, key_len));
}


/**
   Finds an entry with the specified key in the hash map.
   @param root the hash map root
   @param key a pointer to the key 
   @param key_len the key length
   @param hash the key hash value
   @return a pointer to the data of the entry to which the specified key is mapped or NULL if the hash map contains no mapping for this key
*/
void **vmHashFindEntry_Hash(hash_root *root, const void *key, jint key_len, jint hash) {
	hash_entry *e;
	VM_ENTER_CRITICAL_SECTION(root->vm->gcs);
	e = (hash_entry*)(root->slot + ((unsigned)hash % root->capacity) * root->entry_size);
	while (e != NULL) {
		if (e->hash == hash)
			if (!root->compare(e->key, key, e->key_len, key_len)) 
				break;
		e = e->next;
	}
	VM_LEAVE_CRITICAL_SECTION(root->vm->gcs);
	return (e != NULL) ? &(e->data) : NULL;
}


/*****************************************************************
 * Garbage collector
 *****************************************************************/

/**
   Destroyes unused objects (implementation of the accurate mark-sweep garbage collector).
   @param vm the Java VM interface pointer
   @return the number of the destroyed unused objects
*/
jint vmGC(vmJavaVM *vm) {
	jint ret = 0;
#if VM_GC_MARKSWEEP
	vmJNIEnv *env; juint size, entry_size, i, j, n; 
	jobject *heap = vm->heap; juint max_heap_index = vm->heap_max;
#ifdef _DEBUG
	DWORD tick = GetTickCount(), t; juint cnt = 0;
	printf(" -> start garbage collection:\n");
#endif
	VM_ENTER_CRITICAL_SECTION(vm->gcs);

	/* 1) mark all objects */
	for (i = 0; i <= max_heap_index; i++) {
		jobject obj = heap[i];
		if (obj == NULL) continue;
		obj->flags |= VM_OBJECT_GCSWEEP_FLAG;
#ifdef _DEBUG
		cnt++;
#endif
	}
#ifdef _DEBUG
	printf("       Number all objects: %u\n", cnt);
	t = (GetTickCount() - tick);
	printf("    1) marking all objects: %d.%03d s\n", t / 1000, t % 1000);
	tick = GetTickCount();
#endif

	/* unmark objects referenced by static variables */
	vmUnmarkObject(vm->outofmem);
	for (i = 0; i < VM_MAX_JARS_COUNT; i++)
		vmUnmarkObject(vm->jar[i]);
	size = vm->clsdef.capacity; entry_size = vm->clsdef.entry_size;
	for (i = 0; i < size; i++) {
		hash_entry *e = (hash_entry*)(vm->clsdef.slot + i * entry_size);
		while (e != NULL) {
			if (e->data != NULL) {
				class_cache_entry *cce = (class_cache_entry*)&(e->data);
				jobject *classes = cce->obj; clsConstPool *cp = cce->cls->constant_pool;
				clsField *fld = cce->cls->class_fields;
				/* unmark java.lang.Class objects */
				for (j = 0; j <= VM_MAX_ARRAY_DIMENSION; j++)
					if (classes[j] != NULL)
						classes[j]->flags &= ~VM_OBJECT_GCSWEEP_FLAG;
				/* unmark class pool */
				n = cce->cls->constant_pool_count;
				for (j = 1; j < n; j++) {
					clsConstPool *cpj = cp + j;
					if ((cpj->tag == CONSTANT_Class) || (cpj->tag == CONSTANT_String))
						vmUnmarkObject(cpj->p);
				}
				/* unmark static class variables */
				n = cce->cls->class_fields_count;
				for (j = 0; j < n; j++)
					if (fld[j].descriptor[1])
						vmUnmarkObject(fld[j].val.l);
			}
			e = e->next;
		}
	}

	/* unmark objects referenced by local variables */
	env = JVM_MAINENV(vm);
	while (env != NULL) {
		vmFrame *frame = env->frame;
#ifdef _DEBUG
	printf("       thread: 0x%08x\n", env->thread_id);
#endif
		while (frame) {
			VM_STACK_SLOT_TYPE *refs = frame->refs;
			jint top = frame->refs_top, ptr = top;
			while (--ptr >= 0)
				vmUnmarkObject(refs[ptr]);
			frame = frame->prev;
		}
		env = env->next;
	}

#ifdef _DEBUG
	t = (GetTickCount() - tick);
	printf("    2) unmarking used objects: %d.%03d s\n", t / 1000, t % 1000);
	tick = GetTickCount();
#endif

	/* sweep marked (unused) objects */
	env = JVM_MAINENV(vm);
	for (i = 0; i <= max_heap_index; i++) {
		jobject obj = heap[i];
		if (obj == NULL) continue;
		if (obj->flags & VM_OBJECT_GCSWEEP_FLAG) {
#if VM_GC_REFERENCECOUNTING
			jbyte *data = obj->data;
			clsDefinition *cls = obj->clsdef;
			if (obj->dim > 0) {
				/* release array elements */
				juint len = VM_ARRAY_LENGTH(obj);
				jobject* ptr = VM_ARRAY_ARRAY(obj);
				/* array of the objects? */
				if ((obj->dim > 1) || ((obj->dim == 1) && (cls->name[1] != 0)))
					for (j = 0; j < len; j++) {
						jobject o = ptr[j];
						if (o && !(o->flags & VM_OBJECT_GCSWEEP_FLAG))
							JNIDELETEGLOBALREF((JNIEnv*)env, o);
					}
			} else {
#endif
				/* finalize object (invoked only once) */
				if (obj->flags & VM_OBJECT_FINALIZE_FLAG) {
#if !VM_GC_REFERENCECOUNTING
					clsDefinition *cls = obj->clsdef;
#endif
					vmFrame *frame = ((vmJNIEnv*)env)->frame;
					obj->flags &= ~VM_OBJECT_FINALIZE_FLAG;
					VM_PUSH_OBJECT(frame, obj);
					vmExecuteMethod(frame, cls->finalizeID, NULL);
				}
#if VM_GC_REFERENCECOUNTING
				/* release object fields */
				while (cls != NULL) {
					for (j = 0; j < cls->instance_fields_count; j++) {
						clsField *fld = cls->instance_fields + j;
						if ((*(fld->descriptor) == 'L') || (*(fld->descriptor) == '[')) {
							jobject *po = (jobject*)(data + fld->data_off), o = *po;
							if (o && !(o->flags & VM_OBJECT_GCSWEEP_FLAG)) {
								JNIDELETEGLOBALREF((JNIEnv*)env, o);
								*po = NULL;
							}
						}
					}
					cls = cls->super_class;
				}
			}
#endif
		}
	}
	for (i = 0; i <= max_heap_index; i++) {
		jobject obj = heap[i];
		if (obj == NULL) continue;
		if (obj->flags & VM_OBJECT_GCSWEEP_FLAG) {
			vm->heap[obj->heap_index] = NULL;
			/* release object */
			if (VM_IS_EVENT_CREATED(obj->exit_event)) VM_DELETE_EVENT(obj->exit_event);
			if (VM_IS_EVENT_CREATED(obj->wait_event)) VM_DELETE_EVENT(obj->wait_event);
			if (obj->flags & VM_OBJECT_FREEDATA_FLAG) vmMemFree(vm, obj->data);
			vmMemFree(vm, obj);			
			ret++;
		}
	}
#ifdef _DEBUG
	printf("       Number destroyed objects: %u\n", ret);
#endif

#ifdef _DEBUG
	t = (GetTickCount() - tick);
	printf("    3) sweeping marked objects: %d.%03d s\n", t / 1000, t % 1000);
#endif

	vm->heap_last = 0;
	VM_LEAVE_CRITICAL_SECTION(vm->gcs);
#endif /* VM_GC_MARKSWEEP */
	return ret;
}


/**
   Unmarks the object and all referenced objects (implementation of accurate mark-sweep garbage collector).
   @param obj an object
*/
void FASTCALL vmUnmarkObject(jobject obj) {
	if (obj == NULL) return;
	if (!(obj->flags & VM_OBJECT_GCSWEEP_FLAG)) return;
	obj->flags &= ~VM_OBJECT_GCSWEEP_FLAG;
	if (obj->dim > 0) {
		jint n = VM_ARRAY_LENGTH(obj), i;
		jobject *arr = VM_ARRAY_ARRAY(obj);
		/* array */
		if ((obj->dim == 1) && !obj->clsdef->name[1])
			return;
		for (i = 0; i < n; i++)
			vmUnmarkObject(arr[i]);
	} else {
		jbyte *data = obj->data;
		clsDefinition *cls = obj->clsdef;
		while (cls) {
			clsField *fld = cls->instance_fields;
			jint n = cls->instance_fields_count, j;
			for (j = 0; j < n; j++)
				if (fld[j].descriptor[1])
					vmUnmarkObject(*(jobject*)(data + fld[j].data_off));
			cls = cls->super_class;
		}
	}
}


/**
   Allocates uncollected memory block, result must be free by vmMemFree() function.
   @param vm the Java VM interface pointer
   @param size bytes to allocate
   @return the allocated memory block or NULL if VM runs out of memory
*/
void* FASTCALL vmMemAlloc(vmJavaVM *vm, jint size) {
	void *ret = _vmMemAlloc((int)size);
#if VM_GC_MARKSWEEP
	if (ret == NULL) {
		vmGC(vm);
		ret = _vmMemAlloc((int)size);
	}
#endif /* VM_GC_MARKSWEEP */
	return ret;
}


/*****************************************************************
 * Strings
 *****************************************************************/

/**
   Converts an Unicode string into an encoded UTF-8 string.
   @param utf8 a pointer to the output buffer to receive converted UTF-8 string
               (if it is NULL, then this function returns the UTF-8 string length only)
   @param str an Unicode string to convert
   @param strlen the Unicode string length
   @return the UTF-8 string length or negative value if an error occurs
*/
int toUtf8(char *utf8, const jchar *str, int strlen) {
	const WCHAR* buf; int i, cnt, ch;
	buf = str; i = cnt = 0;
	if (strlen < 0) strlen = vmStrLen(str);
	/* compute UTF-8 string length only? */
	if (utf8 == NULL) {
		for (; strlen > 0; ++i, strlen--) {
			ch = buf[i];
			if ((ch > 0) && (ch <= 0x7F))
				cnt++;
			else 
				if (!ch || (ch <= 0x7FF))
					cnt += 2;
				else
					cnt += 3;
			if (cnt > 65535) return -1;
		}
		return cnt;
	}
	/* OK, convert string */
	for (; strlen > 0; ++i, strlen--) {
		ch = buf[i];
		if ((ch > 0) && (ch <= 0x7F))
			utf8[cnt++] = (char)(0xFF & ch);
		else
			if (!ch || (ch <= 0x7FF)) {
				utf8[cnt++] = (char)(0xC0 | (0x1F & (ch >> 6)));
				utf8[cnt++] = (char)(0x80 | (0x3F & ch));
			} else {
				utf8[cnt++] = (char)(0xE0 | (0x0F & (ch >> 12)));
				utf8[cnt++] = (char)(0x80 | (0x3F & (ch >> 6)));
				utf8[cnt++] = (char)(0x80 | (0x3F & ch));
			}
		if (cnt > 65535) { utf8[65535] = 0; return -1; }
	}
	utf8[cnt] = 0;
	return cnt;
}


/**
   Converts an encoded UTF-8 string into an Unicode string.
   @param str a pointer to the output buffer to receive converted Unicode string,
               returned Unicode string will be terminated by zero character
   @param utf8 an UTF-8 string to convert
   @param strsize the output buffer size (number of jchars)
   @return number of the converted Unicode characters in output buffer or negative value if an error occurs
*/
int fromUtf8(jchar *str, const char *utf8, unsigned int strsize) {
	int i, err;	unsigned int strlen;
	i = err = 0; strlen = 0;
	strsize--;	/* place reservation for the last zero character */
	while (utf8[i] && (strlen < strsize)) {			
		if (i >= 65535) { err = -1; break; }
        if ((utf8[i] & 0x80) == 0)
			str[strlen++] = (WCHAR)(utf8[i++] & 0xFF);
		else 
			if ((utf8[i] & 0xE0) == 0xC0) {
				WCHAR ch1 = (WCHAR)(unsigned char)utf8[i++], ch2 = (WCHAR)(unsigned char)utf8[i++];
				if ((ch2 & 0xC0) != 0x80) {	err = -1; break; }
				str[strlen++] = (WCHAR)(((ch1 & 0x1F) << 6) | (ch2 & 0x3F));
			} else 
				if ((utf8[i] & 0xF0) == 0xE0) {
					WCHAR ch1 = (WCHAR)(unsigned char)utf8[i++], ch2 = (WCHAR)(unsigned char)utf8[i++], ch3 = (WCHAR)(unsigned char)utf8[i++];
					if (((ch2 & 0xC0) != 0x80) || ((ch3 & 0xC0) != 0x80)) {	err = -1; break; }
					str[strlen++] = (WCHAR)(((ch1 & 0x0F) << 12) | ((ch2 & 0x3F) << 6) | (ch3 & 0x3F));
				} else {
					err = -1; break; 
				}
	}
	str[strlen] = 0;
	return err ? err : strlen;
}


/*****************************************************************
 * Errors & Exceptions
 *****************************************************************/

/**
   Displays message and terminates the program. 
   @param env the JNI interface pointer
   @param msg an UTF-8 string that is displayed
   @return NULL value
*/
void *vmFatalError(vmJNIEnv *env, const char *msg) {
	vmDisplayError(msg, "Fatal error");	
	exit(-1);
	return NULL;
}


/**
   Creates new Throwable object.
   @param env the JNI interface pointer
   @param cls a class definition (must be throwable subclass)
   @param message the detail message (it can be NULL)
   @return new throwable object or NULL if an error occurs
*/
jthrowable vmCreateThrowable(vmJNIEnv *env, clsDefinition *cls, const char *message) {
	jthrowable obj; jint cnt;
	vmJavaVM *vm = env->vm;
	if (cls->vm != vm) {
		class_cache_entry *cce;
		cce = (class_cache_entry*)vmHashFindEntry_Hash(&vm->clsdef, cls->name, 0, cls->hash);
		if (cce == NULL)
			jniFatalError((JNIEnv*)env, "Class definition not found [vmCreateThrowable]");
		cls = cce->cls;
	}
	/* create new Throwable object */
	cnt = Java_java_lang_Throwable_fillInStackTrace_count((JNIEnv*)env);
	obj = vmCreateObject(env, cls, 0, 0, cnt * sizeof(JavaLangStackTraceIData));
	if (obj != NULL) {
		VM_THROWABLE_STACK_COUNT(obj) = cnt;
		VM_THROWABLE_STACK(obj) = obj->data + cls->total_data_size;
		if (cnt > 0) Java_java_lang_Throwable_fillInStackTrace_fill((JNIEnv*)env, obj);
		/* set message field */
		if (message != NULL)
			JNINEWGLOBALREF((JNIEnv*)env, VM_THROWABLE_MSG(obj) = jniNewStringUTF((JNIEnv*)env, message));
	}
	return obj;
}


/*****************************************************************
 * Class management
 *****************************************************************/

/**
   Creates class cache and registers essential Java classes.
   @param vm the Java VM interface pointer
   @param env the JNI interface pointer
   @return JNI_OK on success or an error code
*/
jint vmRegisterCoreClasses(vmJavaVM *vm, vmJNIEnv *env) {
	vmHashInit(vm, &vm->clsdef, 1024, 700, sizeof(class_cache_entry), vmZeroStringCompareFceUTF);
	vmRegister_JavaLangPackage(vm, env);
	vm->outofmem = jniNewLocalRef((JNIEnv*)env, vmCreateThrowable(env, &clsJAVA_LANG_OUTOFMEMORYERROR, NULL));	
#if JAVA_LANG_REFLECT_ENABLED
	vmRegister_JavaLangReflectPackage(vm, env);
#endif
	vmRegister_JavaIoPackage(vm, env);
#if JAVA_MATH_ENABLED
	vmRegister_JavaMathPackage(vm, env);
#endif
#if JAVA_NET_ENABLED
	vmRegister_JavaNetPackage(vm, env);
#endif
#if JAVA_TEXT_ENABLED
	vmRegister_JavaTextPackage(vm, env);
#endif
#if JAVA_UTIL_ZIP_ENABLED
	vmRegister_JavaUtilZipPackage(vm, env);
#endif
#ifndef DSVM_LITE
	vmRegister_JavaSecurityPackage(vm, env);
	vmRegister_JavaUtilPackage(vm, env);
	vmRegister_JavaBeansPackage(vm, env);
#endif /* DSVM_LITE */
	return JNI_OK;
}


/**
   Registers new class for the Java VM.
   @param vm the Java VM interface pointer
   @param env the JNI interface pointer
   @param cls a pointer to the class definition
   @return registered class object or NULL if an error occurs
*/
jclass vmRegisterClass(vmJavaVM *vm, vmJNIEnv *env, clsDefinition *cls) {
	jint i;
	class_cache_entry *cce;
	jclass clazz; 

	/* clone class definition? */
	if (!(cls->access_flags & ACC_FREEMEM)) {
		for (i = 0; i < cls->constant_pool_count; i++) {
			clsConstPool *cp = cls->constant_pool + i;
			switch (cp->tag) {
				case CONSTANT_Integer:
				case CONSTANT_Long:
				case CONSTANT_Float:
				case CONSTANT_Double:
					cp->p = &(cp->i);
			}
		}
		cls = vmCloneClassDefinition(env, cls);
	}
	if (cls == NULL)
		return NULL;
	cls->vm = vm;

#ifdef _DEBUG
	/* check class hash */
	if (cls->hash != vmZeroStringHashFceUTF(cls->name, 0)) {
		char buf[1024];
		cls->hash = vmZeroStringHashFceUTF(cls->name, 0);
		vmSprintfUTF(buf, "CLASS HASH: %s = 0x%x\n", cls->name, cls->hash);
		vmDisplayInfo(buf, NULL);
	}

	/* check static methods */
	for (i = 0; i < cls->class_methods_count; i++) {
		jmethodID *met; jint hash; char buf[1024], *p; jint parcount, stacksize;
		met = cls->class_methods + i;
		/* check hash */
		hash = vmZeroStringHashFceUTF((*met)->name, 0) ^ vmZeroStringHashFceUTF((*met)->descriptor, 0);
		if ((*met)->hash != hash) {
			vmSprintfUTF(buf, "    METHOD HASH: %s.%s%s = 0x%x\n", cls->name, (*met)->name, (*met)->descriptor, hash);
			vmDisplayInfo(buf, NULL);
			(*met)->hash = hash;
		}
		/* check descriptor */
		p = (*met)->descriptor; parcount = 0, stacksize = 0;
		if (*p == '(')
			p++;
		else {
			vmSprintfUTF(buf, "    METHOD DESCRIPTOR: %s.%s%s = missing '('\n", cls->name, (*met)->name, (*met)->descriptor);
			vmDisplayInfo(buf, NULL);
		}
		while (*p && (*p != ')')) {
			switch (*p) {
				case 'J': 
				case 'D':
					stacksize += VM_STACK_SLOT_LONG_SIZE;
					break;
				case '[':
				case 'L':
					while (*p == (TCHAR)'[') p++;
					if (*p == (TCHAR)'L') {	p++; while (*p != (TCHAR)';') p++; }
				case 'Z':
				case 'B':
				case 'C':
				case 'S':
				case 'I':
				case 'F':
					stacksize++;
					break;
				default: 
					vmSprintfUTF(buf, "    METHOD DESCRIPTOR: %s.%s%s = unexpected '%c'\n", cls->name, (*met)->name, (*met)->descriptor, *p);
					vmDisplayInfo(buf, NULL);
					break;
			}
			p++; parcount++;
		}
		if (*p == ')') {
			char ch = *(++p); if (ch == '[') ch = 'L';
			if (ch != (*met)->return_type) {
				vmSprintfUTF(buf, "    METHOD RETURN TYPE: %s.%s%s = expected '%c' (!= '%c')\n", cls->name, (*met)->name, (*met)->descriptor, ch, (*met)->return_type);
				vmDisplayInfo(buf, NULL);
			}
			if (parcount != (*met)->parameters_count) {
				vmSprintfUTF(buf, "    METHOD PARAMETERS COUNT: %s.%s%s = expected %u (!= %u)\n", cls->name, (*met)->name, (*met)->descriptor, parcount, (*met)->parameters_count);
				vmDisplayInfo(buf, NULL);
			} else
			if (stacksize != (*met)->parameters_stack_size) {
				vmSprintfUTF(buf, "    METHOD STACK SIZE: %s.%s%s = expected %u (!= %u)\n", cls->name, (*met)->name, (*met)->descriptor, stacksize, (*met)->parameters_stack_size);
				vmDisplayInfo(buf, NULL);
			}
		} else {
			vmSprintfUTF(buf, "    METHOD DESCRIPTOR: %s.%s%s = missing ')'\n", cls->name, (*met)->name, (*met)->descriptor);
			vmDisplayInfo(buf, NULL);
		}
	}

	/* check instance methods */
	for (i = 0; i < cls->instance_methods_count; i++) {
		jmethodID *met; jint hash; char buf[1024], *p; jint parcount, stacksize;
		met = cls->instance_methods + i;
		/* check hash */
		hash = vmZeroStringHashFceUTF((*met)->name, 0) ^ vmZeroStringHashFceUTF((*met)->descriptor, 0);
		if ((*met)->hash != hash) {
			vmSprintfUTF(buf, "    METHOD HASH: %s.%s%s = 0x%x\n", cls->name, (*met)->name, (*met)->descriptor, hash);
			vmDisplayInfo(buf, NULL);
			(*met)->hash = hash;
		}
		/* check descriptor */
		p = (*met)->descriptor; parcount = 0, stacksize = 1;
		if (*p == '(')
			p++;
		else {
			vmSprintfUTF(buf, "    METHOD DESCRIPTOR: %s.%s%s = missing '('\n", cls->name, (*met)->name, (*met)->descriptor);
			vmDisplayInfo(buf, NULL);
		}
		while (*p && (*p != ')')) {
			switch (*p) {
				case 'J': 
				case 'D':
					stacksize += VM_STACK_SLOT_LONG_SIZE;
					break;
				case '[':
				case 'L':
					while (*p == (TCHAR)'[') p++;
					if (*p == (TCHAR)'L') {	p++; while (*p != (TCHAR)';') p++; }
				case 'Z':
				case 'B':
				case 'C':
				case 'S':
				case 'I':
				case 'F':
					stacksize++;
					break;
				default: 
					vmSprintfUTF(buf, "    METHOD DESCRIPTOR: %s.%s%s = unexpected '%c'\n", cls->name, (*met)->name, (*met)->descriptor, *p);
					vmDisplayInfo(buf, NULL);
					break;
			}
			p++; parcount++;
		}
		if (*p == ')') {
			char ch = *(++p); if (ch == '[') ch = 'L';
			if (ch != (*met)->return_type) {
				vmSprintfUTF(buf, "    METHOD RETURN TYPE: %s.%s%s = expected '%c' (!= '%c')\n", cls->name, (*met)->name, (*met)->descriptor, ch, (*met)->return_type);
				vmDisplayInfo(buf, NULL);
			}
			if (parcount != (*met)->parameters_count) {
				vmSprintfUTF(buf, "    METHOD PARAMETERS COUNT: %s.%s%s = expected %u (!= %u)\n", cls->name, (*met)->name, (*met)->descriptor, parcount, (*met)->parameters_count);
				vmDisplayInfo(buf, NULL);
			} else
			if (stacksize != (*met)->parameters_stack_size) {
				vmSprintfUTF(buf, "    METHOD STACK SIZE: %s.%s%s = expected %u (!= %u)\n", cls->name, (*met)->name, (*met)->descriptor, stacksize, (*met)->parameters_stack_size);
				vmDisplayInfo(buf, NULL);
			}
		} else {
			vmSprintfUTF(buf, "    METHOD DESCRIPTOR: %s.%s%s = missing ')'\n", cls->name, (*met)->name, (*met)->descriptor);
			vmDisplayInfo(buf, NULL);
		}
	}

	/* check fields hash */
	for (i = 0; i < cls->class_fields_count; i++) {
		jfieldID fld; jint hash;
		fld = cls->class_fields + i;
		hash = vmZeroStringHashFceUTF(fld->name, 0) ^ vmZeroStringHashFceUTF(fld->descriptor, 0);
		if (fld->hash != hash) {
			char buf[1024];
			fld->hash = hash;
			vmSprintfUTF(buf, "    FIELD HASH: %s %s.%s = 0x%x\n", fld->descriptor, cls->name, fld->name, hash);
			vmDisplayInfo(buf, NULL);
		}
	}
	for (i = 0; i < cls->instance_fields_count; i++) {
		jfieldID fld; jint hash;
		fld = cls->instance_fields + i;
		hash = vmZeroStringHashFceUTF(fld->name, 0) ^ vmZeroStringHashFceUTF(fld->descriptor, 0);
		if (fld->hash != hash) {
			char buf[1024];
			fld->hash = hash;
			vmSprintfUTF(buf, "    FIELD HASH: %s %s.%s = 0x%x\n", fld->descriptor, cls->name, fld->name, hash);
			vmDisplayInfo(buf, NULL);
		}
	}
#endif /* _DEBUG */

	/* check static fields */
	for (i = 0; i < cls->class_fields_count; i++) {
		jfieldID fld; jint j;
		fld = cls->class_fields + i;
		if ((fld->access_flags & ACC_STATIC) == 0) {
			char buf[1024];
			vmSprintfUTF(buf, "Missing static flag for class [%s] static field [%s].\n", cls->name, fld->name);
			jniFatalError((JNIEnv*)env, buf);
		}
		if ((cls->access_flags & ACC_INTERFACE) && ((fld->access_flags & ACC_FINAL) == 0)) {
			char buf[1024];
			vmSprintfUTF(buf, "Interface [%s] static field [%s] is not final.\n",	cls->name, fld->name);
			jniFatalError((JNIEnv*)env, buf);
		}
		for (j = 0; j < fld->attributes_count; j++) {
			clsAttribute *att = fld->attributes + j;
			if (!vmStrCmpUTF(att->name, "ConstantValue")) {
				jint i = getClassUShort(att->data);
				clsConstPool *c = cls->constant_pool + i;
				switch (c->tag) {
					case CONSTANT_Integer:
						switch (fld->descriptor[0]) {
							case 'S': fld->val.s = (jshort)*(jint*)(c->p); break;
							case 'C': fld->val.c = (jchar)*(jint*)(c->p); break;
							case 'B': fld->val.b = (jbyte)*(jint*)(c->p); break;
							case 'Z': fld->val.z = (jboolean)*(jint*)(c->p); break;
							default: fld->val.i = *(jint*)(c->p);
						}
						break;
					case CONSTANT_Long:
						fld->val.j = *(jlong*)(c->p);
						break;
					case CONSTANT_Float:
						fld->val.f = *(jfloat*)(c->p);
						break;
					case CONSTANT_Double:
						fld->val.d = *(jdouble*)(c->p);
						break;
					case CONSTANT_String: {
						jint strlen = cls->constant_pool[c->i].i * sizeof(jchar);
						jstring str = JNINEWGLOBALREF((JNIEnv*)env, vmCreateObject((vmJNIEnv*)env, &clsJAVA_LANG_STRING, 0, 0, strlen));
						if (str != NULL) 
							VM_STRING_LEN(str) = fromUtf8(VM_STRING(str), c->q, strlen);
						fld->val.l = str;
						break;
					}
				}
			}
		}
	}

	/* check instance fields */
	for (i = 0; i < cls->instance_fields_count; i++) {
		jfieldID fld; fld = cls->instance_fields + i;
		if ((fld->access_flags & ACC_STATIC) != 0) {
			char buf[1024];
			vmSprintfUTF(buf, "Static flag is set for class [%s] instance field [%s].\n", cls->name, fld->name);
			jniFatalError((JNIEnv*)env, buf);
		}
		if (cls->access_flags & ACC_INTERFACE) {
			char buf[1024];
			vmSprintfUTF(buf, "Interface [%s] contains instance fields.\n", cls->name);
			jniFatalError((JNIEnv*)env, buf);
		}
	}

	/* create Class object instance */
	clazz = JNINEWGLOBALREF((JNIEnv*)env, vmCreateObject(env, vm->class_clsdef, 0, 0, 0));
	VM_CLASS_DEF(clazz) = cls;
	
	/* insert to class cache */
	cce = (class_cache_entry*)&(vmHashInsertEntry_Hash(&vm->clsdef, cls, cls->name, 0, cls->hash)->data);
	cce->obj[0] = clazz;
	return clazz;
}


/**
   Clones a class definition.
   @param env the JNI interface pointer
   @param cls a pointer to the class definition
   @return cloned class definition or NULL if an error occurs
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
clsDefinition *vmCloneClassDefinition(vmJNIEnv *env, clsDefinition *cls) {
	int i, size; char *p;
	clsDefinition *ret;

	/* compute class definition size */
	size = sizeof(clsDefinition);
	size += cls->interfaces_count * sizeof(clsDefinition*);
	size += cls->class_fields_count * sizeof(clsField);
	size += cls->instance_fields_count * sizeof(clsField);
	size += cls->class_methods_count * (sizeof(clsMethod*) + sizeof(clsMethod));
	size += cls->instance_methods_count * (sizeof(clsMethod*) + sizeof(clsMethod));

	/* alloc memory */
	ret = (clsDefinition*)p = vmMemAlloc(env->vm, size);
	if (ret == NULL) {
		vmJavaVM* vm;
		vm = ((vmJNIEnv*)env)->vm;
		if (vm->outofmem != NULL)
			jniThrow((JNIEnv*)env, vm->outofmem);
		else
			jniFatalError((JNIEnv*)env, "Out of memory [vmCloneClassDefinition]");
		return NULL;
	}
	vmMemCpy(ret, cls, sizeof(clsDefinition));
	p += sizeof(clsDefinition);
	if (cls->interfaces_count > 0) {
		ret->interfaces = (clsDefinition**)p;
		vmMemCpy(ret->interfaces, cls->interfaces, cls->interfaces_count * sizeof(clsDefinition*));
		p += ret->interfaces_count * sizeof(clsDefinition*);
	}

	/* copy fields */
	vmMemCpy(ret->class_fields = (clsField*)p, cls->class_fields, cls->class_fields_count * sizeof(clsField));
	p += cls->class_fields_count * sizeof(clsField);
	for (i = 0; i < cls->class_fields_count; i++) {
		ret->class_fields[i].clsdef = ret;
		ret->class_fields[i].val.j = JLONG(0);
	}
	vmMemCpy(ret->instance_fields = (clsField*)p, cls->instance_fields, cls->instance_fields_count * sizeof(clsField));
	p += cls->instance_fields_count * sizeof(clsField);
	for (i = 0; i < cls->instance_fields_count; i++)
		ret->instance_fields[i].clsdef = ret;

	/* copy methods */
	ret->class_methods = (clsMethod**)p;
	p += cls->class_methods_count * sizeof(clsMethod*);
	for (i = 0; i < cls->class_methods_count; i++) {
		ret->class_methods[i] = (clsMethod*)p;
		vmMemCpy(p, cls->class_methods[i], sizeof(clsMethod));
		p += sizeof(clsMethod);
		ret->class_methods[i]->clsdef = ret;
	}
	ret->instance_methods = (clsMethod**)p;
	p += cls->instance_methods_count * sizeof(clsMethod*);
	for (i = 0; i < cls->instance_methods_count; i++) {
		ret->instance_methods[i] = (clsMethod*)p;
		vmMemCpy(p, cls->instance_methods[i], sizeof(clsMethod));
		p += sizeof(clsMethod);
		ret->instance_methods[i]->clsdef = ret;
	}
	if (cls->finalizeID != 0)
		ret->finalizeID = vmGetInstanceMethod(ret, "finalize", "()V", JNI_TRUE);

	ret->access_flags &= ~(ACC_RESOLVED | ACC_INITED);
	ret->access_flags |= ACC_FREEMEM;
	return ret;
}


/**
   Loads a class definition from the raw class data.
   <B>ATTENTION:</B> All pointers to another class definitions in result point to (UTF-8) class names
   and must be replaced with pointers to correct class definitions! (<I>ACC_FINDDEP</I> flag is set)
   @param env the JNI interface pointer
   @param name a class name
   @param buf the raw class data
   @param bufLen length of the raw class data
   @return loaded class definition or NULL if an error occurs
   @exception java.lang.ClassFormatError produced by an invalid class
*/
clsDefinition *vmDefineClass(vmJNIEnv *env, const char *name, const jbyte *buf, jsize bufLen) {
	clsDefinition cls, *ret = NULL; char *s;
	jint i, j, k, cnt; jbyte *p; const jbyte *pbuf; 
	const jbyte *pool;		/* pointer to buffer */
	const jbyte *flds;		/* pointer to buffer */
	const jbyte *mets;		/* pointer to buffer */
	const jbyte *atrs;		/* pointer to buffer */
	jint pool_len = 0;		/* needed size of memory in bytes */
	jint atrnum = 0;		/* total number of the attributes */
	jint atrsize = 0;		/* total size of the attributes */
	if (!buf || (bufLen <= 0)) return NULL;
	vmMemSetZero(&cls, sizeof(cls));

	/* are the .class file data? */
	if (getClassInt(buf) != 0xCAFEBABE) {
		jniThrowNew((JNIEnv*)env, jniFindClass((JNIEnv*)env, clsJAVA_LANG_CLASSFORMATERROR.name), name);
		return NULL;
	}
	cls.minor_version = getClassUShort(buf + 4);
	cls.major_version = getClassUShort(buf + 6);
	cls.constant_pool_count = getClassUShort(buf + 8);
	
	/* compute needed memory size */
	pool = buf + 10; pbuf = pool;
	for (i = 1; i < cls.constant_pool_count; i++)
		switch (*(pbuf++)) {
			case CONSTANT_Utf8: {
				jint len = getClassUShort(pbuf);
				pool_len += len + 1; pbuf += len + 2;
				break; }
			case CONSTANT_Class: 
			case CONSTANT_String: 
				pbuf += 2; break;
			case CONSTANT_Integer: 
			case CONSTANT_Float: 
			case CONSTANT_FieldRef:
			case CONSTANT_MethodRef: 
			case CONSTANT_NameAndType: 
			case CONSTANT_InterfaceMethodRef:
				pbuf += 4; break;
			case CONSTANT_Long: 
			case CONSTANT_Double: 
				i++; pbuf += 8; break;
			default: /* unknown constant tag */
				jniThrowNew((JNIEnv*)env, jniFindClass((JNIEnv*)env, clsJAVA_LANG_CLASSFORMATERROR.name), name);
				return NULL;
		};
	cls.access_flags = ACC_FREEMEM | getClassUShort(pbuf); pbuf += 6;
	cls.interfaces_count = getClassUShort(pbuf); pbuf += 2 + 2 * cls.interfaces_count;
	cnt = getClassUShort(pbuf); pbuf += 2; flds = pbuf;
	for (i = 0; i < cnt; i++) {
		if (getClassUShort(pbuf) & ACC_STATIC) cls.class_fields_count++; 
			else cls.instance_fields_count++;
		j = getClassUShort(pbuf + 6); /* attributes count */
		pbuf += 8; atrnum += j;
		for (k = 0; k < j; k++) {
			jint sz = getClassInt(pbuf + 2); pbuf += 6 + sz; atrsize += sz;
		}
	}
	cnt = getClassUShort(pbuf); pbuf += 2; mets = pbuf;
	for (i = 0; i < cnt; i++) {
		if (getClassUShort(pbuf) & ACC_STATIC) cls.class_methods_count++; 
			else cls.instance_methods_count++;
		j = getClassUShort(pbuf + 6); /* attributes count */
		pbuf += 8; atrnum += j;
		for (k = 0; k < j; k++) {
			jint sz = getClassInt(pbuf + 2); pbuf += 6 + sz; atrsize += sz;
		}
	}
	cls.attributes_count = getClassUShort(pbuf); pbuf += 2; atrs = pbuf;
	atrnum += cls.attributes_count;
	for (k = 0; k < cls.attributes_count; k++) {
		jint sz = getClassInt(pbuf + 2); pbuf += 6 + sz; atrsize += sz; 
	}
	
	/* create new class definition */
	i = sizeof(clsDefinition) + 
		cls.constant_pool_count * sizeof(clsConstPool) + pool_len +
		cls.interfaces_count * sizeof(clsDefinition*) + 
		(cls.class_fields_count + cls.instance_fields_count) * sizeof(clsField) + 
		(cls.class_methods_count + cls.instance_methods_count) * (sizeof(clsMethod*) + sizeof(clsMethod)) + 
		atrnum * sizeof(clsAttribute) + atrsize;
	p = (jbyte*)ret = vmMemAlloc(env->vm, i);
	if (p == NULL) {
		jniThrowNew((JNIEnv*)env, jniFindClass((JNIEnv*)env, clsJAVA_LANG_CLASSFORMATERROR.name), name);
		jniThrow((JNIEnv*)env, env->vm->outofmem);
		return NULL;
	}
	vmMemSetZero(ret, i);
	vmMemCpy(ret, &cls, sizeof(cls));
	p += sizeof(clsDefinition);
	
	/* load the constant pool */
	ret->constant_pool = (clsConstPool*)p;
	p += cls.constant_pool_count * sizeof(clsConstPool);
	pbuf = pool;
	for (i = 1; i < cls.constant_pool_count; i++)
		switch (ret->constant_pool[i].tag = *(pbuf++)) {
			case CONSTANT_Utf8: {
				jint len = ret->constant_pool[i].i = getClassUShort(pbuf);
				vmMemCpy(ret->constant_pool[i].p = p, pbuf + 2, len); 
				p += len + 1; pbuf += len + 2;
				break; }
			case CONSTANT_Class:
			case CONSTANT_String: 
				ret->constant_pool[i].i = getClassUShort(pbuf);
				pbuf += 2; break;
			case CONSTANT_Integer:
			case CONSTANT_Float:
				ret->constant_pool[i].p = &(ret->constant_pool[i].i);
				ret->constant_pool[i].i = getClassInt(pbuf);
				pbuf += 4; break;
			case CONSTANT_FieldRef:
			case CONSTANT_MethodRef: 
			case CONSTANT_NameAndType: 
			case CONSTANT_InterfaceMethodRef:
				ret->constant_pool[i].i = getClassUShort(pbuf);
				ret->constant_pool[i].j = getClassUShort(pbuf + 2);
				pbuf += 4; break;
			case CONSTANT_Long: 
			case CONSTANT_Double: 
				ret->constant_pool[i].p = &(ret->constant_pool[i].i);
				ret->constant_pool[i].i = getClassInt(pbuf + 4);
				ret->constant_pool[i].j = getClassInt(pbuf);
				i++;
				ret->constant_pool[i].tag = CONSTANT_Integer;
				ret->constant_pool[i].p = &(ret->constant_pool[i].i);
				ret->constant_pool[i].i = getClassInt(pbuf);
				pbuf += 8; break;
		};
	for (i = 1; i < cls.constant_pool_count; i++)
		switch (ret->constant_pool[i].tag) {
			case CONSTANT_Class:
			case CONSTANT_String:
				ret->constant_pool[i].q = ret->constant_pool[ret->constant_pool[i].i].p;
				break;
			case CONSTANT_NameAndType:
				ret->constant_pool[i].p = ret->constant_pool[ret->constant_pool[i].i].p;
				ret->constant_pool[i].q = ret->constant_pool[ret->constant_pool[i].j].p;
				break;
		};

	/* class name */
	pbuf += 2;
	ret->name = ret->constant_pool[getClassUShort(pbuf)].q; pbuf += 2;
	ret->hash = vmZeroStringHashFceUTF(ret->name, 0);
	ret->super_class = ret->constant_pool[getClassUShort(pbuf)].q; pbuf += 4;

	/* interfaces */
	if (ret->interfaces_count > 0) {
		ret->interfaces = (clsDefinition**)p;
		p += ret->interfaces_count * sizeof(clsDefinition*);
	}
	for (i = 0; i < ret->interfaces_count; i++) {
		ret->interfaces[i] = (clsDefinition*)getClassUShort(pbuf); pbuf += 2;
	}

	/* fields */
	pbuf = flds;
	cnt = cls.class_fields_count + cls.instance_fields_count;
	ret->class_fields_count = ret->instance_fields_count = 0;
	if (cls.class_fields_count > 0) ret->class_fields = (clsField*)p; p += cls.class_fields_count * sizeof(clsField);
	if (cls.instance_fields_count > 0) ret->instance_fields = (clsField*)p; p += cls.instance_fields_count * sizeof(clsField);
	for (i = 0; i < cnt; i++) {
		clsField *fld;
		jushort flags = getClassUShort(pbuf); 
		if (flags & ACC_STATIC)
			fld = ret->class_fields + ret->class_fields_count++;
		else
			fld = ret->instance_fields + ret->instance_fields_count++;
		fld->access_flags = flags; fld->clsdef = ret;
		fld->name = ret->constant_pool[getClassUShort(pbuf + 2)].p;
		fld->descriptor = ret->constant_pool[getClassUShort(pbuf + 4)].p;
		fld->hash = vmZeroStringHashFceUTF(fld->name, 0) ^ vmZeroStringHashFceUTF(fld->descriptor, 0);
		/* attributes */
		fld->attributes_count = getClassUShort(pbuf + 6); pbuf += 8;
		fld->attributes = (clsAttribute*)p; p += fld->attributes_count * sizeof(clsAttribute);
		for (k = 0; k < fld->attributes_count; k++) {
			clsAttribute *atr = fld->attributes + k;
			atr->name = ret->constant_pool[getClassUShort(pbuf)].p; 
			atr->len = getClassInt(pbuf + 2); atr->data = p; p += atr->len; 
			vmMemCpy(atr->data, pbuf + 6, atr->len); pbuf += 6 + atr->len;
		}
	}

	/* methods */
	pbuf = mets;
	cnt = cls.class_methods_count + cls.instance_methods_count;
	ret->class_methods_count = ret->instance_methods_count = 0;
	if (cls.class_methods_count > 0) ret->class_methods = (clsMethod**)p; p += cls.class_methods_count * sizeof(clsMethod*);
	if (cls.instance_methods_count > 0) ret->instance_methods = (clsMethod**)p; p += cls.instance_methods_count * sizeof(clsMethod*);
	for (i = 0; i < cnt; i++) {
		clsMethod *met = (clsMethod*)p; p += sizeof(clsMethod);
		met->clsdef = ret;
		met->access_flags = getClassUShort(pbuf);
		if (met->access_flags & ACC_STATIC)
			ret->class_methods[ret->class_methods_count++] = met;
		else {
			met->parameters_stack_size++;
			ret->instance_methods[ret->instance_methods_count++] = met;
		}
		met->name = ret->constant_pool[getClassUShort(pbuf + 2)].p;
		s = met->descriptor = ret->constant_pool[getClassUShort(pbuf + 4)].p;
		met->hash = vmZeroStringHashFceUTF(met->name, 0) ^ vmZeroStringHashFceUTF(met->descriptor, 0);
		s++;
		while (*s && (*s != ')')) {
			met->parameters_count++;
			if ((*s == 'J') || (*s == 'D'))
				met->parameters_stack_size += VM_STACK_SLOT_LONG_SIZE;
			else
				met->parameters_stack_size++;
			while (*s == '[') s++;
			if (*s == 'L') while (*s && (*s != ';')) s++;
			s++;
		}
		if (*s == ')') met->return_type = s[1];
		if (met->return_type == '[') met->return_type = 'L';
		/* attributes */
		met->attributes_count = getClassUShort(pbuf + 6); pbuf += 8;
		met->attributes = (clsAttribute*)p; p += met->attributes_count * sizeof(clsAttribute);
		for (k = 0; k < met->attributes_count; k++) {
			clsAttribute *atr = met->attributes + k;
			atr->name = ret->constant_pool[getClassUShort(pbuf)].p; 
			atr->len = getClassInt(pbuf + 2); atr->data = p; p += atr->len; 
			vmMemCpy(atr->data, pbuf + 6, atr->len); pbuf += 6 + atr->len;
			if (!vmStrCmpUTF(atr->name, "Code")) {
				jint i, j, atr_cnt; jbyte *atr_p;
				met->max_operand_stack = getClassUShort(atr->data);
				met->vars_count = getClassUShort(atr->data + 2);
				met->code_len = getClassInt(atr->data + 4);
				met->code = atr->data + 8;
				met->exceptions_count = getClassUShort(atr->data + 8 + met->code_len);
				met->exceptions = (exception_table*)(atr->data + 10 + met->code_len);
				for (i = 0; i < met->exceptions_count; i++) {
					met->exceptions[i].start_pc = getClassUShort((jbyte*)&(met->exceptions[i].start_pc));
					met->exceptions[i].end_pc = getClassUShort((jbyte*)&(met->exceptions[i].end_pc));
					met->exceptions[i].handler_pc = getClassUShort((jbyte*)&(met->exceptions[i].handler_pc));
					met->exceptions[i].catch_type = getClassUShort((jbyte*)&(met->exceptions[i].catch_type));
				}
				atr_cnt = getClassUShort(atr->data + 10 + met->code_len + met->exceptions_count * sizeof(exception_table));
				atr_p = atr->data + 12 + met->code_len + met->exceptions_count * sizeof(exception_table);
				for (i = 0; i < atr_cnt; i++) {
					char *name = ret->constant_pool[getClassUShort(atr_p)].p;
					jint len = getClassInt(atr_p + 2);
					if (!vmStrCmpUTF(name, "LineNumberTable")) {
						met->lines_count = getClassUShort(atr_p + 6);
						met->lines = (line_number_table*)(atr_p + 8);
						for (j = 0; j < met->lines_count; j++) {
							met->lines[j].start_pc = getClassUShort((jbyte*)&(met->lines[j].start_pc));
							met->lines[j].line_number = getClassUShort((jbyte*)&(met->lines[j].line_number));
						}
					}
					atr_p += 6 + len;
				}
			}
		}
	}

	/* attributes */
	pbuf = atrs;
	if (ret->attributes_count > 0) ret->attributes = (clsAttribute*)p; 
	p += ret->attributes_count * sizeof(clsAttribute);
	for (k = 0; k < ret->attributes_count; k++) {
		clsAttribute *atr = ret->attributes + k;
		atr->name = ret->constant_pool[getClassUShort(pbuf)].p; 
		atr->len = getClassInt(pbuf + 2); atr->data = p; p += atr->len; 
		vmMemCpy(atr->data, pbuf + 6, atr->len); pbuf += 6 + atr->len;
	}
	ret->access_flags |= ACC_FINDDEP;
	return ret;
}


/**
   Creates new object on the VM heap. 
   @param env the JNI interface pointer
   @param cls a pointer to the class definition
   @param dim dimension of the created object (must be positive value, 0=not array)
   @param len the array length (if @a dim > 0)
   @param extra_data_size the object data size (number of the bytes that is occupied by the instance fields)
          is increased by @a extra_data_size
   @return created object or NULL if an error occurs
   @exception java.lang.InstantiationException if the class is an interface or an abstract class
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.OutOfMemoryError if VM runs out of memory
*/
jobject vmCreateObject(vmJNIEnv *env, clsDefinition *cls, jshort dim, jint len, jint extra_data_size) {
	jint from, i, data_size;
	jobject ret; vmJavaVM *vm;

	ret = NULL;
	if (env->flags & VM_JNIENV_DESTROYED)
		return NULL;
	vm = env->vm;
	if (cls->vm != vm) {
		class_cache_entry *cce;
		cce = (class_cache_entry*)vmHashFindEntry_Hash(&vm->clsdef, cls->name, 0, cls->hash);
		if (cce == NULL)
			jniFatalError((JNIEnv*)env, "Class definition not found [vmCreateObject]");
		cls = cce->cls;
	}

	/* is class resolved? */
	if ((cls->access_flags & ACC_INITED) == 0) {
		if (jniPushLocalFrame((JNIEnv*)env, 20) == JNI_OK) {
			Java_java_lang_ClassLoader_resolveClass((JNIEnv*)env, 
				((vmJNIEnv*)env)->vm->loader,
				vmFindClassByDef(env, cls, 0));
			jniPopLocalFrame((JNIEnv*)env, NULL);
		}
		if ((cls->access_flags & ACC_INITED) == 0) {
			jniThrowNew((JNIEnv*)env, vmFindClassByDef(env, &clsJAVA_LANG_LINKAGEERROR, 0), cls->name);
			return NULL;
		}
	}

	/* is an abstract class or interface? */
	if ((dim == 0) && (cls->access_flags & (ACC_ABSTRACT | ACC_INTERFACE))) {
		jniThrowNew((JNIEnv*)env, vmFindClassByDef(env, &clsJAVA_LANG_INSTANTIATIONEXCEPTION, 0), cls->name);
		return NULL;
	}

REPEAT:
	/* find free place in VM heap */
	from = vm->heap_last; i = from + 1;
	while (1) {
		if (i >= vm->heap_size) i = 0;
		if (i == from) {
			if (vmGC(vm) > 0)
				goto REPEAT;
OUTOFMEM:	/* out of memory */
			jniThrow((JNIEnv*)env, vm->outofmem);
			return NULL;
		}
		if (vm->heap[i] == NULL) break;
		i++;
	}
	vm->heap_last = i;
	if (vm->heap_max < i) vm->heap_max = i;

	/* compute object data size */
	if (dim > 0) { /* array? */
		len = (len > 0) ? len : 0;
		data_size = (cls->name[1] || (dim > 1)) ? sizeof(jobject) : cls->element_size;
		data_size = sizeof(jint) + len * data_size;
	} else 
		if (dim == 0)
			data_size = cls->total_data_size;
		else
			jniFatalError((JNIEnv*)env, "Negative object dimension [vmCreateObject]");
	
	/* alloc object data */
	ret = vmMemAlloc(env->vm, sizeof(_jobject) + data_size + extra_data_size);
	if (ret == NULL) goto OUTOFMEM;
	if ((data_size + extra_data_size) != 0) {
		ret->data = ((char*)ret) + sizeof(_jobject);
		vmMemSetZero(ret->data, data_size);
	} else
		ret->data = NULL;

	/* init object */
	if ((ret->dim = dim) > 0) {
		ret->clsdefdim = vm->array_clsdef;
		VM_ARRAY_LENGTH(ret) = len; /* array? */
		ret->flags = 0;
	} else {
		ret->clsdefdim = cls;
		ret->flags = (cls->finalizeID != NULL) ? VM_OBJECT_FINALIZE_FLAG : 0;
	}
	ret->clsdef = cls;
#if VM_GC_REFERENCECOUNTING
	ret->cnt = 0;
#endif
	ret->thread_id = 0;
	ret->thread_cnt = 0;
	VM_INIT_EVENT(ret->exit_event);
	VM_INIT_EVENT(ret->wait_event);
	ret->heap_index = i;
	vm->heap[i] = ret;
	return ret;
}


/**
   Destroyes an object on the VM heap. 
   @param env the JNI interface pointer
   @param obj an object
*/
void vmDestroyObject(vmJNIEnv *env, jobject obj) {
	jint i;
	jbyte *data = obj->data;
	clsDefinition *cls = obj->clsdef;
	((vmJNIEnv*)env)->vm->heap[obj->heap_index] = NULL;
	if (obj->dim > 0) {
		/* release array elements */
		jint len = VM_ARRAY_LENGTH(obj);
		jobject* ptr = VM_ARRAY_ARRAY(obj);
		/* array of the objects? */
		if ((obj->dim > 1) || ((obj->dim == 1) && (cls->name[1] != 0)))
			for (i = 0; i < len; i++)
				JNIDELETEGLOBALREF((JNIEnv*)env, ptr[i]);
	} else {
		/* finalize object (invoked only once) */
		if (obj->flags & VM_OBJECT_FINALIZE_FLAG) {
			vmFrame *frame = ((vmJNIEnv*)env)->frame;
			obj->flags &= ~VM_OBJECT_FINALIZE_FLAG;
			VM_PUSH_OBJECT(frame, obj);
			vmExecuteMethod(frame, cls->finalizeID, NULL);
		}
		/* release object fields */
		while (cls != NULL) {
			for (i = 0; i < cls->instance_fields_count; i++) {
				clsField *f = cls->instance_fields + i;
				if ((*(f->descriptor) == 'L') || (*(f->descriptor) == '[')) {
					JNIDELETEGLOBALREF((JNIEnv*)env, *(jobject*)(data + f->data_off));
					*(jobject*)(data + f->data_off) = NULL;
				}
			}
			cls = cls->super_class;
		}
	}
	/* release object */
	if (VM_IS_EVENT_CREATED(obj->exit_event)) VM_DELETE_EVENT(obj->exit_event);
	if (VM_IS_EVENT_CREATED(obj->wait_event)) VM_DELETE_EVENT(obj->wait_event);
	if (obj->flags & VM_OBJECT_FREEDATA_FLAG) vmMemFree(((vmJNIEnv*)env)->vm, obj->data);
	vmMemFree(((vmJNIEnv*)env)->vm, obj);			
}


/**
   Finds a registered class.
   @param env the JNI interface pointer
   @param name a class name
   @param name_len the class name length
   @param dim a class dimension (must be positive value, 0=not array)
   @return a class object or NULL if the class was not found
*/
jclass vmFindClassByName(vmJNIEnv *env, const char *name, jint name_len, jshort dim) {
	if (dim <= VM_MAX_ARRAY_DIMENSION) {
		class_cache_entry *cce;
#ifdef _DEBUG
		if (name_len < 0) 
			jniFatalError((JNIEnv*)env, "Negative class name length! [vmFindClassByName]");
#endif /* _DEBUG */
		cce = (class_cache_entry*)vmHashFindEntry_Fce(&env->vm->clsdef, name, name_len, vmStringHashFceUTF);
		if (cce != NULL) {
			if (cce->obj[dim] == NULL) {
				/* create class object */
				cce->obj[dim] = JNINEWGLOBALREF((JNIEnv*)env,
					vmCreateObject(env, env->vm->class_clsdef, 0, 0, 0));
				VM_CLASS_DEF(cce->obj[dim]) = cce->cls;
				VM_CLASS_DIM(cce->obj[dim]) = dim;
			}
			return cce->obj[dim];
		}
	}
	return NULL;
}


/**
   Finds a registered class.
   @param env the JNI interface pointer
   @param cls a pointer to the class definition
   @param dim a class dimension (must be positive value, 0=not array)
   @return a class object or NULL if the class was not found
*/
jclass vmFindClassByDef(vmJNIEnv *env, clsDefinition *cls, jshort dim) {
	if (dim <= VM_MAX_ARRAY_DIMENSION) {
		class_cache_entry *cce;
		cce = (class_cache_entry*)vmHashFindEntry_Hash(&env->vm->clsdef, cls->name, 0, cls->hash);
		if (cce != NULL) {
			if (cce->obj[dim] == NULL) {
				/* create class object */
				cce->obj[dim] = JNINEWGLOBALREF((JNIEnv*)env,
					vmCreateObject(env, env->vm->class_clsdef, 0, 0, 0));
				VM_CLASS_DEF(cce->obj[dim]) = cce->cls;
				VM_CLASS_DIM(cce->obj[dim]) = dim;
			}
			return cce->obj[dim];
		}
	}
	return NULL;
}


/*****************************************************************
 * Method management
 *****************************************************************/

/**
   Finds a static method of the class.
   @param cls a pointer to the class definition
   @param name the method name
   @param sig the method signature
   @param recursive if it is JNI_TRUE then method is searched in subclasses too
   @return the method ID or NULL if the method was not found
*/
jmethodID vmGetClassMethod(clsDefinition *cls, const char *name, const char *sig, jboolean recursive) {
	if (cls != NULL) {
		jint hash = vmZeroStringHashFceUTF(name, 0) ^ vmZeroStringHashFceUTF(sig, 0);
		register jint cnt = cls->class_methods_count;
		register clsMethod **met = cls->class_methods;
		while (cnt-- > 0) {
			if ((*met)->hash == hash)
				if (!vmStrCmpUTF((*met)->name, name) && !vmStrCmpUTF((*met)->descriptor, sig))
					return *met;
			met++;
		}
		if (recursive != 0)
			return vmGetClassMethod(cls->super_class, name, sig, JNI_TRUE);
	}
	return NULL;
}


/**
   Finds an instance method of the class.
   @param cls a pointer to the class definition
   @param name the method name
   @param sig the method signature
   @param recursive if it is JNI_TRUE then method is searched in subclasses too
   @return the method ID or NULL if the method was not found
*/
jmethodID vmGetInstanceMethod(clsDefinition *cls, const char *name, const char *sig, jboolean recursive) {
	if (cls != NULL) {
		jint hash = vmZeroStringHashFceUTF(name, 0) ^ vmZeroStringHashFceUTF(sig, 0);
		register jint cnt = cls->instance_methods_count;
		register clsMethod **met = cls->instance_methods;
		while (cnt-- > 0) {
			if ((*met)->hash == hash)
				if (!vmStrCmpUTF((*met)->name, name) && !vmStrCmpUTF((*met)->descriptor, sig))
					return *met;
			met++;
		}
		if (recursive != 0)
			return vmGetInstanceMethod(cls->super_class, name, sig, JNI_TRUE);
	}
	return NULL;
}


/**
   Executes a method. 
   Method's attributes (and object of the method's class if it is an instance method) must be pushed on the stack top.
   @param frame the current local frame
   @param met the method ID
   @param clazz it is used for a static method only
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if the object can not be cast to method's clazz
   @exception java.lang.LinkageError if method's class was not resolved successfully
   @exception java.lang.NullPointerException if the object is NULL (instance method only)
   @exception java.lang.UnsatisfiedLinkError if VM cannot link the native method 
*/
void vmExecuteMethod(vmFrame *frame, jmethodID met, jclass clazz) {
	vmJNIEnv *env; vmJavaVM *vm; char buf[2048];
	jobject _this; jint met_flags;
	VM_STACK_SLOT_TYPE *st; TCHAR *p;

#ifdef _DEBUG
	{
//		vmGetMethodDisplayNameUTF(buf, sizeof(buf),	met->clsdef, met->name, met->descriptor, met->access_flags);
//		printf("%s\n", buf);
	}
	if (frame->env->thread_id != vmGetCurrentThreadId())
		printf("Another thread!?\n");
#endif

	env = frame->env; vm = env->vm;
	met_flags = met->access_flags;
	if (met_flags & ACC_ABSTRACT) {
		vmGetMethodDisplayNameUTF(buf, sizeof(buf),	met->clsdef, met->name, met->descriptor, met->access_flags);
		jniThrowNew((JNIEnv*)env, vmFindClassByDef(env, &clsJAVA_LANG_ABSTRACTMETHODERROR, 0), buf);
		return;
	}

	/* is class resolved? */
	if ((met->clsdef->access_flags & ACC_INITED) == 0) {
		if (jniPushLocalFrame((JNIEnv*)env, 20) == JNI_OK) {
			Java_java_lang_ClassLoader_resolveClass((JNIEnv*)env,
				env->vm->loader,
				vmFindClassByDef(env, met->clsdef, 0));
			jniPopLocalFrame((JNIEnv*)env, NULL);
		}
		if ((met->clsdef->access_flags & ACC_INITED) == 0) {
			jniThrowNew((JNIEnv*)env, vmFindClassByDef(env, &clsJAVA_LANG_LINKAGEERROR, 0), met->clsdef->name);
			return;
		}
	}

	/* get object/class */
	if (met_flags & ACC_STATIC)
		_this = clazz;
	else
		_this = *(frame->stack + frame->stack_top - met->parameters_stack_size);
	if (_this == NULL) {
		vmGetMethodDisplayNameUTF(buf, sizeof(buf),	met->clsdef, met->name, met->descriptor, met->access_flags);
		jniThrowNew((JNIEnv*)env, vmFindClassByDef(env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, 0), buf);
		return;
	}

	/* object/class verification */
	if (met_flags & ACC_STATIC) {
		if (vmIsAssignableFrom(met->clsdef, VM_CLASS_DEF(_this)) == JNI_FALSE) {
CLASS_CAST:	vmGetMethodDisplayNameUTF(buf, sizeof(buf),	met->clsdef, met->name, met->descriptor, met->access_flags);
			jniThrowNew((JNIEnv*)env, vmFindClassByDef(env, &clsJAVA_LANG_CLASSCASTEXCEPTION, 0), buf);
			return;
		}
	} else
		if (vmIsAssignableFrom(met->clsdef, _this->clsdef) == JNI_FALSE) {
			if ((met->clsdef->hash != 0x7c015a33) || (_this->clsdef->name[1] != 0) || (_this->dim == 0))   /* primitive type array? */
				goto CLASS_CAST;
		}

	/* execute method */
	if (met_flags & ACC_SYNCHRONIZED)
		jniMonitorEnter((JNIEnv*)env, _this);
	if (met_flags & ACC_NATIVE) {
		jvalue retval; char ret_type;
		ret_type = met->return_type;

		/*** NATIVE (JNI) METHOD ***/
		/* method parameters verification */
		st = frame->stack + frame->stack_top - met->parameters_stack_size;
		p = met->descriptor; p++; if ((met_flags & ACC_STATIC) == 0) st++;
		while (*p != (TCHAR)')') {
			switch (*p) {
				case 'V': 
					break;
				case 'D':
				case 'J': 
					st += VM_STACK_SLOT_LONG_SIZE;
					break;
				case '[':
				case 'L': {
					jint name_len = 0; jshort dim = 0;
					while (*p == (TCHAR)'[') { dim++; p++; }
					if (*p == (TCHAR)'L') {	p++; while (p[name_len] != (TCHAR)';') name_len++; } else name_len++;
					if (*st != NULL) {
						/* method parameters verification */
						class_cache_entry *cce = (class_cache_entry*)vmHashFindEntry_Fce(&vm->clsdef, p, name_len, vmStringHashFceUTF);
						if (cce == NULL)
							goto CLASS_CAST;
						if (vmIsAssignableFrom(cce->cls, (*st)->clsdef) == JNI_FALSE) {
							if ((cce->cls->hash != 0x7c015a33) || (dim > 0) || ((*st)->clsdef->name[1] != 0) || ((*st)->dim == 0))   /* primitive type array? */
								goto CLASS_CAST;
						} else
						if (dim != (*st)->dim)
							if (!((dim == 0) && (cce->cls->hash == 0x7c015a33) && ((*st)->clsdef->name[1] != 0)))	/* java.lang.Object? */
								goto CLASS_CAST;
					}					
					p += name_len; if (*p != (TCHAR)';') p--;
					}
				default: 
					st++; 
					break;
			}
			p++;
		}

		/* is method linked? */
		if (met->code == NULL) {
			char *bufex = buf + 1024, *p, *s; jint li;
			vmStrCpyUTF(buf, "_Java_");
			if (clazz == NULL) clazz = jniFindClass((JNIEnv*)env, met->clsdef->name);
			vmStrCatUTF(buf, VM_CLASS_DEF(clazz)->name);
			vmStrCatUTF(buf, "_");
			p = buf; while (*p) { if (*p == '/') *p = '_'; p++; }
			s = met->name;
			while (*s) {
				*p = *s; if (*p == '_') { p++; *p = '1'; }
				s++; p++;
			}
			*p = 0;
			vmStrCpyUTF(bufex, buf);
			vmSprintfUTF(p, "@%u", ((met->access_flags & ACC_STATIC) ? 8 : 4) + (4 * met->parameters_stack_size));
			p = bufex; while (*p) p++; vmStrCpyUTF(p, "__");
			while (*p) p++; s = met->descriptor + 1;
			while (*s && (*s != ')')) {
				if (*s == '[') {
					vmStrCpyUTF(p, "_3"); p += 2;
				} else
				if (*s == 'L') {
					while (*s != ';') {
						*p = *s;
						if (*p == '/') *p = '_'; else if (*p == '_') { p++; *p = '1'; }
						p++; s++;
					}
					vmStrCpyUTF(p, "_2"); p += 2;
				}
				else {
					*p = *s; p++;
				}
				s++;
			}
			vmSprintfUTF(p, "@%u", ((met->access_flags & ACC_STATIC) ? 8 : 4) + (4 * met->parameters_stack_size));
			for (li = 0; li < vm->lib_count; li++) {
				if (met->code = vmGetProcAddressUTF(vm->lib[li], buf)) 
					break;
				if (met->code = vmGetProcAddressUTF(vm->lib[li], bufex)) 
					break;
			}
			if (met->code == NULL) {
				vmGetMethodDisplayNameUTF(buf, sizeof(buf),	met->clsdef, met->name, met->descriptor, met->access_flags);
				jniThrowNew((JNIEnv*)env, jniFindClass((JNIEnv*)env, clsJAVA_LANG_UNSATISFIEDLINKERROR.name), buf);
				retval.l = NULL;
				goto DONE;
			}
		}

		/* OK, call method */
		VM_NATIVE_PUSH_PARAMS(frame, met);
		if (met_flags & ACC_STATIC)
			VM_NATIVE_PUSH_OBJECT(_this);
		VM_NATIVE_PUSH_OBJECT(env);
		VM_NATIVE_CALL(frame, retval, ret_type);
		/* pop method parameters */
		frame->stack_top -= met->parameters_stack_size;
		/* push return value to stack */
		VM_PUSH_VALUE(frame, retval, ret_type);

	} else {	

		/*** BYTECODE (JAVA) METHOD ***/
		vmFrame *frame2; jthrowable err; jint i;
		jubyte *pc_stop = (jubyte*)met->code + met->code_len;

		/* create new local frame */
		frame->stack_top -= met->parameters_stack_size;
		if (JNI_OK != jniPushLocalFrame((JNIEnv*)env, met->vars_count + met->max_operand_stack)) {
			jniThrowNew((JNIEnv*)env, vmFindClassByDef(env, &clsJAVA_LANG_STACKOVERFLOWERROR, 0), NULL);
			goto DONE;
		}
		frame2 = env->frame;

		/* init local variables */
		st = frame2->stack;
		i = met->vars_count - met->parameters_stack_size;
		while (i-- > 0)
			st[met->parameters_stack_size + i] = NULL;
		frame2->stack_top = met->vars_count;

		/* push parameter references to new local frame */
		if ((met_flags & ACC_STATIC) == 0) {
			jniNewLocalRef((JNIEnv*)env, *st);	/* object reference */
			st++;
		}
		p = met->descriptor; p++;
		while (*p != (TCHAR)')') {
			switch (*p) {
				case 'D':
				case 'J': 
					st += VM_STACK_SLOT_LONG_SIZE;
					break;
				case '[':
				case 'L': {
					jint name_len = 0; jshort dim = 0;
					while (*p == (TCHAR)'[') { dim++; p++; }
					if (*p == (TCHAR)'L') {	p++; while (p[name_len] != (TCHAR)';') name_len++; } else name_len++;
					if (*st != NULL) {
						/* method parameters verification */
						class_cache_entry *cce = (class_cache_entry*)vmHashFindEntry_Fce(&vm->clsdef, p, name_len, vmStringHashFceUTF);
						if (cce == NULL)
							goto CLASS_CAST_POP;
						if (vmIsAssignableFrom(cce->cls, (*st)->clsdef) == JNI_FALSE) {
							if ((cce->cls->hash != 0x7c015a33) || (dim > 0) || ((*st)->clsdef->name[1] != 0) || ((*st)->dim == 0))   /* primitive type array? */
								goto CLASS_CAST_POP;
						} else
						if (dim != (*st)->dim)
							if (!((dim == 0) && (cce->cls->hash == 0x7c015a33) && ((*st)->clsdef->name[1] != 0))) {	/* java.lang.Object? */
CLASS_CAST_POP:					jniPopLocalFrame((JNIEnv*)env, NULL);
								goto CLASS_CAST;
							}
					}					
					p += name_len; if (*p != (TCHAR)';') p--;
					jniNewLocalRef((JNIEnv*)env, *st);
					}
				default: 
					st++;
					break;
			}
			p++;
		}

		/* execute bytecode */
		frame2->met = met;
		frame2->constant_pool = met->clsdef->constant_pool;
		frame2->pc = met->code;
		frame2->wide = JNI_FALSE;
LOOP:	while (frame2->pc < pc_stop)
			if (err = jInstructionSet[*frame2->pc](frame2)) {
				clsDefinition *errclsdef = err->clsdef;
				clsConstPool *cp = frame2->constant_pool;
				jint pc = frame2->pc - (jubyte*)frame2->met->code;
				jint et_count = frame2->met->exceptions_count, i;
				exception_table *et = frame2->met->exceptions;
				for (i = 0; i < et_count; i++)
					if ((et[i].start_pc < pc) && (pc <= et[i].end_pc))
						if (!et[i].catch_type ||
								vmIsAssignableFrom(VM_CLASS_DEF((jobject)cp[et[i].catch_type].p), errclsdef))
						{
							frame2->exception = NULL;
							frame2->pc = (jubyte*)frame2->met->code + et[i].handler_pc;
							VM_PUSH_OBJECT(frame2, err);
							goto LOOP;
						}
				/* exception handler not found */
				frame2->exception = err;
				jniPopLocalFrame((JNIEnv*)env, NULL);
				goto DONE;
			}
		if (frame2->pc > pc_stop)
			jniFatalError((JNIEnv*)env, "Corrupted code (pc overflow)");
	}
DONE:
	if (env->frame != frame)
		jniFatalError((JNIEnv*)env, "Corrupted code (invalid frame)");
	if (met_flags & ACC_SYNCHRONIZED)
		jniMonitorExit((JNIEnv*)env, _this);
}


/**
   Executes a virtual instance method.
   Method's attributes and object of the method's class must be pushed on the stack top.
   @param frame the current local frame
   @param met the method ID
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if the object can not be cast to method's clazz
   @exception java.lang.LinkageError if method's class was not resolved successfully
   @exception java.lang.NullPointerException if the object is NULL (instance method only)
   @exception java.lang.UnsatisfiedLinkError if VM cannot link the native method 
*/
void vmInvokeVirtual(vmFrame *frame, jmethodID met) {
	jobject obj = *(frame->stack + frame->stack_top - met->parameters_stack_size);
	if (obj != NULL)
		if (met->clsdef != obj->clsdefdim) {
			met = vmGetInstanceMethod(obj->clsdefdim, met->name, met->descriptor, JNI_TRUE);
			if ((met == NULL) && (frame->env->flags & VM_JNIENV_DESTROYED))
				return;
		}
	vmExecuteMethod(frame, met, NULL);
}


/**
   Executes a non virtual instance method. 
   Method's attributes and object of the method's class must be pushed on the stack top.
   @param frame the current local frame
   @param met the method ID
   @param clazz a class object
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if the object can not be cast to method's clazz
   @exception java.lang.LinkageError if method's class was not resolved successfully
   @exception java.lang.NullPointerException if the object is NULL (instance method only)
   @exception java.lang.UnsatisfiedLinkError if VM cannot link the native method 
*/
void vmInvokeSpecial(vmFrame *frame, jmethodID met, jclass clazz) {
	if (clazz != NULL)
		if (clazz->clsdef == frame->env->vm->class_clsdef) {
			jobject obj; clsDefinition *cls;
			obj = *(frame->stack + frame->stack_top - met->parameters_stack_size);
			cls = VM_CLASS_DEF_DIM(clazz);
			if (met->clsdef != cls)
				met = vmGetInstanceMethod(cls, met->name, met->descriptor, JNI_FALSE);
		}
	vmExecuteMethod(frame, met, NULL);
}


/**
   Executes a static method. 
   Method's attributes must be pushed on the stack top.
   @param frame the current local frame
   @param met the method ID
   @param clazz it is used for a static method only
   @exception java.lang.AbstractMethodError if is called an abstract method
   @exception java.lang.ClassCastException if the object can not be cast to method's clazz
   @exception java.lang.LinkageError if method's class was not resolved successfully
   @exception java.lang.NullPointerException if the object is NULL (instance method only)
   @exception java.lang.UnsatisfiedLinkError if VM cannot link the native method 
*/
void vmInvokeStatic(vmFrame *frame, jmethodID met, jclass clazz) {
	if (clazz != NULL) {
		clsDefinition *cls;
		cls = VM_CLASS_DEF_DIM(clazz);
		if (met->clsdef != cls)
			met = vmGetClassMethod(cls, met->name, met->descriptor, JNI_TRUE);
	}
	vmExecuteMethod(frame, met, clazz);
}


/**
   Returns a method display name.
   @param buf a pointer to the output buffer to receive method display name
   @param buflen length of the output buffer
   @param cls a class definition
   @param name the method name
   @param sig the method signature
   @return a pointer to returned method display name
*/
char* vmGetMethodDisplayNameUTF(char *buf, int buflen, clsDefinition *cls, const char *name, const char *sig, jint flags) {
	if (buflen >= 32) {
		jboolean isConstructor = !vmStrCmpUTF(name, "<init>");
		char *p; const char *q;
		p = buf; q = sig;
		while (*q && (*q != ')')) q++; if (*q == ')') q++;
		vmMemSetZero(p, buflen--);
		if (flags & ACC_ABSTRACT)
			if (buflen > 9) { vmStrCatUTF(p, "abstract "); while (*p) { p++; buflen--; } }
		if (flags & ACC_PUBLIC)
			if (buflen > 7) { vmStrCatUTF(p, "public "); while (*p) { p++; buflen--; } }
		if (flags & ACC_PROTECTED)
			if (buflen > 10) { vmStrCatUTF(p, "protected "); while (*p) { p++; buflen--; } }
		if (flags & ACC_PRIVATE)
			if (buflen > 8) { vmStrCatUTF(p, "private "); while (*p) { p++; buflen--; } }
		if (flags & ACC_STATIC)
			if (buflen > 7) { vmStrCatUTF(p, "static "); while (*p) { p++; buflen--; } }
		if (flags & ACC_SYNCHRONIZED)
			if (buflen > 13) { vmStrCatUTF(p, "synchronized "); while (*p) { p++; buflen--; } }
		if (!isConstructor) {
			vmGetTypeDisplayNameUTF(p, buflen, q); while (*p) { p++; buflen--; }
			if (buflen) { vmStrCatUTF(p++, " "); buflen--; }
		}
		vmStrnCpyUTF(p, cls->name, buflen); while (*p) { if (*p == '/') *p = '.'; p++; buflen--; }
		if (!isConstructor) {
			if (buflen) { vmStrCatUTF(p++, "."); buflen--; }
			vmStrnCpyUTF(p, name, buflen); while (*p) { p++; buflen--; }
		}
		if (buflen) { vmStrCatUTF(p++, "("); buflen--; }
		q = sig; 
		if (q[1] != ')')
			while (*q && (*q != ')') && (buflen > 0)) {
				if (*q == '(') q++; else if (buflen > 1) { vmStrCatUTF(p++, ", "); buflen -= 2; }
				q = vmGetTypeDisplayNameUTF(p, buflen, q); while (*p) { p++; buflen--; }
			}
		if (buflen) { vmStrCatUTF(p++, ")"); buflen--; }
	}
	return buf;
}


/*****************************************************************
 * Field management
 *****************************************************************/

/**
   Transforms a local reference into a global reference.
   @param frame the current local frame
   @param lref a local reference
   @return the global reference to the object
*/
jboolean vmLocal2GlobalRef(vmFrame *frame, jobject lref) {
	if (lref != NULL) {
		VM_STACK_SLOT_TYPE *refs = frame->refs;
		jint top = frame->refs_top, ptr = top;
		/* find local reference */
		while (--ptr >= 0)
			if (refs[ptr] == lref) {
				jint size = top - ptr - 1;
				if (size > 0)
					vmMemCpy(refs + ptr, refs + ptr + 1, size * sizeof(VM_STACK_SLOT_TYPE));
				frame->refs_top--;
				return JNI_TRUE;
			}
	}
	return JNI_FALSE;
}


/**
   Tests if an object of @a cls2 is assignable to @a cls1.
   @param cls1 a pointer to the class definition
   @param cls2 a pointer to the class definition
   @return JNI_TRUE if an object of @a cls2 is assignable to @a cls1
*/
jboolean vmIsAssignableFrom(clsDefinition *cls1, clsDefinition *cls2) {
	/* process test */
	if (cls1->access_flags & ACC_INTERFACE) {
		while (cls2 != NULL) {
			register jint cnt = cls2->interfaces_count;
			register clsDefinition **intf = cls2->interfaces;
			if (cls2->name == cls1->name)
				return JNI_TRUE;
			while (cnt-- > 0)
				if (vmIsAssignableFrom(cls1, *(intf++)))
//				clsDefinition *intfc = *(intf++);
//				if ((intfc != NULL) && (intfc->name == cls1->name))
					return JNI_TRUE;
//			}
			cls2 = cls2->super_class;
		}
	} else
		while (cls2 != NULL) {
			if (cls2->name == cls1->name)
					return JNI_TRUE;
			cls2 = cls2->super_class;
		}
	return JNI_FALSE;
}


/**
   Tests if an object of @a cls2, @a dim2 is assignable to @a cls1, @a dim1.
   @param cls1 a pointer to the class definition
   @param dim1 a class dimension
   @param cls2 a pointer to the class definition
   @param dim2 a class dimension
   @return JNI_TRUE if an object of @a cls2 is assignable to @a cls1
*/
jboolean FASTCALL vmIsClassAssignableFrom(clsDefinition *cls1, jint dim1, clsDefinition *cls2, jint dim2) {
	if (dim1 != dim2)
		/* Assignable to java.lang.Object? */
		if ((dim1 == 0) && (cls1->name == clsJAVA_LANG_OBJECT.name) && ((dim2 > 0) || (cls2->name[1] != 0)))
			return JNI_TRUE;
		else
			return JNI_FALSE;
	return vmIsAssignableFrom(cls1, cls2);
}


/**
   Finds a static field of the class.
   @param cls a pointer to the class definition
   @param name the field name
   @param sig the field signature
   @param recursive if it is JNI_TRUE then field is searched in subclasses too
   @return the field ID or NULL if the field was not found
*/
jfieldID vmGetClassField(clsDefinition *cls, const char *name, const char *sig, jboolean recursive) {
	if (cls != NULL) {
		jint hash = vmZeroStringHashFceUTF(name, 0) ^ vmZeroStringHashFceUTF(sig, 0);
		register jint cnt = cls->class_fields_count;
		register clsField *fld = cls->class_fields;
		while (cnt-- > 0) {
			if (fld->hash == hash)
				if (!vmStrCmpUTF(fld->name, name) && !vmStrCmpUTF(fld->descriptor, sig))
					return fld;
			fld++;
		}
		if (recursive != 0)
			return vmGetClassField(cls->super_class, name, sig, JNI_TRUE);
	}
	return NULL;
}


/**
   Finds an instance field of the class.
   @param cls a pointer to the class definition
   @param name the field name
   @param sig the field signature
   @param recursive if it is JNI_TRUE then field is searched in subclasses too
   @return the field ID or NULL if the field was not found
*/
jfieldID vmGetInstanceField(clsDefinition *cls, const char *name, const char *sig, jboolean recursive) {
	if (cls != NULL) {
		jint hash = vmZeroStringHashFceUTF(name, 0) ^ vmZeroStringHashFceUTF(sig, 0);
		register jint cnt = cls->instance_fields_count;
		register clsField *fld = cls->instance_fields;
		while (cnt-- > 0) {
			if (fld->hash == hash)
				if (!vmStrCmpUTF(fld->name, name) && !vmStrCmpUTF(fld->descriptor, sig))
					return fld;
			fld++;
		}
		if (recursive != 0)
			return vmGetInstanceField(cls->super_class, name, sig, JNI_TRUE);
	}
	return NULL;
}


/**
   Sets new field value.
   @param env the JNI interface pointer
   @param dest a pointer to the old field value
   @param src new field value
   @param fld the field ID
   @return JNI_FALSE on success or JNI_TRUE if an error occurs
   @exception java.lang.ClassCastException if @a src can not be assigned to the @a dest
*/
jboolean vmSetObjectVar(JNIEnv *env, jobject *dest, jobject src, jfieldID fld) {
	vmJavaVM *vm = ((vmJNIEnv*)env)->vm;
	jobject oldval = NULL;
	/* is assignable to the destination object ? */
	if ((src != NULL) && (fld != NULL)) {
		jint dim1, dim2; clsDefinition *cls1, *cls2;
		if (fld->vartype == NULL)
			fld->vartype = jniFindClass(env, fld->descriptor);
		if (fld->vartype == NULL) {
CASTERR:	jniThrowNew(env, jniFindClass(env, clsJAVA_LANG_CLASSCASTEXCEPTION.name), src->clsdefdim->name);
			return JNI_TRUE;
		}
		dim1 = VM_CLASS_DIM(fld->vartype); dim2 = src->dim;
		cls1 = VM_CLASS_DEF(fld->vartype); cls2 = src->clsdef;
		if (!vmIsClassAssignableFrom(cls1, dim1, cls2, dim2))
			goto CASTERR;
	}
	/* set new value */
	VM_ENTER_CRITICAL_SECTION(vm->gcs);
	oldval = *dest;
	*dest = JNINEWGLOBALREF(env, src);
	VM_LEAVE_CRITICAL_SECTION(vm->gcs);
	/* release old value */
	JNIDELETEGLOBALREF(env, oldval);
	return JNI_FALSE;
}


/**
   Pushes current instance field value to the stack.
   @param frame the current local frame
   @param obj an object
   @param fld the instance field ID
   @return NULL on success or a throwable object if an error occurs
   @exception java.lang.NoSuchFieldException if the object not has the field @a fld
   @exception java.lang.NullPointerException if the object is NULL
*/
jthrowable vmGetField(vmFrame *frame, jobject obj, jfieldID fld) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	if (obj == NULL)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "[getfield]");
	if (fld == NULL)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDEXCEPTION, "[getfield]");
	if (!vmIsAssignableFrom(fld->clsdef, obj->clsdefdim)) {
		fld = vmGetInstanceField(obj->clsdefdim, fld->name, fld->descriptor, JNI_TRUE);
		if (fld == NULL)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDEXCEPTION, "[getfield]");
	}
	VM_ENTER_CRITICAL_SECTION(gcs);
	VM_PUSH_VALUE(frame, *(jvalue*)(obj->data + fld->data_off), fld->descriptor[0]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	return NULL;
}


/**
   Sets new instance field value (object and new value taken from stack).
   @param frame the current local frame
   @param fld the instance field ID
   @return NULL on success or a throwable object if an error occurs
   @exception java.lang.NoSuchFieldException if the object not has the field @a fld
   @exception java.lang.NullPointerException if the object is NULL
*/
jthrowable vmPutField(vmFrame *frame, jfieldID fld) {
	jobject obj; void *val;
	jthrowable ret; char type;
	natSynchronizeData *gcs = frame->env->vm->gcs;

	if (fld == NULL)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDEXCEPTION, "[putfield]");
	ret = NULL;
	type = fld->descriptor[0];
	if ((type == 'J') || (type == 'D'))
		obj = *(frame->stack + frame->stack_top - VM_STACK_SLOT_LONG_SIZE - 1);
	else
		obj = *(frame->stack + frame->stack_top - 2);
	if (obj == NULL)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "[putfield]");
	if (!vmIsAssignableFrom(fld->clsdef, obj->clsdefdim)) {
		fld = vmGetInstanceField(obj->clsdefdim, fld->name, fld->descriptor, JNI_TRUE);
		if (fld == NULL)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDEXCEPTION, "[putfield]");
	}
	val = obj->data + fld->data_off;
	switch (type) {
		case '[':
		case 'L':
			if (vmSetObjectVar((JNIEnv*)frame->env, (jobject*)val, VM_POP_OBJECT(frame), fld))
				ret = jniExceptionOccurred((JNIEnv*)frame->env);
			break;
		case 'I':
			*(jint*)val = VM_POP_INT(frame);
			break;
		case 'D': 
			VM_ENTER_CRITICAL_SECTION(gcs);
			*(jdouble*)val = VM_POP_DOUBLE(frame); 
			VM_LEAVE_CRITICAL_SECTION(gcs);
			break;
		case 'C': 
			*(jchar*)val = VM_POP_CHAR(frame);
			break;
		case 'Z': 
			*(jboolean*)val = VM_POP_BOOLEAN(frame);
			break;
		case 'B': 
			*(jbyte*)val = VM_POP_BYTE(frame);
			break;
		case 'J': 
			VM_ENTER_CRITICAL_SECTION(gcs);
			*(jlong*)val = VM_POP_LONG(frame);
			VM_LEAVE_CRITICAL_SECTION(gcs);
			break;
		case 'F':
			*(jfloat*)val = VM_POP_FLOAT(frame);
			break;
		case 'S':
			*(jshort*)val = VM_POP_SHORT(frame);
			break;
	}
	VM_POP_OBJECT(frame);
	return ret;
}


/**
   Pushes current static field value to the stack.
   @param frame the current local frame
   @param fld the instance field ID
   @return NULL on success or a throwable object if an error occurs
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the object not has the field @a fld
*/
jthrowable vmGetStatic(vmFrame *frame, jfieldID fld) {
	clsDefinition *cls; JNIEnv *env;
	natSynchronizeData *gcs = frame->env->vm->gcs;

	env = (JNIEnv*)frame->env;
	if (fld == NULL)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDEXCEPTION, NULL);
	cls = fld->clsdef;
	if (cls->vm != frame->env->vm)
		jniFatalError((JNIEnv*)env, "Class definition not found [vmGetStatic]");

	/* is a static field? */
	if ((fld->access_flags & ACC_STATIC) == 0)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, "not a static field");

	/* is class resolved? */
	if ((cls->access_flags & ACC_INITED) == 0) {
		if (jniPushLocalFrame(env, 20) == JNI_OK) {
			Java_java_lang_ClassLoader_resolveClass(env,
				((vmJNIEnv*)env)->vm->loader,
				vmFindClassByDef((vmJNIEnv*)env, cls, 0));
			jniPopLocalFrame(env, NULL);
		}
		if ((cls->access_flags & ACC_INITED) == 0) {
			jniThrowNew((JNIEnv*)frame->env, vmFindClassByDef(frame->env, &clsJAVA_LANG_LINKAGEERROR, 0), cls->name);
			return frame->exception;
		}
	}

	VM_ENTER_CRITICAL_SECTION(gcs);
	VM_PUSH_VALUE(frame, fld->val, fld->descriptor[0]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	return NULL;
}


/**
   Sets new static field value (new value taken from stack).
   @param frame the current local frame
   @param fld the static field ID
   @return NULL on success or a throwable object if an error occurs
   @exception java.lang.IncompatibleClassChangeError if the field is not static
   @exception java.lang.LinkageError if the class was not resolved successfully
   @exception java.lang.NoSuchFieldException if the object not has the field @a fld
*/
jthrowable vmPutStatic(vmFrame *frame, jfieldID fld) {
	clsDefinition *cls; JNIEnv *env;
	natSynchronizeData *gcs = frame->env->vm->gcs;

	env = (JNIEnv*)frame->env;
	if (fld == NULL)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDEXCEPTION, NULL);
	cls = fld->clsdef;
	if (cls->vm != frame->env->vm)
		jniFatalError((JNIEnv*)env, "Class definition not found [vmPutStatic]");

	/* is a static field? */
	if ((fld->access_flags & ACC_STATIC) == 0)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, "not a static field");

	/* is class resolved? */
	if ((cls->access_flags & ACC_INITED) == 0) {
		if (jniPushLocalFrame(env, 20) == JNI_OK) {
			Java_java_lang_ClassLoader_resolveClass(env, 
				((vmJNIEnv*)env)->vm->loader,
				vmFindClassByDef((vmJNIEnv*)env, cls, 0));
			jniPopLocalFrame(env, NULL);
		}
		if ((cls->access_flags & ACC_INITED) == 0) {
			jniThrowNew(env, vmFindClassByDef((vmJNIEnv*)env, &clsJAVA_LANG_LINKAGEERROR, 0), cls->name);
			return jniExceptionOccurred(env);
		}
	}

	switch (fld->descriptor[0]) {
		case '[': 
		case 'L': 
			if (vmSetObjectVar(env, (jobject*)&(fld->val.l), VM_POP_OBJECT(frame), fld))
				return jniExceptionOccurred(env);
			break;
		case 'I': 
			fld->val.i = VM_POP_INT(frame); 
			break;
		case 'D': 
			VM_ENTER_CRITICAL_SECTION(gcs);
			fld->val.d = VM_POP_DOUBLE(frame);
			VM_LEAVE_CRITICAL_SECTION(gcs);
			break;
		case 'C': 
			fld->val.c = VM_POP_CHAR(frame); 
			break;
		case 'Z': 
			fld->val.z = VM_POP_BOOLEAN(frame); 
			break;
		case 'B':
			fld->val.b = VM_POP_BYTE(frame);
			break;
		case 'J': 
			VM_ENTER_CRITICAL_SECTION(gcs);
			fld->val.j = VM_POP_LONG(frame); 
			VM_LEAVE_CRITICAL_SECTION(gcs);
			break;
		case 'F': 
			fld->val.f = VM_POP_FLOAT(frame); 
			break;
		case 'S': 
			fld->val.s = VM_POP_SHORT(frame); 
			break;
	}
	return NULL;
}


/**
   Returns a type display name.
   @param buf a pointer to the output buffer to receive type display name
   @param buflen length of the output buffer
   @param sig the type signature
   @return a pointer to returned type display name
*/
const char *vmGetTypeDisplayNameUTF(char *buf, int buflen, const char *sig) {
	int i, dim;
	buf[0] = 0;
	dim = 0; while (*sig && (*sig == '[')) { dim++; sig++; }	
	switch (*sig) {
		case 'V': vmStrnCpyUTF(buf, "void", buflen); buflen -= 4; break;
		case 'Z': vmStrnCpyUTF(buf, "boolean", buflen); buflen -= 7; break;
		case 'B': vmStrnCpyUTF(buf, "byte", buflen); buflen -= 4; break;
		case 'C': vmStrnCpyUTF(buf, "char", buflen); buflen -= 4; break;
		case 'S': vmStrnCpyUTF(buf, "short", buflen); buflen -= 5; break;
		case 'I': vmStrnCpyUTF(buf, "int", buflen); buflen -= 3; break;
		case 'J': vmStrnCpyUTF(buf, "long", buflen); buflen -= 4; break;
		case 'F': vmStrnCpyUTF(buf, "float", buflen); buflen -= 5; break;
		case 'D': vmStrnCpyUTF(buf, "double", buflen); buflen -= 6; break;
		default:
			if (*sig == 'L') sig++;
			while (*sig && (*sig != ';') && (buflen > 0)) {
				char pom[] = ".";
				if (*sig != '/') pom[0] = *sig;
				vmStrCatUTF(buf, pom);
				sig++; buflen--;
			}
	}	
	for (i = 0; (i < dim) && (buflen > 1); i++) { buflen -= 2; vmStrCatUTF(buf, "[]"); }
	return ++sig;
}


/**
   Returns a field display name.
   @param buf a pointer to the output buffer to receive field display name
   @param buflen length of the output buffer
   @param cls a class definition
   @param name the field name
   @param sig the field signature
   @return a pointer to returned field display name
*/
char* vmGetFieldDisplayNameUTF(char *buf, int buflen, clsDefinition *cls, const char *name, const char *sig, jint flags) {
	if (buflen >= 32) {
		char *p; const char *q; jint dim = 0;
		p = buf; q = sig;
		vmMemSetZero(p, buflen--);
		if (flags & ACC_PUBLIC)
			if (buflen > 7) { vmStrCatUTF(p, "public "); while (*p) { p++; buflen--; } }
		if (flags & ACC_PROTECTED)
			if (buflen > 10) { vmStrCatUTF(p, "protected "); while (*p) { p++; buflen--; } }
		if (flags & ACC_PRIVATE)
			if (buflen > 8) { vmStrCatUTF(p, "private "); while (*p) { p++; buflen--; } }
		if (flags & ACC_STATIC)
			if (buflen > 7) { vmStrCatUTF(p, "static "); while (*p) { p++; buflen--; } }
		if (flags & ACC_FINAL)
			if (buflen > 7) { vmStrCatUTF(p, "final "); while (*p) { p++; buflen--; } }
		if (flags & ACC_TRANSIENT)
			if (buflen > 13) { vmStrCatUTF(p, "transient "); while (*p) { p++; buflen--; } }
		if (flags & ACC_VOLATILE)
			if (buflen > 13) { vmStrCatUTF(p, "volatile "); while (*p) { p++; buflen--; } }
		while (*q && (*q == '[')) { dim++; q++; }
		vmGetTypeDisplayNameUTF(p, buflen, q); while (*p) { p++; buflen--; }
		if (buflen > 0) { vmStrCatUTF(p++, " "); buflen--; }
		q = cls->name; while (*q && (*q == '[')) q++;
		vmStrnCpyUTF(p, q, buflen); while (*p) { if (*p == '/') *p = '.'; p++; buflen--; }
		if (buflen) { vmStrCatUTF(p++, "."); buflen--; }
		vmStrnCpyUTF(p, name, buflen); while (*p) { p++; buflen--; }
		while (dim-- > 0)
			if (buflen > 0) { vmStrCatUTF(p++, "[]"); p++; buflen -= 2; }
	}
	return buf;
}
