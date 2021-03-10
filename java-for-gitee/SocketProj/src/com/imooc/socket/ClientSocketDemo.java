package com.imooc.socket;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.ConnectException;
import java.net.Socket;
import java.net.UnknownHostException;

public class ClientSocketDemo {
	public static void main(String[] args) {
		System.out.println("客户端运行...");
		try {
			Socket socket = new Socket("127.0.0.1", 8081);
			BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());
			FileInputStream fis = new FileInputStream("Gameovers.png");
			BufferedInputStream bis = new BufferedInputStream(fis);
			
			byte [] b = new byte[1024];
			int n=0;
			while((n = bis.read(b))!=-1) {
				bos.write(b, 0, n);
				System.out.println(n);
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			System.out.println("上传成功！");
			bis.close();
			bos.close();
			fis.close();
			socket.close();
		} catch (ConnectException e) {
			System.out.println("服务器未启动");
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
	}
}
