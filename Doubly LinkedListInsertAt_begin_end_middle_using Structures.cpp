#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
    Node *prev;
}Node;
Node *head = NULL;

void insert_at_Begin(int data)
{
    Node *new_node = (Node*)(malloc(sizeof(Node)));
    if(head == NULL)
    {
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    head = new_node;
    return;
    }
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;
    head->prev = new_node;
    head = new_node;
}

void insert_at_End(int data)
{
    Node *new_node = (Node*)(malloc(sizeof(Node)));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    Node *temp = head;
    if(temp == NULL)
    {
    head = new_node;
    return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_Middle(int data,int pos)
{
    Node *new_node = (Node*)(malloc(sizeof(Node)));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    Node *temp = head;
    int count = 1;
    if(temp == NULL)
    {
    head = new_node;
    return;
    }
    while(count < pos && temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        temp->next = new_node;
        new_node->prev = temp;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    new_node->next->prev = new_node;
    temp->next = new_node;
}

void display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int data;
        int n;
        cin>>n;

        ////////////////////////////////for inserting at the Beginning ----------------
        for(int i = 0;i<n;i++)
        {
            cin>>data;
            insert_at_Begin(data);
        }
        cout<<"after inserting at the beginning : ";
        display();
        cout<<"\n";
        head = NULL;
                  //////////////for inserting at the END--------------

         for(int i = 0;i<n;i++)
        {
            cin>>data;
            insert_at_End(data);
        }
        cout<<"after inserting at the end : ";
        display();
        cout<<"\n";

            ///////////////////inserting at the middle
        int pos;
        cin>>pos;
        cin>>data;
        cout<<"after inserting at the middle : ";
        insert_at_Middle(data,pos);
        display();
        cout<<"\n";
        head  = NULL;

    }
    return 0;
}
