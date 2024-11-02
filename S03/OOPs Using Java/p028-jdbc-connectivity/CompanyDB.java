// run with java -cp mysql-connector.jar CompanyDB.java

import java.sql.*;

public class CompanyDB {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/companydb";
        String username = "root";
        String password = "ontheway#1200";

        try (Connection cnn = DriverManager.getConnection(url, username, password); Statement smt = cnn.createStatement(); ResultSet rs = smt.executeQuery("select * from employees")) {
            while (rs.next()) {
                System.out.print("id: " + rs.getInt(1));
                System.out.print("; name: " + rs.getString(2));
                System.out.print("; age: " + rs.getInt(3));
                System.out.print("; address: " + rs.getString(4));
                System.out.print("; salary: " + rs.getDouble(5));
                System.out.print("; \n");
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
