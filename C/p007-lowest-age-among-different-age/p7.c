#include <stdio.h>
void main(){
    int age[]= {18, 19, 32, 89, 5, 34, 48}, low = age[0];
    int len = sizeof(age) / sizeof(age[0]);
    for(int i=0; i<len; i++){
        if(low>age[i]){
            low = age[i];
        }
    }
    printf("Lowest = %d", low);
}