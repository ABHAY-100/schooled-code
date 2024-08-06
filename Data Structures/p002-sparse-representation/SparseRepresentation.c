#include <stdio.h>
#define MAX 100

struct SparseMatrix {
    int row;
    int col;
    int value;
};

int createSparseMatrix(int rows, int cols, struct SparseMatrix sparse[]) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            printf("Enter the element at (%d, %d): ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = value;
                k++;
            }
        }
    }
    return k;
}

void displaySparseMatrix(struct SparseMatrix sparse[], int size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int rows, cols;
    struct SparseMatrix sparse[MAX];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int size = createSparseMatrix(rows, cols, sparse);

    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparse, size);

    return 0;
}
