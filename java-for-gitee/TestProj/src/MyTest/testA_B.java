package MyTest;

import java.util.List;

public class testA_B {
	public static void main(String[] args) {
	
			List<A> a;
			List<B> b;
			b=(List<B>) a;
			
			List<?> o;
			o = a;
			o = b;
			
			List<Integer> a2;
			List<Double> b2;
			List<String> c;
			List<? extends Number>o2;
			o2 = a2;
			o2 = b2;
			o2 = c;
	
	}
	
	
	
}
