package game.element;

import java.util.ArrayList;
import java.util.List;

import game.element.vo.GamePlay;
import game.element.vo.SuperElement;
import game.frame.GameJPanel;

/**
 * @说明 所有元素的管理类
 * @职责  1.定义所有的元素或元素集合
 *       2.初始化元素，通过加载器获取资源
 *       3.提供元素的 get方法
 *       4.提供 唯一 的元素管理类的实体对象
 *         单例模式
 */
public class GameManager   {
//	1.定义元素  -> 先新建class 并继承与SuperElement
//	2.初始化元素 ->构造方法初始化集合容器; loadElement初始化对象
//	3.提供方法给予其他类访问元素 ->提供get方法
	private SuperElement gamePlay;//导入的父类
	private SuperElement gamePlay1;//玩家2
	private SuperElement bubbleElement;
	private SuperElement beijin;//背景
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
//	每个关卡都可以 加载资源
	public void LoadElement() {
//		初始化对象由 资源加载器工厂完成
		
		gamePlay=gLoad.elementFactory("birdPlay");
		gamePlay1=gLoad.elementFactory("body");//玩家2
		maps=GameManager.getGameManager().gLoad.getMapElement("box");
		if(maps!=null)
		fasts = GameManager.getGameManager().gLoad.getMapElement("fasts");
//		bubbleElement = gLoad.elementFactory("bubble");
		
		beijin=GameManager.getGameManager().gLoad.elementGameBG("beijin");//背景
		Gameovers=GameManager.getGameManager().gLoad.elementGameBG("Gameovers");//背景
		Titles = GameManager.getGameManager().gLoad.elementGameBG("Titles");
	}
///////////////所有元素的get方法提供访问//////////////////////////////
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







	//	这个资源不需要动啦
	private GameJPanel gjp;
	private GameLoad gLoad;//资源加载器
	private boolean gameStart=false;//游戏是否正式启动
	private boolean gamefirst=false;//游戏是否正式启动
	private boolean gamefirstbutton=false;//游戏是否正式启动
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
	/*用来添加面板资源到资源库的*/
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
 * 通过GameManager.getGameManager()方法获取资源管理器
 */
//	private static final GameManager GM;
//	static{//可以使用 静态语句块进行唯一的赋值
//		GM=getGameManager("s");
//	}
	private static GameManager GM;
//	synchronized 保证只有一个线程在这个方法中运行
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
