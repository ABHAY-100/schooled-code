// Evaluate the arithmetic expression ((a-b/c*d+e)*(f+g)) and display its solution
#include <stdio.h>
void main(){
    int a, b, c, d, e, f, g;
    int result;

    a = 10;
    b = 20;
    c = 5;
    d = 2;
    e = 13;
    f = 22;
    g = 39;

    result = ((a-b/c*d+e)*(f+g));
    printf("Result = %d\n", result);
}