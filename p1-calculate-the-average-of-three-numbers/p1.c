// C program to calculate the average of three numbers

#include <stdio.h>
void main(){
    double num1, num2, num3, n=3;
    printf("Enter three numbers: ");
    scanf("%lf%lf%lf", &num1, &num2, &num3);
    double avg = (num1+num2+num3)/n;
    printf("Average: %lf", avg);
}