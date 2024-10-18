import java.io.*;

public class FileHandling {

    public static void main(String args[]) {
        BufferedReader br1 = null;
        BufferedReader br2 = null;
        BufferedWriter bw = null;

        try {
            br1 = new BufferedReader(new FileReader("input1.txt"));
            br2 = new BufferedReader(new FileReader("input2.txt"));
            bw = new BufferedWriter(new FileWriter("output.txt"));

            String line1, line2;

            while ((line1 = br1.readLine()) != null && (line2 = br2.readLine()) != null) {
                System.out.print(line1);
                bw.write(line1);
                System.out.print(line2);
                bw.write(line2);
                System.out.println();
                bw.newLine();
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        } finally {
            try {
                if (br1 != null) {
                    br1.close();
                }
                if (br2 != null) {
                    br2.close();
                }
                if (bw != null) {
                    bw.close();
                }
            } catch (IOException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
