// Write a program to count number of vowels in a given string
#include <stdio.h>
#include <ctype.h>
void main(){
    char string[20] = "abeay", ch;
    int count = 0;
    for(int i=0; string[i]!='\0'; i++){
        ch = tolower(string[i]);
        switch (ch){
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' : count++;
                       break;
        }
    }
    printf("The String has %d vowels in it!..", count);
}