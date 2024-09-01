#include <stdio.h>
int factorial(int number){
    if(number){
        return number * factorial(number-1);
    }
    else{
        return 1;
    }
}
void main(){
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    int result = factorial(number);
    printf("%d! = %d\t", number, result);
}