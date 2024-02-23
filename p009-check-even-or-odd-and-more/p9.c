// Question: Write a program to check whether the number is even or odd, and then if it is even, check whether it is divisible by 4 or not, and if it is odd, check whether it is divisible by 3 or not (using nested if)

#include <stdio.h>
void main(){
    int num;
    printf("Enter a number: ");
    while(!(scanf("%d", &num))){
        printf("Invalid input! Enter a number: ");
        while (getchar() != '\n');
    };
    if(num%2==0){
        printf("%d is even", num);
        if(num%4==0){
            printf(" & divisible by 4");
        }
        else{
            printf(" & not divisible by 4\n");
        }
    }
    else{
        printf("%d is odd", num);
        if(num%3==0){
            printf(" & divisible by 3");
        }
        else{
            printf(" & not divisible by 3\n");
        }
    }
}