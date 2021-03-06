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


#include "CharSequence.h"


/* =============================================================== */
/*  Instance methods                                               */
/* =============================================================== */

static clsMethod Java_java_lang_CharSequence_charAtID = {&clsJAVA_LANG_CHARSEQUENCE, ACC_PUBLIC|ACC_ABSTRACT, "charAt", "(I)C", 
	   0xaec45832, 0, NULL, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'C'};

static clsMethod Java_java_lang_CharSequence_lengthID = {&clsJAVA_LANG_CHARSEQUENCE, ACC_PUBLIC|ACC_ABSTRACT, "length", "()I", 
	   0xbe0ea18e, 0, NULL, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'I'};

static clsMethod Java_java_lang_CharSequence_subSequenceID = {&clsJAVA_LANG_CHARSEQUENCE, ACC_PUBLIC|ACC_ABSTRACT, "subSequence", "(II)Ljava/lang/CharSequence;", 
	   0x1e7147a4, 0, NULL, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'L'};

static clsMethod Java_java_lang_CharSequence_toStringID = {&clsJAVA_LANG_CHARSEQUENCE, ACC_PUBLIC|ACC_ABSTRACT, "toString", "()Ljava/lang/String;",
	   0xe5d943a7, 0, NULL, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};


/* =============================================================== */
/*  class definition                                               */
/* =============================================================== */

static clsMethod* instance_methods[] = {
	&Java_java_lang_CharSequence_charAtID,
	&Java_java_lang_CharSequence_lengthID,
	&Java_java_lang_CharSequence_subSequenceID,
	&Java_java_lang_CharSequence_toStringID
};

clsDefinition clsJAVA_LANG_CHARSEQUENCE = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/CharSequence",      /* name */
	NULL,                          /* super_class */
	0x73C4692B,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_INTERFACE,    /* access_flags */
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