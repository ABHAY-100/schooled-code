// This is a C program to check for palindrome
#include <stdio.h>
#include <string.h>
int isPali(char str[]){
    int len = strlen(str);
    for(int i=0, j=len-1; i<j; i++, j--){
        if(str[i] != str[j]){
            return 0;
        }
    }
    return 1;
}
void main(){
    char str[100];
    
    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str,"\n")] = 0;

    if(isPali(str))
        printf("%s is a palindrome", str);
    else
        printf("%s is not a palindrome", str);
}