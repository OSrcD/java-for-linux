package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;

public class MapElement extends SuperElement{
	private int imgx;//图片截取的左上角x
	private int imgy;//图片截取的左上角y
	private int imgw;//图片截取的w
	private int imgh;//图片截取的高都
	private boolean bad;//是否可以被摧毁 
	private Image img;
	public MapElement(int x, int y, int w, int h,
			int imgx,int imgy,int imgw,int imgh,Image img,boolean bad
			) {
		super(x, y, w, h,bad);
		this.img=img;
		this.bad=bad;
		this.imgh=imgh;
		this.imgw=imgw;
		this.imgx=imgx;
		this.imgy=imgy;
	}
	public static MapElement getMapElement(int x, int y, int w, int h,
			int imgx,int imgy,int imgw,int imgh,Image img,boolean bad) {
		return new MapElement(x, y, w, h, imgx, imgy, imgw, imgh, img, bad);
	}
	

	
	
	
	
	
	@Override
	public void showElement(Graphics g) {
		g.drawImage(img, 
				getX(), getY(),//屏幕左上点
				getX()+getW(), getY()+getH(),//屏幕右下点
				imgx, imgy, //图片左上点
				imgx+imgw,imgy+imgh, //图片右下点
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

	public boolean isBad() {
		return bad;
	}

	public void setBad(boolean bad) {
		this.bad = bad;
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
	public Image getImg() {
		return img;
	}
	public void setImg(Image img) {
		this.img = img;
	}
	
	
}
