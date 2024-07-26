// Create a concise C program to calculate the sum of the digits of a given number. Prompt the user to enter a number, calculate the sum of its digits, and display the result.
#include <stdio.h>
int sumofDigits(int num){
    int sum=0;
    while(num!=0){
        sum += num%10;
        num /= 10;
    }
    return sum;
}
void main(){
    int num, result;
    printf("Enter a number : ");
    scanf("%d", &num);
    result = sumofDigits(num);
    printf("The sum of digits of %d is : %d\n", num, result);
}