#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DllNode
{
public:
    int data;
    DllNode *next;
    DllNode *prev;
    DllNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class Dll
{
public:
    DllNode *head;
    Dll()                   ///////////constructor--------------
    {
        this->head = nullptr;
    }

    void insert_at_Beginning(int data)
    {
        DllNode *node = new DllNode(data);
        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            head = node;
        }
    }
    void insert_at_Ending(int data)
    {
        DllNode *node = new DllNode(data);
        DllNode *temp = head;
        if(temp == nullptr)
        {
            head = node;
            return;
        }
        else
        {
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
           temp->next = node;
           node->prev = temp;
        }
    }
    void insert_at_Mid(int data,int pos)
    {
        DllNode *node = new DllNode(data);
        DllNode *temp = head;
        int count = 1;
        if(temp== nullptr)
        {
            head = node;
            return;
        }
        while(count < pos && temp->next!= NULL)
        {
            count++;
            temp = temp->next;
        }
        if(temp->next == nullptr)
        {
            node->prev = temp;
            temp->next = node;
        }
        node->next = temp->next;
        node->prev = temp;
        node->next->prev = node;
        temp->next = node;
    }
};

void printlinkedlist(DllNode *head)
{
    DllNode *temp = head;
    while(temp!= nullptr)
    {
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Dll *llist = new Dll;
        int n;
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            int data;
            cin>>data;
            llist->insert_at_Beginning(data);
        }
        printlinkedlist(llist->head);
        llist->head = nullptr;

        for(int i = 0;i<n;i++)
        {
            int data;
            cin>>data;
            llist->insert_at_Ending(data);
        }
        printlinkedlist(llist->head);

        int pos;
        cin>>pos;
        int data;
        cin>>data;
        llist->insert_at_Mid(data,pos);
        printlinkedlist(llist->head);

    }
     return 0;
}
