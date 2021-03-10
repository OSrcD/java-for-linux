package com.imooc.file;

import java.io.File;
import java.io.FileDescriptor;
import java.io.IOException;
import java.util.Scanner;

public class FileDemo {

	public static void main(String[] args) {
//		 File file = new File("E:\\my_JavaIO\\io\\score.txt");
//		 File file  = new File("E:\\my_JavaIO","\\io\\score.txt");
		File file = new File("E:\\my_JavaIO");
		File file1 = new File(file, "\\io\\score");
		System.out.println("是否是目录：" + file1.isDirectory());
		System.out.println("是否是文件：" + file1.isFile());
		File file2 = new File("E:\\my_JavaIO\\set\\HashSet");
		if (!file2.exists()) {
			file2.mkdirs();

		}

		if (!file1.exists()) {
			try {
				file1.createNewFile();
			} catch (IOException e) {

			}
		}
		
		
	 
	}

}
