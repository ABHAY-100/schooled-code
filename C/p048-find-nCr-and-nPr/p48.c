// Develop a concise C program to calculate combinations and permutations using factorial functions. Prompt the user to input values for 'n' and 'r', then compute and display the corresponding nPr and nCr values.
#include <stdio.h>
float findFactorial(float num){
    if(num!=0) return num*findFactorial(num-1);
    else return 1.0;
}
void main(){
    float n, r;
    printf("Enter n : ");
    scanf("%f", &n);
    printf("Enter r : ");
    scanf("%f", &r);
    float nPr = findFactorial(n) / findFactorial(n-r);
    float nCr = findFactorial(n) / (findFactorial(n-r)*findFactorial(r));
    printf("Here, n = %f & r = %f\n", n, r);
    printf("nPr = %f\n", nPr);
    printf("nCr = %f\n", nCr);
}