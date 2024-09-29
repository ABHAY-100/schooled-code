#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack
{
    int top;
    char items[MAX];
};

void initStack(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char value)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

char peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->items[stack->top];
}

int isOperand(char ch)
{
    return isalnum(ch);
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    struct Stack stack;
    initStack(&stack);
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isOperand(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else
        {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
        i++;
    }

    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
