#include <stdio.h>
void main(){
    int age[]= {18, 19, 32, 89, 5, 34, 48}, sum=0;
    double avg;
    int len = sizeof(age) / sizeof(age[0]);
    for(int i = 0; i<len; i++){
        sum += age[i];
    }
    avg = sum/len;
    printf("Average = %lf", avg);
}