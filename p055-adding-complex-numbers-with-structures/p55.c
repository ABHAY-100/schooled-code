// Write a C program using structures to handle complex numbers. Prompt the user to enter the count of complex numbers they want to process. Then, for each complex number, ask for its real and imaginary parts. Calculate and display the sum of all entered complex numbers.
#include <stdio.h>
struct complexNumber{
    int real;
    int imaginary;
};
void main(){
    int n;
    printf("Enter the no. of Complex Numbers : ");
    scanf("%d", &n);
    struct complexNumber s[n], sum;
    for(int i=0; i<n; i++){
        printf("\nComplex Number %d\n", i+1);
        printf("Real Part : ");
        scanf("%d", &s[i].real);
        printf("Imaginary Part : ");
        scanf("%d", &s[i].imaginary);
    }
    for(int i=0; i<n; i++){
        sum.real += s[i].real;
        sum.imaginary += s[i].imaginary;
    }
    printf("\nThe sum is : %d + %di\n", sum.real, sum.imaginary);
}