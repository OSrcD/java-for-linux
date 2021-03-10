package com.imooc.bank;

public class Test {
    public static void main(String[] args) throws InterruptedException {
        Bank bank = new Bank("1001",1000);

        SaveAccount sa = new SaveAccount(bank);
        DrawAccount da = new DrawAccount(bank);
        Thread save = new Thread(sa);
        Thread draw = new Thread(da);
        save.start();


        draw.start();
        save.yield();
        try{

            draw.join();

            save.join();


        }catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.println(bank);
    }
}
