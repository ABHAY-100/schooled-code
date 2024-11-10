#include <stdio.h>

int createSparseMatrix(int sparse[][3])
{
    int val;
    int i = 0, j = 0, k = 0;
    for (int i = 0; i < sparse[0][0]; i++)
    {
        for (int j = 0; j < sparse[0][1]; j++)
        {
            printf("Enter the value at (%d, %d): ", i, j);
            scanf("%d", &val);
            if (val != 0)
            {   
                k++;
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = val;
            }
        }
    }
    sparse[0][2] = k;
}

int addSparseMatrix(int sparse1[][3], int sparse2[][3], int sparse3[][3])
{
    int i = 1, j = 1, k = 1;
    sparse3[0][0] = sparse1[0][0];
    sparse3[0][1] = sparse1[0][1];
    while (i <= sparse1[0][2] && j <= sparse2[0][2])
    {
        if (sparse1[i][0] < sparse2[j][0] || ( sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1] ))
        {
            sparse3[k][0] = sparse1[i][0];
            sparse3[k][1] = sparse1[i][1];
            sparse3[k][2] = sparse1[i][2];
            i++;
        }
        else if (sparse1[i][0] > sparse2[j][0] || ( sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1] ))
        {
            sparse3[k][0] = sparse2[j][0];
            sparse3[k][1] = sparse2[j][1];
            sparse3[k][2] = sparse2[j][2];
            j++;
        }
        else
        {
            sparse3[k][0] = sparse1[i][0];
            sparse3[k][1] = sparse1[i][1];
            sparse3[k][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
        }
        k++;
    }
    while (i <= sparse1[0][2])
    {
        sparse3[k][0] = sparse1[i][0];
        sparse3[k][1] = sparse1[i][1];
        sparse3[k][2] = sparse1[i][2];
        i++;
        k++;
    }
    while (j <= sparse2[0][2])
    {
        sparse3[k][0] = sparse2[j][0];
        sparse3[k][1] = sparse2[j][1];
        sparse3[k][2] = sparse2[j][2];
        j++;
        k++;
    }
    sparse3[0][2] = k-1;
}

void DisplaySparse(int sparse[][3])
{
    printf("Sparse Representation: \n");
    for (int i = 0; i <= sparse[0][2]; i++)
    {
        printf("%d %d %d \n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void main()
{
    int sparse1[20][3], sparse2[20][3], sparse3[40][3];
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d%d", &sparse1[0][0], &sparse1[0][1]);
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d%d", &sparse2[0][0], &sparse2[0][1]);
    if (sparse1[0][0] != sparse2[0][0] || sparse1[0][1] != sparse2[0][1])
    {
        printf("The matix cannot be added!..\n");
        return;
    }
    createSparseMatrix(sparse1);
    DisplaySparse(sparse1);
    createSparseMatrix(sparse2);
    DisplaySparse(sparse2);

    addSparseMatrix(sparse1, sparse2, sparse3);
    DisplaySparse(sparse3);
}
