#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "LL is empty!";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "LL is empty\n";
        }
        Node *temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int value, int pos)
    {
        if (pos < 0)
        {
            cout << "INVALID POSITION...";
        }

        if (pos == 0)
        {
            push_front(value);
        }

        Node *newNode = new Node(value);

        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "INVALID POSITION" << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    void printLL()
    {
        Node *temp = head;

        while (temp != NULL)
        {

            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int search(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp->next != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
};

int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printLL();
    ll.insert(23, 1);
    ll.printLL();
    cout << "index of 23: " << ll.search(234545) << endl;
    return 0;
}