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


#include "PrintStream_lite.h"
#include "..\lang\String.h"
#include "..\lang\System.h"


/* =============================================================== */
/*  fields                                                         */
/* =============================================================== */



/* =============================================================== */
/*  methods                                                        */
/* =============================================================== */

static clsMethod Java_java_io_PrintStream_printIID = {&clsJAVA_IO_PRINTSTREAM, ACC_PUBLIC|ACC_NATIVE, "print", "(I)V",
	   0x64CF483, 0, Java_java_io_PrintStream_printI, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_io_PrintStream_printI(JNIEnv *env, jobject _this, jint i) {
	wprintf(JSTRING("%d"), i);
}

static clsMethod Java_java_io_PrintStream_printSID = {&clsJAVA_IO_PRINTSTREAM, ACC_PUBLIC|ACC_NATIVE, "print", "(Ljava/lang/String;)V",
	   0xAC8C0352, 0, Java_java_io_PrintStream_printS, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_io_PrintStream_printS(JNIEnv *env, jobject _this, jstring s) {
	if (s != NULL)
		wprintf(VM_STRING(s));
	else
		printf("<NULL>");
}

static clsMethod Java_java_io_PrintStream_printlnSID = {&clsJAVA_IO_PRINTSTREAM, ACC_PUBLIC|ACC_NATIVE, "println", "(Ljava/lang/String;)V",
	   0x47EE7910, 0, Java_java_io_PrintStream_printlnS, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};
void JNICALL Java_java_io_PrintStream_printlnS(JNIEnv *env, jobject _this, jstring s) {
	if (s != NULL)
		wprintf(VM_STRING(s));
	else
		printf("<NULL>");
	printf("\n");
}

/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsMethod* instance_methods[] = {
	&Java_java_io_PrintStream_printIID,
	&Java_java_io_PrintStream_printSID,
	&Java_java_io_PrintStream_printlnSID
};

clsDefinition clsJAVA_IO_PRINTSTREAM = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/PrintStream",         /* name */
	&clsJAVA_LANG_OBJECT,          /* super_class */
	0x919E1091,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	0,                             /* interfaces_count */
	NULL,                          /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	instance_methods,              /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};