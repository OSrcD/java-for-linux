package game.element.vo;

import java.awt.Graphics;
import java.awt.Rectangle;

import game.element.GameManager;

/**
 * @author admin
 * @说明 所有界面元素的 父类
 * @职责 1.元素基本属性的抽象，并提供get set方法
 *       2.元素基本方法的抽象，部分共有方法提供算法
 *       3.要最少提供2个构造方法
 *         一个是默认构造，防止子类继承报错
 *         一个是所有参数构造，方便子类传递参数
 */
public abstract class SuperElement {
	private int x;//屏幕显示左上角X 偏移量4个像素
	private int y;//屏幕显示左上角Y 偏移量25个像素
	private int w;//显示的宽度
	private int h;//显示的高度
	private boolean visible;//是否死亡默认false
	private int whobubble;//是否死亡默认false
	public SuperElement(){}
	public SuperElement(int x, int y, int w, int h) {
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
		this.visible=false;
	}
	
	
	public int getWhobubble() {
		return whobubble;
	}
	public void setWhobubble(int whobubble) {
		this.whobubble = whobubble;
	}
	public SuperElement(int x, int y, int w, int h,int whobubble) { //重载
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
		this.visible=visible;
		this.whobubble=whobubble;
	}
	
	
	
	
	
	public SuperElement(int x, int y, int w, int h,boolean visible) { //重载
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
		this.visible=visible;
	}
	
	
	/**显示方法*/
	public abstract void showElement(Graphics g);
	
	/**移动方法*/
	public abstract void moveElement();
	
	/**改变状态方法 bl=true为按下 false为松开，key为数值*/
	public abstract void updateElement(boolean bl,int key);
	
	
	
	public int getX() {
		return x;
	}
//	public int getShowX(){//专门用于进行显示的
//		return x+4;
//	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
//	public int getShowY(){//专门用于进行显示的
//		return y+25;
//	}
	public void setY(int y) {
		this.y = y;
	}
	public int getW() {
		return w;
	}
	public void setW(int w) {
		this.w = w;
	}
	public int getH() {
		return h;
	}
	public void setH(int h) {
		this.h = h;
	}
	public boolean isVisible() {
		return visible;
	}
	public void setVisible(boolean visible) {
		this.visible = visible;
	}
	public int getPKX(){
		return x+w/2;
	}
	public int getPKY(){
		return y+h/2;
	}
	public Rectangle getRectangle(){
		return new Rectangle(x,y,w,h);
	}
	
//	se 是玩家
	public boolean PK(SuperElement se){
//		java.awt.Rectangle
//		int i=se.getPKX()/40;//将坐标变为 2维数组的下标
//		int j=se.getPKY()/40;
//		if(GameManager.getGameManager().getMaps()[i][j]!=null){
//			return true;
//		}
	return this.getRectangle().intersects(se.getRectangle());
		
	/**
	 * 优化碰撞
	 * Rectangle r1 = this.getRectangle();
	 * Rectangle r2 = se.getRectangle();
	 * 
	 * return r1.intersects(se.getRectangle())
	 */
	
	
	}
	
	
	
	
	
	
	
	
}




