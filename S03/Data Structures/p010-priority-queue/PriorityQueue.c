#include <stdio.h>
#define MAX 7

// A normal queue follows the FIFO principle, where elements are dequeued in the order they were enqueued. In contrast, a priority queue dequeues elements based on their priority, with higher-priority elements being removed before lower-priority ones, regardless of the order they were added

int Queue[MAX];
int front = -1, rear = -1;

// Function to insert elements into the priority queue
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue Full!\n");
        return;
    }
    
    if (rear == -1) {  // If the queue is empty
        front = rear = 0;
        Queue[rear] = data;
    } else {
        // Insert element based on priority
        int i;
        for (i = rear; i >= front && Queue[i] < data; i--) {
            Queue[i + 1] = Queue[i];
        }
        Queue[i + 1] = data;
        rear++;
    }
}

// Function to remove elements from the priority queue
void dequeue() {
    if (front == -1) {
        printf("Queue Empty!\n");
    } else if (front == rear) {
        printf("Removed Element: %d\n", Queue[front]);
        front = rear = -1;
    } else {
        printf("Removed Element: %d\n", Queue[front]);
        front++;
    }
}

// Function to display the elements of the priority queue
void display() {
    if (front == -1) {
        printf("Queue Empty!\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int main() {
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
                printf("Enter element to push: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Element to pop: ");
                dequeue();
                break;
            case 3:
                printf("Queue: ");
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try Again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

