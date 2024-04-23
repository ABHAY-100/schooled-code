// WAP to swap two numbers using user defined functions
#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main(){
    int num1, num2;
    printf("Enter Number 1 : ");
    scanf("%d", &num1);
    printf("Enter Number 2 : ");
    scanf("%d", &num2);
    swap(&num1, &num2);
    printf("\nNumber 1 : %d\nNumber 2 : %d\n", num1, num2);
}