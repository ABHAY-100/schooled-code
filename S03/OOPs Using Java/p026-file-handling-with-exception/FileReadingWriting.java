import java.io.*;

class EmptyFileException extends Exception {
    public EmptyFileException(String message) {
        super(message);
    }
}

public class FileReadingWriting {
    public static void main(String[] args) {
        BufferedReader br = null;
        BufferedWriter bw = null;

        try {
            br = new BufferedReader(new FileReader("input.txt"));
            bw = new BufferedWriter(new FileWriter("output.txt", true));
            String line;

            if ((line = br.readLine()) == null) {
                throw new EmptyFileException("The input file is empty.");
            }

            do {
                System.out.println(line);
                bw.write(line);
                bw.newLine();
            } while ((line = br.readLine()) != null);

        } catch (FileNotFoundException e) {
            System.err.println("Error: File not found - " + e.getMessage());
        } catch (IOException e) {
            System.err.println("Error: I/O exception occurred - " + e.getMessage());
        } catch (EmptyFileException e) {
            System.err.println("Error: " + e.getMessage());
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                System.err.println("Error closing BufferedReader: " + e.getMessage());
            }

            try {
                if (bw != null) {
                    bw.close();
                }
            } catch (IOException e) {
                System.err.println("Error closing BufferedWriter: " + e.getMessage());
            }
        }
    }
}
