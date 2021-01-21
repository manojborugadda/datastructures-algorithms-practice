#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class sLinkedListNode
{
public:
    int data;
    sLinkedListNode *next;
    sLinkedListNode(int new_data)
    {
        this->data = new_data;
        this->next = nullptr;
    }
};
class sLinkedList
{
public:
    sLinkedListNode *head;
    sLinkedListNode *tail;

    sLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int data)
    {
        sLinkedListNode *new_node = new sLinkedListNode(data);
        if(!this->head)
        {
            this->head = new_node;
        }
        else
        {
        this->tail->next = new_node;
        }
        this->tail = new_node;
    }
};

void printList(sLinkedListNode *head)
{
    sLinkedListNode *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


bool findCycle(sLinkedListNode *head)
{
    sLinkedListNode *slow = head,*fast = head;
    while(slow!= nullptr && fast!= nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    sLinkedList *node = new sLinkedList();
    int llist_count;
    cin>>llist_count;
    for(int i = 0;i<llist_count;i++)
    {
        int llist_item;
        cin>>llist_item;
        node->insert_node(llist_item);
    }

    node->head->next->next->next->next->next = node->head->next->next; ////test loop --------
    bool result = findCycle(node->head);
    if(result)
    {
        cout<<"cycle found :";
    }
    else
    {
        cout<<"cycle is not found :";
    }
    return 0;
}
