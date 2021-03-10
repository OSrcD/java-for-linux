
interface One{
	static int x=11;
}

interface Two{
	final int x=22;
	
}


class Three{
	public int x=33;
}




public class MutiInterfa extends Three implements One,Two {


	public  void test() {
		System.out.println(this.x);
	}
	
	
	public static void main(String[] args) {
		new MutiInterfa().test();

	}

}
