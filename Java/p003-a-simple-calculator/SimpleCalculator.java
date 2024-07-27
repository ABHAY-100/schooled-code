// java program to perform add, sub, div and multi
import java.util.Scanner;

class SimpleCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter two numbers number: ");
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();

        int choice;

        do {
            System.out.println("\nMenu: ");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Exit\n");

            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Result => " + (num1 + num2));
                    break;
            
                case 2:
                    System.out.println("Result => " + (num1 - num2));
                    break;
    
                case 3:
                    System.out.println("Result => " + (num1 * num2));
                    break;
    
                case 4:
                    System.out.println("Result => " + ((float) num1 / num2));
                    break;
    
                case 5:
                    System.out.println("Exiting...");
                    break;
    
                default:
                    System.out.println("Something went wrong! try again!");
                    break;
            }
        } while (choice != 5);

        scanner.close();
    }
}
