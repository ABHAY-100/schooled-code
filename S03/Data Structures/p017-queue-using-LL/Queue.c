#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue *queue, int data) {
    struct Node *newNode = createNode(data);
    
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
        printf("Enqueued %d into the queue.\n", data);
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Enqueued %d into the queue.\n", data);
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    
    struct Node *temp = queue->front;
    int dequeuedValue = temp->data;

    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("Dequeued %d from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    }
    
    return queue->front->data;
}

void printQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node *temp = queue->front;
    printf("Queue elements: ");
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

int main() {
    struct Queue *queue = createQueue();
    
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                data = peek(queue);
                if (data != -1) {
                    printf("Front element is: %d\n", data);
                }
                break;
            case 4:
                printQueue(queue);
                break;
            case 5:
                free(queue);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
