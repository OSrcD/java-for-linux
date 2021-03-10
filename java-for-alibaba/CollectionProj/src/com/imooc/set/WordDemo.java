package com.imooc.set;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
public class WordDemo {

	public static void main(String[] args) {
		Set set = new HashSet();
		 set.add("blue");
		 set.add("red");
		 set.add("black");
		 set.add("yellow");
		 set.add("white");
		 
		 System.out.println("集合中的元素为：");
		 
		Iterator it =  set.iterator();
	
		while(it.hasNext()) {
			System.out.print(it.next()+" ");
		}
		System.out.println();
//		set.add("grenn");
		set.add("white");
		it = set.iterator();
		System.out.println("********************");
		System.out.println("插入重复后的输出结果为：");
		while(it.hasNext()) {
			System.out.print(it.next()+" ");
		}
		
		
	}

}
