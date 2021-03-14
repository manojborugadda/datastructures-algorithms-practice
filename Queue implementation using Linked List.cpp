#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
  int data;
  struct Node *next;
}Node;

Node *rear = NULL;
Node *front = NULL;

// function for checking  if the linked list is Empty
bool isempty()
{
    if(front == NULL && rear == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}

// function for inserting elements in the linked list-----ENQUEUE operation
void enQueue(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void deQueue()
{
    if(isempty())
    {
        cout<<" Queue is empty \n";
    }
    else
    {
        if(front == rear)          // if there is only one element----
        {
            free(front);
            front = rear =  NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            free(temp);
        }
    }
}


void showfront()
{
    if(isempty())
    {
        cout<<"queue is empty\n";
    }
    else
    {
        cout<<"element at front : "<<front->data;
    }
}

void displayQueue()
{
    if(isempty())
    {
        cout<<"queue is empty\n";
    }
    else
    {
        Node *temp = front;
        while(temp!= NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

int main()
{
    int choice,flag = 1,value;
    while(flag == 1)
    {
        cin>>choice;
        switch(choice)
        {
        case 1: cout<<"enter the value: \n";
                cin>>value;
                enQueue(value);
                break;
        case 2: deQueue();
                break;
        case 3: showfront();
                break;
        case 4: cout<<"displaying the elements in the queue\n";
                displayQueue();
                break;
        case 5: flag = 0;
                break;
        }


        }
    return 0;

    }

