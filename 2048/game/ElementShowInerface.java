package game;

import java.awt.Graphics;

/**
 * 规定：只要是想显示在 界面上的元素，都必须实现这个接口
 * 
 * 接口就是一个标准，实现这个标准就可以连接上 显示功能
 */
public interface ElementShowInerface {
	public void show(Graphics g);
	public void move();
}
