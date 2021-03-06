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


#include "Errors.h"
#include "String.h"


static clsDefinition* interfaces[] = {
	&clsJAVA_IO_SERIALIZABLE
};


/* =============================================================== */
/*  AbstractMethodError                                            */
/* =============================================================== */

static clsMethod Java_java_lang_AbstractMethodError_AbstractMethodError0ID = {&clsJAVA_LANG_ABSTRACTMETHODERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_AbstractMethodError_AbstractMethodError1ID = {&clsJAVA_LANG_ABSTRACTMETHODERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};


static clsMethod* AbstractMethodError_instance_methods[] = {
	&Java_java_lang_AbstractMethodError_AbstractMethodError0ID,
	&Java_java_lang_AbstractMethodError_AbstractMethodError1ID
};

clsDefinition clsJAVA_LANG_ABSTRACTMETHODERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/AbstractMethodError", /* name */
	&clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, /* super_class */
	0xF82D59B1,                    /* name hash */
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
	sizeof(AbstractMethodError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	AbstractMethodError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ClassCircularityError                                          */
/* =============================================================== */

static clsMethod Java_java_lang_ClassCircularityError_ClassCircularityError0ID = {&clsJAVA_LANG_CLASSCIRCULARITYERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ClassCircularityError_ClassCircularityError1ID = {&clsJAVA_LANG_CLASSCIRCULARITYERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ClassCircularityError_instance_methods[] = {
	&Java_java_lang_ClassCircularityError_ClassCircularityError0ID,
	&Java_java_lang_ClassCircularityError_ClassCircularityError1ID
};

clsDefinition clsJAVA_LANG_CLASSCIRCULARITYERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ClassCircularityError", /* name */
	&clsJAVA_LANG_LINKAGEERROR,    /* super_class */
	0xEF567DBD,                    /* name hash */
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
	sizeof(ClassCircularityError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ClassCircularityError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ClassFormatError                                               */
/* =============================================================== */

static clsMethod Java_java_lang_ClassFormatError_ClassFormatError0ID = {&clsJAVA_LANG_CLASSFORMATERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ClassFormatError_ClassFormatError1ID = {&clsJAVA_LANG_CLASSFORMATERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ClassFormatError_instance_methods[] = {
	&Java_java_lang_ClassFormatError_ClassFormatError0ID,
	&Java_java_lang_ClassFormatError_ClassFormatError1ID
};

clsDefinition clsJAVA_LANG_CLASSFORMATERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ClassFormatError",  /* name */
	&clsJAVA_LANG_LINKAGEERROR,    /* super_class */
	0x5A6C5AD,                     /* name hash */
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
	sizeof(ClassFormatError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ClassFormatError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  ExceptionInInitializerError                                    */
/* =============================================================== */

static clsMethod Java_java_lang_ExceptionInInitializerError_ExceptionInInitializerError0ID = {&clsJAVA_LANG_EXCEPTIONININITIALIZERERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_ExceptionInInitializerError_ExceptionInInitializerError1ID = {&clsJAVA_LANG_EXCEPTIONININITIALIZERERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod Java_java_lang_ExceptionInInitializerError_ExceptionInInitializerError3ID = {&clsJAVA_LANG_EXCEPTIONININITIALIZERERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/Throwable;)V", 
	   0xebca81d2, 0, Java_java_lang_Throwable_Throwable3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* ExceptionInInitializerError_instance_methods[] = {
	&Java_java_lang_ExceptionInInitializerError_ExceptionInInitializerError0ID,
	&Java_java_lang_ExceptionInInitializerError_ExceptionInInitializerError1ID,
	&Java_java_lang_ExceptionInInitializerError_ExceptionInInitializerError3ID
};

clsDefinition clsJAVA_LANG_EXCEPTIONININITIALIZERERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/ExceptionInInitializerError", /* name */
	&clsJAVA_LANG_LINKAGEERROR,    /* super_class */
	0x8FC13FC6,                    /* name hash */
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
	sizeof(ExceptionInInitializerError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	ExceptionInInitializerError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  Error                                                          */
/* =============================================================== */

static clsMethod Java_java_lang_Error_Error0ID = {&clsJAVA_LANG_ERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_Error_Error1ID = {&clsJAVA_LANG_ERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod Java_java_lang_Error_Error2ID = {&clsJAVA_LANG_ERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V", 
	   0x9c9fc524, 0, Java_java_lang_Throwable_Throwable2, 0, 0, 0, NULL, /* VM internal affairs */ 2, 3, 'V'};

static clsMethod Java_java_lang_Error_Error3ID = {&clsJAVA_LANG_ERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/Throwable;)V", 
	   0xebca81d2, 0, Java_java_lang_Throwable_Throwable3, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* Error_instance_methods[] = {
	&Java_java_lang_Error_Error0ID,
	&Java_java_lang_Error_Error1ID,
	&Java_java_lang_Error_Error2ID,
	&Java_java_lang_Error_Error3ID,
};

clsDefinition clsJAVA_LANG_ERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/Error",             /* name */
	&clsJAVA_LANG_THROWABLE,       /* super_class */
	0x77176C94,                    /* name hash */
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
	sizeof(Error_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	Error_instance_methods,        /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  IncompatibleClassChangeError                                   */
/* =============================================================== */

static clsMethod Java_java_lang_IncompatibleClassChangeError_IncompatibleClassChangeError0ID = {&clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_IncompatibleClassChangeError_IncompatibleClassChangeError1ID = {&clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* IncompatibleClassChangeError_instance_methods[] = {
	&Java_java_lang_IncompatibleClassChangeError_IncompatibleClassChangeError0ID,
	&Java_java_lang_IncompatibleClassChangeError_IncompatibleClassChangeError1ID
};

clsDefinition clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/IncompatibleClassChangeError", /* name */
	&clsJAVA_LANG_LINKAGEERROR,    /* super_class */
	0x6F17F76D,                    /* name hash */
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
	sizeof(IncompatibleClassChangeError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	IncompatibleClassChangeError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  InstantiationError                                             */
/* =============================================================== */

static clsMethod Java_java_lang_InstantiationError_InstantiationError0ID = {&clsJAVA_LANG_INSTANTIATIONERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_InstantiationError_InstantiationError1ID = {&clsJAVA_LANG_INSTANTIATIONERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* InstantiationError_instance_methods[] = {
	&Java_java_lang_InstantiationError_InstantiationError0ID,
	&Java_java_lang_InstantiationError_InstantiationError1ID
};

clsDefinition clsJAVA_LANG_INSTANTIATIONERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/InstantiationError", /* name */
	&clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, /* super_class */
	0xB2A685AF,                    /* name hash */
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
	sizeof(InstantiationError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	InstantiationError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  LinkageError                                                   */
/* =============================================================== */

static clsMethod Java_java_lang_LinkageError_LinkageError0ID = {&clsJAVA_LANG_LINKAGEERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_LinkageError_LinkageError1ID = {&clsJAVA_LANG_LINKAGEERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* LinkageError_instance_methods[] = {
	&Java_java_lang_LinkageError_LinkageError0ID,
	&Java_java_lang_LinkageError_LinkageError1ID
};

clsDefinition clsJAVA_LANG_LINKAGEERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/LinkageError",      /* name */
	&clsJAVA_LANG_ERROR,           /* super_class */
	0xA8C7F637,                    /* name hash */
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
	sizeof(LinkageError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	LinkageError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NoClassDefFoundError                                           */
/* =============================================================== */

static clsMethod Java_java_lang_NoClassDefFoundError_NoClassDefFoundError0ID = {&clsJAVA_LANG_NOCLASSDEFFOUNDERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NoClassDefFoundError_NoClassDefFoundError1ID = {&clsJAVA_LANG_NOCLASSDEFFOUNDERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NoClassDefFoundError_instance_methods[] = {
	&Java_java_lang_NoClassDefFoundError_NoClassDefFoundError0ID,
	&Java_java_lang_NoClassDefFoundError_NoClassDefFoundError1ID
};

clsDefinition clsJAVA_LANG_NOCLASSDEFFOUNDERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NoClassDefFoundError", /* name */
	&clsJAVA_LANG_LINKAGEERROR,    /* super_class */
	0xC6A6EA88,                    /* name hash */
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
	sizeof(NoClassDefFoundError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NoClassDefFoundError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NoSuchFieldError                                               */
/* =============================================================== */

static clsMethod Java_java_lang_NoSuchFieldError_NoSuchFieldError0ID = {&clsJAVA_LANG_NOSUCHFIELDERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NoSuchFieldError_NoSuchFieldError1ID = {&clsJAVA_LANG_NOSUCHFIELDERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NoSuchFieldError_instance_methods[] = {
	&Java_java_lang_NoSuchFieldError_NoSuchFieldError0ID,
	&Java_java_lang_NoSuchFieldError_NoSuchFieldError1ID
};

clsDefinition clsJAVA_LANG_NOSUCHFIELDERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NoSuchFieldError",  /* name */
	&clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, /* super_class */
	0x280A90EA,                    /* name hash */
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
	sizeof(NoSuchFieldError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NoSuchFieldError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  NoSuchMethodError                                              */
/* =============================================================== */

static clsMethod Java_java_lang_NoSuchMethodError_NoSuchMethodError0ID = {&clsJAVA_LANG_NOSUCHMETHODERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_NoSuchMethodError_NoSuchMethodError1ID = {&clsJAVA_LANG_NOSUCHMETHODERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* NoSuchMethodError_instance_methods[] = {
	&Java_java_lang_NoSuchMethodError_NoSuchMethodError0ID,
	&Java_java_lang_NoSuchMethodError_NoSuchMethodError1ID
};

clsDefinition clsJAVA_LANG_NOSUCHMETHODERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/NoSuchMethodError", /* name */
	&clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR, /* super_class */
	0xA331296B,                    /* name hash */
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
	sizeof(NoSuchMethodError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	NoSuchMethodError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  OutOfMemoryError                                               */
/* =============================================================== */

static clsMethod Java_java_lang_OutOfMemoryError_OutOfMemoryError0ID = {&clsJAVA_LANG_OUTOFMEMORYERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_OutOfMemoryError_OutOfMemoryError1ID = {&clsJAVA_LANG_OUTOFMEMORYERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* OutOfMemoryError_instance_methods[] = {
	&Java_java_lang_OutOfMemoryError_OutOfMemoryError0ID,
	&Java_java_lang_OutOfMemoryError_OutOfMemoryError1ID
};

clsDefinition clsJAVA_LANG_OUTOFMEMORYERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/OutOfMemoryError",  /* name */
	&clsJAVA_LANG_VIRTUALMACHINEERROR, /* super_class */
	0x93D86076,                    /* name hash */
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
	sizeof(OutOfMemoryError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	OutOfMemoryError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  StackOverflowError                                             */
/* =============================================================== */

static clsMethod Java_java_lang_StackOverflowError_StackOverflowError0ID = {&clsJAVA_LANG_STACKOVERFLOWERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_StackOverflowError_StackOverflowError1ID = {&clsJAVA_LANG_STACKOVERFLOWERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* StackOverflowError_instance_methods[] = {
	&Java_java_lang_StackOverflowError_StackOverflowError0ID,
	&Java_java_lang_StackOverflowError_StackOverflowError1ID
};

clsDefinition clsJAVA_LANG_STACKOVERFLOWERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/StackOverflowError", /* name */
	&clsJAVA_LANG_VIRTUALMACHINEERROR, /* super_class */
	0x813F1272,                    /* name hash */
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
	sizeof(StackOverflowError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	StackOverflowError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  UnknownError                                                   */
/* =============================================================== */

static clsMethod Java_java_lang_UnknownError_UnknownError0ID = {&clsJAVA_LANG_UNKNOWNERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_UnknownError_UnknownError1ID = {&clsJAVA_LANG_UNKNOWNERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* UnknownError_instance_methods[] = {
	&Java_java_lang_UnknownError_UnknownError0ID,
	&Java_java_lang_UnknownError_UnknownError1ID
};

clsDefinition clsJAVA_LANG_UNKNOWNERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/UnknownError",      /* name */
	&clsJAVA_LANG_VIRTUALMACHINEERROR, /* super_class */
	0xC27F03D2,                    /* name hash */
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
	sizeof(UnknownError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	UnknownError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  UnsatisfiedLinkError                                           */
/* =============================================================== */

static clsMethod Java_java_lang_UnsatisfiedLinkError_UnsatisfiedLinkError0ID = {&clsJAVA_LANG_UNSATISFIEDLINKERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_UnsatisfiedLinkError_UnsatisfiedLinkError1ID = {&clsJAVA_LANG_UNSATISFIEDLINKERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* UnsatisfiedLinkError_instance_methods[] = {
	&Java_java_lang_UnsatisfiedLinkError_UnsatisfiedLinkError0ID,
	&Java_java_lang_UnsatisfiedLinkError_UnsatisfiedLinkError1ID
};

clsDefinition clsJAVA_LANG_UNSATISFIEDLINKERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/UnsatisfiedLinkError", /* name */
	&clsJAVA_LANG_LINKAGEERROR,    /* super_class */
	0xADA53869,                    /* name hash */
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
	sizeof(UnsatisfiedLinkError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	UnsatisfiedLinkError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  UnsupportedClassVersionError                                   */
/* =============================================================== */

static clsMethod Java_java_lang_UnsupportedClassVersionError_UnsupportedClassVersionError0ID = {&clsJAVA_LANG_UNSUPPORTEDCLASSVERSIONERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_UnsupportedClassVersionError_UnsupportedClassVersionError1ID = {&clsJAVA_LANG_UNSUPPORTEDCLASSVERSIONERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* UnsupportedClassVersionError_instance_methods[] = {
	&Java_java_lang_UnsupportedClassVersionError_UnsupportedClassVersionError0ID,
	&Java_java_lang_UnsupportedClassVersionError_UnsupportedClassVersionError1ID
};

clsDefinition clsJAVA_LANG_UNSUPPORTEDCLASSVERSIONERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/UnsupportedClassVersionError", /* name */
	&clsJAVA_LANG_CLASSFORMATERROR, /* super_class */
	0x5B300BE7,                    /* name hash */
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
	sizeof(UnsupportedClassVersionError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	UnsupportedClassVersionError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};


/* =============================================================== */
/*  VirtualMachineError                                            */
/* =============================================================== */

static clsMethod Java_java_lang_VirtualMachineError_VirtualMachineError0ID = {&clsJAVA_LANG_VIRTUALMACHINEERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "()V", 
	   0x6C5E9907, 0, Java_java_lang_Throwable_Throwable0, 0, 0, 0, NULL, /* VM internal affairs */ 0, 1, 'V'};

static clsMethod Java_java_lang_VirtualMachineError_VirtualMachineError1ID = {&clsJAVA_LANG_VIRTUALMACHINEERROR, ACC_PUBLIC|ACC_NATIVE, "<init>", "(Ljava/lang/String;)V", 
	   0xC68DB38D, 0, Java_java_lang_Throwable_Throwable1, 0, 0, 0, NULL, /* VM internal affairs */ 1, 2, 'V'};

static clsMethod* VirtualMachineError_instance_methods[] = {
	&Java_java_lang_VirtualMachineError_VirtualMachineError0ID,
	&Java_java_lang_VirtualMachineError_VirtualMachineError1ID
};

clsDefinition clsJAVA_LANG_VIRTUALMACHINEERROR = {
	VM_CLASS_MINOR_VERSION,        /* minor_version */
	VM_CLASS_MAJOR_VERSION,        /* major_version */
	"java/lang/VirtualMachineError", /* name */
	&clsJAVA_LANG_ERROR,           /* super_class */
	0x255DA238,                    /* name hash */
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
	sizeof(VirtualMachineError_instance_methods) / sizeof(clsMethod*), /* instance_methods_count */
	VirtualMachineError_instance_methods, /* instance_methods */
	0,                             /* attributes_count */
	NULL,                          /* attributes */
	0,                             /* data size of this class only */
	0,                             /* total data size is computed in vmDefineClass() */
	NULL                           /* finalize() method */
};

