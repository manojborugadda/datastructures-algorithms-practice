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

void delete_at_Begin()
{
    Node *temp = head;
    if(temp == nullptr)
    {
        head == nullptr;
        cout<<"the linked list empty ";
        return;
    }
    if(temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }
    head = head->next;
    head->prev = nullptr;
    temp->next = NULL;
    free(temp);
}

void delete_at_End()
{
    Node *temp = head;
    if(temp == nullptr)
    {
        head == nullptr;
        cout<<"the linked list empty ";
        return;
    }
    if(temp->next == NULL)
    {
       head = nullptr;
       free(temp);
       return;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp1->prev = NULL;
    temp->next = nullptr;
    free(temp1);
}

void delete_at_Middle(int pos)
{
    Node *temp = head;
    if(temp == nullptr)
    {
        head == nullptr;
        cout<<"the linked list is  empty ";
        return;
    }
    if(temp->next == NULL)
    {
       head = nullptr;
       free(temp);
       return;
    }
    int count = 1;
    while(count<pos-1)
    {
        count++;
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    temp1->next = NULL;
    temp1->prev = nullptr;
    free(temp1);
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


       cout<<"linked list after deleting at Beginning";
       delete_at_Begin();
       display();
       cout<<"\n";


       cout<<"linked list after deleting at End";
       delete_at_End();
       display();
       cout<<"\n";

       int pos;
       cin>>pos;
       cout<<"linked list after deleting at Middle";
       delete_at_Middle(pos);
       display();
       cout<<"\n";

}
          return 0;
}
