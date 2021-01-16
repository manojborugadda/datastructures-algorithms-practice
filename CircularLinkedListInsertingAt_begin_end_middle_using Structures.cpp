#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
}Node;

Node *head = NULL;
Node *tail = NULL;


void insert_at_Begin(int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = nullptr;
    if(head == nullptr)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
    tail->next = head;
}

void insert_at_End(int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = nullptr;
    if(head == nullptr)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = new_node;
    tail->next = head;
}
void insert_at_Middle(int data,int pos)
{
     Node *new_node = (Node*)malloc(sizeof(Node));
     Node *temp = head;
    new_node->data = data;
    new_node->next = nullptr;
    if(head == nullptr)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    if(temp->next== nullptr) /////if linked list has one element----------
    {
        tail->next = new_node;
        tail = new_node;
        tail->next = head;
    }
    int count = 1;
    while(count<pos && temp->next!=head)
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

void printCirlinkedlist()
{
    Node *temp = head;
    do{
        cout<<"address = :"<<temp<<"\n";
        cout<<temp->data<<" ";
        cout<<temp->next<<"\n";
        temp = temp->next;
      }while(temp!= head);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int data;
        for(int i = 0;i<n;i++)
        {
            cin>>data;
            insert_at_Begin(data);
        }
        cout<<"inserting at the beginning :";
        printCirlinkedlist();
        cout<<"\n";
        head = NULL;
        tail = NULL;

        for(int i = 0;i<n;i++)
        {
            cin>>data;
            insert_at_End(data);
        }
        printCirlinkedlist();
        cout<<"\n";

        int pos;
        cin>>pos;
        cin>>data;
        insert_at_Middle(data,pos);
        printCirlinkedlist();
        cout<<"\n";
        head = nullptr;
        tail = nullptr;
    }
    return 0;
}
