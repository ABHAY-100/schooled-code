#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>

#define MAX 100

struct Stack
{
    int top;
    int items[MAX];
};

int isFull(struct Stack *stack)
{
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow!");
    }
    else
    {
        stack->items[++(stack->top)] = data;
    }
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow!");
        return -1;
    }
    else
    {
        return (stack->items[(stack->top)--]);
    }
}

int evaluatePostfix(char *postfix)
{
    struct Stack stack;
    stack.top = -1;

    char *token;
    int operand1, operand2, result;

    token = strtok(postfix, " ");
    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            push(&stack, atoi(token));
        }
        else
        {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (token[0])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = 1;
                for (int j = 0; j < operand2; j++)
                {
                    result *= operand1;
                }
                break;
            default:
                printf("Invalid operator: %s\n", token);
                return -1;
            }
            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main()
{
    char expression[] = "5 4 +";

    int result = evaluatePostfix(expression);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}
