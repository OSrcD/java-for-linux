package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;

import game.element.GameManager;

public class BoomElement  extends SuperElement {
	private Image img;
	private int imgx;
	private int imgy;
	private int imgw;
	private int imgh;
	private int notseeTime;
		
	
	
	
	
	
	


	public BoomElement(int x, int y, int w, int h,int imgx,int imgy,int imgw,int imgh,int notseeTime,Image img) {
		super(x, y, w, h);
		this.imgx=imgx;
		this.imgy=imgy;
		this.imgw=imgw;
		this.imgh=imgh;
		this.img=img;
		this.notseeTime=GameManager.timeCount;
	
	}
	
	
	public static BoomElement createBaoZhaElement(int x, int y, int w, int h,int imgx,int imgy,int imgw,int imgh,
			int notseeTime,Image img){
		
		return new BoomElement(x,y,w, h,imgx, imgy, imgw, imgh, 
				notseeTime,img);
	}

	@Override
	public void showElement(Graphics g) {
		// TODO Auto-generated method stub
		g.drawImage(img, getX(), getY(),
				getX()+getW(), //ÆÁÄ»ÉÏ
				getY()+getH(),//ÆÁÄ»ÏÂ
				imgx, imgy,//Í¼Æ¬×óÉÏµã
				imgx+imgw, imgy+imgh, //Í¼Æ¬ÏÂ
				null);
	}

	@Override
	public void moveElement() {
		// TODO Auto-generated method stub
		if(GameManager.timeCount-this.notseeTime>=8){
			this.setVisible(true);
			
			
		}
	}
	


	@Override
	public void updateElement(boolean bl, int key) {
		// TODO Auto-generated method stub
		
	}

	public int getBoomTime() {
		return notseeTime;
	}

	public void setBoomTime(int notseeTime) {
		this.notseeTime = notseeTime;
	}

	
	
	
}
