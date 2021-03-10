
public class Demo {

	public static void main(String[] args) {
		Class clazz = Demo.class;
		ClassLoader classLoader = clazz.getClassLoader();
		
		System.out.println(classLoader.getResource("/ClassLoaderProj/test").getPath());
	}
	
	
	public void test() {
		
	}

}
