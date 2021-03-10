package com.imooc.set;

import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class GoodsTest {

	public static void main(String[] args) {
		Scanner console = new Scanner(System.in);
		Map<String,Goods> goodsMap = new HashMap<String,Goods>();
		
		System.out.println("请输入三条商品信息:");
		int i=0;
		while(i<3) {
			System.out.println("请输入第"+(i+1)+"条商品信息：");
			System.out.println("请输入商品编号：");
			String goodsId = console.next();
			if(goodsMap.containsKey(goodsId)) {
				System.out.println("该商品编号已经存在!请重新输入");
				continue;
			}
			System.out.println("请输入商品名称");
			String goodsName =console.next();
			System.out.println("请输入商品价格");
			double goodsPrice=0;
			try {
			 goodsPrice = console.nextDouble();
			
			}catch(InputMismatchException e) {
				System.out.println("商品价格格式不正确，请重新输入'");
				console.next();
				continue;
			}
			Goods goods = new Goods(goodsId,goodsName,goodsPrice);
			goodsMap.put(goodsId, goods);
			i++;
		}
		
		
		System.out.println("商品的全部信息为：");
		Iterator <Goods> itGoods = goodsMap.values().iterator();
		while(itGoods.hasNext()) {
			System.out.println(itGoods.next());
		}
		
		
		
		
		
		
	}

}
