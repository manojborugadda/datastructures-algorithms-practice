/* Given an integer array move all 0's to the end of it while maintaining the relative order of the non-zero elements.*/

#include <bits/stdc++.h>
  using namespace std;
  void moveZeros(int arr[],int n)
  {
    int right = 0,left =0;
    int temp;
    if(n==0||n==1)
    {
        return;
    }
    while(right<n)
    {
      if(arr[right] == 0)   //  for example we take 1 2 0 4 0 5 0
      {
            ++right;
      }
      else
        {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        ++right;
        ++left;
      }

    }
  }
 int main()
 {   int t;
     cin>>t;
     int n;
     cin>>n;
     int arr[n];
     while(t--)
{
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
    moveZeros(arr,n);
    cout<<"after moving zeros to end :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
    return 0;
 }
