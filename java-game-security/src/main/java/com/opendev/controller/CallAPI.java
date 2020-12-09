package com.opendev.controller;

import com.opendev.common.ReadMemoryInterface;
import com.sun.jna.Memory;
import com.sun.jna.Pointer;

import java.util.Scanner;

public class CallAPI {
    public static void main(String[] args) {
        System.out.println("请输入进程的PID");
        Scanner scanner = new Scanner(System.in);
        int PID = scanner.nextInt();
        Pointer handle = null;
        System.out.println("请输入您要读取的内存地址");
        String address = scanner.next();
        Memory memory = new Memory(4);
        handle = ReadMemoryInterface.readMemoryInterface.openProcess(2035711, false, PID);

        if(handle != null){
            while(true){
                boolean flag = ReadMemoryInterface.readMemoryInterface.ReadProcessMemory(handle, Integer.valueOf(address, 16), memory, 4, null);
                if (!flag) {
                    System.out.println("读取内存地址失败");
                    return;
                }
                System.out.println("读取内存地址" + address + "成功:" + memory.getInt(0));

            }
        }

        System.out.println("获取游戏进程句柄失败");


    }
}
