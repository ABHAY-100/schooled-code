// Question: 5.16 Write a program to find the average of six subjects and display the results as follows.
// AVERAGE                                   RESULT
// -------                                   ------
// >34 & <50                                 Third Division
// >49 & <60                                 Second Division
// >60 & <75                                 First Division
// >75 & <100                                Distinction
// If marks in any subject less than 35      Fail

#include <stdio.h>
int avgCalculator(float marks[6]){
    float sum;
    for(int j=0; j<6; j++){
        sum += marks[j];
    }
    float avg = sum/6;
    return avg;
}
void result(float marks[6]){
    float avg = avgCalculator(marks);
    if(avg<35){ printf("RESULT --> Fail"); }
    else if(avg<35){ printf("RESULT --> Fail"); }
    else if(avg>34 && avg<50){ printf("RESULT --> Third Division"); }
    else if(avg>49 && avg<60){ printf("RESULT --> Second Division"); }
    else if(avg>60 && avg<75){ printf("RESULT --> First Division"); }
    else if(avg>75 && avg<100){ printf("RESULT --> Distinction"); }
    else { printf("ERROR"); }
}
void main(){
    float marks[6];
    printf("Enter the marks of 6 subjects: \n");
    for(int i=0; i<6; i++){
        printf("Subject %d: ", i+1);
        scanf("%f", &marks[i]);
    }
    result(marks);
}