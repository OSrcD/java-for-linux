package game.element;

import java.awt.Image;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.swing.ImageIcon;

import game.control.GameThread;
import game.element.vo.BoomElement;
import game.element.vo.BubbleElement;
import game.element.vo.FastElement;
import game.element.vo.GameBG;
import game.element.vo.GamePlay;
import game.element.vo.GamePlay1;
import game.element.vo.MapElement;
import game.element.vo.SuperElement;

/**
 * @说明 负责加载元素资源-图片等等
 * @职责 1.记载资源到资源库 -图片资源库，音乐资源库
 *       2.负责创建对象-》元素对象
 *         工厂模式
 */
public class GameLoad {
	private  Map<String,Image> map;
	
	private SuperElement [][] BaoZhaArray = new SuperElement [20][20];
	SuperElement [][] fasts = new SuperElement [20][20];
	SuperElement [][] BubblePK = new SuperElement [20][20];
	public boolean myBoomFlag=false;
	public boolean BubblePKFlag = false;
//	实例化资源库
	public GameLoad(){
		map=new HashMap<String,Image>();
		
	}
//	资源加载
	public void load(/***/){
//		如果是第1关，就加载。。。。第2关。。。。
		Image img=new ImageIcon
				("img/1.png").getImage();
		Image mapImg=new ImageIcon
				("img/map.png").getImage();
		Image bodyImg=new ImageIcon
				("img/body.png").getImage();//玩家2
		Image Bubble = new ImageIcon("img/bubble.png").getImage();
		Image over = new ImageIcon("img/Gameovers.png").getImage();
		Image BaoZha = new ImageIcon("img/baozha.png").getImage();
		Image fast = new ImageIcon("img/add.png").getImage();
		Image box = new ImageIcon("img/box.png").getImage();
		Image bgimg=new ImageIcon("img/beijin.png").getImage();//背景
		Image overimg=new ImageIcon("img/Gameovers.png").getImage();//背景
		Image Titles=new ImageIcon("img/Titles.png").getImage();//背景
		Image myfast=new ImageIcon("img/fast.png").getImage();//背景
		map.put("body", bodyImg);//玩家2
		map.put("birdPlay", img);
		map.put("map", mapImg);
		map.put("bubble", Bubble);
		map.put("BaoZha", BaoZha);
		map.put("fast", fast);
		map.put("box", box);
		map.put("over", over);
		map.put("beijin", bgimg);//背景
		map.put("Gameovers",overimg);
		map.put("Titles",Titles);
		map.put("myfast",myfast);
		
		
		
	}
	/**
	 * 工厂：专门用于生产所有的元素对象
	 * 本次开发省略 配置文件读取元素基本数据
	 * @param string
	 * @return
	 */
	public SuperElement elementFactory(String key) {		
		SuperElement se=null;
		switch(key){
		case "birdPlay":
//			先在资源库中获取图片资源
			Image img=map.get(key);
//			通过小作坊实例化一个玩家对象
			se=GamePlay.createGamePlay(100, 100, img);
			break;
		case "body":
//			先在资源库中获取图片资源
			Image bodyImg=map.get(key);
//			通过小作坊实例化一个玩家对象
			se=GamePlay1.createGamePlay1(700, 500, bodyImg);

			break;
//		case "bubble":
//			Image bubbleimg=map.get(key);
//			//东西在窗口左上角x屏幕显示位置 y屏幕显示右上角 //w 显示的宽度 h 显示高度 imgx图像截取的x imgy图像截取的y imgw:图的宽 imgh:图的高度
//			se=BubbleElement.createBubbleElement(GameManager.getGameManager().getGamePlay().getX(),
//					GameManager.getGameManager().getGamePlay().getY(), 32, 38, 0, 8, 32, 38, 0, false, 0, bubbleimg);
//		
//			//////
//			break;
		}
		return se;
	}
//	背景
	public SuperElement elementGameBG(String key) {
		SuperElement se=null;
		switch(key){
		case "beijin":
			Image img=map.get(key);
			se=GameBG.getGameBG(0, 0, img);
		case "Gameovers":
			Image img1=map.get(key);
			se=GameBG.getGameBG(0, 0, img1);
		case "Titles":
			Image img2 = map.get(key);
			se=GameBG.getGameBG(0, 0, img2);
		}
		return se;
	}
	
	
	public SuperElement bigcreateBubbleElement(String key,int x,int y,String play_no){
		SuperElement se=null;
		SuperElement [][] maps=new SuperElement [20][20];
		SuperElement [][] BubblePK = GameManager.getGameManager().getGLoad().getBubblePK();
		
		
		
		switch(key){
	
		case "bubble":
			Image bubbleimg=map.get(key);
			//在窗口左上角x屏幕显示位置 y屏幕显示右上角 //w 显示的宽度 h 显示高度 imgx图像截取的x imgy图像截取的y imgw:图的宽 imgh:图的高度
		int	 mx = ((x)/40);
		int	 my = ((y)/40+1);
			
		
		
			if(maps[mx][my] == null){
				
				
				if(play_no.equals("GamePlay")){
					se=BubbleElement.createBubbleElement(((x)/40)*40,
							((y)/40+1)*40, 40, 40, 0, 8, 32, 38, 0, false, 5, bubbleimg,false,0);
				
					
					BubblePK[mx][my] = new BubbleElement(mx*40, ((y)/40+1)*40, 40, 40, 0, 8, 32, 98, 0, false, 5, bubbleimg,0);
			
				}else{
					se=BubbleElement.createBubbleElement(((x)/40)*40,
							((y)/40+1)*40, 40, 40, 0, 8, 32, 38, 0, false, 5, bubbleimg,false,1);
					BubblePK[mx][my] = new BubbleElement(mx*40, ((y)/40+1)*40, 40, 40, 0, 8, 32, 98, 1, false, 5, bubbleimg,1);
				}
			}else{
			
			}
		
			//////
			break;
		
		
		
		}
		return se;
	}
	
	
	boolean flag = false;
	boolean righflag = false;
	boolean onerighflag = false;
	boolean topflag =false;
	boolean onetopflag = false;
	boolean buttomflag=false;
	boolean onebuttomflag=false;
	boolean leftflag=false;
	boolean oneleftflag=false;
	
	
	
	
	
	
	public List<SuperElement> bigcreateBoomElement(String key,int x,int y,int whobubble){//爆炸生成
		List<SuperElement> newbubbleList=new ArrayList<SuperElement>();
		SuperElement [][] ses=GameManager.getGameManager().getCreateMaps();//获得地图二维数组对象 ,用于判断泡泡前后左右有没有泡泡
		GamePlay tranceforPlay;
		tranceforPlay = (GamePlay)GameManager.getGameManager().getGamePlay(); //向下转型访问子类属性
		 
		GamePlay1 tranceforPlay1;
		tranceforPlay1 = (GamePlay1)GameManager.getGameManager().getGamePlay1(); //向下转型访问子类属性
		switch(key){
	
		case "BaoZha":
			
			Image BaoZha=map.get(key);
			
			if(y/40 ==14 || y/40==0 || x/40==19 || x/40 ==0 ){
				break;
			}
			
			if(whobubble==0){
				for(int j=0;j<tranceforPlay.getBubblenum();j++){
					
					

					//最右
						if((x/40)+j <19){
							if(ses[(x/40)+j][y/40]==null && righflag==false){
								
								if(j==tranceforPlay.getBubblenum()-1){
									newbubbleList.add(BoomElement.createBaoZhaElement(x+(40*j),y,40, 40, 160, 160, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x+(40*j), y, 160, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x+(40*j),y,40, 40, 544, 353, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x+(40*j), y, 544, 353, BaoZha);
								}
								
							}else{
									righflag=true;
									if(onerighflag!=true){
											ses[(x/40)+j][y/40]=null;
											onerighflag=true;
										
										}
										
							}
						}
						
					//最下
					
						
						if((y/40)+j <14){
							if(ses[x/40][(y/40)+j]==null && topflag==false){
								
								if(j==tranceforPlay.getBubblenum()-1){
								newbubbleList.add(BoomElement.createBaoZhaElement(x,y+(40*j),40, 40, 736, 160, 32, 33, 5, BaoZha));
								BaoZhaArray=this.createBoomArray(x, y+(40*j), 736, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x,y+(40*j),40, 40, 352, 352, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x, y+(40*j), 352, 352, BaoZha);
								}
								
							}else{
									topflag=true;
									if(onetopflag!=true){
										
											ses[x/40][(y/40)+j]=null;
											onetopflag=true;
										}
										
							}
						}	
						
					
						
					//最左
						
						if((x/40)-j >=1){
							if(ses[(x/40)-j][y/40]==null && leftflag==false){
							
								if(j==tranceforPlay.getBubblenum()-1){
									newbubbleList.add(BoomElement.createBaoZhaElement(x-(40*j),y,40, 40, 544, 160, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x-(40*j), y, 544, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x-(40*j),y,40, 40, 736, 352, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x-(40*j), y, 736, 352, BaoZha);
								}
							
							}else{
									leftflag=true;
									if(oneleftflag!=true){
											ses[(x/40)-j][y/40]=null;
											oneleftflag=true;
										
										}
										
							}
						}	
						
						if((y/40)-j >=1){
							if(ses[x/40][(y/40)-j]==null && buttomflag==false){
								if(j==tranceforPlay.getBubblenum()-1){
									newbubbleList.add(BoomElement.createBaoZhaElement(x,y-(40*j),40, 40, 928, 160, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x, y-(40*j), 928, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x,y-(40*j),40, 40, 545, 414, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x, y-(40*j), 545, 414, BaoZha);
								}
								
							}else{
								buttomflag=true;
									if(onebuttomflag!=true){
											ses[x/40][(y/40)-j]=null;
											onebuttomflag=true;
											
										}
										
							}
						}	
						

					//最上
			
					//中间	
					newbubbleList.add(BoomElement.createBaoZhaElement(x,y,32, 33, 160, 352, 32, 33, 5, BaoZha));
					BaoZhaArray=this.createBoomArray(x, y, 160, 352, BaoZha);
					}
				
				
				
			}else{
				for(int j=0;j<tranceforPlay1.getBubblenum();j++){
					
					

					//最右
						if((x/40)+j <19){
							if(ses[(x/40)+j][y/40]==null && righflag==false){
								
								if(j==tranceforPlay1.getBubblenum()-1){
									newbubbleList.add(BoomElement.createBaoZhaElement(x+(40*j),y,40, 40, 160, 160, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x+(40*j), y, 160, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x+(40*j),y,40, 40, 544, 353, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x+(40*j), y, 544, 353, BaoZha);
								}
								
							}else{
									righflag=true;
									if(onerighflag!=true){
											ses[(x/40)+j][y/40]=null;
											onerighflag=true;
										
										}
										
							}
						}
						
					//最下
					
						
						if((y/40)+j <14){
							if(ses[x/40][(y/40)+j]==null && topflag==false){
								
								if(j==tranceforPlay1.getBubblenum()-1){
								newbubbleList.add(BoomElement.createBaoZhaElement(x,y+(40*j),40, 40, 736, 160, 32, 33, 5, BaoZha));
								BaoZhaArray=this.createBoomArray(x, y+(40*j), 736, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x,y+(40*j),40, 40, 352, 352, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x, y+(40*j), 352, 352, BaoZha);
								}
								
							}else{
									topflag=true;
									if(onetopflag!=true){
										
											ses[x/40][(y/40)+j]=null;
											onetopflag=true;
										}
										
							}
						}	
						
					
						
					//最左
						
						if((x/40)-j >=1){
							if(ses[(x/40)-j][y/40]==null && leftflag==false){
							
								if(j==tranceforPlay1.getBubblenum()-1){
									newbubbleList.add(BoomElement.createBaoZhaElement(x-(40*j),y,40, 40, 544, 160, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x-(40*j), y, 544, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x-(40*j),y,40, 40, 736, 352, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x-(40*j), y, 736, 352, BaoZha);
								}
							
							}else{
									leftflag=true;
									if(oneleftflag!=true){
											ses[(x/40)-j][y/40]=null;
											oneleftflag=true;
										
										}
										
							}
						}	
						
						if((y/40)-j >=1){
							if(ses[x/40][(y/40)-j]==null && buttomflag==false){
								if(j==tranceforPlay1.getBubblenum()-1){
									newbubbleList.add(BoomElement.createBaoZhaElement(x,y-(40*j),40, 40, 928, 160, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x, y-(40*j), 928, 160, BaoZha);
								}else{
									newbubbleList.add(BoomElement.createBaoZhaElement(x,y-(40*j),40, 40, 545, 414, 32, 33, 5, BaoZha));
									BaoZhaArray=this.createBoomArray(x, y-(40*j), 545, 414, BaoZha);
								}
								
							}else{
								buttomflag=true;
									if(onebuttomflag!=true){
											ses[x/40][(y/40)-j]=null;
											onebuttomflag=true;
											
										}
										
							}
						}	
						

					//最上
			
					//中间	
					newbubbleList.add(BoomElement.createBaoZhaElement(x,y,32, 33, 160, 352, 32, 33, 5, BaoZha));
					BaoZhaArray=this.createBoomArray(x, y, 160, 352, BaoZha);
					}
				
			}
			
			
			break;
		
		}
		
	
	righflag = false;
	 onerighflag = false;
	 topflag =false;
	 onetopflag = false;
	 buttomflag=false;
		 onebuttomflag=false;
		leftflag=false;
		 oneleftflag=false;
	return newbubbleList;
	}
	
	public  SuperElement [][] getMapElement(String name){ //地图生成
		SuperElement [][] maps=new SuperElement [20][20];
//		SuperElement [][] fasts = new SuperElement [20][20];
		boolean falg=false;
		switch(name){
		case "box":
//			int min=40;
//			int i=5;
//			int j=5;
			
			for(int i=0;i<maps.length;i++){
				for(int j=0;j<maps[i].length;j++){
					if(i==0 || i==19 || j==0 || j==14 )
					maps[i][j]=new MapElement(i*40,j*40,40,40,
							0,0,32,32,map.get("box"),false);
					else{
						int playx=GameManager.getGameManager().getGamePlay().getX();
						int playy=GameManager.getGameManager().getGamePlay().getY();
						
						
						int myramx =(int)(Math.random()*12);
						int myramy =(int)(Math.random()*12);
						int myram  =(int)(Math.random()*10);
						if(myramx!=4 && myramx != 5){
//							maps[myramx][myramy]=new MapElement(i*40,j*40,40,40,
//									0,79,32,115,map.get("map"),true);
//							if(playx/32 != i && playy/32+1 != j || playx/32+1 != i);
							if(i !=2 && j!=3 && i!=12 && i!=18 && i!=17
									){
							maps[i][j]=new MapElement(i*40,j*40,40,40,
									96,0,32,32,map.get("box"),false);
							if(maps[i][j]!=null && i!=12 && i!=2 && myram!=0  && fasts[myram][j]==null){
								fasts[myram][myram]= new FastElement(myram*40,myram*40,40,40,
									0,0,31,47,map.get("fast"),false);
							}
							
							}
//							System.out.println(maps[myramx][myramy].isVisible());
//							System.out.println(playx+":"+playy);
						}
						
					
						
						
					}
				}
			}
			//鞋子
			maps[12][12]=new MapElement(12*40,12*40,40,40,
					96,0,32,32,map.get("box"),false);
			maps[2][2]=new MapElement(2*40,2*40,40,40,
					96,0,32,32,map.get("box"),false);
			
			break;
		case "fasts":
			
		
						fasts[12][12]= new FastElement(12*40,12*40,40,40,
								0,0,31,47,map.get("myfast"),false);
						fasts[2][2]= new FastElement(2*40,2*40,40,40,
								0,0,31,47,map.get("myfast"),false);
			
			
			
			
			
			return fasts;
			
		}
		
		
		return maps;
		
	}
	
	public SuperElement [][] createBoomArray(int baoZhaX,int baoZhaY,int imgx,int imgy,Image Baozha){ //爆炸转换二维数组
	
		int x;
		int y;
		x=baoZhaX/40;
		y=baoZhaY/40;
		myBoomFlag=true;
		if(x>=0 && y>=0 && x<20 && y<20){
			BaoZhaArray[x][y] =  BoomElement.createBaoZhaElement(baoZhaX,baoZhaY,40, 40, imgx, imgy, 32, 32, 5, Baozha);
		
		}
		
		return BaoZhaArray;
		
	}
	public SuperElement[][] getCreateBoomArray() {
		return BaoZhaArray;
	}
	public void setBaoZhaArray(SuperElement[][] baoZhaArray) {
		BaoZhaArray = baoZhaArray;
	}
	public Map<String, Image> getMap() {
		return map;
	}
	public void setMap(Map<String, Image> map) {
		this.map = map;
	}
	public SuperElement[][] getBubblePK() {
		return BubblePK;
	}
	public void setBubblePK(SuperElement[][] bubblePK) {
		BubblePK = bubblePK;
	}
	

	
}




