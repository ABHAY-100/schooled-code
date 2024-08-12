#include <stdio.h>

int createSparseMatrix(int sparse[][3], int row, int col)
{
    int val;
    int i = 0, j = 0, k = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the value at (%d, %d): ", i, j);
            scanf("%d", &val);
            if (val != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = val;
                k++;
            }
        }
    }
    return k;
}

int addSparseMatrix(int sparse1[][3], int sparse2[][3], int t1, int t2, int sparse3[][3])
{
    int i = 1, j = 1, k = 1;
    sparse3[0][0] = sparse1[0][0];
    sparse3[0][1] = sparse1[0][1];
    while (i < t1 && j < t2)
    {
        if (sparse1[i][0] < sparse2[j][0] || sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1])
        {
            sparse3[k][0] = sparse1[i][0];
            sparse3[k][1] = sparse1[i][1];
            sparse3[k][2] = sparse1[i][2];
            i++;
        }
        else if (sparse1[i][0] > sparse2[j][0] || sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1])
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
    while (i < t1)
    {
        sparse3[k][0] = sparse1[i][0];
        sparse3[k][1] = sparse1[i][1];
        sparse3[k][2] = sparse1[i][2];
        i++;
        k++;
    }
    while (j < t2)
    {
        sparse3[k][0] = sparse2[j][0];
        sparse3[k][1] = sparse2[j][1];
        sparse3[k][2] = sparse2[j][2];
        j++;
        k++;
    }
    sparse3[0][2] = k - 1;
    return k;
}

void DisplaySparse(int sparse[][3], int k)
{
    printf("Sparse Representation: \n");
    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d \n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void main()
{
    int rows1, cols1, rows2, cols2, t1, t2, t3;
    int sparse1[20][3], sparse2[20][3], sparse3[40][3];
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d%d", &rows1, &cols1);
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d%d", &rows2, &cols2);
    if (rows1 != rows2 || cols1 != cols2)
    {
        printf("The matix cannot be added!..\n");
        return;
    }
    sparse1[0][0] = rows1;
    sparse1[0][1] = cols1;
    t1 = createSparseMatrix(sparse1, rows1, cols1);
    sparse1[0][2] = t1 - 1;
    DisplaySparse(sparse1, t1);
    sparse2[0][0] = rows2;
    sparse2[0][1] = cols2;
    t2 = createSparseMatrix(sparse2, rows2, cols2);
    sparse2[0][2] = t2 - 1;
    DisplaySparse(sparse2, t2);

    t3 = addSparseMatrix(sparse1, sparse2, t1, t2, sparse3);
    DisplaySparse(sparse3, t3);
}
