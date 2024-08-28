// #include <stdio.h>
// #define MAX 7

// int Deque[MAX], front = -1, rear = -1;

// void insertFront(int data) {
//     if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
//         printf("Deque Full!");
//     } else if (front == -1) {
//         front = 0;
//         rear = 0;
//         Deque[front] = data;
//     } else if (front == 0) {
//         front = MAX - 1;
//         Deque[front] = data;
//     } else {
//         Deque[--front] = data;
//     }
// }

// void insertRear(int data) {
//     if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
//         printf("Deque Full!");
//     } else if (rear == -1) {
//         front = 0;
//         rear = 0;
//         Deque[rear] = data;
//     } else if (rear == MAX - 1) {
//         rear = 0;
//         Deque[rear] = data;
//     } else {
//         Deque[++rear] = data;
//     }
// }

// void deleteFront() {
//     if (front == -1) {
//         printf("Deque Empty!");
//     } else if (front == rear) {
//         printf("%d", Deque[front]);
//         front = -1;
//         rear = -1;
//     } else if (front == MAX - 1) {
//         printf("%d", Deque[front]);
//         front = 0;
//     } else {
//         printf("%d", Deque[front++]);
//     }
// }

// void deleteRear() {
//     if (front == -1) {
//         printf("Deque Empty!");
//     } else if (front == rear) {
//         printf("%d", Deque[rear]);
//         front = -1;
//         rear = -1;
//     } else if (rear == 0) {
//         printf("%d", Deque[rear]);
//         rear = MAX - 1;
//     } else {
//         printf("%d", Deque[rear--]);
//     }
// }

// void display() {
//     if (front == -1) {
//         printf("Deque Empty!");
//     } else {
//         int i = front;
//         while (i != rear) {
//             printf("%d ", Deque[i]);
//             i = (i + 1) % MAX;
//         }
//         printf("%d ", Deque[rear]);
//     }
// }

// void main() {
//     int choice, data;
//     do {
//         printf("\n\nMenu: \n");
//         printf("1. Insert at front\n");
//         printf("2. Insert at rear\n");
//         printf("3. Delete from front\n");
//         printf("4. Delete from rear\n");
//         printf("5. Display deque\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         switch (choice) {
//             case 1:
//                 printf("Insert Element at Front: ");
//                 scanf("%d", &data);
//                 insertFront(data);
//                 break;
//             case 2:
//                 printf("Insert Element at Rear: ");
//                 scanf("%d", &data);
//                 insertRear(data);
//                 break;
//             case 3:
//                 printf("Delete Element from Front: ");
//                 deleteFront();
//                 break;
//             case 4:
//                 printf("Delete Element from Rear: ");
//                 deleteRear();
//                 break;
//             case 5:
//                 printf("Deque: ");
//                 display();
//                 break;
//             case 6:
//                 printf("Exiting...");
//                 break;
//             default:
//                 printf("Invalid choice! Try Again.");
//                 break;
//         }
//     } while (choice != 6);
// }
