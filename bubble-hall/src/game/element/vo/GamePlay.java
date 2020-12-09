package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.io.File;
import java.io.FileNotFoundException;

import javax.swing.ImageIcon;

import game.control.GameThread;
import game.element.GameManager;
import game.frame.GameFrame;
import javazoom.jl.decoder.JavaLayerException;

public class GamePlay extends SuperElement{

	private Image img;//用来显示使用的图片
	private int imgx;//图片截取的左上角x
	private int imgy;//图片截取的左上角y
	private int imgw;//图片截取的w
	private int imgh;//图片截取的高都
	private int imgrow;//控制图片行
	private int imgcol;//控制图片列
	private int dnxb;//方向 0代表下 1代表左 2代表右 3代表上 -1代表不动
	private int sudu;
	private boolean moveType=false;//记录是否发生碰撞
	private boolean giveBubble=false;
	private int count=7;
	private static boolean playDieFlag=false;
	public static int timedie=0;
	private int bubblenum=1;
	public GamePlay(int x, int y, int w, int h,Image img) {
		super(x, y, w, h);
		this.img=img;
		this.imgx=29;
		this.imgy=40;
		this.imgw=42;
		this.imgh=60;
		this.imgrow=0;
		this.imgcol=0;
		this.dnxb=-1;
		this.sudu=10;
	}
//	小工厂，小作坊
	public static GamePlay createGamePlay(int x,int y,Image img){
		int w=35;  //7
		int h=50;  //10
		return new GamePlay(x,y,w,h,img);
	}
	
	@Override// 显示元素
	public void showElement(Graphics g) {
		if(GameManager.getGameManager().isplayDieFlag()){
			g.drawImage(new ImageIcon("img/goodbye.png").getImage(), 
					50, getY(),//屏幕左上点
					getX()+60, getY()+80,//屏幕右下点
					100*imgrow+20, 100*imgcol+24, //图片左上点
					100*imgrow+20+80,100*imgcol+24+99, //图片右下点
					null);
			
		}else{
			g.drawImage(img, 
					getX(), getY(),//屏幕左上点
					getX()+getW(), getY()+getH(),//屏幕右下点
					100*imgrow+imgx, 100*imgcol+imgy, //图片左上点
					100*imgrow+imgx+imgw,100*imgcol+imgy+imgh, //图片右下点
					null);
		}
	}
	public Rectangle getRectangle(){
//		return new Rectangle(getX()+4,getY()+30,getW()-10,getH()-40);
		return new Rectangle(getX()+4,getY()+40,getW()-10,getH()-40);
//		return new Rectangle(getX()+3,getY()+36,getW()-4,getH()-37);

	}

	@Override//移动元素
	public void moveElement() {
		imgrow=(imgrow==3)?0:imgrow+1;
		imgcol=(dnxb==-1)?imgcol:dnxb;
		int x=getX();
		int y=getY();//196 193
		if(!GameManager.getGameManager().isplayDieFlag()){
			switch(dnxb){
			case 0: setY(y+sudu);break;
			case 1: setX(x-sudu);break;
			case 2: setX(x+sudu);break;
			case 3: setY(y-sudu);break;
			}
		}
		boolean flag = false;
		if(giveBubble && !GameManager.getGameManager().isplayDieFlag()){//放泡泡
			
			
				
			if(count>0 && count<8
					){
				
		
				
				GameManager.getGameManager().createBubbleElement().add(GameManager.getGameManager().getGLoad().
						bigcreateBubbleElement("bubble",this.getX(),this.getY(), "GamePlay"));
				
				audionorepeat bubbleAudio  = new audionorepeat(new File("audio/bubble.mp3")); 
				gameStart(bubbleAudio);
				count--;
			
				
				
			}else if(count >7){
				count=7;
			}
			
			
		}
	}

	@Override//依据状态修改元素属性->给监听用的
	public void updateElement(boolean bl,int key) {
//		System.out.println(this.dnxb);
		if(bl){
			switch(key){
			case 65:
				if(!(imgcol==1 && moveType)){
					this.dnxb=1;
					moveType=false;
				}
				break;
			case 87:
				if(!(imgcol==3 && moveType)){
					this.dnxb=3;
					moveType=false;
				}
				break;
			case 68:
				if(!(imgcol==2 && moveType)){
					this.dnxb=2;
					moveType=false;
				}
					break;
			case 83: 
				if(!(imgcol==0 && moveType)){
					this.dnxb=0;
					moveType=false;
				}
				break;
			case 32:
				giveBubble=true;
			
				break;
			}
		}else{
			switch(key){
			case 65:dnxb=(dnxb==1)?-1:dnxb;break;
			case 87:dnxb=(dnxb==3)?-1:dnxb;break;
			case 68:dnxb=(dnxb==2)?-1:dnxb;break;
			case 83:dnxb=(dnxb==0)?-1:dnxb;break;
			case 32:giveBubble=false;
			}
		}
	}
	
	public int getDnxb() {
		return dnxb;
	}
	public void setDnxb(int dnxb) {
		this.dnxb = dnxb;
	}
	public boolean isMoveType() {
		return moveType;
	}
	public void setMoveType(boolean moveType) {
		this.moveType = moveType;
	}
	public int getCount() {
		return count;
	}
	public void setCount(int count) {
		this.count = count;
	}
	public boolean isPlayDieFlag() {
		return playDieFlag;
	}
	public void setPlayDieFlag(boolean playDieFlag) {
		this.playDieFlag = playDieFlag;
	}
	public int getSudu() {
		return sudu;
	}
	public void setSudu(int sudu) {
		this.sudu = sudu;
	}
	public boolean isGiveBubble() {
		return giveBubble;
	}
	public void setGiveBubble(boolean giveBubble) {
		this.giveBubble = giveBubble;
	}
	
	
	  public void gameStart(Thread th){
	    	
			th.start();//线程启动
			
		}
	public int getBubblenum() {
		return bubblenum;
	}
	public void setBubblenum(int bubblenum) {
		this.bubblenum = bubblenum;
	}
	

}
