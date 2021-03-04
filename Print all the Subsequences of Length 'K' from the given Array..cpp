#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void recurCombi(int arr[],string res,int i,int n,int k)
{
    if(k == 0)
    {
           cout<<res<<endl;
    }
    for(int j = i;j < n;j++)
    {
        recurCombi(arr,res+to_string(arr[j])+" ",j+1,n,k-1);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    recurCombi(arr,"",0,n,k); // initially we take i =0 and empty string
    return 0;
}
