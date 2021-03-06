package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;

public class GameBG extends SuperElement{
	private Image img;
	private int imgx;//ͼƬ��ȡ�����Ͻ�x
	private int imgy;//ͼƬ��ȡ�����Ͻ�y
	private int imgw;//ͼƬ��ȡ��w
	private int imgh;//ͼƬ��ȡ��h
	
	
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
//				getX(), getY(),//��Ļ���ϵ�
//				getX()+getW(), getY()+getH(),//��Ļ���µ�
//				imgx, imgy, //ͼƬ���ϵ�
//				imgx+imgw,imgy+imgh, //ͼƬ���µ�
//				null);
		
	}

	public void moveElement() {

		
	}

	public void updateElement(boolean bl, int key) {

		
	}
}
