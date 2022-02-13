/// KADANE'S ALGORITHM 

/// Write an efficient program to find the sum of contiguous sub array
/// within a one-dimensional array of numbers that has the largest sum.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int a[],int m)
{
    int curr_sum = 0,max_sum = INT_MIN;
    for(int i=0;i<m;i++)
    {
        curr_sum = curr_sum+a[i];
        max_sum = max(curr_sum,max_sum);
        if(curr_sum  < 0 ){
            curr_sum = 0;
        }
    }
    return max_sum;
}
/// sample input : -2, -3, 4, -1, -2, 1, 5, -3
/// output : 7
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    int max_sum = maxSubArraySum(arr, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
}
