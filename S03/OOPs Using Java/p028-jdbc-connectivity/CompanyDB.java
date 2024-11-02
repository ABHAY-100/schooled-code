// run with java -cp mysql-connector.jar CompanyDB.java

import java.sql.*;

public class CompanyDB {

    public static void main(String args[]) {
        String url = "jdbc:mysql://localhost:3306/companydb";
        String username = "root";
        String password = "ontheway#1200";

        try (Connection connection = DriverManager.getConnection(url, username, password); Statement statement = connection.createStatement(); ResultSet resultSet = statement.executeQuery("select * from employees")) {
            while (resultSet.next()) {
                System.out.print("\nID: " + resultSet.getInt(1));
                System.out.print("; Name: " + resultSet.getString(2));
                System.out.print("; Age: " + resultSet.getInt(3));
                System.out.print("; Address: " + resultSet.getString(4));
                System.out.print("; Salary: " + resultSet.getDouble(5));
                System.out.println("; \n");
            }
        } catch (SQLException e) {
            System.out.println(e);
        }
    }
}
