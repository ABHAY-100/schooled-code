// C program to find angles of a triangle if two angles are given

#include <stdio.h>
void main(){
    float angle1, angle2, angle3;
    printf("Enter two known angles: ");
    scanf("%f%f", &angle1, &angle2);
    angle3 = ( 180 - angle1 - angle2 );
    printf("3rd Angle = %f Degree\n", angle3);
}