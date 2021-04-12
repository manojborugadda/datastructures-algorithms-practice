#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 2147483647;
   long long int findMissing(long long int arr[],int low,int high,int diff)
    {
       if (high <= low)
        return INT_MAX;
      int mid = low + (high - low) / 2;

    /// The element just after the middle element is missing.
    if (arr[mid + 1] - arr[mid] != diff)
        return (arr[mid] + diff);

    /// The element just before mid is missing
    if (mid > 0 && arr[mid] - arr[mid - 1] != diff)
        return (arr[mid - 1] + diff);

    if (arr[mid] == arr[0] + mid * diff)         /// recur for right half
        return findMissing(arr, mid + 1, high, diff);

    /// Else recur for left half
    return findMissing(arr, low, mid - 1, diff);

    }

    long long int fun(long long int arr[],int n)
    {
       long long int diff = (arr[n-1]-arr[0])/n;
      return findMissing(arr,0,n-1,diff);
    }


  int main()
  {
    int t;
    cin>>t;
    while(t--){
    long long int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    cout<<"missing element is : "<<" "<<fun(arr,n)<<endl;
    }
    return 0;
  }



/// constraints : 1 <= T <= 10
            ///   3 <= N < 2*10^6
            ///   1<= A[i] <= 10^7 + 5

/// we are using Binary Search so Time Complexity = O(logn)
