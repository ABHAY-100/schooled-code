import java.lang.Exception;

public class Main {
	public static void main(String[] args) {
		try {
			throw new MyCustomException("This is my Custom Exception!");
		} catch(MyCustomException e) {
			System.out.println(e);
		}
	}
}

class MyCustomException extends Exception {
	MyCustomException(String message) {
		super(message);
	}
}

