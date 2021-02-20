#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
  int main()
  {
  int t;
  cin>>t;
  while(t--)
  {
   int n;
  cin>>n;
  int a[n-1];
  for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    long long sum = 0;
    long long total = ((long long)n*(n+1))/2;
    for(int i = 0;i<n-1;i++)
    {
    sum = a[i]+sum;
    }
    cout<<total-sum<<endl;
   }
  return 0;
  }
