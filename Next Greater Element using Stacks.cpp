 /* Element       NGE
   4      -->   5
   5      -->   25                         // Next Greater Element
   2      -->   25
   25     -->   -1

    Given an array, print the Next Greater Element (NGE) for every element.
    The Next greater Element for an element x is the first greater element on the right side of x in the array.
    Elements for which no greater element exist, consider the next greater element as -1.
   */

   // Using STACKS-------------

#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;

void printNGE(int arr[],int n)
{
    stack<int>s;
    s.push(arr[0]);   //  push the first element to stack
    for(int i=1;i<n;i++)  // iterating for remaining elements in the array
    {
        if(s.empty())
        {
            s.push(arr[i]);
            continue;
        }

        while(s.empty() == false && s.top() < arr[i])
        {
                                                /* if stack is not empty, then
                                                    pop an element from stack.
                                                    If the popped element is smaller
                                                    than next, then
                                                    a) print the pair
                                                    b) keep popping while elements are
                                                    smaller and stack is not empty */
            cout<<s.top()<< "-->" << arr[i]<< endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    /* After iterating over the loop, the remaining
    elements in stack do not have the next greater
    element, so print -1 for them */
    while(s.empty()==false)
    {
        cout<<s.top()<<"-->"<<-1<<endl;
        s.pop();
    }

}

////////////////Main function-------------
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    printNGE(arr,n);
    return 0;
}
