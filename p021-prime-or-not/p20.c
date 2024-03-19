// WAP to check whether the given number is prime or not
#include <stdio.h>
void main(){
    int num=103;
    for(int i=2; i<num; i++){
        if(num%i==0){
            printf("It's not prime");
            return;
        }
    }
    printf("It's prime");
}