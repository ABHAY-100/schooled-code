#include <stdio.h>
void main(){
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    int p[n];
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", (p+i));
    }
    printf("The array elements are: ");
    for(int i=0; i<n; i++){
        printf(" %d", *(p+i));
    }
    printf("\n");
}