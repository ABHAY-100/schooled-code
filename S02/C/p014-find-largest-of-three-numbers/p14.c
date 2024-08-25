// Question: WAP to find largest of 3 numbers.

#include <stdio.h>
void main(){
    float num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    if(num1>num2 && num1>num3){
        printf("%f is larger than %f & %f", num1, num2, num3);
    }
    else if(num2>num1 && num2>num3){
        printf("%f is larger than %f & %f", num2, num1, num3);
    }
    else if(num3>num1 && num3>num2){
        printf("%f is larger than %f & %f", num3, num1, num2);
    }
    else if(num1==num2 && num1==num3){
        printf("All numbers are the same");
    }
    else{
        printf("Try Again!");
    }
}