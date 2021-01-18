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
 * @说明 游戏显示界面
 * @职责 负责从 元素管理器中 获取元素数据
 *      调用统一的方法，让元素显示绘画自己
 */
public class GameJPanel extends JPanel{
	/**
	 * @说明 重写父类的 绘画方法  Graphics 是画笔
	 */
	public void paint(Graphics g) {
		super.paint(g);

//		如果游戏已经启动，才显示元素等
		
		if(GameManager.getGameManager().isGamefirst()){
			paintTitles(g);
			if(GameManager.getGameManager().timeCount>20){
		
				GameManager.getGameManager().setGameStart(true);
			}
			
			
		}
		
		if(GameManager.getGameManager().isGameStart()){
			
			paintBackground(g);//显示背景
			paintNpc(g);//显示敌人等
			paintPlay(g);//显示玩家相关的
			GameManager.getGameManager().setGamefirst(false);
			if(GameManager.getGameManager().isGameoversflag()){
				paintGameovers(g);
				
				
			}
			
			if(GameManager.getGameManager().isSwapbg()){
				GameManager.getGameManager().setGameoversflag(false);
				paintBackground(g);//显示背景
				paintNpc(g);//显示敌人等
				paintPlay(g);//显示玩家相关的
				
//				GameManager.getGameManager().setGameovers(null);
				GameManager.getGameManager().setSwapbg(false);
			}
		}
	}
	/**
	 * @说明 绘制和玩家相关的所有内容:
	 * 		1.玩家
	 * 		2.玩家子弹
	 * 		3.玩家分数，血量 等等
	 */
	private void paintPlay(Graphics g) {
//		显示主角
		
		GameManager.getGameManager().getGamePlay().showElement(g);
		GameManager.getGameManager().getGamePlay1().showElement(g);//玩家2
		showBubbleElement(GameManager.getGameManager().createBubbleElement(),g);
		showBaoZhaElement(GameManager.getGameManager().createBoomList(),g);
//		管理器类.得到管理器.得到玩家对象.显示玩家
	}
	
	/**
	 * @说明 绘制和敌人NPC相关的所有内容
	 * 		1.小敌人，大敌人
	 */
	private void paintNpc(Graphics g) {
		
	}
	/**
	 * @说明 绘制和背景相关的
	 * 		底色啊等等 图片啊  地图
	 */
	
	private void paintGameovers(Graphics g){
		GameManager.getGameManager().getGameovers().showElement(g);
		
	}
	
	private void paintTitles(Graphics g){
		GameManager.getGameManager().getTitles().showElement(g);
		
	}
	
	private void paintBackground(Graphics g) {
//		绘画背景颜色，现在是黑色
//		this.setBackground(new Color(10,100,10));
		GameManager.getGameManager().getbeijin().showElement(g);//背景
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








