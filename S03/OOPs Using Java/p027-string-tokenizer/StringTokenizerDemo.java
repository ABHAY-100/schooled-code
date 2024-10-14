import java.util.StringTokenizer;

class StringTokenizerDemo {
    public static void main(String[] args) {
        String s = "1 2 4 4 5 2", temp;
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
