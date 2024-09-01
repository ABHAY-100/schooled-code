// Create a C program to handle matrices. Prompt the user to enter the dimensions of matrix A and its elements. Sort each row of matrix A in ascending order and display the resulting matrix.
#include <stdio.h>
void sortArray(int array[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void main(){
    int row, column, temp;
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

    printf("The Resulting Matrix is : \n");
    for(int i=0; i<row; i++){
        sortArray(A[i], column);
        for(int j=0; j<column; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}