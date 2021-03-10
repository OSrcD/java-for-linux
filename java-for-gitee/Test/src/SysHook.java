class PoolHook extends Thread {
	SysHook hook;
	GlobalEventListener g_gl;

	PoolHook(GlobalEventListener gl) {
		g_gl = gl;
	}

	public void run() {
		hook = new SysHook();
		hook.registerHook(g_gl);

	}

}

class SysHook {

	static {
		System.loadLibrary("SysHook");
	}

	void processKey(boolean ts, int vk, GlobalEventListener gl) {
		KeyboardEvent event = new KeyboardEvent(this, ts, vk, false, false);
		gl.keyPressed(event);
	}

	void mouseMoved(int cord_x, int cord_y, GlobalEventListener gl) {
		MouseEvent event = new MouseEvent(this, cord_x, cord_y);
		gl.mouseMoved(event);
	}

	native void registerHook(GlobalEventListener gl);

	native void unRegisterHook();

}