
public class Example implements KeyboardEventListener {

	
	
	public static void main(String[] args) throws Exception {
		Example inst = new Example();
		GlobalEventListener gl = new GlobalEventListener();
		gl.addKeyboardEventListener(inst);//ע������� ��ǰ����Ϊ�¼�������
	
	}
	

	@Override
	public void GlobalKeyPressed(KeyboardEvent event) {

		System.out.println("Key Pressed: " + event.getVirtualKeyCode());
	}

	@Override
	public void GlobalKeyReleased(KeyboardEvent event) {
	}

	

	

}