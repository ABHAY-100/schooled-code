// Write a program to read a matrix of size mXn and display its transpose.
#include <stdio.h>
void main(){
    int row, column;
    printf("Enter the number of rows : ");
    scanf("%d", &row);
    printf("Enter the number of columns : ");
    scanf("%d", &column);
    printf("--------------------------------\n\n");
    int matrixA[row][column];
    printf("\nEnter the elements of the matrix\n");
    printf("--------------------------------\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("Enter the element in (%d,%d) : ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("--------------------------------\n\n");
    printf("\nThe entered matrix: \n");
    printf("--------------------------------\n");
    for(int i=0; i<column; i++){
        for(int j=0; j<column; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------------\n\n");
    printf("\nThe transpose is: \n");
    printf("--------------------------------\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ", matrixA[j][i]);
        }
        printf("\n");
    }
    printf("--------------------------------\n\n");
}