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
				System.out.println("�ͻ�����������");
				while(true) {
				
					System.out.println("������������Ϣ");
					String InputData = br.readLine();
					
					dos.writeUTF(InputData);
					if(InputData.equals("bye"))break;
					System.out.println("���ڷ���");
					dos.flush();
					System.out.println("�������");

					String readChatComment = dis.readUTF();
					System.out.println("����������������Ϊ:"+readChatComment);
					
					
					
					
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
