
import java.util.*;



public interface KeyboardEventListener extends EventListener {
	public void GlobalKeyPressed(KeyboardEvent event);
	
	public void GlobalKeyReleased(KeyboardEvent event);

}

class KeyboardEvent extends EventObject {

	boolean ts, ap, ek;
	int vk;

	public KeyboardEvent(Object source, boolean ts, int vk, boolean ap, boolean ek) {
		super(source);
		this.ts = ts;
		this.vk = vk;
		this.ap = ap;
		this.ek = ek;
	}

	

	public boolean getTransitionState() {
		return ts;
	}

	public long getVirtualKeyCode() {
		return vk;
	}

	public boolean isAltPressed() {
		return ap;
	}

	public boolean isExtendedKey() {
		return ek;
	}


}