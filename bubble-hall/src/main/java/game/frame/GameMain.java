package game.frame;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import game.control.GameListener;
import game.control.GameThread;
import game.element.GameLoad;
import game.element.GameManager;
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;
import game.element.vo.*;
/**
 * @˵���� ֻ������������
 */
public class GameMain {

	public static void main(String[] args){
//		��Ϸ����:�����С�����ڵ�״̬��
		GameFrame gf=new GameFrame();
//		��Ϸ��廭��:����滭Ԫ��
		GameJPanel gjp=new GameJPanel();
//		��Ϸ����:���𽻻��ļ���
		GameListener gl=new GameListener();
//		��Դ�����������������Դ,Ԫ����Ĺ���
		GameLoad gLoad=new GameLoad();
//		��Դ������:���������Դ,��Դ�ĳ����
		GameManager gm=GameManager.getGameManager();
//		���̣߳�������Ϸ�����ܿ�
		GameThread gt=new GameThread();
	
//		���ͼ����� Ҳ����Դ�е�һ��
		gm.addJPanel(gjp);//����ǵ�һ����Դ
		gm.addGLoad(gLoad);
//		��壬3�ּ��������̼߳��뵽 ������
		gf.LoadJPanel(gjp);//�������
		gf.loadKeyListener(gl);
		gf.loadMouseListener(gl, gl);
//		�����̣߳���ʼ��Ϸ����
//		audio my_audio = new audio(new File("audio/tree.mp3"));
		
		//���߳��ڴ�
//		gf.gameStart(my_audio);
		gf.gameStart(gt);
		System.out.println();

		audio my_audio = new audio(new File(GameMain.class.getClassLoader().getResource("audio/tree.mp3").getPath()));
		my_audio.loop();
		
	
	
//		try {
//			BufferedInputStream my_buffer = new BufferedInputStream(new FileInputStream("audio/tree.mp3"));
//			Player	player = new Player(my_buffer);
//			
//		
//			player.play();
//		} catch (FileNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		} catch (JavaLayerException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		
		
	}

}
