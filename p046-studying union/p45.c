// Declare a union containing 5 string variables ( Name, House Name, City, State & Pincode). Then read & display the address of a person using a variable of the union.
#include <stdio.h>
#define MAX_SIZE 50
union address{
    char name[MAX_SIZE];
    char house_name[MAX_SIZE];
    char city[MAX_SIZE];
    char state[MAX_SIZE];
    char pincode[MAX_SIZE];
};
void main(){
    union address record1;
    printf("Enter Name : ");
    fgets(record1.name, sizeof(record1.name), stdin);
    printf("Enter House Name : ");
    fgets(record1.house_name, sizeof(record1.house_name), stdin);
    printf("Enter City : ");
    fgets(record1.city, sizeof(record1.city), stdin);
    printf("Enter State : ");
    fgets(record1.state, sizeof(record1.state), stdin);
    printf("Enter Pincode : ");
    fgets(record1.pincode, sizeof(record1.pincode), stdin);
    printf("\nRecord 1 Details : \n");
    printf("Name : %s", record1.name);
    printf("House Name : %s", record1.house_name);
    printf("City : %s", record1.city);
    printf("State : %s", record1.state);
    printf("Pincode : %s\n", record1.pincode);
}