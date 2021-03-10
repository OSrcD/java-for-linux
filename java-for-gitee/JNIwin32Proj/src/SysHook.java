
class PoolHook extends Thread {
	SysHook hook;//声明SysHook 与c++交互类
	GlobalEventListener g_gl;//声明全局事件监听器类
	
	PoolHook(GlobalEventListener gl) {
		g_gl = gl; //引用对象全局事件监听器类
		
	}

	public void run() {
		hook = new SysHook();//实例化 SysHook 与c++交互类
		
		hook.registerHook(g_gl);//设置钩子 把全局事件监听器类对象传递给c++
		
	}

}

public class SysHook {

	static {
		System.loadLibrary("JNIwin32Proj"); //加载c++dll
	}

	/**
	 * 
	 * @param ts
	 * @param vk
	 * @param gl
	 * 
	 * 
	 */
	//c++处理消息之后钩子回调后调用该方法
	void processKey(boolean ts, int vk, GlobalEventListener gl) {
		/*
		 * 事件源改变的状态 来自c++
		 * 把改变事件的各个状态赋值给事件对象
		 * 改变之后
		 * 调用全局事件监听器控制类的keyPressed方法
		 * 遍历所有实现事件监听器的类
		 * 把改变后的事件对象作为参数
		 * 传递给实现事件监听器的类事件处理者方法 GlobalKeyPressed
		 * 根据事件对象的值处理对应的逻辑
		 * 
		 */
		KeyboardEvent event = new KeyboardEvent(this, ts, vk, false, false);
		
		gl.keyPressed(event);
	}

	//native本地设置钩子方法
	native void registerHook(GlobalEventListener gl);
	
	//native卸载钩子
	native void unRegisterHook();

}