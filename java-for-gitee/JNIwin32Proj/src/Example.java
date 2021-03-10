
public class Example implements KeyboardEventListener {

	
	
	public static void main(String[] args) throws Exception {
		Example inst = new Example();
		GlobalEventListener gl = new GlobalEventListener();
		gl.addKeyboardEventListener(inst);//注册监听器 当前类作为事件监听器
	
	}
	

	@Override
	public void GlobalKeyPressed(KeyboardEvent event) {

		System.out.println("Key Pressed: " + event.getVirtualKeyCode());
	}

	@Override
	public void GlobalKeyReleased(KeyboardEvent event) {
	}

	

	

}