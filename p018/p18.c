// Write a C program to accept a coordinate point in an XY coordinate system and determ1ne in wh1ch quadrant the coordinate point lies.
#include <stdio.h>
void quadChecker(double x, double y){
    if(x>0 && y>0){
        printf("The coordinate is in first Quadrant!");
    }
    else if(x>0 && y<0){
        printf("The coordinate is in second Quadrant!");
    }
    else if(x<0 && y<0){
        printf("The coordinate is in third Quadrant!");
    }
    else if(x<0 && y>0){
        printf("The coordinate is in fourth Quadrant!");
    }
    else if(x==0 && (y>0 || y<0)){
        printf("The coordinate lines in y axis!");
    }
    else if((x>0 || x<0) && y==0){
        printf("The coordinate lines in x axis!");
    }
    else if(x==0 && y==0){
        printf("The coordinate lines in Origin!");
    }
    else{
        printf("Try Again!");
    }
}
void main(){
    double x, y;
    printf("Enter the X-Coordinate: ");
    scanf("%lf", &x);
    printf("\nEnter the Y-Coordinate: ");
    scanf("%lf", &y);
    quadChecker(x, y);
}