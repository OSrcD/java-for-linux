package game;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class MyListener implements KeyListener{
	private boolean bl=false;//false ����û�м��̵��
	@Override
	public void keyPressed(KeyEvent key) {	
		if(bl==false){
			bl=true;
			GameElement.createGameElement().KeyClick(key.getKeyCode());
//			System.out.println("keyPressed:"+key.getKeyCode());
		}
	}

	@Override
	public void keyReleased(KeyEvent key) {
		bl=false;//����
		System.out.println("keyReleased:"+key.getKeyCode());
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		
	}
	
}
