//You are given an array of N integers in ascending order and a number N.
//You have to print indexes of two numbers in the array such that the sum equals to number K
// In case no such pair exists print "no answer"(without quotes).
//For each test case on a new line, print the two indexes (i,j) (i<j) . If there are multiple such pair (i,j)
//print max j value pair and if all j's are equal print min i value. If no such pair exist print "no answer"(without quotes).

#include <bits/stdc++.h>
  using namespace std;
  int main()
  {
    int t;
    cin>>t;
    while(t--)
    {
      bool flag = 0;
    int n;
    cin>>n;
    int arr[n];
    for(int i  = 0;i<n;i++)
    {
      cin>>arr[i];
    }
   int k;
   cin>>k;
    int l,r;
    l = 0;
    r = n-1;
    while(l<r)
    {
      if(arr[l]+arr[r] == k)
      {
        cout<<l<<" "<<r<<endl;
       flag = 1;
        break;
      }
      else if(arr[l]+arr[r]<k)
      {
        l++;
      }
      else // arr[l]+arr[r]>k;
      {
        r--;
      }
    }
    if(flag == 0) // comparison is done like this.
    {
      cout<<"no answer"<<endl;
    }
   }
  }


