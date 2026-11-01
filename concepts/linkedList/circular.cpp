#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void delteAtHead()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head == tail)
        {
            head = tail = NULL;
            delete temp;
        }
        else
        {
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail()
    {
        Node *temp = tail;
        Node *prev = head;

        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head == tail)
        {
            head = tail = NULL;
            delete temp;
        }
        else
        {
            while (prev->next != tail)
            {
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void printCl()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;

        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main()
{
    CircularList cl;

    cl.insertAtHead(1);
    cl.insertAtHead(2);
    cl.insertAtHead(3);
    cl.insertAtHead(4);
    cl.insertAtTail(5);
    cl.delteAtHead();
    cl.deleteAtTail();
    cl.printCl();
    return 0;
}