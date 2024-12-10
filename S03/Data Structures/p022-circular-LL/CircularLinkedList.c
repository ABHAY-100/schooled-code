#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself initially
    return newNode;
}

// Function to insert a node at the beginning
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete the first node
void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == *head) { // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next; // Find last node
        }
        
        *head = temp->next; // Move head to next node
        last->next = *head; // Update last node's next pointer
        free(temp); // Free old head
    }
}

// Function to delete the last node
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == *head) { // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        while (temp->next->next != *head) { // Find second last node
            temp = temp->next;
        }
        
        free(temp->next); // Free last node
        temp->next = *head; // Update second last's next pointer to head
    }
}

// Function to print the list contents
void print(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(head)\n");
}

int main() {
   struct Node* head = NULL; // Initialize head of the list as NULL

   int choice, data;

   while (1) {
       printf("\nMenu:\n");
       printf("1. Insert at Beginning\n");
       printf("2. Insert at End\n");
       printf("3. Delete from Beginning\n");
       printf("4. Delete from End\n");
       printf("5. Print List\n");
       printf("6. Exit\n");

       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("Enter the value to insert at the beginning: ");
               scanf("%d", &data);
               insertAtFirst(&head, data);
               break;

           case 2:
               printf("Enter the value to insert at the end: ");
               scanf("%d", &data);
               insertAtEnd(&head, data);
               break;

           case 3:
               deleteFromFirst(&head);
               break;

           case 4:
               deleteFromEnd(&head);
               break;

           case 5:
               print(head);
               break;

           case 6:
               exit(0);

           default:
               printf("Invalid choice! Please try again.\n");
       }
   }

   return 0;
}
