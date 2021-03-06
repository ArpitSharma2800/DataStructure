#include <iostream>

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

    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        node *current = head;
        node *prev = NULL, *next = NULL;

        while (current != NULL)
        {

            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }
        head = prev;
    }
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
    int i, k;
    for (i = 0; i < 5; i++)

    {
        cin >> k;
        L.insertStart(k);
    }
    L.displayAll();
    L.reverse();
    L.displayAll();
    return 0;
}