// Program to copy a string to another without using string handling function
#include <stdio.h>
void main(){
    char var1[20] = "Amul", var2[20];
    for(int i=0; var1[i]!='\0'; i++){
        var2[i] = var1[i];
    }
    printf("Copied String --> %s\t", var2);
}