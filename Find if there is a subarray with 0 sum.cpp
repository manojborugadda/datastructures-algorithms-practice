///Find if there is a subarray with 0 sum
/*Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum.

Example:

Input: {4, 2, -3, 1, 6}
Output: true
Explanation:
There is a sub array with zero sum from index 1 to 3.*/
#include<bits/stdc++.h>
using namespace std;
bool findSubarray(int arr[],int n)
{
    int sum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        sum = sum+arr[i];
        if(sum == 0 || s.find(sum) != s.end())
        {
            return true;
        }
        else
            s.insert(sum);
    }
    return false;
}
/// main function
int main()
{

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(findSubarray(arr,n))
    {
        cout<<"yes we found a sub array with size 0 "<<endl;
    }
    else
        cout<<"No Such Sub Array Exists bro, better luck next time"<<endl;
    return 0;
}

/// Time Complexity - O(N)
/// Space complexity - O(N)
