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

void DisplaySparse(int sparse[][3])
{
	for (int i = 0; i <= sparse[0][2]; i++)
	{
		printf("%d %d %d \n", sparse[i][0], sparse[i][1], sparse[i][2]);
	}
}

void main()
{
	int sparse[20][3];
	printf("Enter the number of rows: ");
	scanf("%d", &sparse[0][0]);
	printf("Enter the number of columns: ");
	scanf("%d", &sparse[0][1]);
	createSparseMatrix(sparse);
	DisplaySparse(sparse);
}
