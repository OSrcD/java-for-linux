
import java.awt.*;
import java.awt.event.InputEvent;

public class Example implements KeyboardEventListener, MouseEventListener {

	static GlobalEventListener gl;
	static PointerInfo pinfo;
	static Point p;
	static Robot rb;
	public static void main(String[] args) throws Exception {

		Example inst = new Example();
		gl = new GlobalEventListener();
		
		gl.addKeyboardEventListener(inst);
	
		gl.addMouseEventListener(inst);
		 rb = new Robot();
	
	
		
		
		
	}

	@Override
	public void GlobalKeyPressed(KeyboardEvent event) {

	
		pinfo = MouseInfo.getPointerInfo();
		p = pinfo.getLocation();	
		if(event.getVirtualKeyCode()==37) {
			rb.mouseMove((int)p.getX()-40,(int)p.getY());
			
		}else if(event.getVirtualKeyCode()==38) {
			rb.mouseMove((int)p.getX(),(int)p.getY()-40);
		}else if(event.getVirtualKeyCode()==39) {
			rb.mouseMove((int)p.getX()+40,(int)p.getY());
		}else if(event.getVirtualKeyCode()==40) {
			rb.mouseMove((int)p.getX(),(int)p.getY()+40);
		}else if(event.getVirtualKeyCode()==189) {
			rb.mousePress(InputEvent.BUTTON1_MASK);
			rb.mousePress(InputEvent.BUTTON2_MASK);
		}else if(event.getVirtualKeyCode()==187) {
			rb.mousePress(InputEvent.BUTTON3_MASK);
			rb.mouseRelease(InputEvent.BUTTON3_MASK);
		}
		
		
	}

	@Override
	public void GlobalKeyReleased(KeyboardEvent event) {
	}

	@Override
	public void GlobalMouseX(MouseEvent event) {
 System.out.println("Mouse X: " + event.getMouseX());

	}

	@Override
	public void GlobalMouseY(MouseEvent event) {
 System.out.println("Mouse Y: " + event.getMouseY());
	}

}