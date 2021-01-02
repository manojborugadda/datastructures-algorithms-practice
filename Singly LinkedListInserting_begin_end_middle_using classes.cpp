#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SLLNode{
public:
    int data;
    SLLNode *next;
    SLLNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Sll{
public:
    SLLNode *head; /////////here only the head is created
    Sll() ////////////default constructor----------
    {
       this->head = nullptr;
    }

    void insert_At_Beginning(int data)
    {
        SLLNode *newNode = new SLLNode(data);
        if(head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insert_At_End(int data)
    {
        SLLNode *newNode = new SLLNode(data);
        SLLNode *temp = head;
        if(temp == nullptr)
        {
            head = newNode;
        }
        else
        {
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        }

    }

    void insert_At_Middle(int data,int pos)
    {
       SLLNode *newNode = new SLLNode(data);
       SLLNode *temp = head;
       if(temp == nullptr)
       {
           head = newNode;
       }
       else
       {
        int count = 1;
        while(count<pos)
        {
            count++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

       }

    }
};

void display(SLLNode *head)
{
   SLLNode *temp = head;
   while(temp != nullptr)
   {
       cout<<temp->data<<" ";
       temp = temp->next;
   }
   cout<<"\n";
}

//////////////main function--------
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Sll *llist = new Sll(); /////////new list is created for inserting at the beginning----------
        int n ;
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            int data;
            cin>>data;
            llist->insert_At_Beginning(data);
        }
        cout<<"linked list after insert at the beginning :";
        display(llist->head);
        ////////////////new list is created for inserting at the end-------------
        Sll *sllist = new Sll();
        for(int i = 0;i<n;i++)
        {
            int data;
            cin>>data;
            sllist->insert_At_End(data);
        }
        cout<<"linked list after insert at the end :";
        display(sllist->head);


        int pos;
        cin>>pos;
        int data;
        cin>>data;
        cout<<"linked list after insert at position after in llist :";
        llist->insert_At_Middle(data,pos);
        display(llist->head);
        cout<<"linked list after insert at position after in sllist :";
        sllist->insert_At_Middle(data,pos);
        display(sllist->head);
    }
    return 0;
}
