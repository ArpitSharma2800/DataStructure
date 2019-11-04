#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    struct node *next;
};

node *createNode(int value)
{
    node *n1 = new node;
    n1->value = value;
    n1->next = NULL;
    return n1;
};

class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertStart(int value)
    {
        node *n1 = createNode(value);
        if (head == NULL)
        {
            head = n1;
            return;
        }
        n1->next = head;
        head = n1;
    }

    void insertback(int value)
    {
        node *n1 = createNode(value);
        if (head == NULL)
        {
            head = n1;
            return;
        }
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n1;
    }

    void givenNode(int x, int y)
    {
        node *ptr = head;
        node *k = new node();
        k->value = y;

        while (ptr != NULL)
        {
            if (ptr->value == x)
            {
                k->next = ptr->next;
                ptr->next = k;
                return;
            }

            ptr = ptr->next;
        }
    }

    // display linked list

    void displayAll()
    {
        if (head == NULL)
            cout << "UnderFlow";
        else
        {
            node *ptr = head;
            while (ptr != NULL)
            {
                cout << ptr->value << "->";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};
int main()
{

    LinkedList L;

    L.insertStart(1);
    L.insertback(2);
    L.insertback(3);
    L.insertback(4);
    L.insertback(5);
    L.insertback(6);
    L.givenNode(2, 8);
    // L.middleElement();
    L.displayAll();

    return 0;
}