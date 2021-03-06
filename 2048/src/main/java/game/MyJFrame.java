package game;

import java.awt.event.KeyListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class MyJFrame extends JFrame{
	/**
	 * 1.�����Լ������ã��̳���JFrame �� ��Ϊһ�����塣�������ö�����д�� ���췽����
	 * 2.���ȼ���:1.��屾����һ��������Ҫ����ſ��Լ��� 2.��屾��Ҳ��Ҫ���ˢ�£�����ܼ�¼һ������
	 * 3.�����ļ���
	 * 4.��ʾ����:�����ķ��� showFrame()
	 */
	private JPanel jPanel;
	
	public MyJFrame(){//Ĭ�Ϲ��췽��  �޲ι���
		
//		super();  ��仰���ص�  ���ø���Ĺ��췽��
//		���飬��ò�Ҫ�ڹ��췽���� д̫��ĳ�ʼ�������������ʼ������Ҫ�ı�
		init();//�����������������ʼ���ģ���Ϊ���췽�������Ա��̳к���д������ͨ��������
	}
//	�ܱ����ķ��� ͬ�������� �ſ��Է��ʣ�����Ҳ���Ծ�����д(��̬��һ�ַ�ʽ)
	protected void init(){
		setTitle("2048");
		setSize(400,430);//�߶�Ҫ���� title�ĸ߶�
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setResizable(true);
		setLocationRelativeTo(null);
	
	}
	public void addJPanel(JPanel jPanel){
		this.jPanel=jPanel;
		add(this.jPanel);//������� ��� jf.add(jp)
	}
	
//	���Է���
//	public static void main(String[] args) {
//		MyJFrame jf=new MyJFrame();
//		jf.addListener("aaa","bbb","ccc");//����һ���Դ����� ��������
//	}
	
	
//	����ֻ�����һ������ �����ļ�����3��  ���� instanceof ��(�ӿ�) 
	public void addListener(Object... listeners){// Object... objects �ɱ䳤����
//		addKeyListener(listener);//�Ǹ���ķ���
		for(Object listener : listeners){
			if(listener instanceof KeyListener){//���̼���
//				�����listener�� KeyListener ��ʵ����� �� ǿ������ת���� ���뵽���̼�����
				addKeyListener((KeyListener)listener);
			}
			if(listener instanceof MouseListener){//������
				addMouseListener((MouseListener)listener);
			}
			if(listener instanceof MouseMotionListener){//����ƶ�����
				addMouseMotionListener((MouseMotionListener)listener);
			}
			
		}
	}
	
	
//	��ʾ����ķ���;���滹�������߳�
	public void showFrame(){
		setVisible(true);
		if(jPanel instanceof Runnable){
			Runnable r=(Runnable)jPanel;
			Thread th=new Thread(r);//thread(Runnable r)��ʵ�ֶ��߳�
			th.start();
		}
	}
	
	
	
}
