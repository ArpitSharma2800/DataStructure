#include<iostream>
using namespace std;
struct node
{
    int value;
    node *next;
};

node *createNode(int value)
{
    node *n1 = new node;
    n1-> value = value;
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

    void insertEnd(int value)
    {
        node *n1 = createNode(value);
        if (head == NULL)
        {
            head = n1;
            return;
        }
        node *ptr = head;
        while (ptr->next != NULL)
            {ptr = ptr->next;}
        ptr->next = n1;
    }
    void insertLoc(int value, int loc)
    {
        node *n1 = createNode(value);
        int i;
        if(head == NULL)
        {
            head = n1;
            return;
        }
        node *prev = head, *curr = head;
        for(i=0;i<loc;i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = n1;
        n1->next = curr;
    }

    void deleteStart()
    {
        node *temp;
        if(head == NULL)
        {
            cout<<"Underflow\n";
        }
        else
        {
            
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    void deleteEnd()
    {
        node *temp1=head, *temp2=head;
        if(head == NULL)
        {
            cout<<"Underflow\n";
        }
        else
        {
             if(head->next == NULL)
            {
                head = NULL;
                free(temp1);
                return;
            }
            while(temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = NULL;
            free(temp1);
        }
        
    }



    void display()
    {
        if(head == NULL)
        {
            cout<<"undeflow\n";
        }
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
    L.insertEnd(8);
    L.insertLoc(9,3);
    L.deleteStart();
    L.deleteEnd();
    L.display();
    
}