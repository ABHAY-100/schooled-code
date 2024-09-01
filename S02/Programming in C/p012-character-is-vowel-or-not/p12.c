// Question: WAP to check whether entered character is vowel or not.

#include <stdio.h>
#include <ctype.h>
void main(){
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    char check = tolower(ch);
    if(ch>='a' && ch<='z' && (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')){
        printf("%c is a vowel", ch);
    }
    else{
        printf("%c is not a vowel", ch);
    }
}