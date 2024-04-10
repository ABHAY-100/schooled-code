// C program for binary search1
#include <stdio.h>
int binarySearch(int array[], int left, int right, int key){
    while(left<=right){
        int mid = left + (right-left)/2;
        if(array[mid]==key){
            return mid;
        }
        if(array[mid]<key) left = mid+1;
        else right = mid-1;
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
    int result = binarySearch(array, 0, n-1, key);
    if(result == -1){
        printf("Element not found!!");
    }
    else printf("Element is found at index %d", result);
}