// WAP to multiply two matrices
#include <stdio.h>
void main(){
    // defining matrix
    int r1, r2, c1, c2;
    printf("Enter the number of rows & columns of matrix A : ");
    scanf("%d%d", &r1, &c1);
    printf("Enter the number of rows & columns of matrix B : ");
    scanf("%d%d", &r2, &c2);
    int A[r1][c1], B[r2][c2];

    // entering matrices
    printf("\nEnter elements of matrix A : \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("Element at (%d,%d) : ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of matrix B : \n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            printf("Element at (%d,%d) : ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // condition check for matrix multiplication
    if(c1!=r2){
        printf("\nTry Again! Matrix cannot be multiplied...\n");
        return;
    }
    int C[r1][c2];
    
    // matrix multiplication
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            C[i][j]=0;
            for(int k=0; k<r2; k++){
                C[i][j] += A[i][j] * B[j][k];
            }
        }
    }

    // printing matrix
    printf("The Resulting Matrix is : \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}