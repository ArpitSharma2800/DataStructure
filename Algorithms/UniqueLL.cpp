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

    void uniqueLL()
    {
        node *ptr1, *ptr2, *dup;
        ptr1 = head;

        while (ptr1 != NULL && ptr1->next != NULL)
        {
            ptr2 = ptr1;

            while (ptr2->next != NULL)
            {

                if (ptr1->value == ptr2->next->value)
                {

                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete (dup);
                }
                else
                    ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
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
    L.insertback(1);
    L.insertback(5);
    L.insertback(5);
    L.uniqueLL();
    // L.middleElement();
    L.displayAll();

    return 0;
}