package game.control;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.List;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import game.element.GameLoad;
import game.element.GameManager;
import game.element.vo.BubbleElement;
import game.element.vo.GamePlay;
import game.element.vo.GamePlay1;
import game.element.vo.MapElement;
import game.element.vo.SuperElement;
import game.element.vo.audio;
import game.element.vo.audionorepeat;
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

/**
 * @author admin
 * @说明 用于控制 游戏的进程
 * @职责 1.控制游戏进程
 *       2.控制自动化的NPC行为
 *       3.依据状态属性改变对应的 元素的属性
 *       4.元素与元素之间的关系-例如：碰撞,发射子弹
 *       5.元素的销毁
 */
public class GameThread extends Thread{//继承多线程的，我就拥有多线程的功能
	
	public void run(){//多线程方法
		while(true){
//			前戏：资源加载 滚动条,加载图片素材
			ready();
		
//			进行时：玩游戏的过程中
			work();
			
//			结束:
			over();
			
		}
	}
//	准备工作，例如 语句关卡加载不一样的元素
	private void ready() { 
		
//		类名 .       得到资源管理器     .得到加载器  . 加载
		GameManager.getGameManager().getGLoad().load();    //导入图片素材
//		进行对象的创建
	
		GameManager.getGameManager().LoadElement();    //加载玩家，加载地图图片对象 加载背景啊

		
		GameManager.getGameManager().setGamefirst(true);
		
		
		
	}
//	关卡进行时
	private void work() {
//		游戏启动
//		GameManager.getGameManager().setGameStart(true);
		while(true){
			
			elementMove();//先移动
			elementTimeDisappear();//对象消失的时间判断
			elementUpdate();//依据状态修改属性
			elementPK();// 碰撞
			elementDestroy();//销毁
//			因为程序跑的很快，所以使用休眠
			try {
				Thread.sleep(100);//休眠100毫秒
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			GameManager.timeCount++;//泡泡时间消失计算
		
//			从资源管理器中获取 面板，进行循环刷新
			GameManager.getGameManager()           //重绘
					.getJPanel().repaint();
		}
	}
//	关卡结束时
	private void over() {
	audionorepeat bubbleAudio  = new audionorepeat(new File("audio/ByeBye.mp3")); 
	bubbleAudio.start();
	int x = JOptionPane.showConfirmDialog(null,"想重新开始吗？","游戏提示",JOptionPane.YES_NO_OPTION);
		//java 对话框api函数 直接拿来用，不需要知道原理
	
	
		if(x==0){
			SuperElement [][] myBooms=GameManager.getGameManager().getGLoad().getCreateBoomArray();//实时获得波纹的转换的二维数组
			List<SuperElement> BoomList = GameManager.getGameManager().createBoomList();//底层原理是数组可以理解为数据结构里的线性表顺序表
			SuperElement [][] BubblePK = GameManager.getGameManager().getGLoad().getBubblePK();
			//BoomList是波纹图像
			
			for(int i=0;i<myBooms.length;i++){
				for(int j=0;j<myBooms[i].length;j++){
					if(myBooms[i][j]!=null){//防止空数组出错
						myBooms[i][j]=null; //清理爆炸数组对象
					
					}
				}
			}
			
		 
			for(int i=0;i<BubblePK.length;i++){
				for(int j=0;j<BubblePK[i].length;j++){
					if(BubblePK[i][j]!=null){
						BubblePK[i][j]=null;
					}
				}
			}
			
			BoomList.removeAll(BoomList);//清理所有爆炸对象
			
			GameManager.getGameManager().createBubbleElement().removeAll(GameManager.getGameManager().createBubbleElement());
			//忘记了
			
			GameManager.getGameManager().setSwapbg(true);
			ready();//重新读取关卡
			
		}else{
			System.exit(0);
		}
		
	}
	



	
	/**元素和元素之间的碰撞*/
	private void elementPK() {
		SuperElement [][] myMaps=GameManager.getGameManager().getCreateMaps();//获得地图二维数组对象
		SuperElement [][] myBooms=GameManager.getGameManager().getGLoad().getCreateBoomArray();//获得转换后的波纹二维数组对象
		SuperElement [][] myFatst = GameManager.getGameManager().getFasts();//获得鞋子对象
		SuperElement [][] BubblePK = GameManager.getGameManager().getGLoad().getBubblePK();
		List<SuperElement> myBubbleList =GameManager.getGameManager().createBubbleElement();
	
		if(GameManager.getGameManager().isplayDieFlag()){
			boolean playPKplay = GameManager.getGameManager().getGamePlay1().PK(GameManager.getGameManager().getGamePlay());
			if(playPKplay){
				audionorepeat bubbleAudio  = new audionorepeat(new File("audio/die.mp3")); 
				bubbleAudio.start();			
				GameManager.getGameManager().setGameoversflag(true);
				
				over();
				
				GameManager.getGameManager().setplayDieFlag(false);
			}
			
		}
		
		if(GameManager.getGameManager().isPlayDieflag1()){
			boolean playPKplay = GameManager.getGameManager().getGamePlay().PK(GameManager.getGameManager().getGamePlay1());
			if(playPKplay){
				audionorepeat bubbleAudio  = new audionorepeat(new File("audio/die.mp3")); 
				bubbleAudio.start();
				GameManager.getGameManager().setGameoversflag(true);
				over();
				GameManager.getGameManager().setPlayDieflag1(false);
			}
			
		}
		
		
		
		
		

		
			for(int i=0;i<myBooms.length;i++){
				for(int j=0;j<myBooms[i].length;j++){
					if(myBooms[i][j]!=null){//不可以访问空数组

//						if(myMaps[i][j]!=null){
//							boolean mapBoomFlag =myBooms[i][j].PK(myMaps[i][j]);   //波纹炸可摧毁地图对象判断
//							if(mapBoomFlag){
//							if(!(i==0 || i==14 || j==0 || j==14 || j==13)) //四边地图元素不可摧毁
//								myMaps[i][j]=null;
//							}
//						}
						
						//获得人物角色，就是那只鸟的图片了
						GamePlay GamePlayDie = (GamePlay)GameManager.getGameManager().getGamePlay();
						//人物与波纹二维数组对象碰撞 如果为true 则死亡,如果false则相反
						GamePlayDie.setPlayDieFlag(myBooms[i][j].PK(GameManager.getGameManager().getGamePlay()));
						for(int b=0;b<myBubbleList.size();b++){
							
							boolean BoomandBubble = myBooms[i][j].PK(myBubbleList.get(b));
							
							if(BoomandBubble){
								
								myBubbleList.get(b).setVisible(true);
								}
							}
						
							
						//获得人物角色，就是那只红男孩啦
						GamePlay1 GamePlayDie1 = (GamePlay1)GameManager.getGameManager().getGamePlay1();
						//同理
						GamePlayDie1.setPlayDieFlag(myBooms[i][j].PK(GameManager.getGameManager().getGamePlay1()));
					
						
								
						
						//死亡，就结束游戏了
						if(GamePlayDie.isPlayDieFlag()){ 										//人物死亡
							GameManager.getGameManager().setplayDieFlag(true); 
//							over();//调用结束函数
							GamePlayDie.timedie=GameManager.timeCount;
						
						}
						
						if(GamePlayDie1.isPlayDieFlag()){
							GameManager.getGameManager().setPlayDieflag1(true);
							GamePlayDie1.timedie=GameManager.timeCount;
							
						}
					}
				}
			}
			GamePlay GamePlayDie = (GamePlay)GameManager.getGameManager().getGamePlay();
			GamePlay1 GamePlayDie1 = (GamePlay1)GameManager.getGameManager().getGamePlay1();
			if(GameManager.getGameManager().isPlayDieflag1()){
				if(GameManager.timeCount-GamePlayDie1.timedie>=30 ){
					
					audionorepeat bubbleAudio  = new audionorepeat(new File("audio/save.mp3")); 
					bubbleAudio.start();
					
					
				
					GameManager.getGameManager().setPlayDieflag1(false);
				}	
			}
			
			if(GameManager.getGameManager().isplayDieFlag()){
				if(GameManager.timeCount-GamePlayDie.timedie>=30 ){
					
					audionorepeat bubbleAudio  = new audionorepeat(new File("audio/save.mp3")); 
					bubbleAudio.start();
					
					
					
					GameManager.getGameManager().setplayDieFlag(false);
				}	
			}
			
	
			
			
			
			
		
		//鞋子与人碰撞
			boolean bl2 = false;
			boolean bl3 =false;
			
			
			
			
			if(myFatst[2][2]!=null&& myMaps[2][2]==null ){
				bl2 = myFatst[2][2].PK(GameManager.getGameManager().getGamePlay());
				 bl3 = myFatst[2][2].PK(GameManager.getGameManager().getGamePlay1());
				 if(bl2){
					 SuperElement se=(GameManager.getGameManager().getGamePlay()); //
						GamePlay gp=(GamePlay)se;//父类指向子类 在多态中经常会用到
						if(gp.getSudu()==15){
							gp.setSudu(gp.getSudu());
							myFatst[2][2]=null;//鞋子图片对象消失
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
						}else{
							gp.setSudu(gp.getSudu()+5); 
							myFatst[2][2]=null;//鞋子图片对象消失
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
				 }
				 }
				 
						 if(bl3){
							 SuperElement se1=(GameManager.getGameManager().getGamePlay1()); //
								GamePlay1 gp1=(GamePlay1)se1;//父类指向子类 在多态中经常会用到
								if(gp1.getSudu()==15){
									gp1.setSudu(gp1.getSudu());
									myFatst[2][2]=null;//鞋子图片对象消失
									audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
									bubbleAudio.start();
								}else{
									gp1.setSudu(gp1.getSudu()+5); 
									myFatst[2][2]=null;//鞋子图片对象消失
									audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
									bubbleAudio.start();
						 }
						
						
						
						 }
				 }
			
			
			
			
			
			if(myFatst[12][12]!=null &&myMaps[12][12]==null){
				bl2 = myFatst[12][12].PK(GameManager.getGameManager().getGamePlay());
				 bl3 = myFatst[12][12].PK(GameManager.getGameManager().getGamePlay1());
				 if(bl2){
					 SuperElement se=(GameManager.getGameManager().getGamePlay()); //
						GamePlay gp=(GamePlay)se;//父类指向子类 在多态中经常会用到
						if(gp.getSudu()==15){
							gp.setSudu(gp.getSudu());
							myFatst[12][12]=null;
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
						}else{
							gp.setSudu(gp.getSudu()+5); 
							myFatst[12][12]=null;//鞋子图片对象消失
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
				 }
				 }
				 
						 if(bl3){
							 SuperElement se1=(GameManager.getGameManager().getGamePlay1()); //
								GamePlay1 gp1=(GamePlay1)se1;//父类指向子类 在多态中经常会用到
								if(gp1.getSudu()==15){
									gp1.setSudu(gp1.getSudu());
									myFatst[12][12]=null;
									audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
									bubbleAudio.start();
								}else{
									gp1.setSudu(gp1.getSudu()+5); 
									myFatst[12][12]=null;//鞋子图片对象消失
									audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
									bubbleAudio.start();
						 }
						
						
						
						 }
				 }
			
			
			
			
			
			
		for(int i=0;i<myFatst.length;i++){ 
			for(int j=0;j<myFatst[i].length;j++){
				
				
				
				if(myFatst[i][j]!=null && myMaps[i][j]==null ){
				
					
					
					
					boolean bl=myFatst[i][j].PK(GameManager.getGameManager().getGamePlay());	
					
					boolean bl1=myFatst[i][j].PK(GameManager.getGameManager().getGamePlay1());
					
					
					
					
					if(bl){
						SuperElement se=(GameManager.getGameManager().getGamePlay()); //
						GamePlay gp=(GamePlay)se;//父类指向子类 在多态中经常会用到
						
						
						
						
						
						if(gp.getBubblenum()==18 ){	
							gp.setBubblenum(gp.getBubblenum());
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
							myFatst[i][j]=null;
						}else{
							
							
							
							gp.setBubblenum(gp.getBubblenum()+1); 
						
	
							
							myFatst[i][j]=null;//鞋子图片对象消失
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
						}
						
				
					
						
					}
					
					
					if(bl1)	{
						SuperElement se1=(GameManager.getGameManager().getGamePlay1());
						GamePlay1 gp1=(GamePlay1)se1;
						if(gp1.getBubblenum()==18){
							gp1.setBubblenum(gp1.getBubblenum());
							myFatst[i][j]=null;
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
						}else{
							gp1.setBubblenum(gp1.getBubblenum()+1);
							myFatst[i][j]=null;
							audionorepeat bubbleAudio  = new audionorepeat(new File("audio/get.mp3")); 
							bubbleAudio.start();
						}
					}
					
					
				}
			}
		}
		
		
		//地图碰撞处理
		
		for(int i=0;i<myMaps.length;i++){        //循环遍历
			for(int j=0;j<myMaps[i].length;j++){
				if(myMaps[i][j]!=null){
					boolean bl=myMaps[i][j].PK(GameManager.getGameManager().getGamePlay());	//地图与人物角色碰撞检测
					boolean bl1=myMaps[i][j].PK(GameManager.getGameManager().getGamePlay1());//地图与人物角色碰撞检测
					if(bl){//检测到碰撞
						SuperElement se=(GameManager.getGameManager().getGamePlay()); //类型本身是父类
						GamePlay gp=(GamePlay)se;//需要进行强转，父类向下转型，一般用在多态啦
						gp.setMoveType(true);
						switch(gp.getDnxb()){ //获得当前对象的方向
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp.setY(gp.getY()-15);break; //下
					
						case 1:gp.setX(gp.getX()+15);break; //左
						case 2:gp.setX(gp.getX()-15);break; //右
						case 3:gp.setY(gp.getY()+15);break; //上
						
						}
						
						gp.setDnxb(-1);//设置当前不能移动
					
						
					}
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					if(bl1){
						
						SuperElement se1=(GameManager.getGameManager().getGamePlay1());
						GamePlay1 gp1=(GamePlay1)se1;
						gp1.setMoveType(true);
						switch(gp1.getDnxb()){
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp1.setY(gp1.getY()-15);break;
						case 1:gp1.setX(gp1.getX()+15);break;
						case 2:gp1.setX(gp1.getX()-15);break;
						case 3:gp1.setY(gp1.getY()+15);break;
						
						}
						
						gp1.setDnxb(-1);
						
						
						
						
						
					}
				}
			}
		}
		
		
		
		
		
		
		
		
		
		//泡泡碰撞 新增加代码
		
		for(int i=0;i<BubblePK.length;i++){        //循环遍历
			for(int j=0;j<BubblePK[i].length;j++){
				if(BubblePK[i][j]!=null){
					boolean bl=BubblePK[i][j].PK(GameManager.getGameManager().getGamePlay());	//泡泡与人物角色碰撞检测
					boolean bl1=BubblePK[i][j].PK(GameManager.getGameManager().getGamePlay1());//泡泡与人物角色碰撞检测
					
					if(bl==false && bl1==false){
						BubblePK[i][j].setVisible(true);
						
					}
					BubbleElement myBubbleElement = (BubbleElement)BubblePK[i][j];
//					System.out.println(myBubbleElement.getImgcol());
					if(bl && myBubbleElement.getImgcol() != 0 || bl && BubblePK[i][j].isVisible() ){//检测到碰撞
						SuperElement se=(GameManager.getGameManager().getGamePlay()); //类型本身是父类
						GamePlay gp=(GamePlay)se;//需要进行强转，父类向下转型，一般用在多态啦
						gp.setMoveType(true);
						switch(gp.getDnxb()){ //获得当前对象的方向
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp.setY(gp.getY()-15);break; //下
						case 1:gp.setX(gp.getX()+15);break; //左
						case 2:gp.setX(gp.getX()-15);break; //右
						case 3:gp.setY(gp.getY()+15);break; //上
						
						}
						
						gp.setDnxb(-1);//设置当前不能移动
					}
					
				
					
					if(bl1 &&   myBubbleElement.getImgcol() != 1 || bl1 && BubblePK[i][j].isVisible()){
						
						SuperElement se1=(GameManager.getGameManager().getGamePlay1());
						GamePlay1 gp1=(GamePlay1)se1;
						gp1.setMoveType(true);
						switch(gp1.getDnxb()){
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp1.setY(gp1.getY()-15);break;
						case 1:gp1.setX(gp1.getX()+15);break;
						case 2:gp1.setX(gp1.getX()-15);break;
						case 3:gp1.setY(gp1.getY()+15);break;
						
						}
						
						gp1.setDnxb(-1);
						
						
						
						
						
					}
				}
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	/**依据状态，修改元素属性*/
	private void elementUpdate() {
			//待定
	}
	
	/**所有元素的移动 */
	private void elementMove() { //角色移动
		GameManager.getGameManager().getGamePlay().moveElement(); //鸟叔移动
		GameManager.getGameManager().getGamePlay1().moveElement(); //红孩子移动
		
	}
	
	private void elementTimeDisappear(){
		GameThread.togetherVisible(GameManager.getGameManager().createBoomList()); //获得波纹集合对象爆炸消失时间判断
		GameThread.togetherVisible(GameManager.getGameManager().createBubbleElement());//获得泡泡集合对象,泡泡消失时间判断
		
	}
	
	
	
	private static void togetherVisible(List<SuperElement> togetherList) { //泡泡与爆炸消失时间判断函数
		for(int i=0;i<togetherList.size();i++){
			togetherList.get(i).moveElement();//调用判断时间函数
		}
		
	}
	
	
	
	
	
	
	
	/**销毁已经无效的元素*/
	
	private void elementDestroy() {
		DestroBubbleElement(GameManager.getGameManager().createBubbleElement());//泡泡集合销毁
		
		DestroyBoomElement(GameManager.getGameManager().createBoomList());//爆炸集合销毁
	
	}
	
	
	
	
	
	int BubbleCount;
	int BubbleCount1;
	private void DestroBubbleElement(List<SuperElement> bubbleList){//遍历泡泡消失时间
		SuperElement [][] BubblePK = GameManager.getGameManager().getGLoad().getBubblePK();
		GamePlay tranceforPlay;
		tranceforPlay = (GamePlay)GameManager.getGameManager().getGamePlay(); //向下转型访问子类属性
		 
		GamePlay1 tranceforPlay1;
		tranceforPlay1 = (GamePlay1)GameManager.getGameManager().getGamePlay1(); //向下转型访问子类属性
		
		
		for(int i=0;i<bubbleList.size();i++){
			if(bubbleList.get(i).isVisible()){			
			
				int x=bubbleList.get(i).getX(); //获得当前泡泡x坐标
				int y=bubbleList.get(i).getY(); //获得当前泡泡Y坐标
				int whobubble = bubbleList.get(i).getWhobubble();
				bubbleList.remove(i);//删除泡泡图像
				BubblePK[x/40][y/40]=null;
				
				   
				GameManager.getGameManager().createBoomList().addAll(GameManager.getGameManager().getGLoad().
				bigcreateBoomElement("BaoZha",x ,y,whobubble)); //生成波文
				
				audionorepeat bubbleAudio  = new audionorepeat(new File("audio/boom.mp3")); 
				bubbleAudio.start();
				
				
				BubbleCount =tranceforPlay.getCount(); //获得当前泡泡
				  if(BubbleCount <8 && BubbleCount >=0)
				   tranceforPlay.setCount(BubbleCount+=1);     //泡泡数量处理
				
				   
				   
				   BubbleCount1 =tranceforPlay1.getCount(); //获得当前泡泡
				 
					  if(BubbleCount1 <8 && BubbleCount1 >=0)
					   tranceforPlay1.setCount(BubbleCount1 +=1);     //泡泡数量处理
					  
				   
				
			}
		
		}
		
	

	}
	
	
	
	private void DestroyBoomElement(List<SuperElement> BoomList){//波纹消失摧毁
		SuperElement [][] myBooms=GameManager.getGameManager().getGLoad().getCreateBoomArray();//实时获得波纹的二维数组
		
		
		if(BoomList.size()>0){//有波纹元素立即销毁,有时候会出现两个同时销毁
		
			if(BoomList.get(1).isVisible()){
//				BoomList.removeAll(BoomList);//波纹表面对象图像消失
				
				
				for(int i=0;i<BoomList.size();i++){
					if(BoomList.get(i).isVisible()){
						BoomList.removeAll(BoomList);
					}
				}
				
				
				
				//逻辑思维连贯性
				if(GameManager.getGameManager().getGLoad().myBoomFlag){//波纹实际对象图像消失
					for(int i=0;i<myBooms.length;i++){
						for(int j=0;j<myBooms[i].length;j++){
							if(myBooms[i][j]!=null){
								myBooms[i][j]=null; //置空
								
							}
						}
					}
				}
				
			}
		}
			
		
		
	

	}
	
	
	
	
}







