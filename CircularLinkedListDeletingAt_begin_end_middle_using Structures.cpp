#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node { 
    int data;
    Node *next;
}Node;
Node *head = NULL;
Node *tail = NULL;

void insert_at_Begin(int data) {
   Node *new_node = (Node*)malloc(sizeof(Node));
   new_node->data = data;
   new_node->next = NULL;
   if(head == nullptr) {
       head = new_node;
       tail = new_node;
       return;
   }
   new_node->next = head;
   head = new_node;
   tail->next = head;
 }
 void delete_at_Begin() {
    Node *temp = head;
    if(temp == nullptr) {
        cout<<"the linked list is empty"<<"\n";
        return;
    }
    head = head->next;
    tail->next = head;
    temp->next = NULL;
    free(temp);
 }

 void delete_at_End() {
      Node *temp = head;
    if(temp == nullptr) {
        cout<<"the linked list is empty"<<"\n";
        return;
    }
    if(temp->next == nullptr) {
        head = NULL;
        tail = NULL;
        free(temp);
        return;
    }
    while(temp->next->next!= head) {
        temp = temp->next;
    }
    Node *temp1 = tail;
    temp->next = head;
    tail = temp;
    temp1->next = NULL;
    free(temp1);
 }

 void delete_at_Mid(int pos) {
     Node *temp = head;
    if(temp == NULL) {
        cout<<"the linked list is empty"<<"\n";
        return;
    }
     if(temp->next == NULL) {
        head = NULL;
        tail = NULL;
        free(temp);
        return;
    }
    int count = 1;
    while(count<pos-1 && temp->next!= head) {
        count++;
        temp = temp->next;
    }
    if(temp->next == head) {
        Node *temp1 = tail;
        temp->next = head;
        tail = temp;
        free(temp1);
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next = NULL;
    free(temp1);
 }

 void display() {
     Node *temp = head;
     do{
        cout<<"address : "<<temp<<"\n";
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

        cout<<"deleting at the Beginning :";
        delete_at_Begin();
         display();
         cout<<"\n";

         cout<<"deleting at the END :";
         delete_at_End();
         display();
         cout<<"\n";

         int pos;
         cin>>pos;
         cout<<"deleting at MIDDLE :"<<pos<<" :";
         delete_at_Mid(pos);
         display();
         cout<<"\n";

         head = NULL;
         tail = nullptr;
     }
     return 0;
 }
