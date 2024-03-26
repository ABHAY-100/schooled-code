// Read n integers, store them in an array and find their sum and average
#include <stdio.h>
void main(){
    int n, sum=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++){
        printf("Enter %dth element: ", i+1);
        scanf("%d", &array[i]);
    }
    for(int i=0; i<n; i++){
        sum += array[i];
    }
    printf("Sum = %d\nAverage = %0.2f", sum, (float)sum/n);
}