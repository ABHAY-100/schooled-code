// WAP to read the length of 3 sides and check whether it forms a triangle.

#include <stdio.h>
void main(){
    float side1, side2, side3;
    printf("Enter the sides of the triangle: ");
    scanf("%f %f %f", &side1, &side2, &side3);
    if(((side1+side2)>side3) || ((side1+side3)>side2) || ((side3+side2)>side1)){
        printf("Its a triangle...");
    }
    else{
        printf("Its not a triangle...");
    }
}