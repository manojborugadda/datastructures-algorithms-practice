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

 void reverse_list(Node **head)
 {
      Node *curr = *head;
      Node *temp = NULL;
     while(curr!= NULL)
     {
         temp = curr->prev;
         curr->prev = curr->next;
         curr->next = temp;
         curr = curr->prev;
     }
     if(temp!= NULL)
     {
        *head = temp->prev;
     }
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
         int n;
         cin>>n;
         int data;
         for(int i = 0;i<n;i++)
         {
             cin>>data;
              insert_at_Begin(data);
         }
         cout<<"inserting at the Beginning :";
         display();
         cout<<"\n";

        cout<<"the linked list after reversing :";
        reverse_list(&head);
        display();
        cout<<"\n";
     }
     return 0;
 }
