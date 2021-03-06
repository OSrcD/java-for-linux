package game.frame;

import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.border.EmptyBorder;

import game.element.GameManager;

/**
 * @author admin
 * @˵�� ��Ϸ������
 * @ְ�� 1.��Ϸ�������ʾ(��С��λ�õȵ�)  OK
 *       2.��Ϸ����ļ���                                 OK
 *       3.��Ϸ�����ļ���(���̣����)     OK
 *       4.��Ϸ�������̵߳�����                      OK
 */
public class GameFrame extends JFrame{
//	���췽��

	private Image image;
	public GameFrame(){
		init();//��ɽ���� ��С�� ��ʼ������
	}
	/**
	 * ר�����ڽ��г�ʼ��������д�����㽫�������ţ�������д
	 */
	public void init(){
		
		this.setSize(800, 610);//��С  �����Ϊ����
		this.setTitle("������");//����
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//�ر�״̬
		this.setResizable(false);//�̶������С
		this.setLocationRelativeTo(null);//����
		
	
    	

		
		
		
		
		
		
		
		
	
    	
	}
	/**
	 * @˵�� ר�ż�����廭��
	 * @param jp
	 */
	public void LoadJPanel(JPanel jp){
		this.add(jp);
		
	}
	/**@˵�� ��Ӽ��̼����¼�
	*/
	public void loadKeyListener(KeyListener key){
		this.addKeyListener(key);
	}
	/**@˵�� ����������¼�
	*/
	public void loadMouseListener(
				 MouseListener ml,
				 MouseMotionListener mml){
//		���������ͽ����˳����� ����
		this.addMouseListener(ml);
//		�������ƶ�����
		this.addMouseMotionListener(mml);
	}
	/**
	 * @˵�� ������Ϸ����������Ϸ�еĶ��߳� �Զ�������
	 * @param th
	 */
	public void gameStart(Thread th){
		this.setVisible(true);//���ô���ɼ�
		th.start();//�߳�����
		
	}
}






