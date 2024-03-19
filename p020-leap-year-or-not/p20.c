// WAP to find whether a year is a leap year or not
#include <stdio.h>
void main(){
    int year=1900;
    if(year%4==0 && year%100!=0){
        printf("It's a leap year");
    }
    else if(year%100==0 && year%400==0){
        printf("It's a leap year");
    }
    else{
        printf("It's not a leap year");
    }
}