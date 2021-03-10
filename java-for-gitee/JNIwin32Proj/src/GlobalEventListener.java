
import javax.swing.event.EventListenerList;

/*
 * //ȫ�ֶ�������������� �����߳� ʵ����װ���������ʵ���¼�����������
 *  �ȷַ����ܿ�����
 *  �����ܿ����ദ��ʵ���¼�����������
 */
public class GlobalEventListener { 
	
	protected EventListenerList listenerList = new EventListenerList(); //ʵ����list
	public GlobalEventListener() {
	
		PoolHook pt = new PoolHook(this); //ʵ�����̶߳���
		pt.start();//�����߳�

	}

	//�¼������������࣬��������¼���������list�ļ���
	

	
	public void addKeyboardEventListener(KeyboardEventListener listener) {
		listenerList.add(KeyboardEventListener.class, listener);
		System.out.println(KeyboardEventListener.class);
		
	}

	public void removeKeyboardEventListener(KeyboardEventListener listener) {
		listenerList.remove(KeyboardEventListener.class, listener);
		System.out.println(listenerList.getListenerCount());
	}




	/**
	 * �������а����¼����ص�����
	 * @param event �¼�����
	 */
	void keyPressed(KeyboardEvent event) {
		Object[] listeners = listenerList.getListenerList();
		for (int i = 0; i < listeners.length; i +=2) {
			if (listeners[i] == KeyboardEventListener.class) {
				((Example) listeners[i+1]).GlobalKeyPressed(event);//�¼�������
			
			}
		}
	}

	
	

}