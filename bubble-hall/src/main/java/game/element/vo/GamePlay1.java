package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.io.File;

import javax.swing.ImageIcon;

import game.element.GameManager;
import game.frame.GameMain;

public class GamePlay1 extends SuperElement{
	private Image img;//������ʾʹ�õ�ͼƬ
	private int imgx;//ͼƬ��ȡ�����Ͻ�x
	private int imgy;//ͼƬ��ȡ�����Ͻ�y
	private int imgw;//ͼƬ��ȡ��w
	private int imgh;//ͼƬ��ȡ�ĸ߶�
	private int imgrow;//����ͼƬ��
	private int imgcol;//����ͼƬ��
	private int dnxb;//���� 0������ 1������ 2������ 3������ -1������
	private int sudu;
	private boolean moveType=false;//��¼�Ƿ�����ײ
	private boolean giveBubble=false;
	private int count=7;
	private static boolean playDieFlag=false;
	public static int timedie=0;
	private int bubblenum=2;
	public GamePlay1(int x, int y, int w, int h,Image bodyImg) {
		super(x, y, w, h);
		this.img=bodyImg;
		this.imgx=29;
		this.imgy=40;
		this.imgw=42;
		this.imgh=60;
		this.imgrow=0;
		this.imgcol=0;
		this.dnxb=-1;
		this.sudu=10;
	}
//	С������С����
	public static GamePlay1 createGamePlay1(int x,int y,Image bodyImg){
		int w=35;  //7
		int h=50;  //10
		return new GamePlay1(x,y,w,h,bodyImg);
	}
	
	
	@Override
	public void showElement(Graphics g) {
		if(GameManager.getGameManager().isPlayDieflag1()){
			g.drawImage(new ImageIcon(GameMain.class.getClassLoader().getResource("img/goodbye.png").getPath()).getImage(),
					getX(), getY(),//��Ļ���ϵ�
					getX()+60, getY()+80,//��Ļ���µ�
					100*imgrow+20, 100*imgcol+24, //ͼƬ���ϵ�
					100*imgrow+20+80,100*imgcol+24+99, //ͼƬ���µ�
					null);
			
		}else{
		
		
		g.drawImage(img, 
				getX(), getY(),//��Ļ���ϵ�
				getX()+getW(), getY()+getH(),//��Ļ���µ�
				100*imgrow+imgx, 100*imgcol+imgy, //ͼƬ���ϵ�
				100*imgrow+imgx+imgw,100*imgcol+imgy+imgh, //ͼƬ���µ�
				null);
		}
		
	}
	public Rectangle getRectangle(){
//		return new Rectangle(getX()+4,getY()+30,getW()-10,getH()-40);
		return new Rectangle(getX()+4,getY()+40,getW()-10,getH()-40);
	}
	
	@Override//�ƶ�Ԫ��
	public void moveElement() {
		
		
		
		imgrow=(imgrow==3)?0:imgrow+1;
		imgcol=(dnxb==-1)?imgcol:dnxb;
		int x=getX();
		int y=getY();
		if(!GameManager.getGameManager().isPlayDieflag1()){
			switch(dnxb){
			case 0: setY(y+sudu);break;
			case 1: setX(x-sudu);break;
			case 2: setX(x+sudu);break;
			case 3: setY(y-sudu);break;
			}
		}
		
		boolean flag = false;
		if(giveBubble  && !GameManager.getGameManager().isPlayDieflag1()){//������
			
			
				
			
			if(count>0 && count<8
					){
				
		
				
				GameManager.getGameManager().createBubbleElement().add(GameManager.getGameManager().getGLoad().
						bigcreateBubbleElement("bubble",this.getX(),this.getY(), "GamePlay1"));

				audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/bubble.mp3").getPath()));
				bubbleAudio.start();
				count--;
			
			
			}else if(count >7){
				count=7;
			}
			
			
		}
		
		
	}
	@Override//����״̬�޸�Ԫ������->�������õ�
	public void updateElement(boolean bl,int key) {
//		System.out.println(this.dnxb);
if(bl){
			
			switch(key){
			case 37:
				if(!(imgcol==1 && moveType))
					this.dnxb=1;
				moveType=false;
				break;
			case 38:
				if(!(imgcol==3 && moveType))
					this.dnxb=3;
					moveType=false;
				break;
			case 39:
				if(!(imgcol==2 && moveType))
						this.dnxb=2;
				moveType=false;
					break;
			case 40: 
				if(!(imgcol==0 && moveType))
					this.dnxb=0;
				moveType=false;
				break;
			case 96:
				giveBubble=true;
				break;
				
			
			}
		}else{
			switch(key){
			case 37:dnxb=(dnxb==1)?-1:dnxb;break;
			case 38:dnxb=(dnxb==3)?-1:dnxb;break;
			case 39:dnxb=(dnxb==2)?-1:dnxb;break;
			case 40:dnxb=(dnxb==0)?-1:dnxb;break;
			case 96:giveBubble=false;
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
	public int getBubblenum() {
		return bubblenum;
	}
	public void setBubblenum(int bubblenum) {
		this.bubblenum = bubblenum;
	}
	
}
