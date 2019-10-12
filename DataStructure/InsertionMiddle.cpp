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
        if(head == NULL)
        {
            head = n1;
            return;
        }
        n1->next = head;
        head = n1;
    }
    void insertMiddle(int value, int loc)
    {
        int i;
        node *n1 = createNode(value);
        if(head == NULL)
        {
            head = n1;
            return;
        }
        node *temp1 = head, *temp2=head;
        for(i=0;i<loc;i++)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = n1;
        n1->next = temp2;
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
    L.insertStart(5);
    L.insertStart(5);
    L.insertStart(5);
    L.insertStart(5);
    L.insertStart(5);
    L.insertMiddle(7,2);
    L.displayAll();
    return 0;
}