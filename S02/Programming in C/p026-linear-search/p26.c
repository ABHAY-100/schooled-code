// C program for linear search
#include <stdio.h>
int linearSearch(int n, int array[], int key){
    for(int i=0; i<n; i++){
        if(key == array[i]){
            return i;
        }
    }
    return -1;
}
void main(){
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++){
        printf("Enter %dth element: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = linearSearch(n, array, key);
    if(result != -1){
        printf("Element is found at index %d", result);
    }
    else printf("Element not found!!");
}