package MyTest;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class MyTestJVM {

	public static void main(String[] args) {
		
		List<String> arrayList = new ArrayList<>();
		try {
			FileOutputStream fos = new FileOutputStream("E:\\JVM.txt",true);	
			OutputStreamWriter osw = new OutputStreamWriter(fos);
			BufferedWriter   buw = new BufferedWriter(osw);
			int i=0;
			while(i<=10000000) {	
				MyTest mt = new MyTest();
				
				arrayList.add(mt.toString());
				
			
			
				i++;
				System.out.println(i);
			}
			
			Collections.sort(arrayList);
			for(String g:arrayList) {
				buw.write(g);
				buw.newLine();
				System.out.println(g);
			}
			buw.flush();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}catch(IOException e) {
			
		}
		
	
	}

}
