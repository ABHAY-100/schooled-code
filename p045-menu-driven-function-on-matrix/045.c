// Write a menu driven program for performing matrix addition, multiplication and find the transpose. And use functions to (i) read a matrix (ii) find the sum of two matrices (iii) find the transpose of a matrix (iv) display a matrix (v) also the product of two matrix
#include <stdio.h>

void readMatrix(int mat[][100], int row, int col);
void addMatrices(int mat1[][100], int mat2[][100], int result[][100], int row, int col);
void multiplyMatrices(int mat1[][100], int mat2[][100], int result[][100], int row1, int col2, int row2);
void transposeMatrix(int mat[][100], int row, int col);
void printMatrix(int mat[][100], int row, int col);

void main(){
    int row1, row2, col1, col2, choice;
    int matrix1[100][100], matrix2[100][100], result[100][100];

    printf("Enter the number of rows and columns of Matrix 1 : ");
    scanf("%d%d", &row1, &col1);
    printf("Enter the number of rows and columns of Matrix 2 : ");
    scanf("%d%d", &row2, &col2);

    matrix1[row1][col1], matrix1[row2][col2];

    printf("\nEnter the elements of the matrix 1 :\n");
    readMatrix(matrix1, row1, col1);
    printf("\nEnter the elements of the matrix 2 :\n");
    readMatrix(matrix2, row2, col2);

    printf("\nEntered Matrix : ");
    printf("\n-------------- ");
    printf("\nThe Matrix 1 : ");
    printMatrix(matrix1, row1, col1);
    printf("\nThe Matrix 2 : ");
    printMatrix(matrix2, row2, col2);
    printf("\n");

    do{
        printf("\nMenu:\n");
        printf("1. Add matrices\n");
        printf("2. Multiply matrices\n");
        printf("3. Transpose matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1 : 
                    if(row1 != row2 || col1 != col2){
                        printf("Matrices cannot be added. They must have the same dimensions.\n");
                        return;
                    }
                    else{
                        addMatrices(matrix1, matrix2, result, row1, col1);
                        printf("Sum of the matrices:\n");
                        printMatrix(result, row1, col1);
                    }
                    break;
            case 2 : 
                    if(row2 != col1){
                        printf("Matrices cannot be multiplied. Columns of matrix 1 must be equal to rows of matrix 2.\n");
                        return;
                    }
                    else{
                        multiplyMatrices(matrix1, matrix2, result, row1, col2, row2);
                        printf("Product of the matrices:\n");
                        printMatrix(result, row1, col2);
                    }
                    break;
            case 3 : 
                    printf("Transpose of matrix 1:\n");
                    transposeMatrix(matrix1, row1, col1);
                    break;
            case 4 : 
                    printf("Exiting...\n");
                    break;
            default : 
                    printf("Invalid choice. Please enter a valid choice.\n");
        }
    }while(choice != 4);
}

void readMatrix(int mat[][100], int row, int col){
    printf("--------------------------------\n"); 
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("Enter the element in (%d,%d) : ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void addMatrices(int mat1[][100], int mat2[][100], int result[][100], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[][100], int mat2[][100], int result[][100], int row1, int col2, int row2){
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            result[i][j]=0;
            for(int k=0; k<row2; k++){
                result[i][j] += mat1[i][j] * mat2[j][k];
            }
        }
    }
}

void transposeMatrix(int mat[][100], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}

void printMatrix(int mat[][100], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}