#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertAtFirst(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);

    if (position == 1)
    {
        insertAtFirst(head, data);
    }
    else
    {
        struct Node *temp = *head;
        for (int i = 1; temp->next != *head && i < position - 1; i++)
        {
            temp = temp->next;
        }
        if (temp->next == *head && position > 2)
        {
            printf("Position out of range\n");
            free(newNode);
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteFromFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    if (temp->next == *head)
    {
        free(temp);
        *head = NULL;
    }
    else
    {
        struct Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        *head = temp->next;
        last->next = *head;
        free(temp);
    }
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    if (temp->next == *head)
    {
        free(temp);
        *head = NULL;
    }
    else
    {
        while (temp->next->next != *head)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = *head;
    }
}

void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        deleteFromFirst(head);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; temp->next != *head && i < position - 1; i++)
    { // Traverse to position - 1
        temp = temp->next;
    }

    if (temp->next == *head || temp->next->next == *head)
    { // Out of range check
        printf("Position out of range\n");
    }
    else
    {
        struct Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("Enter the value and position to insert: ");
            scanf("%d %d", &data, &position);
            insertAtPosition(&head, data, position);
            break;
        case 4:
            deleteFromFirst(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            printf("Enter the position to delete from: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 7:
            print(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
