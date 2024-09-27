public class Main {
	public static void main(String[] args) {
		Sample sample = new Sample(3, 0);
	}
}

class Sample {
	Sample(int a, int b) throws ArithmeticException {
		try {
			int val = a / b;
			System.out.println("Value = " + val);
		} catch(ArithmeticException e) {
			System.out.println(e);
		} finally {
			System.out.println("Completed Try-Catch!");
		}
	}
}
