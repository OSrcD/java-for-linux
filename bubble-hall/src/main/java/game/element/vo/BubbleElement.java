package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;

import game.element.GameManager;

public class BubbleElement extends SuperElement {
	private Image img;
	private int imgx;
	private int imgy;
	private int imgw;
	private int imgh;
	private int imgcol;
	private boolean givebubble;
	private int baozhaTime;
	private int whobubble;
	
	
	
	
	public int getWhobubble() {
		return whobubble;
	}

	public void setWhobubble(int whobubble) {
		this.whobubble = whobubble;
	}

	public BubbleElement(int x, int y, int w, int h,int imgx,int imgy,int imgw,int imgh,int imgcol,boolean givebubble,
			int baozhaTime,Image img,int whobubble) {
		super(x, y, w, h);
		this.imgx=imgx;
		this.imgy=imgy;
		this.imgw=imgw;
		this.imgh=imgh;
		this.imgcol=imgcol;
		this.givebubble=givebubble;
		this.img=img;
		this.baozhaTime=GameManager.timeCount;
		this.whobubble=whobubble;
		
		
	}
	
	//小工厂
	public static BubbleElement createBubbleElement(int x, int y, int w, int h,int imgx,int imgy,int imgw,int imgh,int imgcol,boolean givebubble,
			int baozhaTime,Image img,boolean myBoomflag,int whobubble){
		
	
		return new BubbleElement(x,y,w, h,imgx, imgy, imgw, imgh, imgcol, givebubble,
				 baozhaTime,img,whobubble);
	}
	

	@Override
	public void showElement(Graphics g) {
		// TODO Auto-generated method stub
		g.drawImage(img, getX(), getY(),
				getX()+getW(), //屏幕上
				getY()+getH(),//屏幕下
				imgx, 32*imgcol+imgy,//图片左上点
				imgx+imgw, 32*imgcol+imgy+imgh, //图片下
				null);
	}

	@Override
	public void moveElement() {
		// TODO Auto-generated method stub
	
		if(GameManager.timeCount-this.baozhaTime>=30){
			this.setVisible(true);	
		}
		
		
	}
	


	@Override
	public void updateElement(boolean bl, int key) {
		// TODO Auto-generated method stub
		
	}

	public int getBaozhaTime() {
		return baozhaTime;
	}

	public void setBaozhaTime(int baozhaTime) {
		this.baozhaTime = baozhaTime;
	}

	public boolean isGivebubble() {
		return givebubble;
	}

	public void setGivebubble(boolean givebubble) {
		this.givebubble = givebubble;
	}

	public Image getImg() {
		return img;
	}

	public void setImg(Image img) {
		this.img = img;
	}

	public int getImgx() {
		return imgx;
	}

	public void setImgx(int imgx) {
		this.imgx = imgx;
	}

	public int getImgy() {
		return imgy;
	}

	public void setImgy(int imgy) {
		this.imgy = imgy;
	}

	public int getImgw() {
		return imgw;
	}

	public void setImgw(int imgw) {
		this.imgw = imgw;
	}

	public int getImgh() {
		return imgh;
	}

	public void setImgh(int imgh) {
		this.imgh = imgh;
	}

	public int getImgcol() {
		return imgcol;
	}

	public void setImgcol(int imgcol) {
		this.imgcol = imgcol;
	}

	




	
	
	
	
	
	
	//setget
	
	
	
}
