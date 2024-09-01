// Write a C program to handle matrices. Prompt the user for the dimensions of matrix A and its elements. Calculate and display the sum of all matrix elements.
#include <stdio.h>
void main(){
    int row, column, temp, sum=0;
    printf("Enter the number of rows & columns of matrix A : ");
    scanf("%d%d", &row, &column);
    int A[row][column];

    printf("\nEnter elements of matrix A : \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("Element at (%d,%d) : ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nMatrix : \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            sum += A[i][j];
        }
    }
    printf("\nThe sum of all Matrix elements is : %d\n", sum);
}