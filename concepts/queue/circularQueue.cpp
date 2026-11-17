#include <iostream>
using namespace std;

class CircularQueue
{

    int *arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0, r = -1;
    }

    void push(int data)
    {

        if (currSize == cap)
        {
            cout << "CQ is Full\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "CQ is Empty\n";
            return;
        }

        f = (f + 1) % cap;
        currSize--;
    }

    int front()
    {
        if (is_empty())
        {
            cout << "CQ is Empty\n";
            return -1;
        }
        return arr[f];
    }

    bool is_empty()
    {
        return currSize == 0;
    }

    void print()
    {
        for (int i = 0; i < cap; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{

    CircularQueue cq(5);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.pop();
    cq.push(6);

    cq.print();
    return 0;
}