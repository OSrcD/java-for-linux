package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;

public class GameBG extends SuperElement{
	private Image img;
	private int imgx;//图片截取的左上角x
	private int imgy;//图片截取的左上角y
	private int imgw;//图片截取的w
	private int imgh;//图片截取的h
	
	
	public GameBG(int x, int y, int w, int h,Image img) {
		super(x, y, w, h);
		this.img=img;
		this.imgx=0;
		this.imgy=0;
		this.imgw=800;
		this.imgh=600;
	}
	
	public static GameBG getGameBG(int x,int y,Image img){
		int w=800;
		int h=600;
		return new GameBG(x,y,w,h,img);
	}
	
	
	public static GameBG getGameBG(int x,int y,int w,int h,Image img){
	
		return new GameBG(x,y,w,h,img);
	}
	
	public void showElement(Graphics g) {
		g.drawImage(img, getX(), getY(), 
				getW(), getH(), null);
		
//		g.drawImage(img, 
//				getX(), getY(),//屏幕左上点
//				getX()+getW(), getY()+getH(),//屏幕右下点
//				imgx, imgy, //图片左上点
//				imgx+imgw,imgy+imgh, //图片右下点
//				null);
		
	}

	public void moveElement() {

		
	}

	public void updateElement(boolean bl, int key) {

		
	}
}
