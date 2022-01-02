///C++ program to find number of sub arrays with sum exactly equal to 'K'

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int Findsubarr(int arr[],int n,int k)
{
    unordered_map<int,int>mp;
    int count = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum = sum + arr[i];
        if(sum = k)
        {
            count++;
        }
        if(mp.find(sum-k)!=mp.end())
        {
            count = count+mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
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
    int k;
    cin>>k;
    cout<<"Number of subarrays having sum exactly equal to 'K' is "<<Findsubarr(arr,n,k)<<endl;
    return 0;
}


// for reference https://www.youtube.com/watch?v=HbbYPQc-Oo4
