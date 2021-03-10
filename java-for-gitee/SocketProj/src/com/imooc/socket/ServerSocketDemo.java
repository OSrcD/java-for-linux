package com.imooc.socket;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerSocketDemo {
	public static void main(String[] args) {
		try {
			System.out.println("服务器正在运行");
			ServerSocket ss = new ServerSocket(8081);
			Socket socket = ss.accept();
			
			BufferedInputStream bis = new BufferedInputStream(socket.getInputStream());
			FileOutputStream fos = new FileOutputStream("upload.png");
	
			byte [] bit = new byte[1024];
			int n=bis.read(bit);
			while(n!=-1) {
				fos.write(bit,0,n);
				System.out.println(n);
				fos.flush();
				n = bis.read(bit);
			
			}
			System.out.println("接收完成");
			ss.close();
			socket.close();
			bis.close();
			fos.close();
			
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
