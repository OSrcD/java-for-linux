
import javax.swing.event.EventListenerList;

/*
 * //全局对象监听器控制类 控制线程 实例化装载容器添加实现事件监听器的类
 *  先分发到总控制类
 *  再由总控制类处理实现事件监听器的类
 */
public class GlobalEventListener { 
	
	protected EventListenerList listenerList = new EventListenerList(); //实例化list
	public GlobalEventListener() {
	
		PoolHook pt = new PoolHook(this); //实例化线程对象
		pt.start();//启动线程

	}

	//事件监听器容器类，用来添加事件到容器类list的集合
	

	
	public void addKeyboardEventListener(KeyboardEventListener listener) {
		listenerList.add(KeyboardEventListener.class, listener);
		System.out.println(KeyboardEventListener.class);
		
	}

	public void removeKeyboardEventListener(KeyboardEventListener listener) {
		listenerList.remove(KeyboardEventListener.class, listener);
		System.out.println(listenerList.getListenerCount());
	}




	/**
	 * 遍历所有按下事件，回调方法
	 * @param event 事件对象
	 */
	void keyPressed(KeyboardEvent event) {
		Object[] listeners = listenerList.getListenerList();
		for (int i = 0; i < listeners.length; i +=2) {
			if (listeners[i] == KeyboardEventListener.class) {
				((Example) listeners[i+1]).GlobalKeyPressed(event);//事件处理者
			
			}
		}
	}

	
	

}