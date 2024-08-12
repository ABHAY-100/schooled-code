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

void DisplaySparse(int sparse[][3], int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d %d %d \n", sparse[i][0], sparse[i][1], sparse[i][2]);
	}
}

void main()
{
	int rows, cols, size;
	int sparse[20][3];
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("Enter the number of columns: ");
	scanf("%d", &cols);
	sparse[0][0] = rows;
	sparse[0][1] = cols;
	size = createSparseMatrix(sparse, rows, cols);
	sparse[0][2] = size - 1;
	DisplaySparse(sparse, size);
}
