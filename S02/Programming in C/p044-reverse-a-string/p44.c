// Read a string, store it in an array and obtain its reverse by using user defined function
#include <stdio.h>
#include <string.h>
void reverseString(char string[50]){
    int n = strlen(string);
    char temp;
    for(int i=0, j=n-1; i<j; i++, j--){
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
    printf("The reversed string : %s\n", string);
}
void main(){
    char string[50];
    printf("Enter the string : ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    reverseString(string);
}