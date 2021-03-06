package game;

import java.awt.Graphics;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JPanel;

/**
 * java�ǵ��̳� ��ʵ�ֽӿ�
 * 
 * ���������Ҫʵ�ֵĶ���Ϊ��
 * 1.�ܻ滭 ���е�Ԫ��
 * 	���Է������е�Ԫ�� -> ������Ԫ�ض���� ����
 * 	����̳� �� JPanel
 * 2.���Լ����в�ͣ��ˢ��
 * 	���߳�->thread ֱ��ʵ�ֶ��̵߳� �ӿ��� Runnable
 *
 *�������˼�� -> ����ӿڱ��
 */
public class MyJPanel extends JPanel implements Runnable{
//	����Ԫ�ض��� 
	List<ElementShowInerface> list = null;//�Ƕ����һ������  ���⣺���ǿ��Ƶ���һ�����������ô�Ƿ���Ҫ�ŵ�����
//	����һ�����򼯺� <object> �Ƿ��� -> list�� ֻ���� �洢 object���� ���� ���� �� ʵ�����
//	List<ElementShowInterface> starList = null;
	
	public MyJPanel(){
		init();
	}
//	���������� ��д
	protected void init(){
		list = new ArrayList<ElementShowInerface>();
//		starList = new ArrayList<ElementShowInterface>();
//		ÿ������� ����   ������ɲ�Ӧ�������Ӧ������Դ��������
		list.add(GameElement.createGameElement());
	}
	public void paint(Graphics g) {
		super.paint(g);
//		���� ר����ʾԪ��
		showListElement(list,g);
//		showListElement(starList,g);
	}
//	������ʾ���еļ���
	public void showListElement(List<ElementShowInerface> list,Graphics g){
//		for(int i=0;i<list.size();i++){
//			ElementShowInterface element = list.get(i);
//		}
		for(ElementShowInerface element : list){
			element.show(g);
		}
		
		
	}
	@Override	//thread����д��
	public void run() {//ר���������� ˢ�½����
		while(true){
			repaint();//���»滭
//			���Դ���
			for(ElementShowInerface element:list){
				element.move();
			}
			
			try {
				Thread.sleep(45);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
}
