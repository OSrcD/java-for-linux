package com.opendevel.udp;


import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class DatagramSockeServerDemo {

	public static void main(String[] args) {
		new Thread(()-> {
			
			try {
				DatagramSocket ds = new DatagramSocket(8080);
				FileOutputStream fis = new FileOutputStream("datagramSocketFIS.png");
				BufferedOutputStream bos = new BufferedOutputStream(fis);
			
				byte [] b = new byte [1024];
				
				while(true) {
					
					DatagramPacket dp = new DatagramPacket(b,b.length);
					ds.receive(dp);
					int len = dp.getLength();										
					
						if(len==3) {
							String flag = new String(b, 0, 3);
							if(flag.equals("bye")) {
								break;
							}
						}
						
						bos.write(b,0,len);
						System.out.println("�������");
					
				}
				
				
				
				ds.close();
				fis.close();
				bos.close();
				
				
			} catch (SocketException e) {
				e.printStackTrace();
			}catch(FileNotFoundException e) {
				e.printStackTrace();
			}catch (IOException e) {
				
			}
			
			
			
			
			
		}).start();
		
		
		
	}

}
