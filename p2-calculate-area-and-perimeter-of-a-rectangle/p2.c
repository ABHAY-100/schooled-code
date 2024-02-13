// C Program to calculate the area and perimeter of a rectangle

#include <stdio.h>
void main(){
    float x, y;
    printf("Enter the length: ");
    scanf("%f", &x);
    printf("Enter the breadth: ");
    scanf("%f", &y);
    double area = x*y, perimeter = 2*(x+y);
    printf("\nArea = %lf\n", area);
    printf("Perimeter = %lf", perimeter);
}