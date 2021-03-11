#include <bits/stdc++.h>
  using namespace std;
  typedef struct Node
  {
      int data;
      Node *next;
  }Node;

  Node* head = NULL;

  void insert_at_begin(int data)
  {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return;
  }

  void removeDuplicate(Node *head)
  {
      unordered_set<int>seen;
      Node *curr = head;
      Node *pre = NULL;
      while(curr != NULL)
      {
          if(seen.find(curr->data) != seen.end()) // if current data is there previously in the HASH-set then we will delete that node
          {
              pre->next = curr->next;
              delete(curr);
          }
          else
          {
             seen.insert(curr->data);
              pre = curr;
          }
          curr = pre->next;
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
        for(int i=0;i<n;i++)
        {
            cin>>data;
            insert_at_begin(data);
        }
        cout<<"after inserting at the beginning :";
        display();
        cout<<"\n";
        removeDuplicate(head);
        cout<<"after removing the duplicate elements from the UNSORTED linked list :";
         display();
        cout<<"\n";
      }
      return 0;
  }
