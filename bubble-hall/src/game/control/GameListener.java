package game.control;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import game.element.GameManager;

/**
 * @author admin
 * @说明 游戏监听类
 * @职责 只负责进行游戏的鼠标键盘的监听
 *      需要通过 元素管理器 获取元素
 *      修改元素的控制属性(状态)
 * @implements 接口实现2个 键盘和鼠标
 */
public class GameListener implements 
		KeyListener,MouseListener,MouseMotionListener{
///////////////////以下 键盘监听///////////////////////	
	public void keyTyped(KeyEvent e) {/*不用处理,继承接口必须实现接口所有方面，不能删除*/}
	/**
	 * @说明 键盘按下： 会一直接收
	 */
	public void keyPressed(KeyEvent e) {
//		System.out.println("按下:"+e.getKeyCode());
		GameManager.getGameManager().
			getGamePlay().updateElement(true, e.getKeyCode()); //按键按下人物移动触发，传递给子类的各个updateElement方法
		
		GameManager.getGameManager().
		getGamePlay1().updateElement(true, e.getKeyCode()); //按键按下人物移动触发，同理
	}
	/**
	 * @说明 键盘松开： 松开的时候接收1次
	 */
	public void keyReleased(KeyEvent e) {
//		System.out.println("松开:"+e.getKeyCode());
		GameManager.getGameManager().
			getGamePlay().updateElement(false, e.getKeyCode()); //按键松开相关代码，同理
		
		GameManager.getGameManager().
		getGamePlay1().updateElement(false, e.getKeyCode()); //按键松开相关代码，同理
	}
///////////////////以上  键盘监听///////////////////////
///////////////////以下  鼠标点击监听///////////////////////
	/**鼠标点击事件*/
	public void mouseClicked(MouseEvent e) {
//		System.out.println("click:"+e.getButton()+":"+ 
//		       e.getX()+":"+e.getY()); 
//		不能删除
	}
	/**鼠标按下事件*/
	public void mousePressed(MouseEvent e) {
//		System.out.println("Pressed:"+e.getButton()+":"+
//				       e.getX()+":"+e.getY());
//		不能删除
	}
	/**鼠标松开事件*/
	public void mouseReleased(MouseEvent e) {
//		System.out.println("Released:"+e.getButton()+":"+
//				       e.getX()+":"+e.getY());
//		不能删除
	}
	/**鼠标进入监听*/
	public void mouseEntered(MouseEvent e) {
//		System.out.println(
//				"Entered="+e.getX()+":"+e.getY());
//		不能删除
	}
	/**鼠标退出监听*/
	public void mouseExited(MouseEvent e) {
//		System.out.println(
//				"Exited="+e.getX()+":"+e.getY());
//		不能删除
	}
///////////////////以上  鼠标点击监听///////////////////////
///////////////////以下  鼠标移动监听///////////////////////
	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
//		不能删除
	}
	/*鼠标移动*/
	public void mouseMoved(MouseEvent e) {
//		System.out.println(e.getX()+":"+e.getY());
//		不能删除
	}
///////////////////以上  鼠标移动监听///////////////////////
	
}









