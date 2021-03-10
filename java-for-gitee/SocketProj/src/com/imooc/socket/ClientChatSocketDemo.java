package com.imooc.socket;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

public class ClientChatSocketDemo {

	public static void main(String[] args) {
		new Thread(()-> {
			
			try {
				Socket ClientSocket;
				ClientSocket = new Socket("127.0.0.1", 8085);
				DataInputStream dis = new DataInputStream(ClientSocket.getInputStream());
				DataOutputStream dos = new DataOutputStream(ClientSocket.getOutputStream());
				BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				System.out.println("客户端正在连接");
				while(true) {
				
					System.out.println("请输入聊天信息");
					String InputData = br.readLine();
					
					dos.writeUTF(InputData);
					if(InputData.equals("bye"))break;
					System.out.println("正在发送");
					dos.flush();
					System.out.println("发送完成");

					String readChatComment = dis.readUTF();
					System.out.println("服务器发来的内容为:"+readChatComment);
					
					
					
					
				}
				dis.close();
				dos.close();
				br.close();
				ClientSocket.close();
			} catch (UnknownHostException e1) {
				e1.printStackTrace();
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}).start();
		
		
		
		
		
		
		
	
	}

}
