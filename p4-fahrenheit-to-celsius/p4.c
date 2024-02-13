// C Program to convert temperature in fahrenheit to celsius

#include <stdio.h>
void main(){
    float fahrenheit;
    printf("Enter the temperature in fahrenheit: ");
    scanf("%f", &fahrenheit);
    float celsius = ((fahrenheit-32.0)*(5.0/9.0));
    printf("In Celsius = %f", celsius);
}