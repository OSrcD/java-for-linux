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
#include "Throwable.h"
#include "StackTraceElement.h"
#include "String.h"


/* =============================================================== */
/*  methods                                                        */
/* =============================================================== */

static clsMethod Java_java_lang_Throwable_Throwable0ID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Throwable_Throwable0(JNIEnv *env, jthrowable _this) {
	Java_java_lang_Throwable_fillInStackTrace(env, _this);
}


static clsMethod Java_java_lang_Throwable_Throwable1ID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Throwable_Throwable1(JNIEnv *env, jthrowable _this, jstring msg) {
	Java_java_lang_Throwable_Throwable2(env, _this, msg, NULL);
}


static clsMethod Java_java_lang_Throwable_Throwable2ID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V", 
	   0x9c9fc524, 0, Java_java_lang_Throwable_Throwable2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};
void JNICALL Java_java_lang_Throwable_Throwable2(JNIEnv *env, jthrowable _this, jstring msg, jthrowable cause) {
	if (msg != NULL)
		JNINEWGLOBALREF(env, VM_THROWABLE_MSG(_this) = msg);
	if (cause != NULL)
		JNINEWGLOBALREF(env, VM_THROWABLE_CAUSE(_this) = cause);
	Java_java_lang_Throwable_fillInStackTrace(env, _this);
}


static clsMethod Java_java_lang_Throwable_Throwable3ID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/Throwable;)V", 
	   0xebca81d2, 0, Java_java_lang_Throwable_Throwable3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Throwable_Throwable3(JNIEnv *env, jthrowable _this, jthrowable cause) {
	Java_java_lang_Throwable_Throwable2(env, _this, NULL, cause);
}

/* stack trace support */
jint Java_java_lang_Throwable_fillInStackTrace_count(JNIEnv *env) {
	jint cnt = 0; 
	vmFrame *frame = ((vmJNIEnv*)env)->frame;
	while (frame != NULL) {
		if (frame->met != NULL) cnt++;
		frame = frame->prev;
	}
	return cnt;
}
void Java_java_lang_Throwable_fillInStackTrace_fill(JNIEnv *env, jthrowable _this) {
	jint cnt = 0, i, pc; 
	vmFrame *frame = ((vmJNIEnv*)env)->frame;
	JavaLangStackTraceIData *st = VM_THROWABLE_STACK(_this);
	while (frame != NULL) {
		if (frame->met != NULL) {
			st[cnt].met = frame->met; st[cnt].line_number = -1;
			pc = frame->pc - (jubyte*)frame->met->code;
			if (frame->met->lines != NULL)
				for (i = 0; i < frame->met->lines_count; i++)
					if (pc >= frame->met->lines[i].start_pc) {
						st[cnt].line_number = frame->met->lines[i].line_number;
					} else
						break;
			cnt++;
		}
		frame = frame->prev;
	}
}


static clsMethod Java_java_lang_Throwable_fillInStackTraceID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "fillInStackTrace", "()Ljava/lang/Throwable;",
	   0xa4018c1f, 0, Java_java_lang_Throwable_fillInStackTrace, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Throwable_fillInStackTrace(JNIEnv *env, jthrowable _this) {
	/* compute stack traces count */
	jint cnt = Java_java_lang_Throwable_fillInStackTrace_count(env);
	/* alloc new object data */
	jbyte *data = vmMemAlloc(((vmJNIEnv*)env)->vm, _this->clsdef->total_data_size + cnt * sizeof(JavaLangStackTraceIData));
	vmMemCpy(data, _this->data, _this->clsdef->total_data_size);
	if (_this->flags & VM_OBJECT_FREEDATA_FLAG) vmMemFree(((vmJNIEnv*)env)->vm, _this->data);
	_this->data = data;
	_this->flags |= VM_OBJECT_FREEDATA_FLAG;
	VM_THROWABLE_STACK_COUNT(_this) = cnt;
	VM_THROWABLE_STACK(_this) = data + _this->clsdef->total_data_size;
	/* OK, store current stack */
	Java_java_lang_Throwable_fillInStackTrace_fill(env, _this);
	return _this;
}


static clsMethod Java_java_lang_Throwable_getCauseID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "getCause", "()Ljava/lang/Throwable;",
	   0x6f453969, 0, Java_java_lang_Throwable_getCause, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jthrowable JNICALL Java_java_lang_Throwable_getCause(JNIEnv *env, jthrowable _this) {
	return VM_THROWABLE_CAUSE(_this);
}


static clsMethod Java_java_lang_Throwable_getLocalizedMessageID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "getLocalizedMessage", "()Ljava/lang/String;",
	   0x99087a49, 0, Java_java_lang_Throwable_getLocalizedMessage, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Throwable_getLocalizedMessage(JNIEnv *env, jthrowable _this) {
	return Java_java_lang_Throwable_getMessage(env, _this);
}


static clsMethod Java_java_lang_Throwable_getMessageID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "getMessage", "()Ljava/lang/String;",
	   0x5772a1a, 0, Java_java_lang_Throwable_getMessage, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Throwable_getMessage(JNIEnv *env, jthrowable _this) {
	return jniNewLocalRef(env, VM_THROWABLE_MSG(_this));
}


static clsMethod Java_java_lang_Throwable_initCauseID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "initCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;",
	   0x38ad81bc, 0, Java_java_lang_Throwable_initCause, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'L'};
jthrowable JNICALL Java_java_lang_Throwable_initCause(JNIEnv *env, jthrowable _this, jthrowable cause) {
	vmSetObjectVar(env, &VM_THROWABLE_CAUSE(_this), cause, clsJAVA_LANG_THROWABLE.instance_fields + 1 /* _cause field */);
	return _this;
}


static clsMethod Java_java_lang_Throwable_toStringID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "toString", "()Ljava/lang/String;",
	   0xe5d943a7, 0, Java_java_lang_Throwable_toString, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};
jstring JNICALL Java_java_lang_Throwable_toString(JNIEnv *env, jthrowable _this) {
	char *buf; jstring ret;
	buf = vmMemAlloc(((vmJNIEnv*)env)->vm, Java_java_lang_Throwable_toString_c(env, _this, NULL) + 16);
	Java_java_lang_Throwable_toString_c(env, _this, buf);
	ret = (*env)->NewStringUTF(env, buf);
	vmMemFree(((vmJNIEnv*)env)->vm, buf);
	return ret;
}
/* if (buf == 0) then returns needed buffer size */
jint Java_java_lang_Throwable_toString_c(JNIEnv *env, jthrowable _this, char *buf) {
	jint len = 0;
	if (_this != NULL) {
		len += vmStrLenUTF(_this->clsdef->name);
		if (VM_THROWABLE_MSG(_this) != NULL) len += toUtf8(NULL, VM_STRING(VM_THROWABLE_MSG(_this)), -1) + 2;
		if (buf != NULL) {
			vmStrCpyUTF(buf, _this->clsdef->name);
			while (*buf != 0) {
				if (*buf == '/') *buf = '.';
				buf++;
			}
			if (VM_THROWABLE_MSG(_this) != NULL) {
				vmStrCatUTF(buf, ": "); buf += 2;
				toUtf8(buf, VM_STRING(VM_THROWABLE_MSG(_this)), -1);
			}
		}
	} else
		if (buf != NULL) *buf = 0;
	return len;
}
/* if (buf == 0) then returns needed buffer size */
jint Java_java_lang_Throwable_toStackTrace_c(JNIEnv *env, jthrowable _this, char *buf, jthrowable prev) {
	jint len = 0, i; char *curAtSection = NULL;
	if (_this != NULL) {
		JavaLangStackTraceIData *st = VM_THROWABLE_STACK(_this);
		jint cnt = VM_THROWABLE_STACK_COUNT(_this), more_cnt = 0;
		len += Java_java_lang_Throwable_toString_c(env, _this, buf);
		if (buf != NULL) buf += len;
		if (prev != NULL) {
			JavaLangStackTraceIData *stprev = VM_THROWABLE_STACK(prev);
			jint cntprev = VM_THROWABLE_STACK_COUNT(prev);
			for (i = 1; i < cnt; i++) {
				jint idx = cnt - i, idxprev = cntprev - i;
				if (idxprev < 0) break;
				if (st[idx].line_number != stprev[idxprev].line_number) break;
				if (st[idx].met != stprev[idxprev].met) break;
				more_cnt++;
			}
		}
		for (i = 0; i < (cnt - more_cnt); i++) {
			char *s, *p, tmp[32];
			len += 13; 
			if (buf != NULL) {
				if (curAtSection == NULL) curAtSection = buf;
				vmStrCpyUTF(buf, "\r\n        at "); buf += 13; 
			}
			s = st[i].met->clsdef->name;
			len += vmStrLenUTF(s) + 1; if (buf != NULL) { vmStrCpyUTF(buf, s); vmStrCatUTF(buf, "."); 
				while (*buf) { if (*buf == '/') *buf = '.'; buf++; }; }
			s = st[i].met->name;
			len += vmStrLenUTF(s) + 1; if (buf != NULL) { vmStrCpyUTF(buf, s); vmStrCatUTF(buf, "("); buf += vmStrLenUTF(s) + 1; }
			if (st[i].met->access_flags & ACC_NATIVE) {
				len += 14; if (buf != NULL) { vmStrCpyUTF(buf, "Native Method)"); buf += 14; }
			} else {
				p = s = st[i].met->clsdef->name;
				while (*p) { if (*p == '/') s = p + 1; p++; }
				len += vmStrLenUTF(s); if (buf != NULL) { vmStrCpyUTF(buf, s); buf += vmStrLenUTF(s); }
				vmSprintfUTF(tmp, (st[i].line_number > 0) ? ".java:%u)" : ".java)", st[i].line_number);
				len += vmStrLenUTF(tmp); if (buf != NULL) { vmStrCpyUTF(buf, tmp); buf += vmStrLenUTF(tmp); }
			}
		}
		if (more_cnt > 0) {
			char tmp[64]; vmSprintfUTF(tmp, "\r\n        ... %u more", more_cnt);
			len += vmStrLenUTF(tmp); if (buf != NULL) { vmStrCpyUTF(buf, tmp); buf += vmStrLenUTF(tmp); }
		}
		if (VM_THROWABLE_CAUSE(_this) != NULL) {
			len += 13; if (buf != NULL) { vmStrCatUTF(buf, "\r\nCaused by: ");  buf += 13; }
            len += Java_java_lang_Throwable_toStackTrace_c(env, VM_THROWABLE_CAUSE(_this), buf, _this);
		}
	} else
		if (buf != NULL) *buf = 0;
	return len;
}


clsMethod Java_java_lang_Throwable_printStackTrace0ID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "printStackTrace", "()V",
	   0x6e0ef55f, 0, Java_java_lang_Throwable_printStackTrace0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};
void JNICALL Java_java_lang_Throwable_printStackTrace0(JNIEnv *env, jthrowable _this) {
	jclass systemclass = jniFindClass(env, "java/lang/System");
	Java_java_lang_Throwable_printStackTrace1(env, _this,
		jniGetStaticObjectField(env, systemclass, vmGetClassField(VM_CLASS_DEF(systemclass), "err", "Ljava/io/PrintStream;", JNI_TRUE))
	);
}


clsMethod Java_java_lang_Throwable_printStackTrace1ID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "printStackTrace", "(Ljava/io/PrintStream;)V",
	   0x7e2ce091, 0, Java_java_lang_Throwable_printStackTrace1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Throwable_printStackTrace1(JNIEnv *env, jthrowable _this, jobject ps) {
	char *buf; jstring st;
	if (ps == NULL) return;
	buf = vmMemAlloc(((vmJNIEnv*)env)->vm, Java_java_lang_Throwable_toStackTrace_c(env, _this, NULL, NULL) + 16);
	if (buf != NULL) {		
		Java_java_lang_Throwable_toStackTrace_c(env, _this, buf, NULL);
		st = jniNewStringUTF(env, buf);
		jniCallVoidMethod(env, ps, vmGetInstanceMethod(ps->clsdef, "print", "(Ljava/lang/String;)V", JNI_TRUE), st);
		jniDeleteLocalRef(env, st);
		vmMemFree(((vmJNIEnv*)env)->vm, buf);
	}
}


clsMethod Java_java_lang_Throwable_printStackTrace2ID = {&clsJAVA_LANG_THROWABLE, ACC_PUBLIC|ACC_NATIVE, "printStackTrace", "(Ljava/io/PrintWriter;)V",
	   0xa1235ec2, 0, Java_java_lang_Throwable_printStackTrace2, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_lang_Throwable_printStackTrace2(JNIEnv *env, jthrowable _this, jobject pw) {
	char *buf; jstring st;
	if (pw == NULL) return;
	buf = vmMemAlloc(((vmJNIEnv*)env)->vm, Java_java_lang_Throwable_toStackTrace_c(env, _this, NULL, NULL) + 16);
	if (buf != NULL) {		
		Java_java_lang_Throwable_toStackTrace_c(env, _this, buf, NULL);
		st = jniNewStringUTF(env, buf);
		jniCallVoidMethod(env, pw, vmGetInstanceMethod(pw->clsdef, "print", "(Ljava/lang/String;)V", JNI_TRUE), st);
		jniDeleteLocalRef(env, st);
		vmMemFree(((vmJNIEnv*)env)->vm, buf);
	}
}


/* =============================================================== */
/*  fields                                                         */
/* =============================================================== */

/* FIELDS ORDER NOT MUST BE CHANGED !!! */
static clsField instance_fields[] = {
	{&clsJAVA_LANG_THROWABLE, ACC_PRIVATE, "_msg", "Ljava/lang/String;", 0x52173dc8, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_LANG_THROWABLE, ACC_PRIVATE, "_cause", "Ljava/lang/Throwable;", 0x5fed9951, 0, NULL, 
		/* VM internal affairs */ sizeof(jobject), NULL}
};


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsDefinition* interfaces[] = {
	&clsJAVA_IO_SERIALIZABLE
};

static clsMethod* instance_methods[] = {
	&Java_java_lang_Throwable_Throwable0ID,
	&Java_java_lang_Throwable_Throwable1ID,
	&Java_java_lang_Throwable_Throwable2ID,
	&Java_java_lang_Throwable_Throwable3ID,
	&Java_java_lang_Throwable_fillInStackTraceID,
	&Java_java_lang_Throwable_getCauseID,
	&Java_java_lang_Throwable_getLocalizedMessageID,
	&Java_java_lang_Throwable_getMessageID,
	&Java_java_lang_Throwable_initCauseID,
	&Java_java_lang_Throwable_printStackTrace0ID,
	&Java_java_lang_Throwable_printStackTrace1ID,
	&Java_java_lang_Throwable_printStackTrace2ID,
	&Java_java_lang_Throwable_toStringID
};

clsDefinition clsJAVA_LANG_THROWABLE = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/Throwable",         /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0xAF51CDCC,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	sizeof(instance_fields) / sizeof(clsField), /* instance_fields_count */
	instance_fields,               /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,              /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(JavaLangThrowableIData),/* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};