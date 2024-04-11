// Program to check two strings are equal without using string handling functions
#include <stdio.h>
void main(){
    char var1[20] = "Variable", var2[20] = "Vari";
    int flag = 0;
    int i;
    for(i=0; var1[i]!='\0' && var2[i]!='\0'; i++){
        if(var1[i]!=var2[i]){
            flag = 1;
            break;
        }
    }
    if(flag == 0 && var1[i]=='\0' && var2[i]=='\0') printf("Strings are same");
    else printf("Strings are not same");
}