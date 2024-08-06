#include <stdio.h>

struct sparseMatrix {
	int rows;
	int cols;
	int values;
};

int createSparseMatrix(struct sparseMatrix sparse[], int row, int col) {
	int val;
	int i = 0, j = 0, k = 1;
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			printf("Enter the value at (%d, %d): ", i, j);
			scanf("%d", &val);
			if(val!=0) {
				sparse[k].rows = i;
				sparse[k].cols = j;
				sparse[k].values = val;
				k++;
			}
		}
	}
	return k;	
}

void DisplaySparse(struct sparseMatrix sparse[], int k) {
	for(int i=0; i<k; i++) {
		printf("%d %d %d \n", sparse[i].rows, sparse[i].cols, sparse[i].values);
	}
}

void main() {
	int rows, cols, size;
	struct sparseMatrix sparse[20];
	printf("Enter the number of rows: ");
    	scanf("%d", &rows);
    	printf("Enter the number of columns: ");
	scanf("%d", &cols);
	sparse[0].rows = rows;
	sparse[0].cols = cols;
	size = createSparseMatrix(sparse, rows, cols);
	sparse[0].values = size-1;
	DisplaySparse(sparse, size);
}
