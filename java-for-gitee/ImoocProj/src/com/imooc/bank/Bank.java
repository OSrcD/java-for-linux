package com.imooc.bank;

public class Bank {
    private  String account;
    private  int balance;

    public Bank(String account, int balance) {
        this.account = account;
        this.balance = balance;
    }

    public String getAccount() {
        return account;
    }

    public  void setAccount(String account) {
        this.account = account;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    @Override
    public String toString() {
        return "Bank{" +
                "account='" + account + '\'' +
                ", balance=" + balance +
                '}';
    }

    public synchronized void saveAccount(){
        int balance = getBalance();

        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            e.printStackTrace();
        }

        balance+=100;
        setBalance(balance);
        System.out.println("存款后的账户余额为：" + balance);

    }

    public void drawAccount(){
        synchronized(this) {
            int balance = getBalance();

            balance = balance - 200;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            setBalance(balance);
            System.out.println("取款后的账户余额为：" + balance);
        }
    }

}
