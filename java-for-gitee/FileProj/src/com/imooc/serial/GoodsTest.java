package com.imooc.serial;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class GoodsTest {

	public static void main(String[] args) {
		//对对象进行读取
		Goods goods1 = new Goods("gd001","电脑",3000);
		try {
			FileOutputStream fo = new FileOutputStream("imooc.txt");
			ObjectOutputStream oos = new ObjectOutputStream(fo);
			FileInputStream fs = new FileInputStream("imooc.txt");
			ObjectInputStream ois = new ObjectInputStream(fs);
			
			oos.writeObject(goods1);
			oos.writeBoolean(true);
			oos.flush();
			
			try {
				Goods goods =(Goods)ois.readObject();
				System.out.println(goods);
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
			System.out.println(ois.readBoolean());
			fo.close();
			oos.close();
			fs.close();
			ois.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
