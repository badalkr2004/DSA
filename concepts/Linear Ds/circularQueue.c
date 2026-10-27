#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d removed\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }

    int i = front;

    printf("Queue: ");

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1)
                return 1;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
