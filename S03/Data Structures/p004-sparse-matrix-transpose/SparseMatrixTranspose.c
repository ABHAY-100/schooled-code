#include <stdio.h>

void createSparseMatrix(int sparse[][3])
{
    int val;
    int i = 0, j = 0, k = 0;
    for (i = 0; i < sparse[0][0]; i++)
    {
        for (j = 0; j < sparse[0][1]; j++)
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

void transposeofSparse(int sparse[][3], int result[][3])
{
    result[0][0] = sparse[0][1];
    result[0][1] = sparse[0][0];
    result[0][2] = sparse[0][2];

    int k = 1;

    for (int i = 0; i <= sparse[0][0]; i++)
    {
        for (int j = 0; j <= sparse[0][2]; j++)
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

void DisplaySparse(int sparse[][3])
{
    for (int i = 0; i <= sparse[0][2]; i++)
    {
        printf("%d %d %d \n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void main()
{
    int sparse[20][3], resultSparse[20][3];
    printf("Enter the number of rows: ");
    scanf("%d", &sparse[0][0]);
    printf("Enter the number of columns: ");
    scanf("%d", &sparse[0][1]);
    createSparseMatrix(sparse);
    DisplaySparse(sparse);

    transposeofSparse(sparse, resultSparse);
    printf("\nTranspose: \n");
    DisplaySparse(resultSparse);
}
