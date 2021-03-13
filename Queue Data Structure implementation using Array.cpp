#include <bits/stdc++.h>
using namespace std;
#define SIZE 15
int A[SIZE];
int front = -1;
int rear = -1;

bool isempty()
{
    if(rear == -1 && front == -1)
    {
        return true;
    }
    else
        return false;
}

void enQueue(int data)
{
    if(rear == SIZE-1)  //  OVERFLOW condition for queue
    {
        cout<<"queue is full :";
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear++;
        A[rear] = data; // inserting at REAR
    }
}

void deQueue()
{
    if(isempty())   // checking for UNDERFLOW condition
    {
        cout<<"Queue is empty ";
    }
    else
    {
        if(rear == front) // if there is only element in the queue
        {
            rear = front = -1;
        }
        else
        {
          front++;
        }
    }
}

void showfront()
{
    if(isempty())
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        cout<<"element at the front is : "<<A[front]<<endl;
    }
}

void displayQueue()
{
    if(isempty())
    {
        cout<<"Queue is empty \n";
    }
    else
    {
        for(int i = front;i<=rear;i++)
        {
            cout<<A[i]<<" ";
        }
    }
}

int main()
{
   enQueue(5);
   enQueue(10);
   enQueue(1);
   enQueue(6);
   showfront();
   displayQueue();
   deQueue();
   cout<<"\n";
   displayQueue();
   return 0;
}
