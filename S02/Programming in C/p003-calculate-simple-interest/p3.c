// C program to calculate simple interest

#include <stdio.h>
void main(){
    float p, r, t;
    printf("Enter the Principal: ");
    scanf("%f", &p);
    printf("Enter the Rate of Interet: ");
    scanf("%f", &r);
    printf("Enter the Time Span: ");
    scanf("%f", &t);
    double simpleInterest = (p*r*t)/100;
    printf("S.I. = %lf", simpleInterest);
}