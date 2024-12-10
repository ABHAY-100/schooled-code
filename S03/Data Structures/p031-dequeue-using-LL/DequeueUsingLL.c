#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Deque *createDeque() {
    struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

void insertFront(struct Deque *deque, int data) {
    struct Node *newNode = createNode(data);
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void insertRear(struct Deque *deque, int data) {
    struct Node *newNode = createNode(data);
    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int deleteFront(struct Deque *deque) {
    if (deque->front == NULL) {
        printf("Deque is empty\n");
        return -1;
    }
    
    struct Node *temp = deque->front;
    int data = temp->data;

    deque->front = deque->front->next;

    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }

    free(temp);
    return data; 
}

int deleteRear(struct Deque *deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty\n");
        return -1;
    }
    
    struct Node *temp = deque->rear;
    int data = temp->data;

    deque->rear = deque->rear->prev;

    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }

    free(temp);
    return data; 
}

void printDeque(struct Deque *deque) {
    struct Node *temp = deque->front;
    
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

int main() {
    struct Deque *deque = createDeque();
    
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Print Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(deque, data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(deque, data);
                break;
            case 3:
                printf("Deleted from front: %d\n", deleteFront(deque));
                break;
            case 4:
                printf("Deleted from rear: %d\n", deleteRear(deque));
                break;
            case 5:
                printDeque(deque);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
