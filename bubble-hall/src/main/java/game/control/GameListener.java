package game.control;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import game.element.GameManager;

/**
 * @author admin
 * @˵�� ��Ϸ������
 * @ְ�� ֻ���������Ϸ�������̵ļ���
 *      ��Ҫͨ�� Ԫ�ع����� ��ȡԪ��
 *      �޸�Ԫ�صĿ�������(״̬)
 * @implements �ӿ�ʵ��2�� ���̺����
 */
public class GameListener implements 
		KeyListener,MouseListener,MouseMotionListener{
///////////////////���� ���̼���///////////////////////	
	public void keyTyped(KeyEvent e) {/*���ô���,�̳нӿڱ���ʵ�ֽӿ����з��棬����ɾ��*/}
	/**
	 * @˵�� ���̰��£� ��һֱ����
	 */
	public void keyPressed(KeyEvent e) {
//		System.out.println("����:"+e.getKeyCode());
		GameManager.getGameManager().
			getGamePlay().updateElement(true, e.getKeyCode()); //�������������ƶ����������ݸ�����ĸ���updateElement����
		
		GameManager.getGameManager().
		getGamePlay1().updateElement(true, e.getKeyCode()); //�������������ƶ�������ͬ��
	}
	/**
	 * @˵�� �����ɿ��� �ɿ���ʱ�����1��
	 */
	public void keyReleased(KeyEvent e) {
//		System.out.println("�ɿ�:"+e.getKeyCode());
		GameManager.getGameManager().
			getGamePlay().updateElement(false, e.getKeyCode()); //�����ɿ���ش��룬ͬ��
		
		GameManager.getGameManager().
		getGamePlay1().updateElement(false, e.getKeyCode()); //�����ɿ���ش��룬ͬ��
	}
///////////////////����  ���̼���///////////////////////
///////////////////����  ���������///////////////////////
	/**������¼�*/
	public void mouseClicked(MouseEvent e) {
//		System.out.println("click:"+e.getButton()+":"+ 
//		       e.getX()+":"+e.getY()); 
//		����ɾ��
	}
	/**��갴���¼�*/
	public void mousePressed(MouseEvent e) {
//		System.out.println("Pressed:"+e.getButton()+":"+
//				       e.getX()+":"+e.getY());
//		����ɾ��
	}
	/**����ɿ��¼�*/
	public void mouseReleased(MouseEvent e) {
//		System.out.println("Released:"+e.getButton()+":"+
//				       e.getX()+":"+e.getY());
//		����ɾ��
	}
	/**���������*/
	public void mouseEntered(MouseEvent e) {
//		System.out.println(
//				"Entered="+e.getX()+":"+e.getY());
//		����ɾ��
	}
	/**����˳�����*/
	public void mouseExited(MouseEvent e) {
//		System.out.println(
//				"Exited="+e.getX()+":"+e.getY());
//		����ɾ��
	}
///////////////////����  ���������///////////////////////
///////////////////����  ����ƶ�����///////////////////////
	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
//		����ɾ��
	}
	/*����ƶ�*/
	public void mouseMoved(MouseEvent e) {
//		System.out.println(e.getX()+":"+e.getY());
//		����ɾ��
	}
///////////////////����  ����ƶ�����///////////////////////
	
}









