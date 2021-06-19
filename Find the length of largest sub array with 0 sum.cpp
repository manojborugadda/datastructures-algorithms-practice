///C++ program to find the length of largest sub array with 0 sum

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int Largestsubarr(int arr[],int n)
{
    unordered_map<int,int>mp;
    int sum = 0;
    int maxlen = 0;
    for(int i=0;i<n;i++)
    {
        sum = sum+arr[i];
        if(maxlen == 0 && arr[i]==0)
        {
            maxlen = 1;
        }
        if(sum == 0)
        {
            maxlen = i+1;
        }
        else
        {
            if(mp.find(sum)!= mp.end())
            {
              maxlen = max(maxlen,i- mp[sum]);  /// take maximum of max length and difference of current index and the  previous repeated prefix sum index
            }
            else
                mp[sum] = i; /// insert this sum with index in hash table
        }
    }
    return maxlen;
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
    cout<<"Length of the longest 0 sum sub array is "<<Largestsubarr(arr,n)<<endl;
    return 0;
}

Time Complexity - O(N)
Space Complexity - O(N)
