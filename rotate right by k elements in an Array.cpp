#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
  int main()
  {
  int t;cin>>t;
   while(t--)
  {
  int n,k;cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
     cin>>a[i];
  if(k>=n)
    k=k%n;
  int m;
  if(k==0)
    m=0;
  else
    m=n-k;
  for(int i=m;i<n;i++)
      cout<<a[i]<<" ";
  for(int i=0;i<m;i++)
      cout<<a[i]<<" ";
  cout<<"\n";
  }
  return 0;
  }
