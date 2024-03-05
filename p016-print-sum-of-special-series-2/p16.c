// C program to print the sum of series [1^1 + 2^2 + 3^3 + ....]
#include <stdio.h>
void main(){
    int limit, sum=0, temp=1;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    for(int i=1; i<=limit; i++){
        for(int j=1; j<=i; j++){
            temp *= i;
        }
        sum += temp;
        temp=1;
    }
    printf("Sum of %d elements of the series = %d\n", limit, sum);
}