package com.opendevel.get;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

public class Getrequest {

	public static void main(String[] args) {
		String url="https://dnf.qq.com/";
		
		URL reqURL;
		
		try {
			reqURL = new URL(url);
			
		} catch (MalformedURLException e) {
			e.printStackTrace();
			return;
		}
		
		try {
			InputStream is = reqURL.openStream();
			InputStreamReader isr = new InputStreamReader(is,"UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuffer sbf = new StringBuffer();
			String line = br.readLine();
			
			while(line !=null) {
				sbf.append(line);
				sbf.append('\n');
				line = br.readLine();
			}
			
			System.out.println(sbf);
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
		
	}

}
