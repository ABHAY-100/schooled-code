// WAP to check whether the given number is amstrong or not
#include <stdio.h>
#include <math.h>
void main(){
    int num, i=0;
    printf("Enter a number: ");
    scanf("%d", &num);
    int temp = num;
    while(temp!=0){
        temp /= 10;
        ++i;
    }
    temp = num;
    int digits[i], sum=0;
    for(int j=0; j<i; j++){
        digits[j] = temp%10;
        temp /= 10;
    }
    for(int j=0; j<i; j++){
        sum += pow(digits[j], i);
        // sum += digits[j]*digits[j]*digits[j];
    }
    sum == num ? printf("Its Amstrong Number") : printf("Its not Amstrong Number");
}