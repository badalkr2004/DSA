#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void push_front(int value)
    {

        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int value)
    {

        Node *newNode = new Node(value);
        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {

        if (head == NULL)
        {
            return;
        }

        Node *temp = head;

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
        }

        delete temp;
    }

    void pop_back()
    {

        if (tail == NULL)
        {
            cout << "List is empty..." << endl;
            return;
        }

        Node *temp = tail;
        if (tail == head)
        {
            tail == NULL;
            head == NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
        }

        delete temp;
    }
    void print_dll()
    {

        Node *i = head;

        while (i != NULL)
        {
            cout << i->data << "<->";
            i = i->next;
        }
        cout << "NULL" << endl;
    }
};

main()
{
    DoublyList ll;
    ll.push_front(23);
    ll.push_front(10);
    ll.push_front(24);
    ll.push_front(18);
    ll.push_back(121);

    ll.print_dll();
    ll.pop_front();
    ll.pop_front();
    ll.pop_back();
    ll.print_dll();
}