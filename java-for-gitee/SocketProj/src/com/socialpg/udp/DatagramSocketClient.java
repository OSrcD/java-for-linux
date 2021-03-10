package com.opendevel.udp;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class DatagramSocketClient {

	public static void main(String[] args) {
		System.out.println("�ͻ�����������'");
		new Thread(()->{
			
		
			try {
				DatagramSocket ds = new DatagramSocket();
				FileInputStream fis = new FileInputStream("map.png");
				BufferedInputStream bis = new BufferedInputStream(fis);
				InetAddress iadrr = InetAddress.getByName("localhost");
				
				int n =0;
				byte [] b = new byte[1024];
				while((n=bis.read(b))!=-1) {
					DatagramPacket dp = new DatagramPacket(b,0,n,iadrr,8080);
					ds.send(dp);
				}
				
				
				DatagramPacket dp = new DatagramPacket("bye".getBytes(),0,3,iadrr,8080);
				ds.send(dp);
				System.out.println("�������");
				
				
				
			} catch (SocketException e) {
				e.printStackTrace();
			}catch (FileNotFoundException e) {
				
			}catch(IOException e) {
				
			}
			
			
		}).start();
	}

}
