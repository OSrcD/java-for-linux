package com.opendev.common;

import com.sun.jna.Library;
import com.sun.jna.Memory;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.IntByReference;

public interface ReadMemoryInterface extends Library {

    ReadMemoryInterface readMemoryInterface = Native.load("kernel32.dll", ReadMemoryInterface.class);

    public Pointer openProcess(int dwDesiredAccess, boolean bInheritHandle, int dwProcessId);

    public boolean ReadProcessMemory(Pointer hProcess, int lpBaseAddress, Memory lpBuffer, int nSize, IntByReference lpNumberOfBytesRead);


}
