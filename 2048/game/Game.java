package game;

import javax.swing.JPanel;

public class Game {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		MyJFrame jf = new MyJFrame();
		jf.addJPanel(new MyJPanel());
		jf.addListener(new MyListener());//��Ӽ��̼���
		jf.showFrame();
	}

}
