package com.imooc.file;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileOutputDemo {

	public static void main(String[] args) {
	 FileOutputStream fos ;
	 FileInputStream fis;
	 try {
		fos = new FileOutputStream("E:\\my_JavaIO\\imooc.txt",true);
		fos.write(50);
		fos.write('a');
		fis = new FileInputStream("E:\\my_JavaIO\\imooc.txt");
		System.out.println(fis.read());
		System.out.println((char)fis.read());
		fos.close();
		fis.close();
		
	 } catch (FileNotFoundException e) {
		e.printStackTrace();
	}catch(IOException e) {
		e.printStackTrace();
	}
	 
	 
	 
	 
	}

}
