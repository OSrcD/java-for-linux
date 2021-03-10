package com.imooc.file;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class FileInputDemo2 {

	public static void main(String[] args) {
		try {
			FileInputStream fis = new FileInputStream("E:\\my_JavaIO\\imooc.txt");
			byte [] b = new byte[100];
			fis.read(b,100,5);
			System.out.println(new String(b));
			
		
			fis.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
