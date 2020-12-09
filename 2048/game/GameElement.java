package game;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.Arrays;
/**
 * 单例 是 保证 只有一个实例 ，同时 可以保证数据的统一
 * 	1.需要定义一个私有的 静态的 本类的 属性
 * 	2.构造方法需要私有化 不允许其他类直接实例化
 * 	3.提供一个 公开的 统一的 出口 ，让其他的类获取 本类的唯一的实例对象
 * 
 * 	分2种   一种叫 
 * 	饿汉模式 ->直接创建
 * 		class Game{
 * 			private static Game g = new Game();
 * 			private Game(){}
 * 			public static Game getGame(){
 * 				return g;
 * 			}
 * 		}
 *  懒汉模式 ->延时创建
 *
 *
 *	资源共享，
 */
public class GameElement implements ElementShowInerface{
//	2048的数据储存
	private String [][]values;
	private int elementW;//定义每个框的高和宽的
	private int elementH;
	private int num=0;//记录有多少个格子有数据
	private final int sunNum=16;
	private static GameElement ge;
	
	
	
	private GameElement(){
		values=new String[4][4];
		elementW=80;
		elementH=80;
		CreateNumber();
		CreateNumber();
//		System.out.println(Arrays.toString(values[0]));
//		System.out.println(Arrays.toString(values[1]));
//		System.out.println(Arrays.toString(values[2]));
//		System.out.println(Arrays.toString(values[3]));
	}//synchronized 当一个线程进入方法后，会锁上，其他线程排队等待
	public static synchronized GameElement createGameElement(){
		if(ge==null){
			ge=new GameElement();
		}
		return ge;
	}
	@Override
	public void show(Graphics g) {
		for(int i=0;i<values.length;i++){
			for(int j=0;j<values[i].length;j++){
				g.setColor(new Color(200,200,200));
				g.fillRect(3+j*100, 5+i*100, elementW, elementH);
					int x=34;
				if(values[i][j] !=null){
					Color color = new Color(0,255,0);
					switch(Integer.parseInt(values[i][j])){
					case 2: break;
					case 4: color = new Color(100,100,0);break;
					case 8: color = new Color(200,200,0);break;
					case 16:color = new Color(0,100,100);x=28;break;
					case 32:color = new Color(0,200,200);x=28;break;
					case 64:color = new Color(0,255,255);x=28;break;
					case 128:color = new Color(100,0,255);x=10;break;
					case 256:color = new Color(200,0,255);x=10;break;
					case 512:color = new Color(255,0,255);x=10;break;
					case 1024:color = new Color(0,0,200);x=12;break;
					case 2048:color = new Color(0,0,255);x=12;break;
					
					}
					g.setColor(color);
					g.setFont(new Font("宋体",Font.BOLD,30));
					g.drawString(values[i][j], x+j*100, 52+i*100);
				}
			}
		}
	}
	
	public void CreateNumber(){
		int cnum=sunNum-num;//得到还有多少个空格子
		int c=(int)(Math.random()*cnum+1);//  1 - (sunNum-num)
		System.out.println(c);
		for(int i=0;i<values.length;i++){
			for(int j=0;j<values[i].length;j++){
				if(values[i][j] !=null){
					continue;
				}
				if(c == 1){
					int n=(int)(Math.random()*10);//01234567 89
					values[i][j]=n<8?"2":"4";
					num++;
					return;
				}
				c--;
			}
		}
	}
	
	public void KeyClick(int key){
		switch(key){
		case 37: left();break;//左
		case 38: up2();break;//上
		case 39: right();break;//右
		case 40: button();break;//下
		}
		CreateNumber();
	}
	
	
		
	
	
	
	public void up2(){
		for(int j=0;j<4;j++){
			for(int i=0;i<4;i++){
				if(values[i][j] ==null){
					continue;
					
				}
				
				for(int m=i;m>0;m--){
					if(values[m-1][j]==null){
						values[m-1][j]=values[m][j];
						values[m][j]=null;
						continue;
					}
					if(values[m-1][j].equals(values[m][j])){
						int x = Integer.parseInt(values[m-1][j]);
						values[m-1][j]=x*2+"";
						values[m][j]=null;
						num--;
						break;
					}
					
					
				}
				
			}
		}
	}
	
	
	
	public void button(){
		for(int j=3;j>=0;j--){
			for(int i=3;i>=0;i--){
				if(values[i][j] ==null){
					continue;
					
				}
				
				for(int m=0;m<3;m++){
					if(values[m+1][j]==null){
						values[m+1][j]=values[m][j];
						values[m][j]=null;
						continue;
					}
					
					if(values[m+1][j].equals(values[m][j])){
						int x = Integer.parseInt(values[m+1][j]);
						values[m+1][j]=x*2+"";
						values[m][j]=null;
						num--;
						break;
					}
					
					
				}
				
			}
		}
	}
	
	
	
	
	
	public void left() {
		for(int i=0;i<values.length;i++){
			for(int j=0;j<values[i].length;j++){
				if(values[i][j]==null){
					continue;
				}
				for(int m=j;m>0;m--){
					if(values[i][m-1]==null){
						values[i][m-1]=values[i][m];
						values[i][m]=null;
						continue;
					}
					if(values[i][m-1].equals(values[i][m])){
//						2    Integer.parseInt  "2"   将字符串转换为数字
						int x=Integer.parseInt(values[i][m-1]);
						values[i][m-1]=x*2+"";
						values[i][m]=null;
						num--;//记录多少个数据的 要减1
						break;
					}
				}
			}
		}
	}
	
	
	public void right() {
		for(int i=values.length-1;i>=0;i--){
			for(int j=values[i].length-1;j>=0;j--){
				if(values[i][j]==null){
					continue;
				}
				for(int m=j;m<3;m++){
					if(values[i][m+1]==null){
						values[i][m+1]=values[i][m];
						values[i][m]=null;
						continue;
					}
					if(values[i][m+1].equals(values[i][m])){
//						2    Integer.parseInt  "2"   将字符串转换为数字
						int x=Integer.parseInt(values[i][m+1]);
						values[i][m+1]=x*2+"";
						values[i][m]=null;
						num--;//记录多少个数据的 要减1
						break;
					}
				}
			}
		}
	}
	
	
	
	@Override
	public void move() {
		// TODO Auto-generated method stub
		
	}
	
	
	
}
