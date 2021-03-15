#include <bits/stdc++.h>
using namespace std;
 typedef struct Node
 {
     int data;
     Node *next;
 } Node;
 Node *head  = NULL;
// inserting elements at the end of the linked list------
 void insert_at_begin(int data)
 {
     Node *new_node = (Node*)malloc(sizeof(Node));
     new_node->data = data;
     new_node->next = head;
     head = new_node;

 }

 void printNth_node(Node* head,int k)
 {
     int length =0,i;
     Node *temp = head;
     while(temp != NULL)        // counting  the number of nodes in Linked List
     {
         temp =temp->next;
         length ++;
     }

     //if our N is greater than the length of the linked list we will return
     if(length < k)
     {
         return;
     }
     temp = head;
     for(i=1;i<(length-k+1);i++)
        {
            temp = temp->next;
        }
        cout<<temp->data;
     return;
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
                insert_at_begin(data);
           }
           cout<<"insert at the beginning : ";
           display();
           cout<<'\n';

           int k;
           cin>>k;
           cout<<"Nth node from the end of the linked list\n";
           printNth_node(head,k);



}


     return 0;
 }
