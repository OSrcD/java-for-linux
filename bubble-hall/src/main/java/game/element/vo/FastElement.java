package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;

public class FastElement extends SuperElement {
	private Image img;
	private int imgx;
	private int imgy;
	private int imgw;
	private int imgh;
	private boolean touchFast;
	


	public FastElement(int x, int y, int w, int h,int imgx,int imgy,int imgw,int imgh,Image img,boolean touchFast) {
		super(x, y, w, h);
		this.imgx=imgx;
		this.imgy=imgy;
		this.imgw=imgw;
		this.imgh=imgh;
		this.img=img;
		this.touchFast=touchFast;
	}
	
	public static FastElement createFastElement(int x,int y,int w,int h,int imgx,int imgy,int imgw,int imgh,Image img,boolean touchFast){
		
		
		return new FastElement(x,y,w,h,imgx,imgy,imgw,imgh,img,touchFast);
	}
	

	@Override
	public void showElement(Graphics g) {
		// TODO Auto-generated method stub
		g.drawImage(img, 
				getX(), getY(),//��Ļ���ϵ�
				getX()+getW(), getY()+getH(),//��Ļ���µ�
				imgx, imgy, //ͼƬ���ϵ�
				imgx+imgw,imgy+imgh, //ͼƬ���µ�
				null);
	}

	@Override
	public void moveElement() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void updateElement(boolean bl, int key) {
		// TODO Auto-generated method stub
		
	}

	public boolean isTouchFast() {
		return touchFast;
	}

	public void setTouchFast(boolean touchFast) {
		this.touchFast = touchFast;
	}
	
	

}
