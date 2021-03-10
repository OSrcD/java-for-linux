package interview.loop;

public class BinarySearch {

	public int binarySearch(int [] arr,int k) {
		int a=0;
		int b=arr.length;
	
		while(a<b) {
		 int m=a+(b-a)/2; //
			if(k<arr[m]) {
				b=m;
			}else if(k>arr[m]) {
				a=m+1;
			}else {
				return m;
			}
		}
		
		return -1;
		
	}
	
	
	public static void main(String[] args) {
		BinarySearch bs = new BinarySearch();
		
		System.out.println(bs.binarySearch(new int[] {1,2,10,15,100},15));
	
		System.out.println(bs.binarySearch(new int[] {1,2,10,15,100},-2));
		
		System.out.println(bs.binarySearch(new int[] {1,2,10,15,100},101));
		
		System.out.println(bs.binarySearch(new int[] {1,2,10,15,100},13));
		
		System.out.println("========");
		System.out.println(
				bs.binarySearch(new int[] {},13));
		System.out.println(
				bs.binarySearch(new int[] {12},13));
		System.out.println(
				bs.binarySearch(new int[] {13},13));
		
		System.out.println("========");
		
		System.out.println(
				bs.binarySearch(new int[] {12,13},13));
		System.out.println(
				bs.binarySearch(new int[] {12,13},12));
		
	}
	
}
