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
void binarySearch(int array[]) {
    int left=0, right=size-1;
    int mid;
    while (left <= right) {
        mid = (right+left)/2;
        if (array[mid] == key) {
            printf("\nElement found at Index %d\n", mid);
            return;
        }
        else if (array[mid] > key) right = mid-1;
        else left = mid+1;
    }
    
}
void main() {
    int array[30];
    inputArray(array);
    binarySearch(array);
}