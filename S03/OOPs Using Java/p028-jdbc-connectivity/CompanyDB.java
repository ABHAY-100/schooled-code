// run with java -cp mysql-connector.jar CompanyDB.java

import java.sql.*;

public class CompanyDB {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/companydb";
        String username = "root";
        String password = "ontheway#1200";

        // params for inserting
        // String newName = "Elvin J";
        // int newAge = 20;
        // String newAddress = "From Thrissur";
        // Double newSalary = 30000.00;

        // params for updating
        // int updateID = 2; 
        // String updatedAddress = "Updated Address";
        // double updatedSalary = 350000.00;

        // params for deleting
        // int deleteID = 4;

        try (Connection cnn = DriverManager.getConnection(url, username, password)) {

            // block for insert
            // String insertQuery = "INSERT INTO EMPLOYEES (name, age, address, salary) VALUES (?, ?, ?, ?)";

            // try (PreparedStatement psmt = cnn.prepareStatement(insertQuery)) {
            //     psmt.setString(1, newName);
            //     psmt.setInt(2, newAge);
            //     psmt.setString(3, newAddress);
            //     psmt.setDouble(4, newSalary);
            //     psmt.executeUpdate();
            // }


            // block for update
            // String updateQuery = "UPDATE EMPLOYEES SET address = ?, salary = ? where id = ?";

            // try (PreparedStatement psmtForUpdate = cnn.prepareStatement(updateQuery)) {
            //     psmtForUpdate.setString(1, updatedAddress);
            //     psmtForUpdate.setDouble(2, updatedSalary);
            //     psmtForUpdate.setInt(3, updateID);
            //     psmtForUpdate.executeUpdate();
            // }

            // block for delete
            // String deleteQuery = "DELETE FROM EMPLOYEES WHERE ID = ?";

            // try (PreparedStatement psmtForUpdate = cnn.prepareStatement(deleteQuery)) {
            //     psmtForUpdate.setInt(1, deleteID);
            //     psmtForUpdate.executeUpdate();
            // }

            try (Statement smt = cnn.createStatement(); ResultSet rs = smt.executeQuery("select * from employees")) {
                while (rs.next()) {
                    System.out.print("id: " + rs.getInt(1));
                    System.out.print("; name: " + rs.getString(2));
                    System.out.print("; age: " + rs.getInt(3));
                    System.out.print("; address: " + rs.getString(4));
                    System.out.print("; salary: " + rs.getDouble(5));
                    System.out.print("; \n");
                }
            }
            
        } catch (SQLException e) {
            System.out.println(e);
        }
    }
}
