package com.imooc.file;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileOutpoutDemo1 {

	public static void main(String[] args) {
		 try {
			FileOutputStream fos = new FileOutputStream("happycopy.gif");
			FileInputStream fis = new FileInputStream("happy.gif");
			int n=0;
			byte [] b = new byte[1024];
			while((n=fis.read(b))!=-1) {
				fos.write(b,0,n); 
				System.out.println(11);
			}
			
			fis.close();
			fos.close();
			
		 } catch (FileNotFoundException e) {
			e.printStackTrace();
		}catch(IOException e) {
			e.printStackTrace();
		}
		 
	}

}
