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
    int temp, flag;
    for(int i=0; i<n-1; i++){
        flag = 1;
        for(int j=0; j<n-i-1; j++){
            if(*(p+j) > *(p+j+1)){
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
                flag = 0;
            }
        }
        if(flag != 0){
            break;
        }
    }
    printf("The sorted array is: ");
    for(int i=0; i<n; i++){
        printf(" %d", *(p+i));
    }
    printf("\n");
}