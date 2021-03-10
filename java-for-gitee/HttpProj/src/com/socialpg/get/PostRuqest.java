package com.opendevel.get;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class PostRuqest {
	static final String URLSTRING = "http://www.51work6.com/service/mynotes/WebService.php";
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = null;
		HttpURLConnection conn=null;
		
		URL reqURL = new URL(URLSTRING);
		conn  = (HttpURLConnection) reqURL.openConnection();
		conn.setRequestMethod("POST");
		conn.setDoOutput(true);
		
		String param  = String.format("email=%s&type=%s&action=%s","opendevel@outlook.com","JSON","query");
		DataOutputStream dStream = new DataOutputStream(conn.getOutputStream());
		dStream.writeBytes(param);
		dStream.close();
		
		InputStream is = conn.getInputStream();
		InputStreamReader isr = new InputStreamReader(is,"utf-8");
		br = new BufferedReader(isr);
		StringBuilder sb = new StringBuilder();
		String line = br.readLine();
		
		while(line!=null) {
			sb.append(line);
			line=br.readLine();
		}
		conn.disconnect();
		br.close();
		System.out.println(sb);
	}

}
