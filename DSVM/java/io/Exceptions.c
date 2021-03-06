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


#include "..\lang\String.h"
#include "Exceptions.h"


static clsDefinition* interfaces[] = {
	&clsJAVA_IO_SERIALIZABLE
};


/* =============================================================== */
/*  CharConversionException                                        */
/* =============================================================== */

static clsMethod Java_java_io_CharConversionException_CharConversionException0ID = {&clsJAVA_IO_CHARCONVERSIONEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
		0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_CharConversionException_CharConversionException1ID = {&clsJAVA_IO_CHARCONVERSIONEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* CharConversionException_instance_methods[] = {
	&Java_java_io_CharConversionException_CharConversionException0ID,
	&Java_java_io_CharConversionException_CharConversionException1ID
};

clsDefinition clsJAVA_IO_CHARCONVERSIONEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/CharConversionException", /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0x6B060EA7,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(CharConversionException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	CharConversionException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  EOFException                                                   */
/* =============================================================== */

static clsMethod Java_java_io_EOFException_EOFException0ID = {&clsJAVA_IO_EOFEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_EOFException_EOFException1ID = {&clsJAVA_IO_EOFEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* EOFException_instance_methods[] = {
	&Java_java_io_EOFException_EOFException0ID,
	&Java_java_io_EOFException_EOFException1ID
};

clsDefinition clsJAVA_IO_EOFEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/EOFException",        /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0xA177AF2F,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(EOFException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	EOFException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  FileNotFoundException                                          */
/* =============================================================== */

static clsMethod Java_java_io_FileNotFoundException_FileNotFoundException0ID = {&clsJAVA_IO_FILENOTFOUNDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_FileNotFoundException_FileNotFoundException1ID = {&clsJAVA_IO_FILENOTFOUNDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* FileNotFoundException_instance_methods[] = {
	&Java_java_io_FileNotFoundException_FileNotFoundException0ID,
	&Java_java_io_FileNotFoundException_FileNotFoundException1ID
};

clsDefinition clsJAVA_IO_FILENOTFOUNDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/FileNotFoundException", /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0xBEFC0988,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(FileNotFoundException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	FileNotFoundException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  InterruptedIOException                                         */
/* =============================================================== */

static clsField InterruptedIOException_instance_fields[] = {
	{&clsJAVA_IO_INTERRUPTEDIOEXCEPTION, ACC_PUBLIC, "bytesTransferred ", "I", 0x1d6f06c, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
};

static clsMethod Java_java_io_InterruptedIOException_InterruptedIOException0ID = {&clsJAVA_IO_INTERRUPTEDIOEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_InterruptedIOException_InterruptedIOException1ID = {&clsJAVA_IO_INTERRUPTEDIOEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* InterruptedIOException_instance_methods[] = {
	&Java_java_io_InterruptedIOException_InterruptedIOException0ID,
	&Java_java_io_InterruptedIOException_InterruptedIOException1ID
};

clsDefinition clsJAVA_IO_INTERRUPTEDIOEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/InterruptedIOException", /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0xF03983C3,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	sizeof(InterruptedIOException_instance_fields) / sizeof(clsField), /* instance_fields_count */
	InterruptedIOException_instance_fields, /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(InterruptedIOException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	InterruptedIOException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(jint),                  /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  InvalidClassException                                          */
/* =============================================================== */

static clsField InvalidClassException_instance_fields[] = {
	{&clsJAVA_IO_INVALIDCLASSEXCEPTION, ACC_PRIVATE, "_cname", "Ljava/lang/String;", 0xf5f91f65, 0, NULL, 
		/* VM internal affairs */ 0, NULL}
};

static clsMethod Java_java_io_InvalidClassException_InvalidClassException1ID = {&clsJAVA_IO_INVALIDCLASSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

void JNICALL Java_java_io_InvalidClassException_InvalidClassException(JNIEnv *env, jthrowable _this, jstring cname, jstring msg) {
	jfieldID cnamefld = vmGetInstanceField(_this->clsdef, "_cname", "Ljava/lang/String;", JNI_TRUE);
	Java_java_lang_Throwable_Throwable2(env, _this, msg, NULL);
	jniSetObjectField(env, _this, cnamefld, cname);
}
static clsMethod Java_java_io_InvalidClassException_InvalidClassException2ID = {&clsJAVA_IO_INVALIDCLASSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V", 
	   0x857BF87B, 0, Java_java_io_InvalidClassException_InvalidClassException, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};

jstring JNICALL Java_java_io_InvalidClassException_getMessage(JNIEnv *env, jthrowable _this) {
	jstring ret = jniNewLocalRef(env, VM_THROWABLE_MSG(_this));
	jstring cname = jniGetObjectField(env, _this, InvalidClassException_instance_fields);
	if (ret != NULL) {
		jstring tmp = jniNewString(env, JSTRING(" [class="), 8);
		if (tmp != NULL) {
			jstring con = Java_java_lang_String_concat(env, ret, tmp);
			if (con != NULL) { jniDeleteLocalRef(env, ret); ret = con; }
		}
		jniDeleteLocalRef(env, tmp);
	} else
		ret = jniNewString(env, JSTRING("[class="), 7);
	if ((ret != NULL) && (cname != NULL)) {
		jstring con = Java_java_lang_String_concat(env, ret, cname);
		if (con != NULL) { jniDeleteLocalRef(env, ret); ret = con; }
	}
	if (ret != NULL) {
		jstring tmp = jniNewString(env, JSTRING("]"), 1);
		if (tmp != NULL) {
			jstring con = Java_java_lang_String_concat(env, ret, tmp);
			if (con != NULL) { jniDeleteLocalRef(env, ret); ret = con; }
		}
		jniDeleteLocalRef(env, tmp);
	}
	return ret;
}
static clsMethod Java_java_io_InvalidClassException_getMessageID = {&clsJAVA_IO_INVALIDCLASSEXCEPTION, ACC_PROTECTED|ACC_NATIVE, "getMessage", "()Ljava/lang/String;",
	   0x5772A1A, 0, Java_java_io_InvalidClassException_getMessage, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};

static clsMethod* InvalidClassException_instance_methods[] = {
	&Java_java_io_InvalidClassException_InvalidClassException1ID,
	&Java_java_io_InvalidClassException_InvalidClassException2ID,
	&Java_java_io_InvalidClassException_getMessageID
};

clsDefinition clsJAVA_IO_INVALIDCLASSEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/InvalidClassException", /* name */
	&clsJAVA_IO_OBJECTSTREAMEXCEPTION, /* super_class */
	0x1BD85292,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	sizeof(InvalidClassException_instance_fields) / sizeof(clsField), /* instance_fields_count */
	InvalidClassException_instance_fields, /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(InvalidClassException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	InvalidClassException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	sizeof(jobject),               /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  InvalidObjectException                                         */
/* =============================================================== */

static clsMethod Java_java_io_InvalidObjectException_InvalidObjectException1ID = {&clsJAVA_IO_INVALIDOBJECTEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* InvalidObjectException_instance_methods[] = {
	&Java_java_io_InvalidObjectException_InvalidObjectException1ID
};

clsDefinition clsJAVA_IO_INVALIDOBJECTEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/InvalidObjectException", /* name */
	&clsJAVA_IO_OBJECTSTREAMEXCEPTION, /* super_class */
	0xC3F73A55,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(InvalidObjectException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	InvalidObjectException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IOException                                                    */
/* =============================================================== */

static clsMethod Java_java_io_IOException_IOException0ID = {&clsJAVA_IO_IOEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_IOException_IOException1ID = {&clsJAVA_IO_IOEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IOException_instance_methods[] = {
	&Java_java_io_IOException_IOException0ID,
	&Java_java_io_IOException_IOException1ID
};

clsDefinition clsJAVA_IO_IOEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/IOException",         /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0xE9B4C1ED,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(IOException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IOException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NotActiveException                                             */
/* =============================================================== */

static clsMethod Java_java_io_NotActiveException_NotActiveException0ID = {&clsJAVA_IO_NOTACTIVEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_NotActiveException_NotActiveException1ID = {&clsJAVA_IO_NOTACTIVEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NotActiveException_instance_methods[] = {
	&Java_java_io_NotActiveException_NotActiveException0ID,
	&Java_java_io_NotActiveException_NotActiveException1ID
};

clsDefinition clsJAVA_IO_NOTACTIVEEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/NotActiveException",  /* name */
	&clsJAVA_IO_OBJECTSTREAMEXCEPTION, /* super_class */
	0x7999C012,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(NotActiveException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NotActiveException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NotSerializableException                                       */
/* =============================================================== */

static clsMethod Java_java_io_NotSerializableException_NotSerializableException0ID = {&clsJAVA_IO_NOTSERIALIZABLEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_NotSerializableException_NotSerializableException1ID = {&clsJAVA_IO_NOTSERIALIZABLEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NotSerializableException_instance_methods[] = {
	&Java_java_io_NotSerializableException_NotSerializableException0ID,
	&Java_java_io_NotSerializableException_NotSerializableException1ID
};

clsDefinition clsJAVA_IO_NOTSERIALIZABLEEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/NotSerializableException", /* name */
	&clsJAVA_IO_OBJECTSTREAMEXCEPTION, /* super_class */
	0x33F38B79,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(NotSerializableException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NotSerializableException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ObjectStreamException                                          */
/* =============================================================== */

static clsMethod Java_java_io_ObjectStreamException_ObjectStreamException0ID = {&clsJAVA_IO_OBJECTSTREAMEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_ObjectStreamException_ObjectStreamException1ID = {&clsJAVA_IO_OBJECTSTREAMEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ObjectStreamException_instance_methods[] = {
	&Java_java_io_ObjectStreamException_ObjectStreamException0ID,
	&Java_java_io_ObjectStreamException_ObjectStreamException1ID
};

clsDefinition clsJAVA_IO_OBJECTSTREAMEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/ObjectStreamException", /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0x9D5BC274,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(ObjectStreamException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ObjectStreamException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  OptionalDataException                                          */
/* =============================================================== */

static clsField OptionalDataException_instance_fields[] = {
	{&clsJAVA_IO_OPTIONALDATAEXCEPTION, ACC_PUBLIC, "eof", "Z", 0x188a6, 0, NULL, 
		/* VM internal affairs */ 0, NULL},
	{&clsJAVA_IO_OPTIONALDATAEXCEPTION, ACC_PUBLIC, "length", "I", 0xbe0e3aaf, 0, NULL, 
		/* VM internal affairs */ sizeof(jboolean), NULL}
};

clsDefinition clsJAVA_IO_OPTIONALDATAEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/OptionalDataException", /* name */
	&clsJAVA_IO_OBJECTSTREAMEXCEPTION, /* super_class */
	0x5BF7C349,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	sizeof(OptionalDataException_instance_fields) / sizeof(clsField), /* instance_fields_count */
	OptionalDataException_instance_fields, /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	0,                             /* instance_methods_count */
	NULL,                          /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	2 * sizeof(jint),              /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  StreamCorruptedException                                       */
/* =============================================================== */

static clsMethod Java_java_io_StreamCorruptedException_StreamCorruptedException0ID = {&clsJAVA_IO_STREAMCORRUPTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_StreamCorruptedException_StreamCorruptedException1ID = {&clsJAVA_IO_STREAMCORRUPTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* StreamCorruptedException_instance_methods[] = {
	&Java_java_io_StreamCorruptedException_StreamCorruptedException0ID,
	&Java_java_io_StreamCorruptedException_StreamCorruptedException1ID
};

clsDefinition clsJAVA_IO_STREAMCORRUPTEDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/StreamCorruptedException", /* name */
	&clsJAVA_IO_OBJECTSTREAMEXCEPTION, /* super_class */
	0x87DE205F,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(StreamCorruptedException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	StreamCorruptedException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  SyncFailedException                                            */
/* =============================================================== */

static clsMethod Java_java_io_SyncFailedException_SyncFailedException1ID = {&clsJAVA_IO_SYNCFAILEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* SyncFailedException_instance_methods[] = {
	&Java_java_io_SyncFailedException_SyncFailedException1ID
};

clsDefinition clsJAVA_IO_SYNCFAILEDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/SyncFailedException", /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0x52BDD87B,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(SyncFailedException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	SyncFailedException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  UnsupportedEncodingException                                   */
/* =============================================================== */

static clsMethod Java_java_io_UnsupportedEncodingException_UnsupportedEncodingException0ID = {&clsJAVA_IO_UNSUPPORTEDENCODINGEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_UnsupportedEncodingException_UnsupportedEncodingException1ID = {&clsJAVA_IO_UNSUPPORTEDENCODINGEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* UnsupportedEncodingException_instance_methods[] = {
	&Java_java_io_UnsupportedEncodingException_UnsupportedEncodingException0ID,
	&Java_java_io_UnsupportedEncodingException_UnsupportedEncodingException1ID
};

clsDefinition clsJAVA_IO_UNSUPPORTEDENCODINGEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/UnsupportedEncodingException", /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0x889E2F03,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(UnsupportedEncodingException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	UnsupportedEncodingException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  UTFDataFormatException                                         */
/* =============================================================== */

static clsMethod Java_java_io_UTFDataFormatException_UTFDataFormatException0ID = {&clsJAVA_IO_UTFDATAFORMATEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_UTFDataFormatException_UTFDataFormatException1ID = {&clsJAVA_IO_UTFDATAFORMATEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* UTFDataFormatException_instance_methods[] = {
	&Java_java_io_UTFDataFormatException_UTFDataFormatException0ID,
	&Java_java_io_UTFDataFormatException_UTFDataFormatException1ID
};

clsDefinition clsJAVA_IO_UTFDATAFORMATEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/UTFDataFormatException", /* name */
	&clsJAVA_IO_IOEXCEPTION,       /* super_class */
	0x47C87963,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(UTFDataFormatException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	UTFDataFormatException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  WriteAbortedException                                          */
/* =============================================================== */

static clsMethod Java_java_io_WriteAbortedException_WriteAbortedException0ID = {&clsJAVA_IO_WRITEABORTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_io_WriteAbortedException_WriteAbortedException1ID = {&clsJAVA_IO_WRITEABORTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* WriteAbortedException_instance_methods[] = {
	&Java_java_io_WriteAbortedException_WriteAbortedException0ID,
	&Java_java_io_WriteAbortedException_WriteAbortedException1ID
};

clsDefinition clsJAVA_IO_WRITEABORTEDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/io/WriteAbortedException", /* name */
	&clsJAVA_IO_OBJECTSTREAMEXCEPTION, /* super_class */
	0xEF540643,                    /* name hash */
	0,                             /* constant_pool_count */
	NULL,                          /* constant_pool */
	ACC_PUBLIC + ACC_SUPER,        /* access_flags */
	sizeof(interfaces) / sizeof(clsDefinition*), /* interfaces_count */
	interfaces,                    /* interfaces */
	0,                             /* class_fields_count */
	NULL,                          /* class_fields */
	0,                             /* instance_fields_count */
	NULL,                          /* instance_fields */
	0,                             /* class_methods_count */
	NULL,                          /* class_methods */
	sizeof(WriteAbortedException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	WriteAbortedException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


