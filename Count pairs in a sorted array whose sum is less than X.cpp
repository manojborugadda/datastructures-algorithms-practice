/// Count pairs in a sorted array whose sum is less than x

/* Given a sorted integer array and number x, the task is to count pairs in array whose sum is less than x.
Input  : arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
         x = 7
Output : 6
Pairs are (1, 2), (1, 3), (1, 4), (1, 5)
          (2, 3) and (2, 4)
 */

 /// Two Pointer Technique

#include<bits/stdc++.h>
using namespace std;

int PairsFinding(int arr[],int n,int x)
{
    int l = 0 , r = n-1;
    int result = 0;
        while(l < r)
        {
            if(arr[l]+arr[r]< x )
            {
                result = result+(r-l);
                l++;
            }
            else
            {
                r--;
            }
        }

    return result;
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
    int k;
    cin>>k;
    cout<<PairsFinding(arr,n,k);
    return 0;
}

/// Time Complexity - O(N)
/// Space complexity - O(1)
