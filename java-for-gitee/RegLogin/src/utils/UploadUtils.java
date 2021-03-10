package utils;

import java.util.UUID;

public class UploadUtils {
	/**
	 * ����Ψһ���ļ���:
	 */
	
	
	public static String getUUIDFIleName(String fileName) {
		
		int idx =  fileName.indexOf(".");
		String extension = fileName.substring(idx);
		String uuidFileName= UUID.randomUUID().toString().replace("-", "")+extension;
		
		return uuidFileName;
	}
	
	public static void main(String[] args) {
		System.out.println(getUUIDFIleName("1.jpg"));
	}
}
