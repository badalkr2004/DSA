#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// insert an element
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!!!");
        return;
    };
    stack[++top] = value;
    printf("%d pushed to stack\n", value);
}

// remove top element
void pop()
{
    if (top == -1)
    {
        printf("Stack is already empty or stack underflow\n");
        return;
    }

    int pop = stack[top--];
    printf("%d popped from stack\n", pop);
}

// display

void peek()
{
    if (top == -1)
    {
        printf("stack is empty!!\n");
        return;
    }

    printf("Top elements in the stack is %d\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("stack is empty!!");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{

    int choice, value;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input!\n");
                return 1;
            }
            push(value);
            break;
        case 2:
            pop();
            break;

        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}