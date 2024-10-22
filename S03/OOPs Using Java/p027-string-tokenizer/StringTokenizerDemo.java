import java.util.StringTokenizer;
import java.util.Scanner;

class StringTokenizerDemo {
    public static void main(String[] args) {
    	  Scanner sn = new Scanner(System.in);
    	  String s = sn.nextLine();
    	  String temp;
        int sum = 0, n;

        StringTokenizer str = new StringTokenizer(s, " ");

        while (str.hasMoreTokens()) {
            temp = str.nextToken();
            n = Integer.parseInt(temp);

            System.out.println(n);
            sum = sum + n;
        }

        System.out.println("SUM = " + sum);
    }
}
 
