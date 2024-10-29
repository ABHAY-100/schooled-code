#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node **head, int coeff, int exp)
{
    struct Node *newNode = createNode(coeff, exp);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPolynomial(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d*x^%d ", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *poly = NULL;
    int choice, coeff, exp;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Term\n");
        printf("2. Display Polynomial\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter coefficient and exponent: ");
            scanf("%d %d", &coeff, &exp);
            insertTerm(&poly, coeff, exp);
            break;
        case 2:
            printf("Polynomial: ");
            displayPolynomial(poly);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}