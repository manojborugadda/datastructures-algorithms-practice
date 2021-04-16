/* Given an array A[] and a number x, check for pair in A[] with sum as x */


#include <bits/stdc++.h>
using namespace std;
void printPairs(int arr[],int n,int k)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        int temp = k-arr[i];
        if(s.find(temp)!=s.end())
        {
            cout<<"pair with given sum is :"<<" "<<"("<<arr[i]<<","<<temp<<")"<<endl;
        }
        s.insert(arr[i]);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    printPairs(arr,n,sum);
    return 0;
}

 /// Time Complexity: O(n).
///  As the whole array is needed to be traversed only once.
///  Auxiliary Space: O(n).
///  A hash map has been used to store array elements.
