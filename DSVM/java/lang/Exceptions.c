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


#include "Exceptions.h"
#include "String.h"


static clsDefinition* interfaces[] = {
	&clsJAVA_IO_SERIALIZABLE
};


/* =============================================================== */
/*  ArithmeticException                                            */
/* =============================================================== */

static clsMethod Java_java_lang_ArithmeticException_ArithmeticException0ID = {&clsJAVA_LANG_ARITHMETICEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ArithmeticException_ArithmeticException1ID = {&clsJAVA_LANG_ARITHMETICEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ArithmeticException_instance_methods[] = {
	&Java_java_lang_ArithmeticException_ArithmeticException0ID,
	&Java_java_lang_ArithmeticException_ArithmeticException1ID
};

clsDefinition clsJAVA_LANG_ARITHMETICEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ArithmeticException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x3ABE0C51,                    /* name hash */
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
	sizeof(ArithmeticException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ArithmeticException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ArrayIndexOutOfBoundsException                                 */
/* =============================================================== */

static clsMethod Java_java_lang_ArrayIndexOutOfBoundsException_ArrayIndexOutOfBoundsException0ID = {&clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ArrayIndexOutOfBoundsException_ArrayIndexOutOfBoundsException1ID = {&clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ArrayIndexOutOfBoundsException_instance_methods[] = {
	&Java_java_lang_ArrayIndexOutOfBoundsException_ArrayIndexOutOfBoundsException0ID,
	&Java_java_lang_ArrayIndexOutOfBoundsException_ArrayIndexOutOfBoundsException1ID
};

clsDefinition clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ArrayIndexOutOfBoundsException", /* name */
	&clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, /* super_class */
	0xEA115B22,                    /* name hash */
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
	sizeof(ArrayIndexOutOfBoundsException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ArrayIndexOutOfBoundsException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ArrayStoreException                                            */
/* =============================================================== */

static clsMethod Java_java_lang_ArrayStoreException_ArrayStoreException0ID = {&clsJAVA_LANG_ARRAYSTOREEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ArrayStoreException_ArrayStoreException1ID = {&clsJAVA_LANG_ARRAYSTOREEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ArrayStoreException_instance_methods[] = {
	&Java_java_lang_ArrayStoreException_ArrayStoreException0ID,
	&Java_java_lang_ArrayStoreException_ArrayStoreException1ID
};

clsDefinition clsJAVA_LANG_ARRAYSTOREEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ArrayStoreException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x51C148B3,                    /* name hash */
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
	sizeof(ArrayStoreException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ArrayStoreException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ClassCastException                                             */
/* =============================================================== */

static clsMethod Java_java_lang_ClassCastException_ClassCastException0ID = {&clsJAVA_LANG_CLASSCASTEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ClassCastException_ClassCastException1ID = {&clsJAVA_LANG_CLASSCASTEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ClassCastException_instance_methods[] = {
	&Java_java_lang_ClassCastException_ClassCastException0ID,
	&Java_java_lang_ClassCastException_ClassCastException1ID
};

clsDefinition clsJAVA_LANG_CLASSCASTEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ClassCastException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0xC76D3E2C,                    /* name hash */
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
	sizeof(ClassCastException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ClassCastException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ClassNotFoundException                                         */
/* =============================================================== */

static clsMethod Java_java_lang_ClassNotFoundException_ClassNotFoundException0ID = {&clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ClassNotFoundException_ClassNotFoundException1ID = {&clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod Java_java_lang_ClassNotFoundException_ClassNotFoundException2ID = {&clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V", 
	   0x9c9fc524, 0, Java_java_lang_Throwable_Throwable2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};

static clsMethod Java_java_lang_ClassNotFoundException_getExceptionID = {&clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION, ACC_PROTECTED|ACC_NATIVE, "getException", "()Ljava/lang/Throwable;",
	   0x4cc6e243, 0, Java_java_lang_Throwable_getCause, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'L'};

static clsMethod* ClassNotFoundException_instance_methods[] = {
	&Java_java_lang_ClassNotFoundException_ClassNotFoundException0ID,
	&Java_java_lang_ClassNotFoundException_ClassNotFoundException1ID,
	&Java_java_lang_ClassNotFoundException_ClassNotFoundException2ID,
	&Java_java_lang_ClassNotFoundException_getExceptionID
};

clsDefinition clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ClassNotFoundException", /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x2C2938FC,                    /* name hash */
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
	sizeof(ClassNotFoundException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ClassNotFoundException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  CloneNotSupportedException                                     */
/* =============================================================== */

static clsMethod Java_java_lang_CloneNotSupportedException_CloneNotSupportedException0ID = {&clsJAVA_LANG_CLONENOTSUPPORTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_CloneNotSupportedException_CloneNotSupportedException1ID = {&clsJAVA_LANG_CLONENOTSUPPORTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* CloneNotSupportedException_instance_methods[] = {
	&Java_java_lang_CloneNotSupportedException_CloneNotSupportedException0ID,
	&Java_java_lang_CloneNotSupportedException_CloneNotSupportedException1ID
};

clsDefinition clsJAVA_LANG_CLONENOTSUPPORTEDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/CloneNotSupportedException",  /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x59E70B0B,                    /* name hash */
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
	sizeof(CloneNotSupportedException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	CloneNotSupportedException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  Exception                                                      */
/* =============================================================== */

static clsMethod Java_java_lang_Exception_Exception0ID = {&clsJAVA_LANG_EXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_Exception_Exception1ID = {&clsJAVA_LANG_EXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod Java_java_lang_Exception_Exception2ID = {&clsJAVA_LANG_EXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V", 
	   0x9c9fc524, 0, Java_java_lang_Throwable_Throwable2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};

static clsMethod Java_java_lang_Exception_Exception3ID = {&clsJAVA_LANG_EXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/Throwable;)V", 
	   0xebca81d2, 0, Java_java_lang_Throwable_Throwable3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* Exception_instance_methods[] = {
	&Java_java_lang_Exception_Exception0ID,
	&Java_java_lang_Exception_Exception1ID,
	&Java_java_lang_Exception_Exception2ID,
	&Java_java_lang_Exception_Exception3ID,
};

clsDefinition clsJAVA_LANG_EXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/Exception",         /* name */
	&clsJAVA_LANG_THROWABLE,       /* super_class */
	0x527A44DB,                    /* name hash */
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
	sizeof(Exception_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	Exception_instance_methods,    /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IllegalAccessException                                         */
/* =============================================================== */

static clsMethod Java_java_lang_IllegalAccessException_IllegalAccessException0ID = {&clsJAVA_LANG_ILLEGALACCESSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_IllegalAccessException_IllegalAccessException1ID = {&clsJAVA_LANG_ILLEGALACCESSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IllegalAccessException_instance_methods[] = {
	&Java_java_lang_IllegalAccessException_IllegalAccessException0ID,
	&Java_java_lang_IllegalAccessException_IllegalAccessException1ID
};

clsDefinition clsJAVA_LANG_ILLEGALACCESSEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/IllegalAccessException", /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x67EDE3E9,                    /* name hash */
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
	sizeof(IllegalAccessException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IllegalAccessException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IllegalArgumentException                                       */
/* =============================================================== */

static clsMethod Java_java_lang_IllegalArgumentException_IllegalArgumentException0ID = {&clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_IllegalArgumentException_IllegalArgumentException1ID = {&clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IllegalArgumentException_instance_methods[] = {
	&Java_java_lang_IllegalArgumentException_IllegalArgumentException0ID,
	&Java_java_lang_IllegalArgumentException_IllegalArgumentException1ID
};

clsDefinition clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/IllegalArgumentException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x7258FF30,                    /* name hash */
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
	sizeof(IllegalArgumentException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IllegalArgumentException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IllegalMonitorStateException                                   */
/* =============================================================== */

static clsMethod Java_java_lang_IllegalMonitorStateException_IllegalMonitorStateException0ID = {&clsJAVA_LANG_ILLEGALMONITORSTATEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_IllegalMonitorStateException_IllegalMonitorStateException1ID = {&clsJAVA_LANG_ILLEGALMONITORSTATEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IllegalMonitorStateException_instance_methods[] = {
	&Java_java_lang_IllegalMonitorStateException_IllegalMonitorStateException0ID,
	&Java_java_lang_IllegalMonitorStateException_IllegalMonitorStateException1ID
};

clsDefinition clsJAVA_LANG_ILLEGALMONITORSTATEEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/IllegalMonitorStateException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x8FD74CD6,                    /* name hash */
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
	sizeof(IllegalMonitorStateException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IllegalMonitorStateException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IllegalStateException                                          */
/* =============================================================== */

static clsMethod Java_java_lang_IllegalStateException_IllegalStateException0ID = {&clsJAVA_LANG_ILLEGALSTATEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_IllegalStateException_IllegalStateException1ID = {&clsJAVA_LANG_ILLEGALSTATEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IllegalStateException_instance_methods[] = {
	&Java_java_lang_IllegalStateException_IllegalStateException0ID,
	&Java_java_lang_IllegalStateException_IllegalStateException1ID
};

clsDefinition clsJAVA_LANG_ILLEGALSTATEEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/IllegalStateException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0xC4585A60,                    /* name hash */
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
	sizeof(IllegalStateException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IllegalStateException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IllegalThreadStateException                                    */
/* =============================================================== */

static clsMethod Java_java_lang_IllegalThreadStateException_IllegalThreadStateException0ID = {&clsJAVA_LANG_ILLEGALTHREADSTATEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_IllegalThreadStateException_IllegalThreadStateException1ID = {&clsJAVA_LANG_ILLEGALTHREADSTATEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IllegalThreadStateException_instance_methods[] = {
	&Java_java_lang_IllegalThreadStateException_IllegalThreadStateException0ID,
	&Java_java_lang_IllegalThreadStateException_IllegalThreadStateException1ID
};

clsDefinition clsJAVA_LANG_ILLEGALTHREADSTATEEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/IllegalThreadStateException", /* name */
	&clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION, /* super_class */
	0x2C73198A,                    /* name hash */
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
	sizeof(IllegalThreadStateException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IllegalThreadStateException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IndexOutOfBoundsException                                      */
/* =============================================================== */

static clsMethod Java_java_lang_IndexOutOfBoundsException_IndexOutOfBoundsException0ID = {&clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_IndexOutOfBoundsException_IndexOutOfBoundsException1ID = {&clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IndexOutOfBoundsException_instance_methods[] = {
	&Java_java_lang_IndexOutOfBoundsException_IndexOutOfBoundsException0ID,
	&Java_java_lang_IndexOutOfBoundsException_IndexOutOfBoundsException1ID
};

clsDefinition clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/IndexOutOfBoundsException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x62750913,                    /* name hash */
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
	sizeof(IndexOutOfBoundsException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IndexOutOfBoundsException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  InstantiationException                                         */
/* =============================================================== */

static clsMethod Java_java_lang_InstantiationException_InstantiationException0ID = {&clsJAVA_LANG_INSTANTIATIONEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_InstantiationException_InstantiationException1ID = {&clsJAVA_LANG_INSTANTIATIONEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* InstantiationException_instance_methods[] = {
	&Java_java_lang_InstantiationException_InstantiationException0ID,
	&Java_java_lang_InstantiationException_InstantiationException1ID
};

clsDefinition clsJAVA_LANG_INSTANTIATIONEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/InstantiationException", /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x90515876,                    /* name hash */
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
	sizeof(InstantiationException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	InstantiationException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  InterruptedException                                           */
/* =============================================================== */

static clsMethod Java_java_lang_InterruptedException_InterruptedException0ID = {&clsJAVA_LANG_INTERRUPTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_InterruptedException_InterruptedException1ID = {&clsJAVA_LANG_INTERRUPTEDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* InterruptedException_instance_methods[] = {
	&Java_java_lang_InterruptedException_InterruptedException0ID,
	&Java_java_lang_InterruptedException_InterruptedException1ID
};

clsDefinition clsJAVA_LANG_INTERRUPTEDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/InterruptedException", /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x62E72821,                    /* name hash */
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
	sizeof(InterruptedException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	InterruptedException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NegativeArraySizeException                                     */
/* =============================================================== */

static clsMethod Java_java_lang_NegativeArraySizeException_NegativeArraySizeException0ID = {&clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NegativeArraySizeException_NegativeArraySizeException1ID = {&clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NegativeArraySizeException_instance_methods[] = {
	&Java_java_lang_NegativeArraySizeException_NegativeArraySizeException0ID,
	&Java_java_lang_NegativeArraySizeException_NegativeArraySizeException1ID
};

clsDefinition clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NegativeArraySizeException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x2D02517E,                    /* name hash */
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
	sizeof(NegativeArraySizeException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NegativeArraySizeException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NoSuchFieldException                                           */
/* =============================================================== */

static clsMethod Java_java_lang_NoSuchFieldException_NoSuchFieldException0ID = {&clsJAVA_LANG_NOSUCHFIELDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NoSuchFieldException_NoSuchFieldException1ID = {&clsJAVA_LANG_NOSUCHFIELDEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NoSuchFieldException_instance_methods[] = {
	&Java_java_lang_NoSuchFieldException_NoSuchFieldException0ID,
	&Java_java_lang_NoSuchFieldException_NoSuchFieldException1ID
};

clsDefinition clsJAVA_LANG_NOSUCHFIELDEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NoSuchFieldException", /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x51F74E31,                    /* name hash */
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
	sizeof(NoSuchFieldException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NoSuchFieldException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NoSuchMethodException                                          */
/* =============================================================== */

static clsMethod Java_java_lang_NoSuchMethodException_NoSuchMethodException0ID = {&clsJAVA_LANG_NOSUCHMETHODEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NoSuchMethodException_NoSuchMethodException1ID = {&clsJAVA_LANG_NOSUCHMETHODEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NoSuchMethodException_instance_methods[] = {
	&Java_java_lang_NoSuchMethodException_NoSuchMethodException0ID,
	&Java_java_lang_NoSuchMethodException_NoSuchMethodException1ID
};

clsDefinition clsJAVA_LANG_NOSUCHMETHODEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NoSuchMethodException", /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x2F2BBE32,                    /* name hash */
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
	sizeof(NoSuchMethodException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NoSuchMethodException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NullPointerException                                           */
/* =============================================================== */

static clsMethod Java_java_lang_NullPointerException_NullPointerException0ID = {&clsJAVA_LANG_NULLPOINTEREXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NullPointerException_NullPointerException1ID = {&clsJAVA_LANG_NULLPOINTEREXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NullPointerException_instance_methods[] = {
	&Java_java_lang_NullPointerException_NullPointerException0ID,
	&Java_java_lang_NullPointerException_NullPointerException1ID
};

clsDefinition clsJAVA_LANG_NULLPOINTEREXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NullPointerException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x7E75FE2D,                    /* name hash */
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
	sizeof(NullPointerException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NullPointerException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NumberFormatException                                          */
/* =============================================================== */

static clsMethod Java_java_lang_NumberFormatException_NumberFormatException0ID = {&clsJAVA_LANG_NUMBERFORMATEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NumberFormatException_NumberFormatException1ID = {&clsJAVA_LANG_NUMBERFORMATEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NumberFormatException_instance_methods[] = {
	&Java_java_lang_NumberFormatException_NumberFormatException0ID,
	&Java_java_lang_NumberFormatException_NumberFormatException1ID
};

clsDefinition clsJAVA_LANG_NUMBERFORMATEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NumberFormatException", /* name */
	&clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION, /* super_class */
	0x21A8C21B,                    /* name hash */
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
	sizeof(NumberFormatException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NumberFormatException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  RuntimeException                                               */
/* =============================================================== */

static clsMethod Java_java_lang_RuntimeException_RuntimeException0ID = {&clsJAVA_LANG_RUNTIMEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_RuntimeException_RuntimeException1ID = {&clsJAVA_LANG_RUNTIMEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod Java_java_lang_RuntimeException_RuntimeException2ID = {&clsJAVA_LANG_RUNTIMEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V", 
	   0x9c9fc524, 0, Java_java_lang_Throwable_Throwable2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};

static clsMethod Java_java_lang_RuntimeException_RuntimeException3ID = {&clsJAVA_LANG_RUNTIMEEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/Throwable;)V", 
	   0xebca81d2, 0, Java_java_lang_Throwable_Throwable3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* RuntimeException_instance_methods[] = {
	&Java_java_lang_RuntimeException_RuntimeException0ID,
	&Java_java_lang_RuntimeException_RuntimeException1ID,
	&Java_java_lang_RuntimeException_RuntimeException2ID,
	&Java_java_lang_RuntimeException_RuntimeException3ID
};

clsDefinition clsJAVA_LANG_RUNTIMEEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/RuntimeException",  /* name */
	&clsJAVA_LANG_EXCEPTION,       /* super_class */
	0x5CF0094B,                    /* name hash */
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
	sizeof(RuntimeException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	RuntimeException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  SecurityException                                              */
/* =============================================================== */

static clsMethod Java_java_lang_SecurityException_SecurityException0ID = {&clsJAVA_LANG_SECURITYEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_SecurityException_SecurityException1ID = {&clsJAVA_LANG_SECURITYEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* SecurityException_instance_methods[] = {
	&Java_java_lang_SecurityException_SecurityException0ID,
	&Java_java_lang_SecurityException_SecurityException1ID
};

clsDefinition clsJAVA_LANG_SECURITYEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/SecurityException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x9944C97B,                    /* name hash */
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
	sizeof(SecurityException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	SecurityException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  StringIndexOutOfBoundsException                                */
/* =============================================================== */

static clsMethod Java_java_lang_StringIndexOutOfBoundsException_StringIndexOutOfBoundsException0ID = {&clsJAVA_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_StringIndexOutOfBoundsException_StringIndexOutOfBoundsException1ID = {&clsJAVA_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* StringIndexOutOfBoundsException_instance_methods[] = {
	&Java_java_lang_StringIndexOutOfBoundsException_StringIndexOutOfBoundsException0ID,
	&Java_java_lang_StringIndexOutOfBoundsException_StringIndexOutOfBoundsException1ID
};

clsDefinition clsJAVA_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/StringIndexOutOfBoundsException", /* name */
	&clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION, /* super_class */
	0x4963F502,                    /* name hash */
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
	sizeof(StringIndexOutOfBoundsException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	StringIndexOutOfBoundsException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  UnsupportedOperationException                                  */
/* =============================================================== */

static clsMethod Java_java_lang_UnsupportedOperationException_UnsupportedOperationException0ID = {&clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_UnsupportedOperationException_UnsupportedOperationException1ID = {&clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* UnsupportedOperationException_instance_methods[] = {
	&Java_java_lang_UnsupportedOperationException_UnsupportedOperationException0ID,
	&Java_java_lang_UnsupportedOperationException_UnsupportedOperationException1ID
};

clsDefinition clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/UnsupportedOperationException", /* name */
	&clsJAVA_LANG_RUNTIMEEXCEPTION, /* super_class */
	0x1B0D9049,                    /* name hash */
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
	sizeof(UnsupportedOperationException_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	UnsupportedOperationException_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


