package com.opendevel.get;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class Downloader {

	private static String urlString ="http://120.77.47.215/wp-content/uploads/2018/11/1537284444720.mp4?_=3";
	public static void main(String[] args) throws IOException {
		download();
	}
	
	public static void download() throws IOException {
		HttpURLConnection conn = null;
		
		URL reqURL  = new URL(urlString);
		conn = (HttpURLConnection)reqURL.openConnection();
		
		InputStream is = conn.getInputStream();
		BufferedInputStream bin = new BufferedInputStream(is);
		OutputStream os = new  FileOutputStream("download.mp4");
		BufferedOutputStream bout = new BufferedOutputStream(os);
		byte [] buffer = new byte[1024];
		int bytesRead = bin.read(buffer);
		while(bytesRead !=-1) {
			System.out.println("*********");
			bout.write(buffer, 0, bytesRead);
			bytesRead = bin.read(buffer);
			
		}
		System.out.println("�������");
	}

}
