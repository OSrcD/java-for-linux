package wrap;

public class WrapperTest {

	public static void main(String[] args) {
		Integer one = new Integer(100);
		Integer two = new Integer(100);
		System.out.println("one==two�Ľ��"+(one==two));
		
		Integer three = 100;
		System.out.println("three==100�Ľ����"+(three==100));
		
		Integer four = 100;
		System.out.println("three==four�Ľ����"+(three==four));
		
		Integer five = 200;
		System.out.println("five==200�Ľ��:"+(five==200));
		
		Integer six  = 200;
		System.out.println("five==six�Ľ��"+(five==six));
		
		
		Double d1 = Double.valueOf(100D);
		System.out.println("d1==100D�Ľ����"+(d1==100D));
		
		Double d2 = Double.valueOf(100D);
		System.out.println("d1==d2�Ľ���ǣ�"+(d1==d2));
		
	}

}
