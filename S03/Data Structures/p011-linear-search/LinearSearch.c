#include <stdio.h>
int key, size;
void inputArray(int array[]) {
    int  i;
    printf("\nEnter the no. of array elements: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (i=0; i<size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the key: ");
    scanf("%d", &key); 
}
void linearSearch(int array[]) {
    for (int i=0; i<size; i++) {
        if (key == array[i]) {
            printf("\nElement found at Index %d\n", i);
            return;
        }
    }
    printf("Element not found!\n");
}
void main() {
    int array[30];
    inputArray(array);
    linearSearch(array);
}