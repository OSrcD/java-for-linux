package game;

import java.awt.Graphics;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JPanel;

/**
 * java是单继承 多实现接口
 * 
 * 这个累中需要实现的东西为：
 * 1.能绘画 所有的元素
 * 	可以访问所有的元素 -> 有所有元素对象的 引用
 * 	必须继承 于 JPanel
 * 2.能自己进行不停的刷新
 * 	多线程->thread 直接实现多线程的 接口类 Runnable
 *
 *面向对象思想 -> 面向接口编程
 */
public class MyJPanel extends JPanel implements Runnable{
//	定义元素对象 
	List<ElementShowInerface> list = null;//是定义的一组数据  问题：主角控制的是一个人物对象，那么是否需要放到集合
//	定义一个有序集合 <object> 是泛型 -> list中 只可以 存储 object类型 或者 子类 的 实体对象
//	List<ElementShowInterface> starList = null;
	
	public MyJPanel(){
		init();
	}
//	可以让子类 重写
	protected void init(){
		list = new ArrayList<ElementShowInerface>();
//		starList = new ArrayList<ElementShowInterface>();
//		每个对象的 生成   这个生成不应该在这里，应该在资源加载器中
		list.add(GameElement.createGameElement());
	}
	public void paint(Graphics g) {
		super.paint(g);
//		用于 专门显示元素
		showListElement(list,g);
//		showListElement(starList,g);
	}
//	可以显示所有的集合
	public void showListElement(List<ElementShowInerface> list,Graphics g){
//		for(int i=0;i<list.size();i++){
//			ElementShowInterface element = list.get(i);
//		}
		for(ElementShowInerface element : list){
			element.show(g);
		}
		
		
	}
	@Override	//thread里面写的
	public void run() {//专门用来进行 刷新界面的
		while(true){
			repaint();//重新绘画
//			测试代码
			for(ElementShowInerface element:list){
				element.move();
			}
			
			try {
				Thread.sleep(45);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
}
