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
    void insertback(int value)
    {
        node *n1 = createNode(value);
        if(head == NULL)
        {
            head = n1;
            return;
        }
        node *ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n1;
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
    L.insertback(5);
    L.displayAll();
    return 0;
}