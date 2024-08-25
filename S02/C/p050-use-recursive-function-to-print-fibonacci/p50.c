// Write a concise C program to generate the Fibonacci series up to a given limit. Prompt the user to enter the limit, then display the Fibonacci series up to that limit.
#include <stdio.h>
int findFibonacci(int num){
    if(num==0) return 0;
    else if(num==1) return 1;
    return findFibonacci(num-1)+findFibonacci(num-2);
}
void main(){
    int limit, result;
    printf("Enter limit : ");
    scanf("%d", &limit);
    printf("The Series is : ");
    for(int i=0; i<limit; i++){
        result = findFibonacci(i);
        printf("%d ", result);
    }
}