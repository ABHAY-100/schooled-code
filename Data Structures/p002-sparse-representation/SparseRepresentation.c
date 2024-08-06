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

int addSparseMatrices(struct SparseMatrix sparse1[], int size1, struct SparseMatrix sparse2[], int size2, struct SparseMatrix result[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (sparse1[i].row == sparse2[j].row && sparse1[i].col == sparse2[j].col) {
            result[k].row = sparse1[i].row;
            result[k].col = sparse1[i].col;
            result[k].value = sparse1[i].value + sparse2[j].value;
            i++;
            j++;
            k++;
        } else if (sparse1[i].row < sparse2[j].row || (sparse1[i].row == sparse2[j].row && sparse1[i].col < sparse2[j].col)) {
            result[k] = sparse1[i];
            i++;
            k++;
        } else {
            result[k] = sparse2[j];
            j++;
            k++;
        }
    }

    while (i < size1) {
        result[k] = sparse1[i];
        i++;
        k++;
    }

    while (j < size2) {
        result[k] = sparse2[j];
        j++;
        k++;
    }

    return k;
}

int main() {
    int rows, cols;
    struct SparseMatrix sparse1[MAX], sparse2[MAX], result[MAX];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter elements for the first matrix:\n");
    int size1 = createSparseMatrix(rows, cols, sparse1);

    printf("Enter elements for the second matrix:\n");
    int size2 = createSparseMatrix(rows, cols, sparse2);

    printf("\nFirst Sparse Matrix Representation:\n");
    displaySparseMatrix(sparse1, size1);

    printf("\nSecond Sparse Matrix Representation:\n");
    displaySparseMatrix(sparse2, size2);

    int size3 = addSparseMatrices(sparse1, size1, sparse2, size2, result);

    printf("\nResultant Sparse Matrix Representation (after addition):\n");
    displaySparseMatrix(result, size3);

    return 0;
}
