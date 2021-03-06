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
   The Java byte code handlers.
   The appropriate Java byte code handler is called by the virtual machine
   for each interpreted and executed Java instruction.
   @author Dusan Stastny <info@developservice.cz>
*/

/* Notes: */
/* - constant pool indexes are not checked */

#include <float.h>
#include <math.h>
#include "config.h"
#include "java\lang\_all.h"


/** Reads a byte from the buffer @a p. */
#define GET_JBYTE(p)   (jbyte)(*(p+1))

/** Reads an unsigned byte from the buffer @a p. */
#define GET_JUBYTE(p)  (jubyte)(*(p+1))

/** Reads a short integer from the buffer @a p. */
#define GET_JSHORT(p)  (jshort)((*(p+1) << 8) | *(p+2))

/** Reads an unsigned short integer from the buffer @a p. */
#define GET_JUSHORT(p) (jushort)((*(p+1) << 8) | *(p+2))

/** Reads a integer from the buffer @a p. */
#define GET_JINT(p)    (jint)((*(p+1) << 24) | (*(p+2) << 16) | (*(p+3) << 8) | *(p+4))

/** Implementation of the java.lang.Float.isNan() method. */
jboolean JNICALL Java_java_lang_Float_isNan(JNIEnv *env, jclass clazz, jfloat f) {
	return 0 != _isnan(f);
}

/** Implementation of the java.lang.Double.isNan() method. */
jboolean JNICALL Java_java_lang_Double_isNan(JNIEnv *env, jclass clazz, jdouble d) {
	return 0 != _isnan(d);
}


/**
   The handler for unknown Java instruction. 
   @param frame the current local frame
   @return NULL on success or a throwable object that must be thrown by the virtual machine
   @exception java.lang.VirtualMachineError always
*/
static jthrowable jUnknownCode(vmFrame *frame) {
	char buf[64];
	vmSprintfUTF(buf, "Unknown instruction [%i]", *frame->pc);
	frame->pc++;
	return vmCreateThrowable(frame->env, &clsJAVA_LANG_VIRTUALMACHINEERROR, buf);
}


/* 0 */
static jthrowable _nop(vmFrame *frame) {
	frame->pc++;
	return NULL;
}


/* 1 */
static jthrowable _aconst_null(vmFrame *frame) {
	VM_PUSH_OBJECT(frame, NULL);
	frame->pc++;
	return NULL;
}


/* 2 */
static jthrowable _iconst_m1(vmFrame *frame) {
	VM_PUSH_INT(frame, -1);
	frame->pc++;
	return NULL;
}


/* 3 */
static jthrowable _iconst_0(vmFrame *frame) {
	VM_PUSH_INT(frame, 0);
	frame->pc++;
	return NULL;
}


/* 4 */
static jthrowable _iconst_1(vmFrame *frame) {
	VM_PUSH_INT(frame, 1);
	frame->pc++;
	return NULL;
}


/* 5 */
static jthrowable _iconst_2(vmFrame *frame) {
	VM_PUSH_INT(frame, 2);
	frame->pc++;
	return NULL;
}


/* 6 */
static jthrowable _iconst_3(vmFrame *frame) {
	VM_PUSH_INT(frame, 3);
	frame->pc++;
	return NULL;
}


/* 7 */
static jthrowable _iconst_4(vmFrame *frame) {
	VM_PUSH_INT(frame, 4);
	frame->pc++;
	return NULL;
}


/* 8 */
static jthrowable _iconst_5(vmFrame *frame) {
	VM_PUSH_INT(frame, 5);
	frame->pc++;
	return NULL;
}


/* 9 */
static jthrowable _lconst_0(vmFrame *frame) {
	VM_PUSH_LONG(frame, 0);
	frame->pc++;
	return NULL;
}


/* 10 */
static jthrowable _lconst_1(vmFrame *frame) {
	VM_PUSH_LONG(frame, 1);
	frame->pc++;
	return NULL;
}


/* 11 */
static jthrowable _fconst_0(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, 0);
	frame->pc++;
	return NULL;
}


/* 12 */
static jthrowable _fconst_1(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, 1);
	frame->pc++;
	return NULL;
}


/* 13 */
static jthrowable _fconst_2(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, 2);
	frame->pc++;
	return NULL;
}


/* 14 */
static jthrowable _dconst_0(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, 0);
	frame->pc++;
	return NULL;
}


/* 15 */
static jthrowable _dconst_1(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, 1);
	frame->pc++;
	return NULL;
}


/* 16 */
static jthrowable _bipush(vmFrame *frame) {
	VM_PUSH_INT(frame, GET_JBYTE(frame->pc));
	frame->pc += 2;
	return NULL;
}


/* 17 */
static jthrowable _sipush(vmFrame *frame) {
	VM_PUSH_INT(frame, GET_JSHORT(frame->pc));
	frame->pc += 3;
	return NULL;
}


/* 18 */
static jthrowable _ldc(vmFrame *frame) {
	clsConstPool *cp = frame->constant_pool + GET_JUBYTE(frame->pc);
	switch (cp->tag) {
		case CONSTANT_Integer: VM_PUSH_INT(frame, cp->i); break;
		case CONSTANT_Float: VM_PUSH_FLOAT(frame, *(jfloat*)(cp->p)); break;
		case CONSTANT_String: VM_PUSH_OBJECT(frame, cp->p); break;
		default: jniFatalError((JNIEnv*)frame->env, "Illegal constant type [ldc]");
	}
	frame->pc += 2;
	return NULL;
}


/* 19 */
static jthrowable _ldc_w(vmFrame *frame) {
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	switch (cp->tag) {
		case CONSTANT_Integer: VM_PUSH_INT(frame, cp->i); break;
		case CONSTANT_Float: VM_PUSH_FLOAT(frame, *(jfloat*)(cp->p)); break;
		case CONSTANT_String: VM_PUSH_OBJECT(frame, cp->p); break;
		default: jniFatalError((JNIEnv*)frame->env, "Illegal constant type [ldc_w]");
	}
	frame->pc += 3;
	return NULL;
}


/* 20 */
static jthrowable _ldc2_w(vmFrame *frame) {
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	switch (cp->tag) {
		case CONSTANT_Long: VM_PUSH_LONG(frame, *(jlong*)(cp->p)); break;
		case CONSTANT_Double: VM_PUSH_DOUBLE(frame, *(jdouble*)(cp->p)); break;
		default: jniFatalError((JNIEnv*)frame->env, "Illegal constant type [ldc2_w]");
	}
	frame->pc += 3;
	return NULL;
}


/* 21 */
static jthrowable _iload(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	VM_PUSH_INT(frame, frame->stack[index]);
	return NULL;
}


/* 22 */
static jthrowable _lload(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	VM_PUSH_LONG(frame, *(jlong*)(frame->stack + index));
	return NULL;
}


/* 23 */
static jthrowable _fload(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	VM_PUSH_FLOAT(frame, *(jfloat*)(frame->stack + index));
	return NULL;
}


/* 24 */
static jthrowable _dload(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	VM_PUSH_DOUBLE(frame, *(jdouble*)(frame->stack + index));
	return NULL;
}


/* 25 */
static jthrowable _aload(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	VM_PUSH_OBJECT(frame, frame->stack[index]);
	return NULL;
}


/* 26 */
static jthrowable _iload_0(vmFrame *frame) {
	VM_PUSH_INT(frame, frame->stack[0]);
	frame->pc++;
	return NULL;
}


/* 27 */
static jthrowable _iload_1(vmFrame *frame) {
	VM_PUSH_INT(frame, frame->stack[1]);
	frame->pc++;
	return NULL;
}


/* 28 */
static jthrowable _iload_2(vmFrame *frame) {
	VM_PUSH_INT(frame, frame->stack[2]);
	frame->pc++;
	return NULL;
}


/* 29 */
static jthrowable _iload_3(vmFrame *frame) {
	VM_PUSH_INT(frame, frame->stack[3]);
	frame->pc++;
	return NULL;
}


/* 30 */
static jthrowable _lload_0(vmFrame *frame) {
	VM_PUSH_LONG(frame, *(jlong*)frame->stack);
	frame->pc++;
	return NULL;
}


/* 31 */
static jthrowable _lload_1(vmFrame *frame) {
	VM_PUSH_LONG(frame, *(jlong*)(frame->stack + 1));
	frame->pc++;
	return NULL;
}


/* 32 */
static jthrowable _lload_2(vmFrame *frame) {
	VM_PUSH_LONG(frame, *(jlong*)(frame->stack + 2));
	frame->pc++;
	return NULL;
}


/* 33 */
static jthrowable _lload_3(vmFrame *frame) {
	VM_PUSH_LONG(frame, *(jlong*)(frame->stack + 3));
	frame->pc++;
	return NULL;
}


/* 34 */
static jthrowable _fload_0(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, *(jfloat*)frame->stack);
	frame->pc++;
	return NULL;
}


/* 35 */
static jthrowable _fload_1(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, *(jfloat*)(frame->stack + 1));
	frame->pc++;
	return NULL;
}


/* 36 */
static jthrowable _fload_2(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, *(jfloat*)(frame->stack + 2));
	frame->pc++;
	return NULL;
}


/* 37 */
static jthrowable _fload_3(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, *(jfloat*)(frame->stack + 3));
	frame->pc++;
	return NULL;
}


/* 38 */
static jthrowable _dload_0(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, *(jdouble*)frame->stack);
	frame->pc++;
	return NULL;
}


/* 39 */
static jthrowable _dload_1(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, *(jdouble*)(frame->stack + 1));
	frame->pc++;
	return NULL;
}


/* 40 */
static jthrowable _dload_2(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, *(jdouble*)(frame->stack + 2));
	frame->pc++;
	return NULL;
}


/* 41 */
static jthrowable _dload_3(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, *(jdouble*)(frame->stack + 3));
	frame->pc++;
	return NULL;
}


/* 42 */
static jthrowable _aload_0(vmFrame *frame) {
	VM_PUSH_OBJECT(frame, frame->stack[0]);
	frame->pc++;
	return NULL;
}


/* 43 */
static jthrowable _aload_1(vmFrame *frame) {
	VM_PUSH_OBJECT(frame, frame->stack[1]);
	frame->pc++;
	return NULL;
}


/* 44 */
static jthrowable _aload_2(vmFrame *frame) {
	VM_PUSH_OBJECT(frame, frame->stack[2]);
	frame->pc++;
	return NULL;
}


/* 45 */
static jthrowable _aload_3(vmFrame *frame) {
	VM_PUSH_OBJECT(frame, frame->stack[3]);
	frame->pc++;
	return NULL;
}


/* 46 */
static jthrowable _iaload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [iaload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [iaload]");	
	}
	VM_PUSH_INT(frame, ((jint*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 47 */
static jthrowable _laload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [laload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [laload]");	
	}
	VM_PUSH_LONG(frame, ((jlong*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 48 */
static jthrowable _faload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [faload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [faload]");	
	}
	VM_PUSH_FLOAT(frame, ((jfloat*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 49 */
static jthrowable _daload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [daload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [daload]");	
	}
	VM_PUSH_DOUBLE(frame, ((jdouble*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 50 */
static jthrowable _aaload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [aaload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [aaload]");	
	}
	VM_PUSH_OBJECT(frame, ((jobject*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 51 */
static jthrowable _baload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [baload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [baload]");	
	}
	VM_PUSH_INT(frame, ((jbyte*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 52 */
static jthrowable _caload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [caload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [caload]");	
	}
	VM_PUSH_INT(frame, ((jchar*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 53 */
static jthrowable _saload(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [saload]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [saload]");	
	}
	VM_PUSH_INT(frame, ((jshort*)VM_ARRAY_ARRAY(array))[index]);
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 54 */
static jthrowable _istore(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	*(jint*)(frame->stack + index) = VM_POP_INT(frame);
	return NULL;
}


/* 55 */
static jthrowable _lstore(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	*(jlong*)(frame->stack + index) = VM_POP_LONG(frame);
	return NULL;
}


/* 56 */
static jthrowable _fstore(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	*(jfloat*)(frame->stack + index) = VM_POP_FLOAT(frame);
	return NULL;
}


/* 57 */
static jthrowable _dstore(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	*(jdouble*)(frame->stack + index) = VM_POP_DOUBLE(frame);
	return NULL;
}


/* 58 */
static jthrowable _astore(vmFrame *frame) {
	jobject *var;
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->pc += 3;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		frame->pc += 2;
	}
	var = frame->stack + index;
	jniDeleteLocalRef((JNIEnv*)frame->env, *var);
	*var = jniNewLocalRef((JNIEnv*)frame->env, VM_POP_OBJECT(frame));	
	return NULL;
}


/* 59 */
static jthrowable _istore_0(vmFrame *frame) {
	*(jint*)(frame->stack) = VM_POP_INT(frame);	
	frame->pc++;
	return NULL;
}


/* 60 */
static jthrowable _istore_1(vmFrame *frame) {
	*(jint*)(frame->stack + 1) = VM_POP_INT(frame);	
	frame->pc++;
	return NULL;
}


/* 61 */
static jthrowable _istore_2(vmFrame *frame) {
	*(jint*)(frame->stack + 2) = VM_POP_INT(frame);	
	frame->pc++;
	return NULL;
}


/* 62 */
static jthrowable _istore_3(vmFrame *frame) {
	*(jint*)(frame->stack + 3) = VM_POP_INT(frame);	
	frame->pc++;
	return NULL;
}


/* 63 */
static jthrowable _lstore_0(vmFrame *frame) {
	*(jlong*)(frame->stack) = VM_POP_LONG(frame);	
	frame->pc++;
	return NULL;
}


/* 64 */
static jthrowable _lstore_1(vmFrame *frame) {
	*(jlong*)(frame->stack + 1) = VM_POP_LONG(frame);	
	frame->pc++;
	return NULL;
}


/* 65 */
static jthrowable _lstore_2(vmFrame *frame) {
	*(jlong*)(frame->stack + 2) = VM_POP_LONG(frame);	
	frame->pc++;
	return NULL;
}


/* 66 */
static jthrowable _lstore_3(vmFrame *frame) {
	*(jlong*)(frame->stack + 3) = VM_POP_LONG(frame);	
	frame->pc++;
	return NULL;
}


/* 67 */
static jthrowable _fstore_0(vmFrame *frame) {
	*(jfloat*)(frame->stack) = VM_POP_FLOAT(frame);	
	frame->pc++;
	return NULL;
}


/* 68 */
static jthrowable _fstore_1(vmFrame *frame) {
	*(jfloat*)(frame->stack + 1) = VM_POP_FLOAT(frame);	
	frame->pc++;
	return NULL;
}


/* 69 */
static jthrowable _fstore_2(vmFrame *frame) {
	*(jfloat*)(frame->stack + 2) = VM_POP_FLOAT(frame);	
	frame->pc++;
	return NULL;
}


/* 70 */
static jthrowable _fstore_3(vmFrame *frame) {
	*(jfloat*)(frame->stack + 3) = VM_POP_FLOAT(frame);	
	frame->pc++;
	return NULL;
}


/* 71 */
static jthrowable _dstore_0(vmFrame *frame) {
	*(jdouble*)(frame->stack) = VM_POP_DOUBLE(frame);	
	frame->pc++;
	return NULL;
}


/* 72 */
static jthrowable _dstore_1(vmFrame *frame) {
	*(jdouble*)(frame->stack + 1) = VM_POP_DOUBLE(frame);	
	frame->pc++;
	return NULL;
}


/* 73 */
static jthrowable _dstore_2(vmFrame *frame) {
	*(jdouble*)(frame->stack + 2) = VM_POP_DOUBLE(frame);	
	frame->pc++;
	return NULL;
}


/* 74 */
static jthrowable _dstore_3(vmFrame *frame) {
	*(jdouble*)(frame->stack + 3) = VM_POP_DOUBLE(frame);	
	frame->pc++;
	return NULL;
}


/* 75 */
static jthrowable _astore_0(vmFrame *frame) {
	jobject *var = frame->stack;
	jniDeleteLocalRef((JNIEnv*)frame->env, *var);
	*var = jniNewLocalRef((JNIEnv*)frame->env, VM_POP_OBJECT(frame));	
	frame->pc++;
	return NULL;
}


/* 76 */
static jthrowable _astore_1(vmFrame *frame) {
	jobject *var = frame->stack + 1;
	jniDeleteLocalRef((JNIEnv*)frame->env, *var);
	*var = jniNewLocalRef((JNIEnv*)frame->env, VM_POP_OBJECT(frame));	
	frame->pc++;
	return NULL;
}


/* 77 */
static jthrowable _astore_2(vmFrame *frame) {
	jobject *var = frame->stack + 2;
	jniDeleteLocalRef((JNIEnv*)frame->env, *var);
	*var = jniNewLocalRef((JNIEnv*)frame->env, VM_POP_OBJECT(frame));	
	frame->pc++;
	return NULL;
}


/* 78 */
static jthrowable _astore_3(vmFrame *frame) {
	jobject *var = frame->stack + 3;
	jniDeleteLocalRef((JNIEnv*)frame->env, *var);
	*var = jniNewLocalRef((JNIEnv*)frame->env, VM_POP_OBJECT(frame));	
	frame->pc++;
	return NULL;
}


/* 79 */
static jthrowable _iastore(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jint val = VM_POP_INT(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [iastore]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [iastore]");	
	}
	((jint*)VM_ARRAY_ARRAY(array))[index] = val;
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 80 */
static jthrowable _lastore(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jlong val = VM_POP_LONG(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [lastore]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [lastore]");	
	}
	((jlong*)VM_ARRAY_ARRAY(array))[index] = val;
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 81 */
static jthrowable _fastore(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jfloat val = VM_POP_FLOAT(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [fastore]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [fastore]");	
	}
	((jfloat*)VM_ARRAY_ARRAY(array))[index] = val;
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 82 */
static jthrowable _dastore(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jdouble val = VM_POP_DOUBLE(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [dastore]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [dastore]");	
	}
	((jdouble*)VM_ARRAY_ARRAY(array))[index] = val;
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 83 */
static jthrowable _aastore(vmFrame *frame) {
	jobject val = VM_POP_OBJECT(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	jniSetObjectArrayElement((JNIEnv*)frame->env, array, index, val);
	frame->pc++;
	return frame->exception;
}


/* 84 */
static jthrowable _bastore(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jbyte val = (jbyte)VM_POP_INT(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [bastore]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [bastore]");	
	}
	((jbyte*)VM_ARRAY_ARRAY(array))[index] = val;
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 85 */
static jthrowable _castore(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jchar val = (jchar)VM_POP_INT(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [castore]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [castore]");	
	}
	((jchar*)VM_ARRAY_ARRAY(array))[index] = val;
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 86 */
static jthrowable _sastore(vmFrame *frame) {
	natSynchronizeData *gcs = frame->env->vm->gcs;
	jshort val = (jshort)VM_POP_INT(frame);
	jint index = VM_POP_INT(frame);
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "array [sastore]");
	VM_ENTER_CRITICAL_SECTION(gcs);
	if ((index < 0) || (index >= VM_ARRAY_LENGTH(array))) {
		VM_LEAVE_CRITICAL_SECTION(gcs);
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, "array [sastore]");	
	}
	((jshort*)VM_ARRAY_ARRAY(array))[index] = val;
	VM_LEAVE_CRITICAL_SECTION(gcs);
	frame->pc++;
	return NULL;
}


/* 87 */
static jthrowable _pop(vmFrame *frame) {
	VM_POP_INT(frame);
	frame->pc++;
	return NULL;
}


/* 88 */
static jthrowable _pop2(vmFrame *frame) {
	VM_POP_LONG(frame);
	frame->pc++;
	return NULL;
}


/* 89 */
static jthrowable _dup(vmFrame *frame) {
	jobject val = frame->stack[frame->stack_top - 1];
	VM_PUSH_OBJECT(frame, val);
	frame->pc++;
	return NULL;
}


/* 90 */
static jthrowable _dup_x1(vmFrame *frame) {
	jobject val1 = VM_POP_OBJECT(frame);
	jobject val2 = VM_POP_OBJECT(frame);
	VM_PUSH_OBJECT(frame, val1);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	frame->pc++;
	return NULL;
}


/* 91 */
static jthrowable _dup_x2(vmFrame *frame) {
	jobject val1 = VM_POP_OBJECT(frame);
	jobject val2 = VM_POP_OBJECT(frame);
	jobject val3 = VM_POP_OBJECT(frame);
	VM_PUSH_OBJECT(frame, val1);
	VM_PUSH_OBJECT(frame, val3);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	frame->pc++;
	return NULL;
}


/* 92 */
static jthrowable _dup2(vmFrame *frame) {
	jobject val1 = VM_POP_OBJECT(frame);
	jobject val2 = VM_POP_OBJECT(frame);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	frame->pc++;
	return NULL;
}


/* 93 */
static jthrowable _dup2_x1(vmFrame *frame) {
	jobject val1 = VM_POP_OBJECT(frame);
	jobject val2 = VM_POP_OBJECT(frame);
	jobject val3 = VM_POP_OBJECT(frame);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	VM_PUSH_OBJECT(frame, val3);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	frame->pc++;
	return NULL;
}


/* 94 */
static jthrowable _dup2_x2(vmFrame *frame) {
	jobject val1 = VM_POP_OBJECT(frame);
	jobject val2 = VM_POP_OBJECT(frame);
	jobject val3 = VM_POP_OBJECT(frame);
	jobject val4 = VM_POP_OBJECT(frame);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	VM_PUSH_OBJECT(frame, val4);
	VM_PUSH_OBJECT(frame, val3);
	VM_PUSH_OBJECT(frame, val2);
	VM_PUSH_OBJECT(frame, val1);
	frame->pc++;
	return NULL;
}


/* 95 */
static jthrowable _swap(vmFrame *frame) {
	jobject val1 = VM_POP_OBJECT(frame);
	jobject val2 = VM_POP_OBJECT(frame);
	VM_PUSH_OBJECT(frame, val1);
	VM_PUSH_OBJECT(frame, val2);
	frame->pc++;
	return NULL;
}


/* 96 */
static jthrowable _iadd(vmFrame *frame) {
	VM_PUSH_INT(frame, VM_POP_INT(frame) + VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 97 */
static jthrowable _ladd(vmFrame *frame) {
	VM_PUSH_LONG(frame, VM_POP_LONG(frame) + VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 98 */
static jthrowable _fadd(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, VM_POP_FLOAT(frame) + VM_POP_FLOAT(frame));
	frame->pc++;
	return NULL;
}


/* 99 */
static jthrowable _dadd(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, VM_POP_DOUBLE(frame) + VM_POP_DOUBLE(frame));
	frame->pc++;
	return NULL;
}


/* 100 */
static jthrowable _isub(vmFrame *frame) {
	jint val2 = VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	VM_PUSH_INT(frame, val1 - val2);
	frame->pc++;
	return NULL;
}


/* 101 */
static jthrowable _lsub(vmFrame *frame) {
	jlong val2 = VM_POP_LONG(frame);
	jlong val1 = VM_POP_LONG(frame);
	VM_PUSH_LONG(frame, val1 - val2);
	frame->pc++;
	return NULL;
}


/* 102 */
static jthrowable _fsub(vmFrame *frame) {
	jfloat val2 = VM_POP_FLOAT(frame);
	jfloat val1 = VM_POP_FLOAT(frame);
	VM_PUSH_FLOAT(frame, val1 - val2);
	frame->pc++;
	return NULL;
}


/* 103 */
static jthrowable _dsub(vmFrame *frame) {
	jdouble val2 = VM_POP_DOUBLE(frame);
	jdouble val1 = VM_POP_DOUBLE(frame);
	VM_PUSH_DOUBLE(frame, val1 - val2);
	frame->pc++;
	return NULL;
}


/* 104 */
static jthrowable _imul(vmFrame *frame) {
	VM_PUSH_INT(frame, VM_POP_INT(frame) * VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 105 */
static jthrowable _lmul(vmFrame *frame) {
	VM_PUSH_LONG(frame, VM_POP_LONG(frame) * VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 106 */
static jthrowable _fmul(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, VM_POP_FLOAT(frame) * VM_POP_FLOAT(frame));
	frame->pc++;
	return NULL;
}


/* 107 */
static jthrowable _dmul(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, VM_POP_DOUBLE(frame) * VM_POP_DOUBLE(frame));
	frame->pc++;
	return NULL;
}


/* 108 */
static jthrowable _idiv(vmFrame *frame) {
	jint val2 = VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	if (val2 == 0) return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARITHMETICEXCEPTION, "zero division [idiv]");
	VM_PUSH_INT(frame, val1 / val2);
	frame->pc++;
	return NULL;
}


/* 109 */
static jthrowable _ldiv(vmFrame *frame) {
	jlong val2 = VM_POP_LONG(frame);
	jlong val1 = VM_POP_LONG(frame);
	if (val2 == JLONG(0)) return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARITHMETICEXCEPTION, "zero division [ldiv]");
	VM_PUSH_LONG(frame, val1 / val2);
	frame->pc++;
	return NULL;
}


/* 110 */
static jthrowable _fdiv(vmFrame *frame) {
	jfloat val2 = VM_POP_FLOAT(frame);
	jfloat val1 = VM_POP_FLOAT(frame);
	/* float divide by zero in Java do not lead to error state, but +/-Infinity result value */
	VM_PUSH_FLOAT(frame, val1 / val2);
	frame->pc++;
	return NULL;
}


/* 111 */
static jthrowable _ddiv(vmFrame *frame) {
	jdouble val2 = VM_POP_DOUBLE(frame);
	jdouble val1 = VM_POP_DOUBLE(frame);
	/* double divide by zero in Java do not lead to error state, but +/-Infinity result value */
	VM_PUSH_DOUBLE(frame, val1 / val2);
	frame->pc++;
	return NULL;
}


/* 112 */
static jthrowable _irem(vmFrame *frame) {
	jint val2 = VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	if (val2 == 0) return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARITHMETICEXCEPTION, "zero division [irem]");
	VM_PUSH_INT(frame, val1 % val2);
	frame->pc++;
	return NULL;
}


/* 113 */
static jthrowable _lrem(vmFrame *frame) {
	jlong val2 = VM_POP_LONG(frame);
	jlong val1 = VM_POP_LONG(frame);
	if (val2 == JLONG(0)) return vmCreateThrowable(frame->env, &clsJAVA_LANG_ARITHMETICEXCEPTION, "zero division [lrem]");
	VM_PUSH_LONG(frame, val1 % val2);
	frame->pc++;
	return NULL;
}


/* 114 */
static jthrowable _frem(vmFrame *frame) {
	jfloat val2 = VM_POP_FLOAT(frame);
	jfloat val1 = VM_POP_FLOAT(frame);
	VM_PUSH_FLOAT(frame, (float)fmod((float)val1, (float)val2));
	frame->pc++;
	return NULL;
}


/* 115 */
static jthrowable _drem(vmFrame *frame) {
	jdouble val2 = VM_POP_DOUBLE(frame);
	jdouble val1 = VM_POP_DOUBLE(frame);
	VM_PUSH_DOUBLE(frame, fmod(val1, val2));
	frame->pc++;
	return NULL;
}


/* 116 */
static jthrowable _ineg(vmFrame *frame) {
	VM_PUSH_INT(frame, -VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 117 */
static jthrowable _lneg(vmFrame *frame) {
	VM_PUSH_LONG(frame, -VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 118 */
static jthrowable _fneg(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, -VM_POP_FLOAT(frame));
	frame->pc++;
	return NULL;
}


/* 119 */
static jthrowable _dneg(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, -VM_POP_DOUBLE(frame));
	frame->pc++;
	return NULL;
}


/* 120 */
static jthrowable _ishl(vmFrame *frame) {
	jint val2 = 0x1F & VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	VM_PUSH_INT(frame, val1 << val2);
	frame->pc++;
	return NULL;
}


/* 121 */
static jthrowable _lshl(vmFrame *frame) {
	jint val2 = 0x3F & VM_POP_INT(frame);
	jlong val1 = VM_POP_LONG(frame);
	VM_PUSH_LONG(frame, val1 << val2);
	frame->pc++;
	return NULL;
}


/* 122 */
static jthrowable _ishr(vmFrame *frame) {
	jint val2 = 0x1F & VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	if (val1 >= 0)
        VM_PUSH_INT(frame, val1 >> val2);
	else
        VM_PUSH_INT(frame, -1 - ((-1 - val1) >> val2));
	frame->pc++;
	return NULL;
}


/* 123 */
static jthrowable _lshr(vmFrame *frame) {
	jint val2 = 0x3F & VM_POP_INT(frame);
	jlong val1 = VM_POP_LONG(frame);
	if (val1 >= JLONG(0)) {
		VM_PUSH_LONG(frame, val1 >> val2);
	} else
        VM_PUSH_LONG(frame, JLONG(-1) - ((JLONG(-1) - val1) >> val2));
	frame->pc++;
	return NULL;
}


/* 124 */
static jthrowable _iushr(vmFrame *frame) {
	register jint val2 = 0x1F & VM_POP_INT(frame);
	register jint val1 = VM_POP_INT(frame);
	VM_PUSH_INT(frame, (val1 >> val2) + ((val1 < 0) ? (2 << (~val2  & 0x1f)) : 0));
	frame->pc++;
	return NULL;
}


/* 125 */
static jthrowable _lushr(vmFrame *frame) {
	jint val2 = 0x3F & VM_POP_INT(frame);
	jlong val1 = VM_POP_LONG(frame);
	VM_PUSH_LONG(frame, (val1 >> val2) + ((val1 < JLONG(0)) ? (JLONG(2) << (~val2  & 0x3f)) : JLONG(0)));
	frame->pc++;
	return NULL;
}


/* 126 */
static jthrowable _iand(vmFrame *frame) {
	VM_PUSH_INT(frame, VM_POP_INT(frame) & VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 127 */
static jthrowable _land(vmFrame *frame) {
	VM_PUSH_LONG(frame, VM_POP_LONG(frame) & VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 128 */
static jthrowable _ior(vmFrame *frame) {
	VM_PUSH_INT(frame, VM_POP_INT(frame) | VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 129 */
static jthrowable _lor(vmFrame *frame) {
	VM_PUSH_LONG(frame, VM_POP_LONG(frame) | VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 130 */
static jthrowable _ixor(vmFrame *frame) {
	VM_PUSH_INT(frame, VM_POP_INT(frame) ^ VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 131 */
static jthrowable _lxor(vmFrame *frame) {
	VM_PUSH_LONG(frame, VM_POP_LONG(frame) ^ VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 132 */
static jthrowable _iinc(vmFrame *frame) {
	jushort index; jint c;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		c = GET_JBYTE(frame->pc + 2);
		frame->pc += 4;
		frame->wide = JNI_FALSE;
	} else {
		index = GET_JUBYTE(frame->pc);
		c = GET_JBYTE(frame->pc + 1);
		frame->pc += 3;
	}
	*(jint*)(frame->stack + index) += c;
	return NULL;
}


/* 133 */
static jthrowable _i2l(vmFrame *frame) {
	VM_PUSH_LONG(frame, (jlong)VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 134 */
static jthrowable _i2f(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, (jfloat)VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 135 */
static jthrowable _i2d(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, (jdouble)VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 136 */
static jthrowable _l2i(vmFrame *frame) {
	VM_PUSH_INT(frame, (jint)VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 137 */
static jthrowable _l2f(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, (jfloat)VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 138 */
static jthrowable _l2d(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, (jdouble)VM_POP_LONG(frame));
	frame->pc++;
	return NULL;
}


/* 139 */
static jthrowable _f2i(vmFrame *frame) {
	VM_PUSH_INT(frame, (jint)VM_POP_FLOAT(frame));
	frame->pc++;
	return NULL;
}


/* 140 */
static jthrowable _f2l(vmFrame *frame) {
	VM_PUSH_LONG(frame, (jlong)VM_POP_FLOAT(frame));
	frame->pc++;
	return NULL;
}


/* 141 */
static jthrowable _f2d(vmFrame *frame) {
	VM_PUSH_DOUBLE(frame, (jdouble)VM_POP_FLOAT(frame));
	frame->pc++;
	return NULL;
}


/* 142 */
static jthrowable _d2i(vmFrame *frame) {
	VM_PUSH_INT(frame, (jint)VM_POP_DOUBLE(frame));
	frame->pc++;
	return NULL;
}


/* 143 */
static jthrowable _d2l(vmFrame *frame) {
	VM_PUSH_LONG(frame, (jlong)VM_POP_DOUBLE(frame));
	frame->pc++;
	return NULL;
}


/* 144 */
static jthrowable _d2f(vmFrame *frame) {
	VM_PUSH_FLOAT(frame, (jfloat)VM_POP_DOUBLE(frame));
	frame->pc++;
	return NULL;
}


/* 145 */
static jthrowable _i2b(vmFrame *frame) {
	VM_PUSH_INT(frame, 0xFF & VM_POP_INT(frame));
	frame->pc++;
	return NULL;
}


/* 146 */
static jthrowable _i2c(vmFrame *frame) {
	VM_PUSH_INT(frame, (jchar)(0xFFFF & VM_POP_INT(frame)));
	frame->pc++;
	return NULL;
}


/* 147 */
static jthrowable _i2s(vmFrame *frame) {
	VM_PUSH_INT(frame, (jshort)(0xFFFF & VM_POP_INT(frame)));
	frame->pc++;
	return NULL;
}


/* 148 */
static jthrowable _lcmp(vmFrame *frame) {
	jlong val2 = VM_POP_LONG(frame);
	jlong val1 = VM_POP_LONG(frame);
	if (val1 == val2)
		VM_PUSH_INT(frame, 0);
	else
		VM_PUSH_INT(frame, (val1 > val2) ? 1 : -1);
	frame->pc++;
	return NULL;
}


/* 149 */
static jthrowable _fcmpl(vmFrame *frame) {
	jfloat val2 = VM_POP_FLOAT(frame);
	jfloat val1 = VM_POP_FLOAT(frame);
	if (Java_java_lang_Float_isNan((JNIEnv*)frame->env, NULL, val1) || Java_java_lang_Float_isNan((JNIEnv*)frame->env, NULL, val2))
		VM_PUSH_INT(frame, -1);
	else		
		if (val1 == val2)
			VM_PUSH_INT(frame, 0);
		else
			VM_PUSH_INT(frame, (val1 > val2) ? 1 : -1);
	frame->pc++;
	return NULL;
}


/* 150 */
static jthrowable _fcmpg(vmFrame *frame) {
	jfloat val2 = VM_POP_FLOAT(frame);
	jfloat val1 = VM_POP_FLOAT(frame);
	if (Java_java_lang_Float_isNan((JNIEnv*)frame->env, NULL, val1) || Java_java_lang_Float_isNan((JNIEnv*)frame->env, NULL, val2))
		VM_PUSH_INT(frame, 1);
	else		
		if (val1 == val2)
			VM_PUSH_INT(frame, 0);
		else
			VM_PUSH_INT(frame, (val1 > val2) ? 1 : -1);
	frame->pc++;
	return NULL;
}


/* 151 */
static jthrowable _dcmpl(vmFrame *frame) {
	jdouble val2 = VM_POP_DOUBLE(frame);
	jdouble val1 = VM_POP_DOUBLE(frame);
	if (Java_java_lang_Double_isNan((JNIEnv*)frame->env, NULL, val1) || Java_java_lang_Double_isNan((JNIEnv*)frame->env, NULL, val2))
		VM_PUSH_INT(frame, -1);
	else		
		if (val1 == val2)
			VM_PUSH_INT(frame, 0);
		else
			VM_PUSH_INT(frame, (val1 > val2) ? 1 : -1);
	frame->pc++;
	return NULL;
}


/* 152 */
static jthrowable _dcmpg(vmFrame *frame) {
	jdouble val2 = VM_POP_DOUBLE(frame);
	jdouble val1 = VM_POP_DOUBLE(frame);
	if (Java_java_lang_Double_isNan((JNIEnv*)frame->env, NULL, val1) || Java_java_lang_Double_isNan((JNIEnv*)frame->env, NULL, val2))
		VM_PUSH_INT(frame, 1);
	else		
		if (val1 == val2)
			VM_PUSH_INT(frame, 0);
		else
			VM_PUSH_INT(frame, (val1 > val2) ? 1 : -1);
	frame->pc++;
	return NULL;
}


/* 153 */
static jthrowable _ifeq(vmFrame *frame) {
	if (VM_POP_INT(frame) == 0)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 154 */
static jthrowable _ifne(vmFrame *frame) {
	if (VM_POP_INT(frame) != 0)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 155 */
static jthrowable _iflt(vmFrame *frame) {
	if (VM_POP_INT(frame) < 0)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 156 */
static jthrowable _ifge(vmFrame *frame) {
	if (VM_POP_INT(frame) >= 0)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 157 */
static jthrowable _ifgt(vmFrame *frame) {
	if (VM_POP_INT(frame) > 0)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 158 */
static jthrowable _ifle(vmFrame *frame) {
	if (VM_POP_INT(frame) <= 0)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 159 */
static jthrowable _if_icmpeq(vmFrame *frame) {
	if (VM_POP_INT(frame) == VM_POP_INT(frame))
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 160 */
static jthrowable _if_icmpne(vmFrame *frame) {
	if (VM_POP_INT(frame) != VM_POP_INT(frame))
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 161 */
static jthrowable _if_icmplt(vmFrame *frame) {
	jint val2 = VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	if (val1 < val2)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 162 */
static jthrowable _if_icmpge(vmFrame *frame) {
	jint val2 = VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	if (val1 >= val2)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 163 */
static jthrowable _if_icmpgt(vmFrame *frame) {
	jint val2 = VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	if (val1 > val2)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 164 */
static jthrowable _if_icmple(vmFrame *frame) {
	jint val2 = VM_POP_INT(frame);
	jint val1 = VM_POP_INT(frame);
	if (val1 <= val2)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 165 */
static jthrowable _if_acmpeq(vmFrame *frame) {
	if (VM_POP_OBJECT(frame) == VM_POP_OBJECT(frame))
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 166 */
static jthrowable _if_acmpne(vmFrame *frame) {
	if (VM_POP_OBJECT(frame) != VM_POP_OBJECT(frame))
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 167 */
static jthrowable _goto(vmFrame *frame) {
	frame->pc += GET_JSHORT(frame->pc);
	return NULL;
}


/* 168 */
static jthrowable _jsr(vmFrame *frame) {
	VM_PUSH_INT(frame, frame->pc - (jubyte*)frame->met->code + 3);
	frame->pc += GET_JSHORT(frame->pc);
	if (*(frame->pc) == 196) {  /* wide */
		frame->wide = JNI_TRUE;
		frame->pc++;
	}
	if (*(frame->pc) == 58) {  /* astore */
		jobject *var;
		jushort index;
		if (frame->wide) {
			index = GET_JUSHORT(frame->pc);
			frame->pc += 3;
			frame->wide = JNI_FALSE;
		} else {
			index = GET_JUBYTE(frame->pc);
			frame->pc += 2;
		}
		var = frame->stack + index;
		jniDeleteLocalRef((JNIEnv*)frame->env, *var);
		*var = VM_POP_OBJECT(frame);
	} else
	if ((75 <= *(frame->pc)) && (*(frame->pc) <= 78))  {  /* astore_0, astore_1, astore_2, astore_3 */
		jobject *var = frame->stack + (jint)(*(frame->pc)) - 75;
		jniDeleteLocalRef((JNIEnv*)frame->env, *var);
		*var = VM_POP_OBJECT(frame);
		frame->pc++;
	}
	return NULL;
}


/* 169 */
static jthrowable _ret(vmFrame *frame) {
	jushort index;
	if (frame->wide) {
		index = GET_JUSHORT(frame->pc);
		frame->wide = JNI_FALSE;
	} else
		index = GET_JUBYTE(frame->pc);
	frame->pc = frame->met->code;
	frame->pc += *(jint*)(frame->stack + index);
	return NULL;
}


/* 170 */
static jthrowable _tableswitch(vmFrame *frame) {
	jint index, def, pc, n1, n2; jubyte *s;
	index = VM_POP_INT(frame);
	s = frame->pc;
	pc = frame->pc - (jubyte*)frame->met->code;
	frame->pc += 3 - ((pc + 4) & 3);
	def = GET_JINT(frame->pc); frame->pc += 4;
	n1 = GET_JINT(frame->pc); frame->pc += 4;
	n2 = GET_JINT(frame->pc); frame->pc += 4;
	if ((n1 <= index) && (index <= n2)) {
		frame->pc = s + GET_JINT(frame->pc + 4 * (index - n1));
		return NULL;
	}
	frame->pc = s + def; 
	return NULL;
}


/* 171 */
static jthrowable _lookupswitch(vmFrame *frame) {
	jint key, def, pc, i, n; jubyte *s;
	key = VM_POP_INT(frame);
	s = frame->pc;
	pc = frame->pc - (jubyte*)frame->met->code;
	frame->pc += 3 - ((pc + 4) & 3);
	def = GET_JINT(frame->pc); frame->pc += 4;
	n = GET_JINT(frame->pc); frame->pc += 4;
	for (i = 0; i < n; i++) {
		if (GET_JINT(frame->pc) == key) {
			frame->pc = s + GET_JINT(frame->pc + 4);
			return NULL;
		}
		frame->pc += 8;
	}
	frame->pc = s + def; 
	return NULL;
}


/* 172, 174 */
static jthrowable _ireturn(vmFrame *frame) {
	vmJNIEnv *env = frame->env;
	*frame->stack = frame->stack[frame->stack_top - 1];
	jniPopLocalFrame((JNIEnv*)env, NULL);	
	env->frame->stack_top++;
	frame->pc = (jubyte*)frame->met->code + frame->met->code_len;
	return NULL;
}


/* 173, 175 */
static jthrowable _lreturn(vmFrame *frame) {
	vmJNIEnv *env = frame->env;
	jlong retval = VM_POP_LONG(frame);
	jniPopLocalFrame((JNIEnv*)env, NULL);	
	VM_PUSH_LONG(env->frame, retval);
	frame->pc = (jubyte*)frame->met->code + frame->met->code_len;
	return NULL;
}


/* 176 */
static jthrowable _areturn(vmFrame *frame) {
	vmJNIEnv *env = frame->env;
	jobject retval = frame->stack[frame->stack_top - 1];
	retval = jniPopLocalFrame((JNIEnv*)env, retval);	
	VM_PUSH_OBJECT(env->frame, retval);
//	VM_PUSH_OBJECT(env->frame, jniNewLocalRef((JNIEnv*)env, retval));
	frame->pc = (jubyte*)frame->met->code + frame->met->code_len;
	return NULL;
}


/* 177 */
static jthrowable _return(vmFrame *frame) {
	jniPopLocalFrame((JNIEnv*)frame->env, NULL);
	frame->pc = (jubyte*)frame->met->code + frame->met->code_len;
	return NULL;
}


/* 178 */
static jthrowable _getstatic(vmFrame *frame) {
	jthrowable ret = NULL;
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_FieldRef)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDERROR, "not field reference [getstatic]");
	if (cp->p == NULL)
		cp->p = vmGetClassField(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
	ret = vmGetStatic(frame, (clsField*)(cp->p));
	frame->pc += 3;
	return ret;
}


/* 179 */
static jthrowable _putstatic(vmFrame *frame) {
	jthrowable ret = NULL;
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_FieldRef)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDERROR, "not field reference [putstatic]");
	if (cp->p == NULL)
		cp->p = vmGetClassField(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
	ret = vmPutStatic(frame, (clsField*)(cp->p));
	frame->pc += 3;
	return ret;
}


/* 180 */
static jthrowable _getfield(vmFrame *frame) {
	jobject obj; jthrowable ret;
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_FieldRef)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDERROR, "not field reference [getfield]");
	if (cp->p == NULL) {
		clsField *fld;
		cp->p = vmGetInstanceField(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
		fld = (clsField*)(cp->p);
		if (fld == NULL)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDERROR, "field not found [getfield]");
		if (fld->access_flags & ACC_STATIC) 
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, "a static field [getfield]");
	}
	obj = VM_POP_OBJECT(frame);
	ret = vmGetField(frame, obj, cp->p);
	frame->pc += 3;
	return ret;
}


/* 181 */
static jthrowable _putfield(vmFrame *frame) {
	jthrowable ret;
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_FieldRef)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDERROR, "not field reference [putfield]");
	if (cp->p == NULL) {
		clsField *fld;
		cp->p = vmGetInstanceField(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
		fld = (clsField*)(cp->p);
		if (fld == NULL)
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHFIELDERROR, "field not found [putfield]");
		if (fld->access_flags & ACC_STATIC) 
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, "a static field [putfield]");
	}
	ret = vmPutField(frame, cp->p);
	frame->pc += 3;
	return ret;
}


/* 182 */
static jthrowable _invokevirtual(vmFrame *frame) {
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_MethodRef)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHMETHODERROR, "not method reference [invokevirtual]");
	if (cp->p == NULL) {
		cp->p = vmGetInstanceMethod(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
		if (cp->p == NULL) {
			char buf[2048]; vmGetMethodDisplayNameUTF(buf, sizeof(buf),
				VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
				frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, 0);
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHMETHODERROR, buf);
		}
		if (((jmethodID)(cp->p))->access_flags & ACC_STATIC) {
			cp->p = NULL;
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, "a static method [invokevirtual]");
		}
	}
	/* execute method */
	vmInvokeVirtual(frame, cp->p);
	frame->pc += 3;
	return frame->exception;
}


/* 183 */
static jthrowable _invokespecial(vmFrame *frame) {
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_MethodRef)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHMETHODERROR, "not method reference [invokespecial]");
	if (cp->p == NULL) {
		cp->p = vmGetInstanceMethod(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
		if (cp->p == NULL) {
			char buf[2048]; vmGetMethodDisplayNameUTF(buf, sizeof(buf),
				VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
				frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, 0);
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHMETHODERROR, buf);
		}
		if (((jmethodID)(cp->p))->access_flags & ACC_STATIC) {
			cp->p = NULL;
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, "a static method [invokespecial]");
		}
	}
	/* execute method */
	vmExecuteMethod(frame, cp->p, NULL);
	frame->pc += 3;
	return frame->exception;
}


/* 184 */
static jthrowable _invokestatic(vmFrame *frame) {
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_MethodRef)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHMETHODERROR, "not method reference [invokestatic]");
	if (cp->p == NULL) {
		jmethodID met;
		cp->p = vmGetClassMethod(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
		if (cp->p == NULL) {
			char buf[2048]; vmGetMethodDisplayNameUTF(buf, sizeof(buf),
				VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
				frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, ACC_STATIC);
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHMETHODERROR, buf);
		}
		met = cp->p;
		if ((met->access_flags & ACC_STATIC) == 0) {
			cp->p = NULL;
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, "not a static method [invokestatic]");
		}
		cp->q = jniFindClass((JNIEnv*)frame->env, met->clsdef->name);
	}
	/* execute method */
	vmExecuteMethod(frame, cp->p, cp->q);
	frame->pc += 3;
	return frame->exception;
}


/* 185 */
static jthrowable _invokeinterface(vmFrame *frame) {
	jmethodID met; jobject obj;
	clsConstPool *cp = frame->constant_pool + GET_JUSHORT(frame->pc);
	if (cp->tag != CONSTANT_InterfaceMethodRef)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NOSUCHMETHODERROR, "not method reference [invokeinterface]");
	if (cp->p == NULL) {
		cp->p = vmGetInstanceMethod(
			VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
			frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, JNI_TRUE);
		if (cp->p == NULL)
ABSTRACT_ERR:
		{	char buf[2048]; vmGetMethodDisplayNameUTF(buf, sizeof(buf) - 20,
				VM_CLASS_DEF((jobject)frame->constant_pool[cp->i].p),
				frame->constant_pool[cp->j].p, frame->constant_pool[cp->j].q, 0);
			return vmCreateThrowable(frame->env, &clsJAVA_LANG_ABSTRACTMETHODERROR, buf);
		}
		met = cp->p;
		if ((met->access_flags & ACC_ABSTRACT) == 0)
			goto ABSTRACT_ERR;
	}
	/* find object method */
	met = cp->p;
	obj = *(frame->stack + frame->stack_top - met->parameters_stack_size);
	if (obj == NULL)
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, NULL);
	met = vmGetInstanceMethod(obj->clsdef, met->name, met->descriptor, JNI_TRUE);
	if (met == NULL)
		goto ABSTRACT_ERR;
	/* execute method */
	vmExecuteMethod(frame, met, (met->access_flags & ACC_STATIC) ? jniFindClass((JNIEnv*)frame->env, met->clsdef->name) : NULL);
	frame->pc += 5;
	return frame->exception;
}


/* 187 */
static jthrowable _new(vmFrame *frame) {
	VM_PUSH_OBJECT(frame, jniAllocObject((JNIEnv*)frame->env, 
		frame->constant_pool[GET_JUSHORT(frame->pc)].p));	
	frame->pc += 3;
	return frame->exception;
}


/* 188 */
static jthrowable _newarray(vmFrame *frame) {
	JNIEnv* env = (JNIEnv*)frame->env;
	jint length = VM_POP_INT(frame);
	jarray arr = NULL;
	switch (GET_JUBYTE(frame->pc)) {
		case 4: arr = jniNewBooleanArray(env, length); break;
		case 5: arr = jniNewCharArray(env, length); break;
		case 6: arr = jniNewFloatArray(env, length); break;
		case 7: arr = jniNewDoubleArray(env, length); break;
		case 8: arr = jniNewByteArray(env, length); break;
		case 9: arr = jniNewShortArray(env, length); break;
		case 10: arr = jniNewIntArray(env, length); break;
		case 11: arr = jniNewLongArray(env, length); break;
	}
	VM_PUSH_OBJECT(frame, arr);	
	frame->pc += 2;
	return NULL;
}


/* 189 */
static jthrowable _anewarray(vmFrame *frame) {
	jint length = VM_POP_INT(frame);
	VM_PUSH_OBJECT(frame, jniNewObjectArray((JNIEnv*)frame->env, length, 
		frame->constant_pool[GET_JUSHORT(frame->pc)].p, NULL));	
	frame->pc += 3;
	return frame->exception;
}


/* 190 */
static jthrowable _arraylength(vmFrame *frame) {
	jarray array = VM_POP_OBJECT(frame);
	if (array == NULL) return vmCreateThrowable(frame->env, &clsJAVA_LANG_NULLPOINTEREXCEPTION, "[arraylength]");
	VM_PUSH_INT(frame, VM_ARRAY_LENGTH(array));
	frame->pc++;
	return NULL;
}


/* 191 */
static jthrowable _athrow(vmFrame *frame) {
/*	clsConstPool *cp = frame->constant_pool;
	jint pc = frame->pc - (jubyte*)frame->met->code;
	jint et_count = frame->met->exceptions_count, i;
	exception_table *et = frame->met->exceptions;
	jthrowable err = VM_POP_OBJECT(frame);
	clsDefinition *errclsdef = &clsJAVA_LANG_THROWABLE;
	if (err != NULL) errclsdef = err->clsdef;
	for (i = 0; i < et_count; i++)
		if ((et[i].start_pc <= pc) && (pc < et[i].end_pc))
			if (vmIsAssignableFrom(VM_CLASS_DEF((jobject)cp[et[i].catch_type].p), errclsdef)) {
				frame->pc = (jubyte*)frame->met->code + et[i].handler_pc;
				frame->stack_top = frame->met->vars_count;
				VM_PUSH_OBJECT(frame, err);
				return NULL;
			}
	/* exception handler not found */
//	return err;
	frame->pc++;
	return VM_POP_OBJECT(frame);
}


/* 192 */
static jthrowable _checkcast(vmFrame *frame) {
	jobject obj = VM_POP_OBJECT(frame);
	if (!jniIsInstanceOf((JNIEnv*)frame->env, obj, frame->constant_pool[GET_JUSHORT(frame->pc)].p))
		return vmCreateThrowable(frame->env, &clsJAVA_LANG_CLASSCASTEXCEPTION, "[checkcast]");
	VM_PUSH_OBJECT(frame, obj);
	frame->pc += 3;
	return NULL;
}


/* 193 */
static jthrowable _instanceof(vmFrame *frame) {
	VM_PUSH_INT(frame, jniIsInstanceOf((JNIEnv*)frame->env, VM_POP_OBJECT(frame), 
		frame->constant_pool[GET_JUSHORT(frame->pc)].p));
	frame->pc += 3;
	return NULL;
}


/* 194 */
static jthrowable _monitorenter(vmFrame *frame) {
	if (JNI_OK != jniMonitorEnter((JNIEnv*)frame->env, VM_POP_OBJECT(frame)))
		return jniExceptionOccurred((JNIEnv*)frame->env);
	frame->pc++;
	return NULL;
}


/* 195 */
static jthrowable _monitorexit(vmFrame *frame) {
	if (JNI_OK != jniMonitorExit((JNIEnv*)frame->env, VM_POP_OBJECT(frame)))
		return jniExceptionOccurred((JNIEnv*)frame->env);
	frame->pc++;
	return NULL;
}


/* 196 */
static jthrowable _wide(vmFrame *frame) {
	frame->wide = JNI_TRUE;
	frame->pc++;
	return NULL;
}


/* 197 */
static jboolean createSubArray(JNIEnv *env, jarray arr, jint *count, jshort len, jclass *elementType) {
	jint i;
	if (count[1] < 0) return JNI_TRUE;
	for (i = 0; i < *count; i++) {
		jarray subArray = jniNewObjectArray(env, count[1], *(elementType - 1), NULL);
		if ((len > 1) && (count[1] > 0))
			createSubArray(env, subArray, count + 1, len - 1, elementType - 1);
		jniSetObjectArrayElement(env, arr, i, subArray);
		jniDeleteLocalRef(env, subArray);
	}
	return JNI_FALSE;
}
static jthrowable _multianewarray(vmFrame *frame) {
	jshort len = GET_JUBYTE(frame->pc+2), i;
	jclass type = frame->constant_pool[GET_JUSHORT(frame->pc)].p;
	clsDefinition *cls = VM_CLASS_DEF(type);
	class_cache_entry *cce = (class_cache_entry*)vmHashFindEntry_Hash(&frame->env->vm->clsdef, cls->name, 0, cls->hash);
	jshort dim = VM_CLASS_DIM(type);
	jint *count = (jint*)(frame->stack + frame->stack_top - len);
	jarray arr;
	/* create subtypes */
	for (i = 0; i < len; i++)
		if (cce->obj[dim - i] == NULL) {
			cce->obj[dim - i] = JNINEWGLOBALREF((JNIEnv*)frame->env,
				vmCreateObject(frame->env, frame->env->vm->class_clsdef, 0, 0, 0));
			VM_CLASS_DEF(cce->obj[dim - i]) = cls;
			VM_CLASS_DIM(cce->obj[dim - i]) = dim - i;
		}
	/* create array */
	if (count[0] < 0)
NEGERROR: return vmCreateThrowable(frame->env, &clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION, "[anewarray]");	
	arr = jniNewObjectArray((JNIEnv*)frame->env, count[0], cce->obj[dim - 1], NULL);
	if (createSubArray((JNIEnv*)frame->env, arr, count, len - 1, cce->obj + dim - 1))
		goto NEGERROR;
	/* OK, done */ 
	for (i = 0; i < len; i++) 
		VM_POP_INT(frame);
	VM_PUSH_OBJECT(frame, arr);
	frame->pc += 4;
	return jniExceptionOccurred((JNIEnv*)frame->env);
}


/* 198 */
static jthrowable _ifnull(vmFrame *frame) {
	if (VM_POP_OBJECT(frame) == NULL)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 199 */
static jthrowable _ifnonnull(vmFrame *frame) {
	if (VM_POP_OBJECT(frame) != NULL)
		frame->pc += GET_JSHORT(frame->pc);
	else
		frame->pc += 3;
	return NULL;
}


/* 200 */
static jthrowable _goto_w(vmFrame *frame) {
	frame->pc += GET_JINT(frame->pc);
	return NULL;
}


/* 201 */
static jthrowable _jsr_w(vmFrame *frame) {
	VM_PUSH_INT(frame, frame->pc + 5);
	frame->pc += GET_JINT(frame->pc);
	return NULL;
}


/**
   Array of the Java byte code handlers.
   Handler array index is equal to the appropriated Java instruction code.
*/
jInstructionHandler jInstructionSet[256] = {
	/* 0 */ _nop,
	/* 1 */ _aconst_null,
	/* 2 */ _iconst_m1,
	/* 3 */ _iconst_0,
	/* 4 */ _iconst_1,
	/* 5 */ _iconst_2,
	/* 6 */ _iconst_3,
	/* 7 */ _iconst_4,
	/* 8 */ _iconst_5,
	/* 9 */ _lconst_0,
	/* 10 */ _lconst_1,
	/* 11 */ _fconst_0,
	/* 12 */ _fconst_1,
	/* 13 */ _fconst_2,
	/* 14 */ _dconst_0,
	/* 15 */ _dconst_1,
	/* 16 */ _bipush,
	/* 17 */ _sipush,
	/* 18 */ _ldc,
	/* 19 */ _ldc_w,
	/* 20 */ _ldc2_w,
	/* 21 */ _iload,
	/* 22 */ _lload,
	/* 23 */ _fload,
	/* 24 */ _dload,
	/* 25 */ _aload,
	/* 26 */ _iload_0,
	/* 27 */ _iload_1,
	/* 28 */ _iload_2,
	/* 29 */ _iload_3,
	/* 30 */ _lload_0,
	/* 31 */ _lload_1,
	/* 32 */ _lload_2,
	/* 33 */ _lload_3,
	/* 34 */ _fload_0,
	/* 35 */ _fload_1,
	/* 36 */ _fload_2,
	/* 37 */ _fload_3,
	/* 38 */ _dload_0,
	/* 39 */ _dload_1,
	/* 40 */ _dload_2,
	/* 41 */ _dload_3,
	/* 42 */ _aload_0,
	/* 43 */ _aload_1,
	/* 44 */ _aload_2,
	/* 45 */ _aload_3,
	/* 46 */ _iaload,
	/* 47 */ _laload,
	/* 48 */ _faload,
	/* 49 */ _daload,
	/* 50 */ _aaload,
	/* 51 */ _baload,
	/* 52 */ _caload,
	/* 53 */ _saload,
	/* 54 */ _istore,
	/* 55 */ _lstore,
	/* 56 */ _fstore,
	/* 57 */ _dstore,
	/* 58 */ _astore,
	/* 59 */ _istore_0,
	/* 60 */ _istore_1,
	/* 61 */ _istore_2,
	/* 62 */ _istore_3,
	/* 63 */ _lstore_0,
	/* 64 */ _lstore_1,
	/* 65 */ _lstore_2,
	/* 66 */ _lstore_3,
	/* 67 */ _fstore_0,
	/* 68 */ _fstore_1,
	/* 69 */ _fstore_2,
	/* 70 */ _fstore_3,
	/* 71 */ _dstore_0,
	/* 72 */ _dstore_1,
	/* 73 */ _dstore_2,
	/* 74 */ _dstore_3,
	/* 75 */ _astore_0,
	/* 76 */ _astore_1,
	/* 77 */ _astore_2,
	/* 78 */ _astore_3,
	/* 79 */ _iastore,
	/* 80 */ _lastore,
	/* 81 */ _fastore,
	/* 82 */ _dastore,
	/* 83 */ _aastore,
	/* 84 */ _bastore,
	/* 85 */ _castore,
	/* 86 */ _sastore,
	/* 87 */ _pop,
	/* 88 */ _pop2,
	/* 89 */ _dup,
	/* 90 */ _dup_x1,
	/* 91 */ _dup_x2,
	/* 92 */ _dup2,
	/* 93 */ _dup2_x1,
	/* 94 */ _dup2_x2,
	/* 95 */ _swap,
	/* 96 */ _iadd,
	/* 97 */ _ladd,
	/* 98 */ _fadd,
	/* 99 */ _dadd,
	/* 100 */ _isub,
	/* 101 */ _lsub,
	/* 102 */ _fsub,
	/* 103 */ _dsub,
	/* 104 */ _imul,
	/* 105 */ _lmul,
	/* 106 */ _fmul,
	/* 107 */ _dmul,
	/* 108 */ _idiv,
	/* 109 */ _ldiv,
	/* 110 */ _fdiv,
	/* 111 */ _ddiv,
	/* 112 */ _irem,
	/* 113 */ _lrem,
	/* 114 */ _frem,
	/* 115 */ _drem,
	/* 116 */ _ineg,
	/* 117 */ _lneg,
	/* 118 */ _fneg,
	/* 119 */ _dneg,
	/* 120 */ _ishl,
	/* 121 */ _lshl,
	/* 122 */ _ishr,
	/* 123 */ _lshr,
	/* 124 */ _iushr,
	/* 125 */ _lushr,
	/* 126 */ _iand,
	/* 127 */ _land,
	/* 128 */ _ior,
	/* 129 */ _lor,
	/* 130 */ _ixor,
	/* 131 */ _lxor,
	/* 132 */ _iinc,
	/* 133 */ _i2l,
	/* 134 */ _i2f,
	/* 135 */ _i2d,
	/* 136 */ _l2i,
	/* 137 */ _l2f,
	/* 138 */ _l2d,
	/* 139 */ _f2i,
	/* 140 */ _f2l,
	/* 141 */ _f2d,
	/* 142 */ _d2i,
	/* 143 */ _d2l,
	/* 144 */ _d2f,
	/* 145 */ _i2b,
	/* 146 */ _i2c,
	/* 147 */ _i2s,
	/* 148 */ _lcmp,
	/* 149 */ _fcmpl,
	/* 150 */ _fcmpg,
	/* 151 */ _dcmpl,
	/* 152 */ _dcmpg,
	/* 153 */ _ifeq,
	/* 154 */ _ifne,
	/* 155 */ _iflt,
	/* 156 */ _ifge,
	/* 157 */ _ifgt,
	/* 158 */ _ifle,
	/* 159 */ _if_icmpeq,
	/* 160 */ _if_icmpne,
	/* 161 */ _if_icmplt,
	/* 162 */ _if_icmpge,
	/* 163 */ _if_icmpgt,
	/* 164 */ _if_icmple,
	/* 165 */ _if_acmpeq,
	/* 166 */ _if_acmpne,
	/* 167 */ _goto,
	/* 168 */ _jsr,
	/* 169 */ _ret,
	/* 170 */ _tableswitch,
	/* 171 */ _lookupswitch,
	/* 172 */ _ireturn,
	/* 173 */ _lreturn,
	/* 174 */ _ireturn,
	/* 175 */ _lreturn,
	/* 176 */ _areturn,
	/* 177 */ _return,
	/* 178 */ _getstatic,
	/* 179 */ _putstatic,
	/* 180 */ _getfield,
	/* 181 */ _putfield,
	/* 182 */ _invokevirtual,
	/* 183 */ _invokespecial,
	/* 184 */ _invokestatic,
	/* 185 */ _invokeinterface,
	/* 186 */ jUnknownCode,
	/* 187 */ _new,
	/* 188 */ _newarray,
	/* 189 */ _anewarray,
	/* 190 */ _arraylength,
	/* 191 */ _athrow,
	/* 192 */ _checkcast,
	/* 193 */ _instanceof,
	/* 194 */ _monitorenter,
	/* 195 */ _monitorexit,
	/* 196 */ _wide,
	/* 197 */ _multianewarray,
	/* 198 */ _ifnull,
	/* 199 */ _ifnonnull,
	/* 200 */ _goto_w,
	/* 201 */ _jsr_w,
	/* 202 */ jUnknownCode,
	/* 203 */ jUnknownCode,
	/* 204 */ jUnknownCode,
	/* 205 */ jUnknownCode,
	/* 206 */ jUnknownCode,
	/* 207 */ jUnknownCode,
	/* 208 */ jUnknownCode,
	/* 209 */ jUnknownCode,
	/* 210 */ jUnknownCode,
	/* 211 */ jUnknownCode,
	/* 212 */ jUnknownCode,
	/* 213 */ jUnknownCode,
	/* 214 */ jUnknownCode,
	/* 215 */ jUnknownCode,
	/* 216 */ jUnknownCode,
	/* 217 */ jUnknownCode,
	/* 218 */ jUnknownCode,
	/* 219 */ jUnknownCode,
	/* 220 */ jUnknownCode,
	/* 221 */ jUnknownCode,
	/* 222 */ jUnknownCode,
	/* 223 */ jUnknownCode,
	/* 224 */ jUnknownCode,
	/* 225 */ jUnknownCode,
	/* 226 */ jUnknownCode,
	/* 227 */ jUnknownCode,
	/* 228 */ jUnknownCode,
	/* 229 */ jUnknownCode,
	/* 230 */ jUnknownCode,
	/* 231 */ jUnknownCode,
	/* 232 */ jUnknownCode,
	/* 233 */ jUnknownCode,
	/* 234 */ jUnknownCode,
	/* 235 */ jUnknownCode,
	/* 236 */ jUnknownCode,
	/* 237 */ jUnknownCode,
	/* 238 */ jUnknownCode,
	/* 239 */ jUnknownCode,
	/* 240 */ jUnknownCode,
	/* 241 */ jUnknownCode,
	/* 242 */ jUnknownCode,
	/* 243 */ jUnknownCode,
	/* 244 */ jUnknownCode,
	/* 245 */ jUnknownCode,
	/* 246 */ jUnknownCode,
	/* 247 */ jUnknownCode,
	/* 248 */ jUnknownCode,
	/* 249 */ jUnknownCode,
	/* 250 */ jUnknownCode,
	/* 251 */ jUnknownCode,
	/* 252 */ jUnknownCode,
	/* 253 */ jUnknownCode,
	/* 254 */ jUnknownCode,
	/* 255 */ jUnknownCode
};
