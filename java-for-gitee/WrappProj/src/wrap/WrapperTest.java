package wrap;

public class WrapperTest {

	public static void main(String[] args) {
		Integer one = new Integer(100);
		Integer two = new Integer(100);
		System.out.println("one==two的结果"+(one==two));
		
		Integer three = 100;
		System.out.println("three==100的结果："+(three==100));
		
		Integer four = 100;
		System.out.println("three==four的结果："+(three==four));
		
		Integer five = 200;
		System.out.println("five==200的结果:"+(five==200));
		
		Integer six  = 200;
		System.out.println("five==six的结果"+(five==six));
		
		
		Double d1 = Double.valueOf(100D);
		System.out.println("d1==100D的结果："+(d1==100D));
		
		Double d2 = Double.valueOf(100D);
		System.out.println("d1==d2的结果是："+(d1==d2));
		
	}

}
