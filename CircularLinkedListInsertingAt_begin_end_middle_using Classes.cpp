#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class CllNode
{
public:
    int data;
    CllNode *next;
    CllNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Cll
{
public:

    CllNode *head ;
    CllNode *tail;
    Cll()      ////constructor
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_at_Beginning(int data)
    {
        CllNode *new_node = new CllNode(data);
        if(head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
            tail->next = head;
        }
    }

    void insert_at_Ending(int data)
    {

        CllNode *new_node = new CllNode(data);
        if(head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
        }
    }

    void insert_at_Mid(int data ,int pos)
    {
        CllNode *new_node = new CllNode(data);
        CllNode *temp = head;
        if(head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        if(temp->next == nullptr)
        {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
            return;
        }
        int count = 1;
        while(count<pos && temp->next!= head)
        {
            count++;
            temp = temp->next;
        }
        if(temp->next == head)
        {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
};

void display(CllNode *head)
{
    CllNode *temp = head;
    do
    {
        cout<<"address = :"<<temp<<"\n";
        cout<<temp->data<<" ";
        cout<<temp->next<<"\n";
        temp = temp->next;
    }while(temp!=head);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Cll *llist = new Cll();
        int n;
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            int data;
            cin>>data;
           llist->insert_at_Beginning(data);
        }
        cout<<"inserting at thes5 beginning :";
        display(llist->head);
        cout<<"\n";

         Cll *sllist = new Cll();
        for(int i = 0;i<n;i++)
        {
            int data;
            cin>>data;
            sllist->insert_at_Ending(data);
        }
        cout<<"inserting at the end :";
       display(sllist->head);
        cout<<"\n";

        int pos;
        cin>>pos;
        int data;
        cin>>data;
        cout<<"the linked list after inserting at middle in llist :";
        llist->insert_at_Mid(data,pos);
        display(llist->head);
        cout<<"the linked list after inserting at middle in sllist :";
        sllist->insert_at_Mid(data,pos);
        display(sllist->head);
        cout<<"\n";
    }
    return 0;
}
