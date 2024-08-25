// Find the sum of series 1 + 1/2! + 1/3!...
#include <stdio.h>
int findFactorial(int num){
    if(num!=0) return num*findFactorial(num-1);
    else return 1;
}
void main(){
    int limit;
    double sum=0;
    printf("Enter the limit : ");
    scanf("%d", &limit);
    for(int i=1; i<=limit; i++){
        sum += 1.0/findFactorial(i);
    }
    printf("The Sum is %lf", sum);
}