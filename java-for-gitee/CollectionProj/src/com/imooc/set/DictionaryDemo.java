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
		System.out.println("请输入三组单词对应的注释，并存放到HashMap中");
		Scanner console= new Scanner(System.in);
		int i=0;
		while(i<3) {
			System.out.println("请输入key值（单词）：");
			String key = console.next();
			System.out.println("请输入value值（注释）:");
			String value = console.next();
			animal.put(key, value);
			i++;
		}
		
		System.out.println("*****************************");
		System.out.println("使用迭代器输出所有的value");
		Iterator<String> it = animal.values().iterator();
		while(it.hasNext()) {
			System.out.print(it.next()+"  ");
		}
		System.out.println();
		System.out.println("*****************************");
		
		System.out.println("通过entrySet方法得到key-value：");
		
		Set<Entry<String, String>> entrySet = animal.entrySet();
		for(Entry<String,String> entry:entrySet) {
			
			System.out.print(entry.getKey()+"-");
			System.out.println(entry.getValue());
			
		}
		
		System.out.println();
		System.out.println("*****************************");
		System.out.println("请输入要查找的单词");
		String strSearch = console.next();
		Set<String> keySet = animal.keySet();
		
		boolean flag =false;
		for(String key:keySet) {
			if(strSearch.equals(key)) {
				System.out.println("找到了！"+"键值对为："+key+"-"+animal.get(key));
				flag=true;
				break;
			}
		} 
		if(!flag) {
			System.out.println("查找失败");
		}
	}

}
