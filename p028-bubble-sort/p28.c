// C program for bubble sort
#include <stdio.h>
int bubbleSort(int n, int array[]){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
int printArray(int n, int array[]){
    printf("Sorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
}
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++){
        printf("Enter %dth element: ", i+1);
        scanf("%d", &array[i]);
    }
    bubbleSort(n, array);
    printArray(n, array);
}