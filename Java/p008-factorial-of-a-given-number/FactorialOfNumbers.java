// java program to find factorial of a number
import java.util.Scanner;
import java.math.BigInteger;
public class FactorialOfNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        System.out.println("Factorial of " + number + " is " + factorial(number));
        scanner.close();
    }

    public static BigInteger factorial(int number) {
        if(number == 0) {
            return BigInteger.ONE;
        } else {
            return BigInteger.valueOf(number).multiply(factorial(number-1));
        }
    }
}
