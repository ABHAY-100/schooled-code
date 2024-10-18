import java.io.*;
import java.util.HashMap;

public class FileHandling {

    public static void main(String[] args) {
        HashMap<String, String> nameMap = new HashMap<>();
        HashMap<String, String> ageMap = new HashMap<>();

        try (
            BufferedReader br1 = new BufferedReader(new FileReader("input1.txt"));
            BufferedReader br2 = new BufferedReader(new FileReader("input2.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"))
        ) {
            String line;

            while ((line = br1.readLine()) != null) {
                String[] parts = line.split(";");
                if (parts.length < 2) continue;
                String id = parts[1].split(":")[1].trim();
                nameMap.put(id, parts[0].trim());
            }

            while ((line = br2.readLine()) != null) {
                String[] parts = line.split(";");
                if (parts.length < 2) continue;
                String id = parts[0].split(":")[1].trim();
                String age = parts[1].trim();
                ageMap.put(id, age);
            }

            for (String id : nameMap.keySet()) {
                String nameInfo = nameMap.get(id);
                String ageInfo = ageMap.get(id);

                if (ageInfo != null) {
                    String outputLine = nameInfo + " ; id: " + id + " ; " + ageInfo;
                    bw.write(outputLine);
                    bw.newLine();
                    System.out.println(outputLine);
                }
            }
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}