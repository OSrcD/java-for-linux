package MyTest;



public class myMain {
	
	
	public static int fib(int n) {
		if(n == 1) 
			return 1;
		
		
		return n * fib(n-1);
		
		
		
	}

	public static void main(String[] args){
	 System.out.println(myMain.fib(4));	
	
		
	
		

	}

}
