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

// Stack structure
struct Stack {
    struct Node *top; // Pointer to the top of the stack
};

// Function to create a stack
struct Stack *createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = stack->top; // Point new node to the current top
    stack->top = newNode;        // Update top to new node
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1; // Indicate that the stack is empty
    }
    struct Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next; // Update top to next node
    free(temp);              // Free old top node
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1; // Indicate that the stack is empty
    }
    return stack->top->data; // Return the top element's data
}

// Function to print the elements of the stack
void printStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    
    struct Node *temp = stack->top;
    printf("Stack elements: ");
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Stack *stack = createStack();
    
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                data = peek(stack);
                if (data != -1) {
                    printf("Top element is: %d\n", data);
                }
                break;
            case 4:
                printStack(stack);
                break;
            case 5:
                free(stack); // Free allocated memory for the stack before exiting
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}