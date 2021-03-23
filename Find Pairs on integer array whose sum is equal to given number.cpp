#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
                                    /// time complexity is O(n)
 void func(int arr[],int n,int k)
 {
     unordered_map<int,int>m;
     for(int i = 0;i<n;i++)
     {
         m[arr[i]]++;      /// counting the frequencies of the elements in the array
     }

     for(int i=0;i<n;i++)
     {
         if( m[k-arr[i]] > 0)
         {
             cout<<arr[i]<< ","<<k-arr[i]<<endl;
             m[arr[i]] = 0;
         }
     }
 }


int main()
{
    int t;
    cin>>t;
    while(t--)
 {
    cout<<"Enter 'n' and 'k' ";
    int n;
    cin>>n;
    int k;        /// sum which we have to find the pairs for
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    func(arr,n,k);

 }

    return 0;
}
