package game.element;

import java.util.ArrayList;
import java.util.List;

import game.element.vo.GamePlay;
import game.element.vo.SuperElement;
import game.frame.GameJPanel;

/**
 * @˵�� ����Ԫ�صĹ�����
 * @ְ��  1.�������е�Ԫ�ػ�Ԫ�ؼ���
 *       2.��ʼ��Ԫ�أ�ͨ����������ȡ��Դ
 *       3.�ṩԪ�ص� get����
 *       4.�ṩ Ψһ ��Ԫ�ع������ʵ�����
 *         ����ģʽ
 */
public class GameManager   {
//	1.����Ԫ��  -> ���½�class ���̳���SuperElement
//	2.��ʼ��Ԫ�� ->���췽����ʼ����������; loadElement��ʼ������
//	3.�ṩ�����������������Ԫ�� ->�ṩget����
	private SuperElement gamePlay;//����ĸ���
	private SuperElement gamePlay1;//���2
	private SuperElement bubbleElement;
	private SuperElement beijin;//����
	private SuperElement Gameovers;
	private SuperElement Titles;
	private List<SuperElement> bubbleList;
	private List<SuperElement> boomList;
	private SuperElement[][] maps;
	private SuperElement[][] fasts;


	private boolean playDieFlag=false; 
	private boolean playDieflag1=false;
	private boolean swapbg =false;
	public static int timeCount=0;
	
	
	
	public boolean isSwapbg() {
		return swapbg;
	}
	public void setSwapbg(boolean swapbg) {
		this.swapbg = swapbg;
	}
	public GameManager(){
		bubbleList=new ArrayList<SuperElement>();
		boomList=new ArrayList<SuperElement>();
	}
//	ÿ���ؿ������� ������Դ
	public void LoadElement() {
//		��ʼ�������� ��Դ�������������
		
		gamePlay=gLoad.elementFactory("birdPlay");
		gamePlay1=gLoad.elementFactory("body");//���2
		maps=GameManager.getGameManager().gLoad.getMapElement("box");
		if(maps!=null)
		fasts = GameManager.getGameManager().gLoad.getMapElement("fasts");
//		bubbleElement = gLoad.elementFactory("bubble");
		
		beijin=GameManager.getGameManager().gLoad.elementGameBG("beijin");//����
		Gameovers=GameManager.getGameManager().gLoad.elementGameBG("Gameovers");//����
		Titles = GameManager.getGameManager().gLoad.elementGameBG("Titles");
	}
///////////////����Ԫ�ص�get�����ṩ����//////////////////////////////
	public SuperElement getGamePlay() {
		return gamePlay;
	}
	public SuperElement getGamePlay1() {
		return gamePlay1;
	}
//	public List<SuperElement> getEnemyList() {
//		return bubbleList;
//	}
	public SuperElement getbeijin(){
		return beijin;
	}
	
	

	public SuperElement getGameovers() {
		return Gameovers;
	}







	public SuperElement getTitles() {
		return Titles;
	}
	public void setTitles(SuperElement titles) {
		Titles = titles;
	}
	public void setGameovers(SuperElement gameovers) {
		Gameovers = gameovers;
	}







	//	�����Դ����Ҫ����
	private GameJPanel gjp;
	private GameLoad gLoad;//��Դ������
	private boolean gameStart=false;//��Ϸ�Ƿ���ʽ����
	private boolean gamefirst=false;//��Ϸ�Ƿ���ʽ����
	private boolean gamefirstbutton=false;//��Ϸ�Ƿ���ʽ����
	private boolean Gameoversflag = false;
	
	
	
	
	public boolean isGamefirstbutton() {
		return gamefirstbutton;
	}
	public void setGamefirstbutton(boolean gamefirstbutton) {
		this.gamefirstbutton = gamefirstbutton;
	}
	public boolean isGamefirst() {
		return gamefirst;
	}
	public void setGamefirst(boolean gamefirst) {
		this.gamefirst = gamefirst;
	}
	public boolean isGameoversflag() {
		return Gameoversflag;
	}
	public void setGameoversflag(boolean gameoversflag) {
		Gameoversflag = gameoversflag;
	}
	public boolean isGameStart() {
		return gameStart;
	}
	public void setGameStart(boolean gameStart) {
		this.gameStart = gameStart;
	}
	/*������������Դ����Դ���*/
	public void addJPanel(GameJPanel gjp) {
		this.gjp=gjp;
	}
	public GameJPanel getJPanel(){
		return gjp;
	}
	public SuperElement[][] getCreateMaps() {
		return maps;
	}
	public void addGLoad(GameLoad gLoad) {
		this.gLoad=gLoad;
	}
	public GameLoad getGLoad(){
		return gLoad;
	}
	
	
	
	
	
	
public SuperElement[][] getFasts() {
		return fasts;
	}
	public void setFasts(SuperElement[][] fasts) {
		this.fasts = fasts;
	}
	
public List<SuperElement> createBubbleElement() {
		return bubbleList;
	}





public List<SuperElement> createBoomList() {
	return boomList;
}
public void setBaoZhalist(List<SuperElement> baoZhalist) {
	boomList = baoZhalist;
}




public boolean isplayDieFlag() {
	return playDieFlag;
}
public void setplayDieFlag(boolean playDieFlag) {
	this.playDieFlag = playDieFlag;
}

public boolean isPlayDieflag1() {
	return playDieflag1;
}
public void setPlayDieflag1(boolean playDieflag1) {
	this.playDieflag1 = playDieflag1;
}

/**
 * ͨ��GameManager.getGameManager()������ȡ��Դ������
 */
//	private static final GameManager GM;
//	static{//����ʹ�� ��̬�������Ψһ�ĸ�ֵ
//		GM=getGameManager("s");
//	}
	private static GameManager GM;
//	synchronized ��ֻ֤��һ���߳����������������
	public static synchronized GameManager getGameManager(){
		if(GM==null){
//			return new GameManager();
			GM= new GameManager();
		}
		return GM;
	}
//	public static void main(String[] args) {
//		System.out.println(
//				GameManager.getGameManager("m"));
//	}
	
	
	
	
}
