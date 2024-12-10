#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};

struct Node *createNode(int data, int priority) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int data, int priority) {
    struct Node *newNode = createNode(data, priority);
    if (*head == NULL || (*head)->priority < priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeue(struct Node **head) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    
    struct Node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

void printQueue(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("Data: %d, Priority: %d -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data, priority;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                insert(&head, data, priority);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(&head));
                break;
            case 3:
                printQueue(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
