package game.element.vo;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;

public class MapElement extends SuperElement{
	private int imgx;//ͼƬ��ȡ�����Ͻ�x
	private int imgy;//ͼƬ��ȡ�����Ͻ�y
	private int imgw;//ͼƬ��ȡ��w
	private int imgh;//ͼƬ��ȡ�ĸ߶�
	private boolean bad;//�Ƿ���Ա��ݻ� 
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
