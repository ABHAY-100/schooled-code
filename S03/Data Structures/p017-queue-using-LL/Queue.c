#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Queue structure
struct Queue {
    struct Node *front; // Pointer to the front of the queue
    struct Node *rear;  // Pointer to the rear of the queue
};

// Function to create a queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int data) {
    struct Node *newNode = createNode(data);
    
    if (queue->rear == NULL) {
        // If the queue is empty, both front and rear are set to the new node
        queue->front = newNode;
        queue->rear = newNode;
        printf("Enqueued %d into the queue.\n", data);
        return;
    }
    
    // Add the new node at the end of the queue and update rear
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Enqueued %d into the queue.\n", data);
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Indicate that the queue is empty
    }
    
    struct Node *temp = queue->front;
    int dequeuedValue = temp->data;

    // Move front to the next node
    queue->front = temp->next;

    // If front becomes NULL, then also set rear to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp); // Free old front node
    printf("Dequeued %d from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to peek at the front element of the queue
int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // Indicate that the queue is empty
    }
    
    return queue->front->data; // Return front element's data
}

// Function to print the elements of the queue
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

// Main function to demonstrate queue operations
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
                free(queue); // Free allocated memory for the queue before exiting
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}