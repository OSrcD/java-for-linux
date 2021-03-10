package com.imooc.queue;

public class Test {

    public static void main(String[] args) {
        Queue queue = new Queue();

        new Thread(new Producer(queue)).start();

        new Thread(new Comsumer(queue)).start();
    }

}
