package com.imooc.thread;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

public class Test {
    public static void main(String[] args) {
        Callable<String> call = new TirdThread();

        FutureTask<String> ft = new FutureTask<>(call);

        Thread th = new Thread(ft);
        th.start();

        try{
            System.out.println(ft.get());
        }catch(InterruptedException | ExecutionException e){
            e.printStackTrace();
        }

    }
}
