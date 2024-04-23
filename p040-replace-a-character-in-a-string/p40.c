// This is a C program to replace a character in a string with a new character
#include <stdio.h>
#include <string.h>
void replaceChar(char str[], char oldChar, char newChar){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==oldChar){
            str[i]=newChar;
        }
        i++;
    }
}
void main(){
    char str[100], oldChar, newChar;

    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Enter the new character : ");
    scanf(" %c", &newChar);

    printf("To replace : ");
    scanf(" %c", &oldChar);

    printf("Original string: %s\n", str);

    replaceChar(str, oldChar, newChar);

    printf("After replacement: %s\n", str);
}