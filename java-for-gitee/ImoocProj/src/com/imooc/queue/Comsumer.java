package com.imooc.queue;

public class Comsumer implements Runnable{

    private Queue queue;

    public Comsumer(Queue queue){
        this.queue = queue;
    }


    @Override
    public void run(){
        while(true){
            this.queue.get();
            try{
                Thread.sleep(1000);
            }catch(InterruptedException e){
                e.printStackTrace();
            }

        }
    }
}
