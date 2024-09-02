#include <stdio.h>
#include <ctype.h> // For isdigit() and isalpha() functions

#define MAX 100

// Stack structure to hold operators
char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;
    
    while (infix[i] != '\0') {
        c = infix[i];

        // If the character is an operand, add it to postfix expression
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it to stack
        else if (c == '(') {
            push(c);
        }
        // If the character is ')', pop from stack to postfix until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' from stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }

    // Pop remaining operators from stack to postfix
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

