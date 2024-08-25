// Question: Classify a person's age group and determine if they are eligible to vote. A person under 18 is a minor, between 18 and 65 is an Adult, and above 65 is a Senior. Only Adults & Seniors are eligible to vote.

#include <stdio.h>
void calcAge(int age){
    if(age>0 && age<18){
        int more= 18-age;
        printf("Oops! You are a Minor. Try Again after %d years", more);
    }
    else if(age>=18 && age <=65){
        printf("Yea u'r a Adult! You are eligible to Vote.");
    }
    else if(age >=65){
        printf("Yea u'r a Senior! You are eligible to Vote.");
    }
    else{
        printf("Try Again!");
    }
}
void main(){
    int age;
    printf("Enter your Age: ");
    scanf("%d", &age);
    calcAge(age);
}