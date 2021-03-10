package com.imooc.set;

import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;

public class DictionaryDemo   {
	
	public static void main(String[] args) {
		Map<String,String> animal = new HashMap<String,String>();
		System.out.println("���������鵥�ʶ�Ӧ��ע�ͣ�����ŵ�HashMap��");
		Scanner console= new Scanner(System.in);
		int i=0;
		while(i<3) {
			System.out.println("������keyֵ�����ʣ���");
			String key = console.next();
			System.out.println("������valueֵ��ע�ͣ�:");
			String value = console.next();
			animal.put(key, value);
			i++;
		}
		
		System.out.println("*****************************");
		System.out.println("ʹ�õ�����������е�value");
		Iterator<String> it = animal.values().iterator();
		while(it.hasNext()) {
			System.out.print(it.next()+"  ");
		}
		System.out.println();
		System.out.println("*****************************");
		
		System.out.println("ͨ��entrySet�����õ�key-value��");
		
		Set<Entry<String, String>> entrySet = animal.entrySet();
		for(Entry<String,String> entry:entrySet) {
			
			System.out.print(entry.getKey()+"-");
			System.out.println(entry.getValue());
			
		}
		
		System.out.println();
		System.out.println("*****************************");
		System.out.println("������Ҫ���ҵĵ���");
		String strSearch = console.next();
		Set<String> keySet = animal.keySet();
		
		boolean flag =false;
		for(String key:keySet) {
			if(strSearch.equals(key)) {
				System.out.println("�ҵ��ˣ�"+"��ֵ��Ϊ��"+key+"-"+animal.get(key));
				flag=true;
				break;
			}
		} 
		if(!flag) {
			System.out.println("����ʧ��");
		}
	}

}
