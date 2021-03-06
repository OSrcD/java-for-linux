package game.frame;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.util.List;
import java.util.Map;

import javax.swing.JPanel;

import game.element.GameManager;
import game.element.vo.SuperElement;

/**
 * @˵�� ��Ϸ��ʾ����
 * @ְ�� ����� Ԫ�ع������� ��ȡԪ������
 *      ����ͳһ�ķ�������Ԫ����ʾ�滭�Լ�
 */
public class GameJPanel extends JPanel{
	/**
	 * @˵�� ��д����� �滭����  Graphics �ǻ���
	 */
	public void paint(Graphics g) {
		super.paint(g);

//		�����Ϸ�Ѿ�����������ʾԪ�ص�
		
		if(GameManager.getGameManager().isGamefirst()){
			paintTitles(g);
			if(GameManager.getGameManager().timeCount>20){
		
				GameManager.getGameManager().setGameStart(true);
			}
			
			
		}
		
		if(GameManager.getGameManager().isGameStart()){
			
			paintBackground(g);//��ʾ����
			paintNpc(g);//��ʾ���˵�
			paintPlay(g);//��ʾ�����ص�
			GameManager.getGameManager().setGamefirst(false);
			if(GameManager.getGameManager().isGameoversflag()){
				paintGameovers(g);
				
				
			}
			
			if(GameManager.getGameManager().isSwapbg()){
				GameManager.getGameManager().setGameoversflag(false);
				paintBackground(g);//��ʾ����
				paintNpc(g);//��ʾ���˵�
				paintPlay(g);//��ʾ�����ص�
				
//				GameManager.getGameManager().setGameovers(null);
				GameManager.getGameManager().setSwapbg(false);
			}
		}
	}
	/**
	 * @˵�� ���ƺ������ص���������:
	 * 		1.���
	 * 		2.����ӵ�
	 * 		3.��ҷ�����Ѫ�� �ȵ�
	 */
	private void paintPlay(Graphics g) {
//		��ʾ����
		
		GameManager.getGameManager().getGamePlay().showElement(g);
		GameManager.getGameManager().getGamePlay1().showElement(g);//���2
		showBubbleElement(GameManager.getGameManager().createBubbleElement(),g);
		showBaoZhaElement(GameManager.getGameManager().createBoomList(),g);
//		��������.�õ�������.�õ���Ҷ���.��ʾ���
	}
	
	/**
	 * @˵�� ���ƺ͵���NPC��ص���������
	 * 		1.С���ˣ������
	 */
	private void paintNpc(Graphics g) {
		
	}
	/**
	 * @˵�� ���ƺͱ�����ص�
	 * 		��ɫ���ȵ� ͼƬ��  ��ͼ
	 */
	
	private void paintGameovers(Graphics g){
		GameManager.getGameManager().getGameovers().showElement(g);
		
	}
	
	private void paintTitles(Graphics g){
		GameManager.getGameManager().getTitles().showElement(g);
		
	}
	
	private void paintBackground(Graphics g) {
//		�滭������ɫ�������Ǻ�ɫ
//		this.setBackground(new Color(10,100,10));
		GameManager.getGameManager().getbeijin().showElement(g);//����
		SuperElement [][] maps=GameManager.getGameManager().getCreateMaps();
		SuperElement [][] fasts=GameManager.getGameManager().getFasts();
		
		if(fasts!=null){
			for(SuperElement[] ses:fasts){
				for(SuperElement se:ses){
					if (se!=null )
					
						se.showElement(g);
				}
			}
		}
		
		if(maps!=null){
			for(SuperElement[] ses:maps){
				for(SuperElement se:ses){
					if (se!=null  )
					
						se.showElement(g);
				}
			}
		}
		
		
		
		
	}
	private void showBubbleElement(List<SuperElement> list,Graphics g){
		for(int i=0;i<list.size();i++){
			list.get(i).showElement(g);
		}
	}
	
	private void showBaoZhaElement(List<SuperElement> baoZhalist, Graphics g) {
		// TODO Auto-generated method stub
		for(int i=0;i<baoZhalist.size();i++){
			baoZhalist.get(i).showElement(g);
		}
		
	}
	
}








