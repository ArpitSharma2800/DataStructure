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

     void deleteBeginning()
    {
        node *temp;
        if (head == NULL)
            cout << "UnderFlow\n";
        else
        {
            temp = head;
            head = head->next;
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
};

int main()
{
    LinkedList L;
    L.insertStart(5);
    L.insertStart(7);
    L.insertStart(7);
    L.insertStart(7);
    L.deleteBeginning();
    L.displayAll();
}