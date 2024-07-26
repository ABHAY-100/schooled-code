// Find the factorial of a given natural number using recursive function
#include <stdio.h>
int findFactorial(int num){
    if(num!=0) return num*findFactorial(num-1);
    else return 1;
}
void main(){
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    int result = findFactorial(num);
    printf("Result : %d! = %d\n", num, result);
}