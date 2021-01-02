#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SLLNode{
public:
    int data;
    SLLNode *next;
    SLLNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Sll{
public:
    SLLNode *head; /////////here only the head is created
    Sll() ////////////default constructor----------
    {
       this->head = nullptr;
    }
      void insert_At_Beginning(int data)
    {
        SLLNode *newNode = new SLLNode(data);
        if(head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteNode_at_begin()
    {
        SLLNode *temp = head;
        if(temp == NULL)
        {
            cout<<"linked list is empty : ";
            return;
        }
        else
        {
            head = head->next;
            free(temp);
        }
    }

    void deleteNode_at_end()
    {
        SLLNode *temp = head;
        if(temp == NULL)      /////////////// if the list is empty------------------------
        {
            cout<<"the linked list has no nodes or empty : ";
            return;
        }
        if(temp->next == NULL) /////////if the list has only ONE node----------
        {
            head = NULL;
            free(temp);
            return;
        }
        while(temp->next != NULL && temp->next->next != NULL)
            {
                temp = temp->next;
            }
            SLLNode *temp1 = temp->next;
            temp->next = NULL;
            free(temp1);
    }

    void delete_atMiddle(int pos)
    {
       SLLNode *temp = head;
        if(temp == NULL)      /////////////// if the list is empty------------------------
        {
            cout<<"the linked list has no nodes or empty : ";
            return;
        }
        if(temp->next == NULL) /////////if the list has only ONE node----------
        {
            head = NULL;
            free(temp);
            return;
        }
        int count = 1;

        while(temp->next != NULL && count< pos - 1)
        {
            temp = temp->next;
        }
        SLLNode *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        free(temp2);

    }


};

void display(SLLNode *head)
{
   SLLNode *temp = head;
   while(temp != nullptr)
   {
       cout<<temp->data<<" ";
       temp = temp->next;
   }
   cout<<"\n";
}

//////////////main function--------
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Sll *llist = new Sll(); /////////new list is created for inserting at the beginning----------
        int n ;
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            int data;
            cin>>data;
            llist->insert_At_Beginning(data);
        }
        cout<<"linked list after insert at the beginning :";
        display(llist->head);

        cout<<"linked list after the deleting at beginning :";
        llist->deleteNode_at_begin();
        display(llist->head);
        cout<<"\n";

        cout<<"linked list after the deleting at end :";
        llist->deleteNode_at_end();
        display(llist->head);
        cout<<"\n";

        int pos;
        cin>>pos;
        cout<<"list after deleting at middle :";
        llist->delete_atMiddle(pos);
        display(llist->head);


    }
    return 0;
}
