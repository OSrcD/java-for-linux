package game.control;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.List;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import game.element.GameLoad;
import game.element.GameManager;
import game.element.vo.BubbleElement;
import game.element.vo.GamePlay;
import game.element.vo.GamePlay1;
import game.element.vo.MapElement;
import game.element.vo.SuperElement;
import game.element.vo.audio;
import game.element.vo.audionorepeat;
import game.frame.GameMain;
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

/**
 * @author admin
 * @˵�� ���ڿ��� ��Ϸ�Ľ���
 * @ְ�� 1.������Ϸ����
 *       2.�����Զ�����NPC��Ϊ
 *       3.����״̬���Ըı��Ӧ�� Ԫ�ص�����
 *       4.Ԫ����Ԫ��֮��Ĺ�ϵ-���磺��ײ,�����ӵ�
 *       5.Ԫ�ص�����
 */
public class GameThread extends Thread{//�̳ж��̵߳ģ��Ҿ�ӵ�ж��̵߳Ĺ���
	
	public void run(){//���̷߳���
		while(true){
//			ǰϷ����Դ���� ������,����ͼƬ�ز�
			ready();
		
//			����ʱ������Ϸ�Ĺ�����
			work();
			
//			����:
			over();
			
		}
	}
//	׼������������ ���ؿ����ز�һ����Ԫ��
	private void ready() { 
		
//		���� .       �õ���Դ������     .�õ�������  . ����
		GameManager.getGameManager().getGLoad().load();    //����ͼƬ�ز�
//		���ж���Ĵ���
	
		GameManager.getGameManager().LoadElement();    //������ң����ص�ͼͼƬ���� ���ر�����

		
		GameManager.getGameManager().setGamefirst(true);
		
		
		
	}
//	�ؿ�����ʱ
	private void work() {
//		��Ϸ����
//		GameManager.getGameManager().setGameStart(true);
		while(true){
			
			elementMove();//���ƶ�
			elementTimeDisappear();//������ʧ��ʱ���ж�
			elementUpdate();//����״̬�޸�����
			elementPK();// ��ײ
			elementDestroy();//����
//			��Ϊ�����ܵĺܿ죬����ʹ������
			try {
				Thread.sleep(100);//����100����
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			GameManager.timeCount++;//����ʱ����ʧ����
		
//			����Դ�������л�ȡ ��壬����ѭ��ˢ��
			GameManager.getGameManager()           //�ػ�
					.getJPanel().repaint();
		}
	}
//	�ؿ�����ʱ
	private void over() {
	audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/ByeBye.mp3").getPath()));
	bubbleAudio.start();
	int x = JOptionPane.showConfirmDialog(null,"�����¿�ʼ��","��Ϸ��ʾ",JOptionPane.YES_NO_OPTION);
		//java �Ի���api���� ֱ�������ã�����Ҫ֪��ԭ��
	
	
		if(x==0){
			SuperElement [][] myBooms=GameManager.getGameManager().getGLoad().getCreateBoomArray();//ʵʱ��ò��Ƶ�ת���Ķ�ά����
			List<SuperElement> BoomList = GameManager.getGameManager().createBoomList();//�ײ�ԭ��������������Ϊ���ݽṹ������Ա�˳���
			SuperElement [][] BubblePK = GameManager.getGameManager().getGLoad().getBubblePK();
			//BoomList�ǲ���ͼ��
			
			for(int i=0;i<myBooms.length;i++){
				for(int j=0;j<myBooms[i].length;j++){
					if(myBooms[i][j]!=null){//��ֹ���������
						myBooms[i][j]=null; //����ը�������
					
					}
				}
			}
			
		 
			for(int i=0;i<BubblePK.length;i++){
				for(int j=0;j<BubblePK[i].length;j++){
					if(BubblePK[i][j]!=null){
						BubblePK[i][j]=null;
					}
				}
			}
			
			BoomList.removeAll(BoomList);//�������б�ը����
			
			GameManager.getGameManager().createBubbleElement().removeAll(GameManager.getGameManager().createBubbleElement());
			//������
			
			GameManager.getGameManager().setSwapbg(true);
			ready();//���¶�ȡ�ؿ�
			
		}else{
			System.exit(0);
		}
		
	}
	



	
	/**Ԫ�غ�Ԫ��֮�����ײ*/
	private void elementPK() {
		SuperElement [][] myMaps=GameManager.getGameManager().getCreateMaps();//��õ�ͼ��ά�������
		SuperElement [][] myBooms=GameManager.getGameManager().getGLoad().getCreateBoomArray();//���ת����Ĳ��ƶ�ά�������
		SuperElement [][] myFatst = GameManager.getGameManager().getFasts();//���Ь�Ӷ���
		SuperElement [][] BubblePK = GameManager.getGameManager().getGLoad().getBubblePK();
		List<SuperElement> myBubbleList =GameManager.getGameManager().createBubbleElement();
	
		if(GameManager.getGameManager().isplayDieFlag()){
			boolean playPKplay = GameManager.getGameManager().getGamePlay1().PK(GameManager.getGameManager().getGamePlay());
			if(playPKplay){

				audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/die.mp3").getPath()));
				bubbleAudio.start();			
				GameManager.getGameManager().setGameoversflag(true);
				
				over();
				
				GameManager.getGameManager().setplayDieFlag(false);
			}
			
		}
		
		if(GameManager.getGameManager().isPlayDieflag1()){
			boolean playPKplay = GameManager.getGameManager().getGamePlay().PK(GameManager.getGameManager().getGamePlay1());
			if(playPKplay){

				audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/die.mp3").getPath()));
				bubbleAudio.start();
				GameManager.getGameManager().setGameoversflag(true);
				over();
				GameManager.getGameManager().setPlayDieflag1(false);
			}
			
		}
		
		
		
		
		

		
			for(int i=0;i<myBooms.length;i++){
				for(int j=0;j<myBooms[i].length;j++){
					if(myBooms[i][j]!=null){//�����Է��ʿ�����

//						if(myMaps[i][j]!=null){
//							boolean mapBoomFlag =myBooms[i][j].PK(myMaps[i][j]);   //����ը�ɴݻٵ�ͼ�����ж�
//							if(mapBoomFlag){
//							if(!(i==0 || i==14 || j==0 || j==14 || j==13)) //�ıߵ�ͼԪ�ز��ɴݻ�
//								myMaps[i][j]=null;
//							}
//						}
						
						//��������ɫ��������ֻ���ͼƬ��
						GamePlay GamePlayDie = (GamePlay)GameManager.getGameManager().getGamePlay();
						//�����벨�ƶ�ά���������ײ ���Ϊtrue ������,���false���෴
						GamePlayDie.setPlayDieFlag(myBooms[i][j].PK(GameManager.getGameManager().getGamePlay()));
						for(int b=0;b<myBubbleList.size();b++){
							
							boolean BoomandBubble = myBooms[i][j].PK(myBubbleList.get(b));
							
							if(BoomandBubble){
								
								myBubbleList.get(b).setVisible(true);
								}
							}
						
							
						//��������ɫ��������ֻ���к���
						GamePlay1 GamePlayDie1 = (GamePlay1)GameManager.getGameManager().getGamePlay1();
						//ͬ��
						GamePlayDie1.setPlayDieFlag(myBooms[i][j].PK(GameManager.getGameManager().getGamePlay1()));
					
						
								
						
						//�������ͽ�����Ϸ��
						if(GamePlayDie.isPlayDieFlag()){ 										//��������
							GameManager.getGameManager().setplayDieFlag(true); 
//							over();//���ý�������
							GamePlayDie.timedie=GameManager.timeCount;
						
						}
						
						if(GamePlayDie1.isPlayDieFlag()){
							GameManager.getGameManager().setPlayDieflag1(true);
							GamePlayDie1.timedie=GameManager.timeCount;
							
						}
					}
				}
			}
			GamePlay GamePlayDie = (GamePlay)GameManager.getGameManager().getGamePlay();
			GamePlay1 GamePlayDie1 = (GamePlay1)GameManager.getGameManager().getGamePlay1();
			if(GameManager.getGameManager().isPlayDieflag1()){
				if(GameManager.timeCount-GamePlayDie1.timedie>=30 ){

					audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/save.mp3").getPath()));
					bubbleAudio.start();
					
					
				
					GameManager.getGameManager().setPlayDieflag1(false);
				}	
			}
			
			if(GameManager.getGameManager().isplayDieFlag()){
				if(GameManager.timeCount-GamePlayDie.timedie>=30 ){

					audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/save.mp3").getPath()));
					bubbleAudio.start();
					
					
					
					GameManager.getGameManager().setplayDieFlag(false);
				}	
			}
			
	
			
			
			
			
		
		//Ь��������ײ
			boolean bl2 = false;
			boolean bl3 =false;
			
			
			
			
			if(myFatst[2][2]!=null&& myMaps[2][2]==null ){
				bl2 = myFatst[2][2].PK(GameManager.getGameManager().getGamePlay());
				 bl3 = myFatst[2][2].PK(GameManager.getGameManager().getGamePlay1());
				 if(bl2){
					 SuperElement se=(GameManager.getGameManager().getGamePlay()); //
						GamePlay gp=(GamePlay)se;//����ָ������ �ڶ�̬�о������õ�
						if(gp.getSudu()==15){
							gp.setSudu(gp.getSudu());
							myFatst[2][2]=null;//Ь��ͼƬ������ʧ

							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
						}else{
							gp.setSudu(gp.getSudu()+5); 
							myFatst[2][2]=null;//Ь��ͼƬ������ʧ

							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
				 }
				 }
				 
						 if(bl3){
							 SuperElement se1=(GameManager.getGameManager().getGamePlay1()); //
								GamePlay1 gp1=(GamePlay1)se1;//����ָ������ �ڶ�̬�о������õ�
								if(gp1.getSudu()==15){
									gp1.setSudu(gp1.getSudu());
									myFatst[2][2]=null;//Ь��ͼƬ������ʧ

									audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
									bubbleAudio.start();
								}else{
									gp1.setSudu(gp1.getSudu()+5); 
									myFatst[2][2]=null;//Ь��ͼƬ������ʧ
									audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
									bubbleAudio.start();
						 }
						
						
						
						 }
				 }
			
			
			
			
			
			if(myFatst[12][12]!=null &&myMaps[12][12]==null){
				bl2 = myFatst[12][12].PK(GameManager.getGameManager().getGamePlay());
				 bl3 = myFatst[12][12].PK(GameManager.getGameManager().getGamePlay1());
				 if(bl2){
					 SuperElement se=(GameManager.getGameManager().getGamePlay()); //
						GamePlay gp=(GamePlay)se;//����ָ������ �ڶ�̬�о������õ�
						if(gp.getSudu()==15){
							gp.setSudu(gp.getSudu());
							myFatst[12][12]=null;
							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
						}else{
							gp.setSudu(gp.getSudu()+5); 
							myFatst[12][12]=null;//Ь��ͼƬ������ʧ
							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
				 }
				 }
				 
						 if(bl3){
							 SuperElement se1=(GameManager.getGameManager().getGamePlay1()); //
								GamePlay1 gp1=(GamePlay1)se1;//����ָ������ �ڶ�̬�о������õ�
								if(gp1.getSudu()==15){
									gp1.setSudu(gp1.getSudu());
									myFatst[12][12]=null;
									audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
									bubbleAudio.start();
								}else{
									gp1.setSudu(gp1.getSudu()+5); 
									myFatst[12][12]=null;//Ь��ͼƬ������ʧ
									audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
									bubbleAudio.start();
						 }
						
						
						
						 }
				 }
			
			
			
			
			
			
		for(int i=0;i<myFatst.length;i++){ 
			for(int j=0;j<myFatst[i].length;j++){
				
				
				
				if(myFatst[i][j]!=null && myMaps[i][j]==null ){
				
					
					
					
					boolean bl=myFatst[i][j].PK(GameManager.getGameManager().getGamePlay());	
					
					boolean bl1=myFatst[i][j].PK(GameManager.getGameManager().getGamePlay1());
					
					
					
					
					if(bl){
						SuperElement se=(GameManager.getGameManager().getGamePlay()); //
						GamePlay gp=(GamePlay)se;//����ָ������ �ڶ�̬�о������õ�
						
						
						
						
						
						if(gp.getBubblenum()==18 ){	
							gp.setBubblenum(gp.getBubblenum());
							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
							myFatst[i][j]=null;
						}else{
							
							
							
							gp.setBubblenum(gp.getBubblenum()+1); 
						
	
							
							myFatst[i][j]=null;//Ь��ͼƬ������ʧ
							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
						}
						
				
					
						
					}
					
					
					if(bl1)	{
						SuperElement se1=(GameManager.getGameManager().getGamePlay1());
						GamePlay1 gp1=(GamePlay1)se1;
						if(gp1.getBubblenum()==18){
							gp1.setBubblenum(gp1.getBubblenum());
							myFatst[i][j]=null;
							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
						}else{
							gp1.setBubblenum(gp1.getBubblenum()+1);
							myFatst[i][j]=null;
							audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/get.mp3").getPath()));
							bubbleAudio.start();
						}
					}
					
					
				}
			}
		}
		
		
		//��ͼ��ײ����
		
		for(int i=0;i<myMaps.length;i++){        //ѭ������
			for(int j=0;j<myMaps[i].length;j++){
				if(myMaps[i][j]!=null){
					boolean bl=myMaps[i][j].PK(GameManager.getGameManager().getGamePlay());	//��ͼ�������ɫ��ײ���
					boolean bl1=myMaps[i][j].PK(GameManager.getGameManager().getGamePlay1());//��ͼ�������ɫ��ײ���
					if(bl){//��⵽��ײ
						SuperElement se=(GameManager.getGameManager().getGamePlay()); //���ͱ����Ǹ���
						GamePlay gp=(GamePlay)se;//��Ҫ����ǿת����������ת�ͣ�һ�����ڶ�̬��
						gp.setMoveType(true);
						switch(gp.getDnxb()){ //��õ�ǰ����ķ���
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp.setY(gp.getY()-15);break; //��
					
						case 1:gp.setX(gp.getX()+15);break; //��
						case 2:gp.setX(gp.getX()-15);break; //��
						case 3:gp.setY(gp.getY()+15);break; //��
						
						}
						
						gp.setDnxb(-1);//���õ�ǰ�����ƶ�
					
						
					}
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					if(bl1){
						
						SuperElement se1=(GameManager.getGameManager().getGamePlay1());
						GamePlay1 gp1=(GamePlay1)se1;
						gp1.setMoveType(true);
						switch(gp1.getDnxb()){
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp1.setY(gp1.getY()-15);break;
						case 1:gp1.setX(gp1.getX()+15);break;
						case 2:gp1.setX(gp1.getX()-15);break;
						case 3:gp1.setY(gp1.getY()+15);break;
						
						}
						
						gp1.setDnxb(-1);
						
						
						
						
						
					}
				}
			}
		}
		
		
		
		
		
		
		
		
		
		//������ײ �����Ӵ���
		
		for(int i=0;i<BubblePK.length;i++){        //ѭ������
			for(int j=0;j<BubblePK[i].length;j++){
				if(BubblePK[i][j]!=null){
					boolean bl=BubblePK[i][j].PK(GameManager.getGameManager().getGamePlay());	//�����������ɫ��ײ���
					boolean bl1=BubblePK[i][j].PK(GameManager.getGameManager().getGamePlay1());//�����������ɫ��ײ���
					
					if(bl==false && bl1==false){
						BubblePK[i][j].setVisible(true);
						
					}
					BubbleElement myBubbleElement = (BubbleElement)BubblePK[i][j];
//					System.out.println(myBubbleElement.getImgcol());
					if(bl && myBubbleElement.getImgcol() != 0 || bl && BubblePK[i][j].isVisible() ){//��⵽��ײ
						SuperElement se=(GameManager.getGameManager().getGamePlay()); //���ͱ����Ǹ���
						GamePlay gp=(GamePlay)se;//��Ҫ����ǿת����������ת�ͣ�һ�����ڶ�̬��
						gp.setMoveType(true);
						switch(gp.getDnxb()){ //��õ�ǰ����ķ���
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp.setY(gp.getY()-15);break; //��
						case 1:gp.setX(gp.getX()+15);break; //��
						case 2:gp.setX(gp.getX()-15);break; //��
						case 3:gp.setY(gp.getY()+15);break; //��
						
						}
						
						gp.setDnxb(-1);//���õ�ǰ�����ƶ�
					}
					
				
					
					if(bl1 &&   myBubbleElement.getImgcol() != 1 || bl1 && BubblePK[i][j].isVisible()){
						
						SuperElement se1=(GameManager.getGameManager().getGamePlay1());
						GamePlay1 gp1=(GamePlay1)se1;
						gp1.setMoveType(true);
						switch(gp1.getDnxb()){
//						case 0:gp.setY(gp.getY()-18);break;
//						case 1:gp.setX(gp.getX()+18);break;
//						case 2:gp.setX(gp.getX()-18);break;
//						case 3:gp.setY(gp.getY()+18);break;
						case 0:gp1.setY(gp1.getY()-15);break;
						case 1:gp1.setX(gp1.getX()+15);break;
						case 2:gp1.setX(gp1.getX()-15);break;
						case 3:gp1.setY(gp1.getY()+15);break;
						
						}
						
						gp1.setDnxb(-1);
						
						
						
						
						
					}
				}
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	/**����״̬���޸�Ԫ������*/
	private void elementUpdate() {
			//����
	}
	
	/**����Ԫ�ص��ƶ� */
	private void elementMove() { //��ɫ�ƶ�
		GameManager.getGameManager().getGamePlay().moveElement(); //�����ƶ�
		GameManager.getGameManager().getGamePlay1().moveElement(); //�캢���ƶ�
		
	}
	
	private void elementTimeDisappear(){
		GameThread.togetherVisible(GameManager.getGameManager().createBoomList()); //��ò��Ƽ��϶���ը��ʧʱ���ж�
		GameThread.togetherVisible(GameManager.getGameManager().createBubbleElement());//������ݼ��϶���,������ʧʱ���ж�
		
	}
	
	
	
	private static void togetherVisible(List<SuperElement> togetherList) { //�����뱬ը��ʧʱ���жϺ���
		for(int i=0;i<togetherList.size();i++){
			togetherList.get(i).moveElement();//�����ж�ʱ�亯��
		}
		
	}
	
	
	
	
	
	
	
	/**�����Ѿ���Ч��Ԫ��*/
	
	private void elementDestroy() {
		DestroBubbleElement(GameManager.getGameManager().createBubbleElement());//���ݼ�������
		
		DestroyBoomElement(GameManager.getGameManager().createBoomList());//��ը��������
	
	}
	
	
	
	
	
	int BubbleCount;
	int BubbleCount1;
	private void DestroBubbleElement(List<SuperElement> bubbleList){//����������ʧʱ��
		SuperElement [][] BubblePK = GameManager.getGameManager().getGLoad().getBubblePK();
		GamePlay tranceforPlay;
		tranceforPlay = (GamePlay)GameManager.getGameManager().getGamePlay(); //����ת�ͷ�����������
		 
		GamePlay1 tranceforPlay1;
		tranceforPlay1 = (GamePlay1)GameManager.getGameManager().getGamePlay1(); //����ת�ͷ�����������
		
		
		for(int i=0;i<bubbleList.size();i++){
			if(bubbleList.get(i).isVisible()){			
			
				int x=bubbleList.get(i).getX(); //��õ�ǰ����x����
				int y=bubbleList.get(i).getY(); //��õ�ǰ����Y����
				int whobubble = bubbleList.get(i).getWhobubble();
				bubbleList.remove(i);//ɾ������ͼ��
				BubblePK[x/40][y/40]=null;
				
				   
				GameManager.getGameManager().createBoomList().addAll(GameManager.getGameManager().getGLoad().
				bigcreateBoomElement("BaoZha",x ,y,whobubble)); //���ɲ���


				audionorepeat bubbleAudio  = new audionorepeat(new File(GameMain.class.getClassLoader().getResource("audio/boom.mp3").getPath()));
				bubbleAudio.start();
				
				
				BubbleCount =tranceforPlay.getCount(); //��õ�ǰ����
				  if(BubbleCount <8 && BubbleCount >=0)
				   tranceforPlay.setCount(BubbleCount+=1);     //������������
				
				   
				   
				   BubbleCount1 =tranceforPlay1.getCount(); //��õ�ǰ����
				 
					  if(BubbleCount1 <8 && BubbleCount1 >=0)
					   tranceforPlay1.setCount(BubbleCount1 +=1);     //������������
					  
				   
				
			}
		
		}
		
	

	}
	
	
	
	private void DestroyBoomElement(List<SuperElement> BoomList){//������ʧ�ݻ�
		SuperElement [][] myBooms=GameManager.getGameManager().getGLoad().getCreateBoomArray();//ʵʱ��ò��ƵĶ�ά����
		
		
		if(BoomList.size()>0){//�в���Ԫ����������,��ʱ����������ͬʱ����
		
			if(BoomList.get(1).isVisible()){
//				BoomList.removeAll(BoomList);//���Ʊ������ͼ����ʧ
				
				
				for(int i=0;i<BoomList.size();i++){
					if(BoomList.get(i).isVisible()){
						BoomList.removeAll(BoomList);
					}
				}
				
				
				
				//�߼�˼ά������
				if(GameManager.getGameManager().getGLoad().myBoomFlag){//����ʵ�ʶ���ͼ����ʧ
					for(int i=0;i<myBooms.length;i++){
						for(int j=0;j<myBooms[i].length;j++){
							if(myBooms[i][j]!=null){
								myBooms[i][j]=null; //�ÿ�
								
							}
						}
					}
				}
				
			}
		}
			
		
		
	

	}
	
	
	
	
}







