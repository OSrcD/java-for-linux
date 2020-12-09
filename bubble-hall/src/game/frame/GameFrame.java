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
 * @说明 游戏主窗体
 * @职责 1.游戏窗体的显示(大小，位置等等)  OK
 *       2.游戏界面的加载                                 OK
 *       3.游戏监听的加载(键盘，鼠标)     OK
 *       4.游戏主控制线程的启动                      OK
 */
public class GameFrame extends JFrame{
//	构造方法

	private Image image;
	public GameFrame(){
		init();//完成界面的 大小等 初始化工作
	}
	/**
	 * 专门用于进行初始化，这样写，方便将来可扩张，子类重写
	 */
	public void init(){
		
		this.setSize(806, 634);//大小  后面改为变量
		this.setTitle("泡泡堂");//标题
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//关闭状态
		this.setResizable(false);//固定窗体大小
		this.setLocationRelativeTo(null);//居中
		
	
    	

		
		
		
		
		
		
		
		
	
    	
	}
	/**
	 * @说明 专门加载面板画笔
	 * @param jp
	 */
	public void LoadJPanel(JPanel jp){
		this.add(jp);
		
	}
	/**@说明 添加键盘监听事件
	*/
	public void loadKeyListener(KeyListener key){
		this.addKeyListener(key);
	}
	/**@说明 添加鼠标监听事件
	*/
	public void loadMouseListener(
				 MouseListener ml,
				 MouseMotionListener mml){
//		添加鼠标点击和进入退出窗体 监听
		this.addMouseListener(ml);
//		添加鼠标移动监听
		this.addMouseMotionListener(mml);
	}
	/**
	 * @说明 启动游戏，并启动游戏中的多线程 自动化控制
	 * @param th
	 */
	public void gameStart(Thread th){
		this.setVisible(true);//设置窗体可见
		th.start();//线程启动
		
	}
}






