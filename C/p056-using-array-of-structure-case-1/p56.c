// Declare a structure namely Student to store the details (roll number, name, mark_for_C) of a student. Then, write a program in C to find the average mark obtained by the students in a class for the subject Programming in C (using the field mark_for_C). Use array of structures to store the required data.
#include <stdio.h>
struct student{
    int roll_no;
    char name[50];
    int mark_in_c;
};
void main(){
    int n;
    printf("Enter the no. of students : ");
    scanf("%d", &n);
    struct student s[n];
    printf("\nEnter the details :");
    for(int i=0; i<n; i++){
        printf("\nStudent %d :\n", i+1);
        printf("Name : ");
        scanf("%s", s[i].name);
        printf("Roll no. : ");
        scanf("%d", &s[i].roll_no);
        printf("Mark : ");
        scanf("%d", &s[i].mark_in_c);
    }
    float avg, sum=0;
    for(int i=0; i<n; i++){
        sum += s[i].mark_in_c;
    }
    avg = sum/(float)n;
    printf("\n\nThe Average is %f\n", avg);
}