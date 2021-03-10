package com.imooc.charstream;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class ReaderDemo {

	public static void main(String[] args) {
		try {
			FileInputStream fis = new FileInputStream("imooc.txt");
			InputStreamReader isr = new InputStreamReader(fis);
			FileOutputStream fos = new FileOutputStream("imooc1.txt");
			OutputStreamWriter osw = new OutputStreamWriter(fos);
			BufferedReader br = new BufferedReader(isr);
			BufferedWriter bw = new BufferedWriter(osw);
			int n=0;
			char [] cbuf = new char[10];
//			while((n=isr.read())!=-1) {
//				System.out.print((char)n);
//			}
			
//			while((n=isr.read(cbuf))!=-1) {
//				String s = new String(cbuf,0,n);
//				System.out.print(s);
//			
//			} 
			
			while((n=br.read(cbuf))!=-1) {
				//String s = new String(cbuf,0,n);
				bw.write(cbuf,0,n);
				bw.flush();
			}
			fis.close();
			fos.close();
			isr.close();
			osw.close();
			br.close();
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
