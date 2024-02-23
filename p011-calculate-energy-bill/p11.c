// Question: Write a program to calculate energy bill. Read the starting and ending meter reading. The charges are as follows.
// No. Of Units Consumed           Rates in (Rs.)
// ---------------------           --------------
// 200-500                         3.50
// 100-200                         2.50
// Less than 100                   1.50

#include <stdio.h>
void main(){
    float startingReading, endingReading;
    printf("Enter the Start Meter Reading: ");
    scanf("%f", &startingReading);
    printf("Enter the End Meter Reading: ");
    scanf("%f", &endingReading);
    while(startingReading<0 || endingReading<0 || startingReading>endingReading){
        printf("Error! Try Again\n");
        printf("Enter the Start Meter Reading: ");
        scanf("%f", &startingReading);
        printf("Enter the End Meter Reading: ");
        scanf("%f", &endingReading);
        while(getchar() != '\n');
    }
    int unitConsumed = endingReading - startingReading;
    if(unitConsumed<100){ printf("Rate: Rs.%f", unitConsumed*1.50); }
    else if(unitConsumed>=100 && unitConsumed<=200){ printf("Bill: Rs.%f\n", unitConsumed*2.50); }
    else if(unitConsumed>=200 && unitConsumed<=500){ printf("Bill: Rs.%f\n", unitConsumed*3.50); }
    else{ printf("Over Use!!!.."); }
}