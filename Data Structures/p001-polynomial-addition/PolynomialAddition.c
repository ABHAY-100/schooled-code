#include <stdio.h>
struct poly {
    float coeff;
    int exp;
};
struct poly p1[20], p2[20], p3[20];
int ReadPoly (struct poly p[]) {
    int t, i;
    printf("Enter the no. terms in the polynomial: ");
    scanf("%d", &t);
    for (i=0; i<t; i++) {
        printf("Enter the coefficient of term %d: ", i+1);
        scanf("%f", &p[i].coeff);
        printf("Enter the exponent of term %d: ", i+1);
        scanf("%d", &p[i].exp);
    }
    printf("\n");
    return t;
}
int AddPoly (struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i=0, j=0, k=0;
    while (i<t1 && j<t2) {
        if(p1[i].exp == p2[j].exp) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        } else if (p1[i].exp > p2[j].exp) {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
    }
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }
    return k;
}
int DisplayPoly (struct poly p[], int t) {
    int k;
    for (k=0; k<t-1; k++) 
        printf("%0.2f(X^%d) + ", p[k].coeff, p[k].exp);
    printf("%0.2f(X^%d)\n", p[t-1].coeff, p[t-1].exp);
}
int main() {
    int t1, t2, t3;
    printf("\nPOLYNOMIAL 1 :\n\n");
    t1 = ReadPoly(p1);
    DisplayPoly(p1, t1);
    printf("\nPOLYNOMIAL 2 :\n\n");
    t2 = ReadPoly(p2);
    DisplayPoly(p2, t2);
    printf("\nSUM: \n\n");
    t3 = AddPoly(p1, p2, t1, t2, p3);
    DisplayPoly(p3, t3);
    return 0;
}