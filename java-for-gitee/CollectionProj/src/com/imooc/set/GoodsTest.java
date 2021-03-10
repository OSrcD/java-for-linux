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
		
		System.out.println("������������Ʒ��Ϣ:");
		int i=0;
		while(i<3) {
			System.out.println("�������"+(i+1)+"����Ʒ��Ϣ��");
			System.out.println("��������Ʒ��ţ�");
			String goodsId = console.next();
			if(goodsMap.containsKey(goodsId)) {
				System.out.println("����Ʒ����Ѿ�����!����������");
				continue;
			}
			System.out.println("��������Ʒ����");
			String goodsName =console.next();
			System.out.println("��������Ʒ�۸�");
			double goodsPrice=0;
			try {
			 goodsPrice = console.nextDouble();
			
			}catch(InputMismatchException e) {
				System.out.println("��Ʒ�۸��ʽ����ȷ������������'");
				console.next();
				continue;
			}
			Goods goods = new Goods(goodsId,goodsName,goodsPrice);
			goodsMap.put(goodsId, goods);
			i++;
		}
		
		
		System.out.println("��Ʒ��ȫ����ϢΪ��");
		Iterator <Goods> itGoods = goodsMap.values().iterator();
		while(itGoods.hasNext()) {
			System.out.println(itGoods.next());
		}
		
		
		
		
		
		
	}

}
