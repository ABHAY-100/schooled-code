import java.util.Scanner;
public class Main {
    static void createMatrix(int Matrix[][], int row, int col, Scanner scn) {
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                System.out.print("Enter the element at (" + i + "," + j + "): ");
                Matrix[i][j] = scn.nextInt();
            }
        }
    }

    static void multiplyMatrix(int Matrix1[][], int Matrix2[][], int Matrix3[][], int col1, int row1, int col2) {
        for (int i=0; i<row1; i++) {
            for (int j=0; j<col2; j++) {
                Matrix3[i][j] = 0;
                for (int k=0; k<col1; k++) {
                    Matrix3[i][j] += Matrix1[i][k] * Matrix2[k][j];
                }
            }
        }
    }

    static void displayMatrix(int Matrix[][], int row, int col) {
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                System.out.print(Matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int rows1, cols1, rows2, cols2;
        System.out.print("Enter the rows and columns of Matrix 1: ");
        rows1 = scn.nextInt();
        cols1 = scn.nextInt();
        System.out.print("Enter the rows and columns of Matrix 2: ");
        rows2 = scn.nextInt();
        cols2 = scn.nextInt();

        if (cols1 != rows2) {
            System.out.println("Matrix multiplication is not possible! Try Again");
            scn.close();
            return;
        }

        int[][] M1 = new int[rows1][cols1];
        int[][] M2 = new int[rows2][cols2];

        System.out.println("\nMatrix 1 : ");
        createMatrix(M1, rows1, cols1, scn);
        System.out.println("\nEntered Matrix: ");
        displayMatrix(M1, rows1, cols1);

        System.out.println("\nMatrix 2 : ");
        createMatrix(M2, rows2, cols2, scn);
        System.out.println("\nEntered Matrix: ");
        displayMatrix(M2, rows2, cols2);
        
        int[][] M3 = new int [rows1][cols2];
        multiplyMatrix(M1, M2, M3, cols1, rows1, cols2);

        System.out.println("After multiplication: ");
        displayMatrix(M3, rows1, cols2);
        scn.close();
    }
}
