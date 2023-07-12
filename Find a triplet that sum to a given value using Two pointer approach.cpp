/// Find a triplet that sum to a given value

/* Given an array and a value, find if there is a triplet in array whose sum is equal to the given value.
If there is such a triplet present in array, then print the triplet and return true. Else return false.

Input: array = {12, 3, 4, 1, 6, 9}, sum = 24; 
Output: 12, 3, 9
 */

 /// Two Pointer Technique

#include<bits/stdc++.h>
using namespace std;

bool triplets(int arr[],int n,int sum)
{
    int l,r;
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        l = i+1;
        r = n-1;
        while(l<r)
        {
            if(arr[i]+arr[l]+arr[r] == sum)
            {
                cout<<"Triplets are"<<" "<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                return true;
            }
            else if(arr[i]+arr[l]+arr[r]<sum )
            {
                l++;
            }
            else{
                r--;
            }
        }
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
    int k; /// sum value for which we have to find the triplets
    cin>>k;
    triplets(arr,n,k);
    return 0;
}

/// Time Complexity - O(N^2)
/// Space complexity - O(1)
