#include <stdio.h>

#define MAX_SIZE 100

int a[MAX_SIZE];

void buildtree(int a[], int i, int item)
{
    int ch, value;
    a[i] = item;

    printf("Do you want to create left child for %d (1/0): ", item);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter the left child: ");
        scanf("%d", &value);
        buildtree(a, 2 * i, value);
    }

    printf("Do you want to create right child for %d (1/0): ", item);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter the right child: ");
        scanf("%d", &value);
        buildtree(a, 2 * i + 1, value);
    }
}

void preorder(int a[], int index)
{
    if (index >= MAX_SIZE || a[index] == -1)
        return;
    printf("%d\t", a[index]);
    preorder(a, 2 * index);
    preorder(a, 2 * index + 1);
}

void inorder(int a[], int index)
{
    if (index >= MAX_SIZE || a[index] == -1)
        return;
    inorder(a, 2 * index);
    printf("%d\t", a[index]);
    inorder(a, 2 * index + 1);
}

void postorder(int a[], int index)
{
    if (index >= MAX_SIZE || a[index] == -1)
        return;
    postorder(a, 2 * index);
    postorder(a, 2 * index + 1);
    printf("%d\t", a[index]);
}

void creation()
{
    int root;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        a[i] = -1;
    }

    printf("Enter the root node: ");
    scanf("%d", &root);

    buildtree(a, 1, root);

    printf("\n");
}

int main()
{
    int choice;
    char cont;

    do
    {
        printf("The operations are:\n");
        printf("1. Creation\n2. Preorder\n3. Inorder\n4. Postorder\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            creation();
            break;
        case 2:
            printf("Preorder Traversal: ");
            preorder(a, 1);
            printf("\n");
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorder(a, 1);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorder(a, 1);
            printf("\n");
            break;
        default:
            printf("Invalid entry\n");
        }

        printf("\nDo you want to continue (y/n)? : ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
