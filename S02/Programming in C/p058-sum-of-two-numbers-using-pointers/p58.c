#include <stdio.h>
void main(){
    int num1 = 20, num2 = 10;
    int *p1, *p2;
    p1 = &num1;
    p2 = &num2;
    printf("Sum = %d", *p1+*p2);
}