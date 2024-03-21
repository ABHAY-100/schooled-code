// WAP to print the factorial of a given number
#include <stdio.h>
int factorial(int num){
    if(num!=0){
        return num*factorial(num-1);
    }
    else{
        return 1;
    }
}
void main(){
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Result = %d", factorial(number));
}