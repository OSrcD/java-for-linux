package com.imooc.queue;

public class Queue {
    private int n;
    private boolean flag = false;

    public synchronized int get(){
        if(!flag){
            try {
                wait(); // Object的方法
            }catch (InterruptedException e){
                e.printStackTrace();
            }
        }
        System.out.println("消费："+n);
        flag = false;
        notifyAll();
        return n;
    }

    public synchronized void set(int n){
        if(flag){
            try{
                wait();
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        this.n = n;
        System.out.println("生产："+ n);
        flag = true;
        notifyAll();
    }
}
