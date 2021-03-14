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
    if((rear+1)%SIZE == front)  //  OVERFLOW condition for queue
    {
        cout<<"queue is full :";
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
         rear = (rear+1)%SIZE;
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
          front = (front+1)%SIZE;
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
        int i;
        if(front <=rear)      // first condition
        {
           for(i = front;i<=rear;i++)
          {
            cout<<A[i]<<" ";
          }

        }
        else
        {
            i = front;         // front > = rear // second condition-------
            while(i < SIZE)
            {
                cout<<A[i]<<" ";
                i++;
            }
            i = 0;
            while(i <=rear)
            {
                 cout<<A[i]<<" ";
                i++;
            }

        }
    }
}

int main()
{
   enQueue(5);
   enQueue(10);
   enQueue(2);
   enQueue(15);
   enQueue(16);
   deQueue();
   deQueue();
   displayQueue();
   return 0;
}
