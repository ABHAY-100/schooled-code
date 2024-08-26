#include <stdio.h>
struct poly {
    float coeff;
    int exp;
};
struct poly p[50];
int avail = 0;
void readPoly(struct poly p[]) {
    int t;
    printf("Enter the number of elements: ");
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        printf("Enter the coeff: ");
        scanf("%f", &p[avail].coeff);
        printf("Enter the exp: ");
        scanf("%d", &p[avail].exp);
        avail++;
    }
    printf("\n");
}
void addPoly(struct poly p[], int startA, int startB, int finishA, int finishB, int startD) {
    int i=startA, j=startB, k=startD;
    while (i<=finishA && j<=finishB) {
        if(p[i].exp < p[j].exp) {
            p[k].exp = p[j].exp;
            p[k].coeff = p[j].coeff;
            j++;
            k++;
            avail++;
        } else if (p[i].exp > p[j].exp) {
            p[k].exp = p[i].exp;
            p[k].coeff = p[i].coeff;
            i++;
            k++;
            avail++;
        } else {
            p[k].exp = p[i].exp;
            p[k].coeff = p[i].coeff + p[j].coeff;
            i++;
            j++;
            k++;
            avail++;
        }
    }
    while (i<=finishA) {
        p[k].exp = p[i].exp;
        p[k].coeff = p[i].coeff;
        i++;
        k++;
        avail++;
    }
    while (j<=finishB) {
        p[k].exp = p[j].exp;
        p[k].coeff = p[j].coeff;
        j++;
        k++;
        avail++;
    }
}
void display(struct poly p[], int start, int finish) {
    printf("Polynomial: ");
    for (int i=start; i<finish; i++) {
        printf("%f(x^%d) + ", p[i].coeff, p[i].exp);
    }
    printf("%f(x^%d)\n", p[finish].coeff, p[finish].exp);
}
void main() {
    int startA, startB, finishA, finishB, startD, finishD;
    printf("\nPOLYNOMIAL 1: \n");
    startA = avail;
    readPoly(p);
    finishA = avail-1;
    display(p, startA, finishA);
    printf("\nPOLYNOMIAL 2: \n");
    startB = avail;
    readPoly(p);
    finishB = avail-1;
    display(p, startB, finishB);
    printf("\nAfter Adding Polynomials: \n");
    startD = avail;
    addPoly(p, startA, startB, finishA, finishB, startD);
    finishD = avail-1;
    display(p, startD, finishD);
}