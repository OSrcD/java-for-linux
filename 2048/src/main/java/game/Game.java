package game;

import javax.swing.JPanel;

public class Game {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		MyJFrame jf = new MyJFrame();
		jf.addJPanel(new MyJPanel());
		jf.addListener(new MyListener());//Ìí¼Ó¼üÅÌ¼àÌı
		jf.showFrame();
	}

}
