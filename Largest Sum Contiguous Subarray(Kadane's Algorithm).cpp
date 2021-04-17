/// KADANE'S ALGORITHM  by "tech dose" YouTube channel

/// Write an efficient program to find the sum of contiguous sub array
/// within a one-dimensional array of numbers that has the largest sum.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int a[],int m)
{
    int max_end_here = 0,max_so_far = INT_MIN;
    for(int i=0;i<m;i++)
    {
        max_end_here = max_end_here+a[i];
        if(max_end_here < a[i])
        {
          max_end_here = a[i];
        }
        if(max_so_far < max_end_here)
        {
          max_so_far = max_end_here;
        }
    }
    return max_so_far;
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
