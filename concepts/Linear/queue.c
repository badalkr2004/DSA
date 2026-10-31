#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    queue[++rear] = value;

    print("%d inserted in a queue", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow!!");
        return;
    }

    printf("%d removed from queue\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
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

// Display all elements
void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{

    return 0;
}