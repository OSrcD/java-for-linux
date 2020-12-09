package game.element.vo;

import java.awt.Graphics;
import java.awt.Rectangle;

import game.element.GameManager;

/**
 * @author admin
 * @˵�� ���н���Ԫ�ص� ����
 * @ְ�� 1.Ԫ�ػ������Եĳ��󣬲��ṩget set����
 *       2.Ԫ�ػ��������ĳ��󣬲��ֹ��з����ṩ�㷨
 *       3.Ҫ�����ṩ2�����췽��
 *         һ����Ĭ�Ϲ��죬��ֹ����̳б���
 *         һ�������в������죬�������ഫ�ݲ���
 */
public abstract class SuperElement {
	private int x;//��Ļ��ʾ���Ͻ�X ƫ����4������
	private int y;//��Ļ��ʾ���Ͻ�Y ƫ����25������
	private int w;//��ʾ�Ŀ��
	private int h;//��ʾ�ĸ߶�
	private boolean visible;//�Ƿ�����Ĭ��false
	private int whobubble;//�Ƿ�����Ĭ��false
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
	public SuperElement(int x, int y, int w, int h,int whobubble) { //����
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
		this.visible=visible;
		this.whobubble=whobubble;
	}
	
	
	
	
	
	public SuperElement(int x, int y, int w, int h,boolean visible) { //����
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
		this.visible=visible;
	}
	
	
	/**��ʾ����*/
	public abstract void showElement(Graphics g);
	
	/**�ƶ�����*/
	public abstract void moveElement();
	
	/**�ı�״̬���� bl=trueΪ���� falseΪ�ɿ���keyΪ��ֵ*/
	public abstract void updateElement(boolean bl,int key);
	
	
	
	public int getX() {
		return x;
	}
//	public int getShowX(){//ר�����ڽ�����ʾ��
//		return x+4;
//	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
//	public int getShowY(){//ר�����ڽ�����ʾ��
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
	
//	se �����
	public boolean PK(SuperElement se){
//		java.awt.Rectangle
//		int i=se.getPKX()/40;//�������Ϊ 2ά������±�
//		int j=se.getPKY()/40;
//		if(GameManager.getGameManager().getMaps()[i][j]!=null){
//			return true;
//		}
	return this.getRectangle().intersects(se.getRectangle());
		
	/**
	 * �Ż���ײ
	 * Rectangle r1 = this.getRectangle();
	 * Rectangle r2 = se.getRectangle();
	 * 
	 * return r1.intersects(se.getRectangle())
	 */
	
	
	}
	
	
	
	
	
	
	
	
}




