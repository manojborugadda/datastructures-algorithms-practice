#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *next;
}Node;
Node *head = NULL;

void insertAtBeginning(int data)
{
    Node *new_node =(Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void insertAtEnd(int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    Node *temp = head;
    if(temp == NULL)
    {
        head = new_node;
        return ;
    }
    else
    {
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = new_node;
    }
}

void insertAtMiddle(int data,int pos)
{
    Node *temp = head;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(temp == NULL) //////checking whether the linked list is empty or head is empty
    {
        head = new_node;
        return;
    }
    int count = 1;
    while(count < pos && temp->next != NULL) ////checking the position where we want to insert is less than the count or position is Greater than the elements
    {
        count++;
        temp = temp->next;
    }
    if(temp->next == NULL)               //////////checking whether position is at the end of the linkedlist
    {
        temp->next = new_node;
        return;
    }
    new_node->next = temp->next;      ////////// here is our condition for INSERT AT THE MIDDLE satisfying above all conditions
    temp->next = new_node;
}


void display()
{
    Node *temp;
    temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

////////////////main function--------------------------------
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
                insertAtBeginning(data);
           }
           cout<<"insert at the beginning : ";
           display();
           cout<<'\n';

       head = NULL; // when we give a new test case our head will be re initialize

           for(int i = 0;i<n;i++)
           {
                cin>>data;
                insertAtEnd(data);
           }
           cout<<"insert at the ending : ";
           display();
           cout<<"\n";

           int pos;
           cin>>pos;
           cin>>data;
           insertAtMiddle(data,pos);
           cout<<"insert at the middle : ";
           display();
           cout<<"\n";
           head = NULL;
  }
}

