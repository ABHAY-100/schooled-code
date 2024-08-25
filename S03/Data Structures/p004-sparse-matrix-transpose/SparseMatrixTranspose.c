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

void transposeofSparse(int sparse[][3], int t, int result[][3])
{
    result[0][0] = sparse[0][1];
    result[0][1] = sparse[0][0];
    result[0][2] = sparse[0][2];

    int k = 1;

    for (int i = 0; i < sparse[0][0]; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (sparse[j][1] == i)
            {
                result[k][0] = sparse[j][1];
                result[k][1] = sparse[j][0];
                result[k][2] = sparse[j][2];
                k++;
            }
        }
    }
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
    int rows, cols, size;
    int sparse1[20][3], resultSparse[20][3];
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);
    sparse1[0][0] = rows;
    sparse1[0][1] = cols;
    size = createSparseMatrix(sparse1, rows, cols);
    sparse1[0][2] = size - 1;
    DisplaySparse(sparse1, size);

    transposeofSparse(sparse1, size, resultSparse);
    printf("\nTranspose: ");
    DisplaySparse(resultSparse, size);
}
