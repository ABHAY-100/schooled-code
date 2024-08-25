#include <stdio.h>
void main(){
    int num1 = 20, num2 = 10;
    int *p1, *p2, temp;
    p1 = &num1;
    p2 = &num2;
    printf("After Swap:\n");
    printf("num1: %d, num2: %d\n\n", *p1, *p2);
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("Before Swap:\n");
    printf("num1: %d, num2: %d", *p1, *p2);
}