#include <stdio.h>
void main(){
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    printf("\nThe array elements are: \n");
    for(int i=n-1; i>=0; i--){
        printf("Element %d : %d\n", i+1, array[i]);
    }
}