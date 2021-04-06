#include <bits/stdc++.h>
using namespace std;

int indexofFirstOne(int arr[],int low,int high)
{
   while(low <= high)
   {
       int mid = low+(high-low)/2;
       if( arr[mid] == 1 && ( mid == 0 || arr[mid-1] == 0 ) )
            {
                return mid;
            }
        else if( arr[mid] == 1)
        {
           high = mid-1;
        }
        else
       {
            low = mid+1;
       }
   }
   return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"first index of 1 is :"<<" "<<indexofFirstOne(arr,0,n-1)<<endl;
    return 0;
}
