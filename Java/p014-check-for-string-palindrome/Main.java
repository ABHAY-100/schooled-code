import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String rev = "";
        System.out.print("Enter a string: ");
        String str = scn.nextLine().toLowerCase().trim();
        scn.close();

        for (int i = (str.length()-1); i >= 0; i--) {
            rev += str.charAt(i);
        }

        if (str.equals(rev)) {
            System.out.println(str + " is palindrome.");
            return;
        }
        System.out.println(str + " is not a palindrome.");
    }
}
