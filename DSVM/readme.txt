DS Virtual Machine Lite
=======================
Copyright (c) 2006, 2007 Dusan Stastny


DS Virtual Machine (DSVM) is an open source implementation of the Java
Virtual Machine, but it IS NOT Java (it is not certified by Sun).
DS Virtual Machine is implementation publicly available specifications.
See http://developservice.cz/ for more informations.


Note:
-----
This is lite (open source) version of the DSVM, but you can download full
(binary only) version of the DSVM too. Full version of the DSVM contains more
Java core classes, but it is distributed as freeware for noncommercial
usage. With full version you can run for example Rhino or SWT.


Features:
---------

- it is open source
- it is small, simple and well-documented
- it is written in C
- it runs on Win32 platform
- it is tested with MS Visual Studio only
- it uses native (operating system) threads
- it uses reference-counting garbage collector and/or accurate mark-sweep garbage collector
- it interprets and executes java byte codes (not contains any JIT compiler)
- it supports JNI version 1.2
- it contains some Java core classes. You can use Java class libraries from
  OpenJDK (http://openjdk.java.net), ClassPath (http://www.gnu.org/software/classpath)
  or Harmony project (http://harmony.apache.org)


Usage of the DSVM:
-------------------

DS Virtual Machine Lite 1.00, Copyright (c) 2006-2007 Dusan Stastny
This tool launches a Java application.

Using:   dsvm [options] class_file [arguments]

Options:
    -classpath path      class path entries separated by semicolons (;)
    -cp path             class path entries separated by semicolons (;)
    -Dproperty=value     set a system property value
    -Xproperty=value     set a VM specific property value
    -help                this help

Arguments:
    arguments passed to the main function


Licensing information:
----------------------
DS Virtual Machine Lite is free software released under the terms of the GNU
General Public License Version 2 (GPLv2) as published by the Free Software Foundation.
See the copying file for more details.


WARNING
--------

This software is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
license for more details.


Dusan Stastny                   stastny@developservice.cz
Jizni Svahy 804                 http://developservice.cz/
330 27 Vejprnice
Czech Republic - EUROPE
