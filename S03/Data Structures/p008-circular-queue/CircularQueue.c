#include <stdio.h>
#define MAX 7
int Queue_CQ[MAX], front = -1, rear = -1;
void enqueue(int data) {
    if ((rear+1)%MAX == front) {
        printf("Queue Full!");
    } else if (rear == -1) {
        front = 0;
        rear = 0;
        Queue_CQ[rear] = data;
    } else {
        rear = (rear+1)%MAX;
        Queue_CQ[rear] = data;
    }
}
void dequeue() {
    if (front == -1) {
        printf("Queue Empty!");
    } else if (front == rear) {
        printf("%d", Queue_CQ[front]);
        front = -1;
        rear = -1;
    } else {
        printf("%d", Queue_CQ[front]);
        front = (front+1)%MAX;
    }
}
void display()
{
    if (front == -1) {
        printf("Queue Empty!");
    } else {
        int i = front;
        while (1) {
            printf("%d ", Queue_CQ[i]);
            if (i == rear)
                break;
            i = (i+1)%MAX;
        }
        printf("\n");
    }
}
void main()
{
    int choice, data;
    do {
        printf("\n\nMenu: \n");
        printf("1. Add an element\n");
        printf("2. Delete an element\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Push Element: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Pop Element: ");
                dequeue();
                break;
            case 3:
                printf("Queue: ");
                display();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Something went wrong! Try Again.");
                break;
        }
    } while (choice != 4);
}
