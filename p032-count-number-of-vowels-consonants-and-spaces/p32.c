// Write a program to count number of vowels in a given string
#include <stdio.h>
#include <ctype.h>
void main(){
    char string[20] = "abeay kumar", ch;
    int c = 0, v = 0, s = 0;
    for(int i=0; string[i]!='\0'; i++){
        ch = tolower(string[i]);
        switch (ch){
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' : v++;
            break;
            default : if( ch >= 'a' && ch <= 'z') c++;
			break;
        }
        switch(ch){
			case ' ' : s++;
			break;
		}
    }
    printf("The String has %d vowels, %d consonants & %d white spaces in it!..\n", v, c, s);
}