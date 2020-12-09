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
 * @author 任我行
 * @说明： 只负责启动程序
 */
public class GameMain {

	public static void main(String[] args){
//		游戏窗体:负责大小，窗口的状态的
		GameFrame gf=new GameFrame();
//		游戏面板画笔:负责绘画元素
		GameJPanel gjp=new GameJPanel();
//		游戏监听:负责交互的监听
		GameListener gl=new GameListener();
//		资源加载器：负责加载资源,元素类的工厂
		GameLoad gLoad=new GameLoad();
//		资源管理器:负责管理资源,资源的出入口
		GameManager gm=GameManager.getGameManager();
//		多线程：负责游戏进程总控
		GameThread gt=new GameThread();
	
//		面板和加载器 也是资源中的一种
		gm.addJPanel(gjp);//面板是第一个资源
		gm.addGLoad(gLoad);
//		面板，3种监听，多线程加入到 窗体中
		gf.LoadJPanel(gjp);//加载面板
		gf.loadKeyListener(gl);
		gf.loadMouseListener(gl, gl);
//		启动线程，开始游戏进程
//		audio my_audio = new audio(new File("audio/tree.mp3"));
		
		//多线程在此
//		gf.gameStart(my_audio);
		gf.gameStart(gt);
		
		audio my_audio = new audio(new File("audio/tree.mp3"));
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
