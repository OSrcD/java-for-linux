
class PoolHook extends Thread {
	SysHook hook;//����SysHook ��c++������
	GlobalEventListener g_gl;//����ȫ���¼���������
	
	PoolHook(GlobalEventListener gl) {
		g_gl = gl; //���ö���ȫ���¼���������
		
	}

	public void run() {
		hook = new SysHook();//ʵ���� SysHook ��c++������
		
		hook.registerHook(g_gl);//���ù��� ��ȫ���¼�����������󴫵ݸ�c++
		
	}

}

public class SysHook {

	static {
		System.loadLibrary("JNIwin32Proj"); //����c++dll
	}

	/**
	 * 
	 * @param ts
	 * @param vk
	 * @param gl
	 * 
	 * 
	 */
	//c++������Ϣ֮���ӻص�����ø÷���
	void processKey(boolean ts, int vk, GlobalEventListener gl) {
		/*
		 * �¼�Դ�ı��״̬ ����c++
		 * �Ѹı��¼��ĸ���״̬��ֵ���¼�����
		 * �ı�֮��
		 * ����ȫ���¼��������������keyPressed����
		 * ��������ʵ���¼�����������
		 * �Ѹı����¼�������Ϊ����
		 * ���ݸ�ʵ���¼������������¼������߷��� GlobalKeyPressed
		 * �����¼������ֵ�����Ӧ���߼�
		 * 
		 */
		KeyboardEvent event = new KeyboardEvent(this, ts, vk, false, false);
		
		gl.keyPressed(event);
	}

	//native�������ù��ӷ���
	native void registerHook(GlobalEventListener gl);
	
	//nativeж�ع���
	native void unRegisterHook();

}