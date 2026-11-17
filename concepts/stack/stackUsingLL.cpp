#include <iostream>
using namespace std;
#include <list>

class Stack
{
    list<int> ll;

public:
    void push(int value)
    {
        ll.push_front(value);
    }

    void pop()
    {
        ll.pop_front();
    }

    int top() { return ll.front(); }

    bool empty()
    {
        return ll.size() == 0;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}