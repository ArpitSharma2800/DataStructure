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

    void givenNode(int x)
    {
        node *ptr = head;
        bool flag = false;

        while (ptr != NULL)
        {
            if (ptr->value == x)
                flag = true;
            if (flag)
                cout << ptr->value << "->";
            ptr = ptr->next;
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
    L.givenNode(4);
    return 0;
}