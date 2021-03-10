package com.opendevel.get;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class CtrlGetques {
	static String urlString = "http://www.51work6.com/service/mynotes/WebService.php?"
			+"email=opendevel@outlook.com&type=JSON&action=query";
	public static void main(String[] args) throws IOException {
		BufferedReader br =null;
		HttpURLConnection conn=null;
		
		try {
			URL reqURL = new URL(urlString);
			conn = (HttpURLConnection)reqURL.openConnection();
			System.out.println(conn);
			conn.setRequestMethod("GET");
			InputStream is = conn.getInputStream();
			InputStreamReader isr = new InputStreamReader(is,"utf-8");
			br = new BufferedReader(isr);
			StringBuilder sb =new StringBuilder();
			String line = br.readLine();
			
			
			while(line!=null) {
				sb.append(line);
				line=br.readLine();
			}
			
			
			System.out.println(sb);
			
			
		} catch (MalformedURLException e) {
			e.printStackTrace();
		}finally {
			if(conn!=null) {
				conn.disconnect();
			}
			if(br!=null) {
				br.close();
			}
		}
		
	}

}
