// C program to print the sum of series [1^2 + 2^2 + 3^3 + ....]
#include <stdio.h>

int main() {
    int n;
    double sum = 0.0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        double term = 1.0;
        for (int j = 0; j < i; j++) {
            term *= i;
        }
        sum += term;
    }

    printf("The sum of the series is: %.2lf\n", sum);

    return 0;
}
