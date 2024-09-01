import java.util.Scanner;
public class Main {
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = scn.nextLine().toLowerCase().trim();
        System.out.print("Enter the character to search: ");
        char ch = scn.next().charAt(0);
        scn.close();

        int count = 0;
        for(int i=(str.length()-1); i>=0; i--) {
            if(ch == str.charAt(i)) {
                count++;
            }
        }

        System.out.println("Frequency of " + ch + " is " + count);
    }
}
