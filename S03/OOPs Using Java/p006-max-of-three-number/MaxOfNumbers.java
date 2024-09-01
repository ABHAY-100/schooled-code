// java program to find maximum of three numbers
import java.util.Scanner;
public class MaxOfNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter three numbers: ");
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        int num3 = scanner.nextInt();

        int maxofAB = Math.max(num1, num2);
        int maxofABC = Math.max(maxofAB, num3);

        System.out.println("Maximum of " + num1 + ", " + num2 + " and " + num3 + " is " + maxofABC);
        scanner.close();
    }
}
