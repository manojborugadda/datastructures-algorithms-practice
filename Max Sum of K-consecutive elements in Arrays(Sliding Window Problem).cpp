#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  int main()
  {
  int t;
  cin>>t;
  while(t--)
  {
   int n,k;
   cin>>n>>k;
   int arr[n];

   for(int i = 0;i<n;i++)
   {
       cin>>arr[i];
   }

   int curr_sum = 0,max = 0;

   for(int i = 0;i<k;i++)
   {
       curr_sum = curr_sum + arr[i];
   }

   max = curr_sum;

   for(int i = k;i < n;i++)
   {
       curr_sum = curr_sum + arr[i] - arr[i-k];
     
   if(curr_sum >max)
   {
       max = curr_sum;
   }
   }
   cout<<max<<endl;
  }
  return 0;
  }
