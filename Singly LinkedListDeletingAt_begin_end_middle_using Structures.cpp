#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
}Node;
Node *head = nullptr;

void insertAtBeginning(int data)
{
    Node *new_node = (Node*)(malloc(sizeof(Node)));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void delete_at_Begin()
{
    Node *temp = head;
    if(temp == NULL)
    {
        cout<<"the linked list is empty :";
        return;
    }
    head = head->next;
    free(temp);
}
void delete_at_End()
{
   Node *temp = head;
   if(temp == NULL)                      /////// if the list is EMPTY------
   {
       cout<<"the linked list is empty :";
       return;
   }
   if(temp->next == NULL)               ///////if the linked list has one element-----------
   {
       head = NULL;
       free(temp);
       return;
   }
   while(temp->next->next != NULL)            ////////we will traverse until the last before element in the list ----------
   {
       temp = temp->next;
   }
    Node *temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
}

void delete_at_Middle(int pos)
{
    Node *temp = head;
    if(temp == NULL)
    {
        cout<<"the linked list is empty : ";
        return;
    }
    if(temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }
    int count = 1;
    while(count < pos-1)
    {
        count++;
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next = NULL;
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
        for(int i = 0;i<n;i++)
        {
            cin>>data;
            insertAtBeginning(data);
        }
        cout<<"after inserting at the beginning : ";
        display();
        cout<<"\n";

        cout<<"after delete at the beginning :";
        delete_at_Begin();
        display();
        cout<<"\n";

         cout<<"after delete at the end :";
        delete_at_End();
        display();
        cout<<"\n";

         cout<<"after delete at the middle :";
         int pos;
         cin>>pos;
        delete_at_Middle(pos);
        display();
        head = NULL;
        return 0;
    }
}
