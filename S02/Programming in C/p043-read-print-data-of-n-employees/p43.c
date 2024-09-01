// Read and print the data of n employees using structures
#include <stdio.h>
struct employeesData{
    char name[50];
    int id;
    float salary;
};
void readData(struct employeesData *emp, int n){
    printf("\n");
    for(int i=0; i<n; i++){
        getchar();
        printf("Enter details of employee %d : \n", i+1);
        printf("Name : ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        printf("ID : ");
        scanf("%d", &emp[i].id);
        printf("Salary : ");
        scanf("%f", &emp[i].salary);
        printf("\n");
    }
}
void printData(struct employeesData *emp, int n){
    printf("\nEmployee Details : \n");
    printf("================\n\n");
    for(int i=0; i<n; i++){
        printf("Name : %s", emp[i].name);
        printf("ID : %d\n", emp[i].id);
        printf("Salary : %f\n\n", emp[i].salary);
    }
}
void main(){
    int n;
    printf("Enter the number of employees : ");
    scanf("%d", &n);

    struct employeesData emp[n];
    readData(emp, n);
    printData(emp, n);
}

