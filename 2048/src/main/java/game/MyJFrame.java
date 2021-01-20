package game;

import java.awt.event.KeyListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class MyJFrame extends JFrame{
	/**
	 * 1.窗体自己的设置：继承与JFrame 类 成为一个窗体。所有设置都可以写在 构造方法中
	 * 2.面板等加载:1.面板本身是一个对象，需要传入才可以加载 2.面板本身也需要多次刷新，最好能记录一个引用
	 * 3.监听的加载
	 * 4.显示窗体:独立的方法 showFrame()
	 */
	private JPanel jPanel;
	
	public MyJFrame(){//默认构造方法  无参构造
		
//		super();  这句话隐藏的  调用父类的构造方法
//		建议，最好不要在构造方法中 写太多的初始化，除非这个初始化不需要改变
		init();//这个方法是用来做初始化的：因为构造方法不可以被继承和重写，而普通方法可以
	}
//	受保护的方法 同包或子类 才可以访问，子类也可以就行重写(多态的一种方式)
	protected void init(){
		setTitle("2048");
		setSize(400,430);//高度要算上 title的高度
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setResizable(true);
		setLocationRelativeTo(null);
	
	}
	public void addJPanel(JPanel jPanel){
		this.jPanel=jPanel;
		add(this.jPanel);//窗体添加 面板 jf.add(jp)
	}
	
//	测试方法
//	public static void main(String[] args) {
//		MyJFrame jf=new MyJFrame();
//		jf.addListener("aaa","bbb","ccc");//可以一次性传入多个 监听对象
//	}
	
	
//	现在只是添加一个监听 基本的监听有3个  对象 instanceof 类(接口) 
	public void addListener(Object... listeners){// Object... objects 可变长参数
//		addKeyListener(listener);//是父类的方法
		for(Object listener : listeners){
			if(listener instanceof KeyListener){//键盘监听
//				如果是listener是 KeyListener 的实体对象 就 强制类型转换后 传入到键盘监听中
				addKeyListener((KeyListener)listener);
			}
			if(listener instanceof MouseListener){//鼠标监听
				addMouseListener((MouseListener)listener);
			}
			if(listener instanceof MouseMotionListener){//鼠标移动监听
				addMouseMotionListener((MouseMotionListener)listener);
			}
			
		}
	}
	
	
//	显示窗体的方法;后面还会加入多线程
	public void showFrame(){
		setVisible(true);
		if(jPanel instanceof Runnable){
			Runnable r=(Runnable)jPanel;
			Thread th=new Thread(r);//thread(Runnable r)来实现多线程
			th.start();
		}
	}
	
	
	
}
