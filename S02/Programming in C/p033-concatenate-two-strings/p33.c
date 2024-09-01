// Program to concatenate two strings without using string handling function
#include <stdio.h>
void main(){
    char string1[100] = "Kings", string2[100] = "men";
    int i;
    for(i=0; string1[i]!='\0'; i++);
    for(int j=0; string2[j]!='\0'; j++, i++){
        string1[i] = string2[j];
    }
    printf("The Concatenate string is %s", string1);
}