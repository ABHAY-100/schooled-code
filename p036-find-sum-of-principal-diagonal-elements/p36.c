// WAP a program to read a matrix of size mXn and display the sum of its principal diagonal elements
#include <stdio.h>
void main(){
    int row, column, sum=0;
    printf("Enter the number of rows : ");
    scanf("%d", &row);
    printf("Enter the number of columns : ");
    scanf("%d", &column);
    int matrixA[row][column];

    printf("\nEnter the elements of the matrix\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("Enter the element in (%d,%d) : ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("\nThe entered matrix: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\nThe sum of principal diagonal elements is : ");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(i==j){
                sum += matrixA[i][j];
            }
        }
    }
    printf("%d\n", sum);
}