// Write a concise C program to calculate the sum of the first N natural numbers. Prompt the user to input the limit N, then compute and display the sum.
#include <stdio.h>
int sumofNumbers(int limit){
    int sum=0, i=1;
    while(i<=limit){
        sum += i;
        i++;
    }
    return sum;
}
void main(){
    int limit, result;
    printf("Enter the limit : ");
    scanf("%d", &limit);
    result = sumofNumbers(limit);
    printf("The sum of %d natural numbers is : %d\n", limit, result);
}