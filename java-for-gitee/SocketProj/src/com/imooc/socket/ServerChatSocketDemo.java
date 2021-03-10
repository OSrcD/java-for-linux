package com.imooc.socket;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerChatSocketDemo {

	public static void main(String[] args) {
		Thread td = new Thread(()->{	
			
			
			
			try {
				System.out.println("server staring");
				ServerSocket ss = new ServerSocket(8085);
				Socket socket = ss.accept();
				DataInputStream dis = new DataInputStream(socket.getInputStream());
				DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
				BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
				
				
				while(true) {
					String readData = dis.readUTF();
					System.out.println("rev message:"+readData);
					System.out.println("«Î ‰»Îƒ⁄»›");
					String keyInputData =  br.readLine();
					if(keyInputData.equals("bye")) {
						break;
					}
					dos.writeUTF(keyInputData);
					dos.flush();
				}
				dos.close();
				dis.close();
				br.close();
				ss.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
	
			
	
		});
		td.start();
	}
}
	
