// Write a program to create a structure employee with member variables name, age, bs, da, hra and tsalary. Total Salary is calculated by the equation tsalary= (1 + da + hra) ^ * bs. Read the values of 3 employees and display details based on descending order of tsalary.
#include <stdio.h>
struct employeesData{
    char name[50];
    int age;
    float bs;
    float da;
    float hra;
    float tsalary;
};
void readData(struct employeesData *emp, int n){
    printf("\n");
    for(int i=0; i<n; i++){
        getchar();
        printf("Enter details of employee %d : \n", i+1);
        printf("Name : ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        printf("Basic Salary : ");
        scanf("%f", &emp[i].bs);
        printf("DA Percentage : ");
        scanf("%f", &emp[i].da);
        printf("HRA Percentage : ");
        scanf("%f", &emp[i].hra);
        emp[i].tsalary = ((1.0+emp[i].da+emp[i].hra)*emp[i].bs);
        printf("\n");
    }
}
void printData(struct employeesData *emp, int n){
    printf("\nEmployee Details : \n");
    printf("================\n\n");
    for(int i=0; i<n; i++){
        printf("Name : %s", emp[i].name);
        printf("Age : %d\n", emp[i].age);
        printf("Basic Salary : %f\n", emp[i].bs);
        printf("DA Percentage : %f\n", emp[i].da);
        printf("HRA Percentage : %f\n", emp[i].hra);
        printf("Total Salary : %f\n\n", emp[i].tsalary);
    }
}
void sortData(struct employeesData *emp, int n){
    struct employeesData temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(emp[j].tsalary<emp[j+1].tsalary){
                temp = emp[j+1];
                emp[j+1] = emp[j];
                emp[j] = temp;
            }
        }
    }
};
void main(){
    int n;
    printf("Enter the number of employees : ");
    scanf("%d", &n);

    struct employeesData emp[n];
    readData(emp, n);
    sortData(emp, n);
    printData(emp, n);
}
