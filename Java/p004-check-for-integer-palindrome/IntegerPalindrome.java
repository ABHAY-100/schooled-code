// java program to check for palindrome
import java.util.Scanner;

class IntegerPalindrome {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        int temp = number, rev = 0;
        while(temp != 0) {
            rev = rev*10 + temp%10;
            temp = temp/10;
        }

        if(number == rev) {
            System.out.println("The number " + number + " is a palindrome.");
        } else {
            System.out.println("The number " + number + " is not a palindrome.");
        }

        scanner.close();
    }
}
