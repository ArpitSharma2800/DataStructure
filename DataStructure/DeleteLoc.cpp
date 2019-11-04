#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
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
    void deleteLoc()
    {

        if (head == NULL)
        {
            cout << "UNDERFLOW" << endl;
        }
        else
        {
            node *temp = head, *temp2 = head;
            if (head->next == NULL)
            {
                head = NULL;
                free(temp);
                return;
            }
            while (temp->next != NULL)
            {
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = NULL;
            free(temp);
        }
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
} L;
int main()
{
    L.insertStart(5);
    L.insertStart(7);
    L.insertStart(7);
    L.insertStart(7);
    L.deleteEnd();
    L.displayAll();
}