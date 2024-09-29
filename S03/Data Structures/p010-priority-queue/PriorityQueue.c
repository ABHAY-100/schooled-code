#include <stdio.h>
#define SIZE 7

int front = -1, rear = -1;

struct PQueue
{
    int data;
    int priority;
} PQ[SIZE];

int isFull()
{
    return (rear == SIZE - 1);
}

int isEmpty()
{
    return (front == -1 && rear == -1);
}

void enqueue(int data, int priority)
{
    if (isFull())
    {
        printf("Queue Full!\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
        PQ[rear].data = data;
        PQ[rear].priority = priority;
    }
    else
    {
        int i;
        for (i = rear; i >= front && PQ[i].priority >= priority; i--)
        {
            PQ[i + 1] = PQ[i];
        }
        PQ[i + 1].data = data;
        PQ[i + 1].priority = priority;
        rear++;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d (%d)\n", PQ[i].data, PQ[i].priority);
    }
}

int main()
{
    int option, data, priority;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option! Try again.\n");
        }
    } while (option != 4);

    return 0;
}
