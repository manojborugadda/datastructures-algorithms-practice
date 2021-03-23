#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool comp(const pair<int ,int>&a,const pair<int ,int>&b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

 void func(int arr[],int n)
 {
     unordered_map<int,int>m;
     for(int i = 0;i<n;i++)
     {
         m[arr[i]]++;      /// counting the frequencies of the elements in the array
     }
      /// i want to copy these KEY VALUE pairs into a Vector so that i can sort using the inbuilt functions
     vector<pair<int,int>>v;
     copy(m.begin(),m.end(),back_inserter(v));
     sort(v.begin(),v.end(),comp);


     for(int i=0;i<v.size();i++)     /// we will decrease the count and print the elements which are repeating ------
     {
         while(v[i].second--)
         {
             cout<<v[i].first<<" ";
         }
     }
     cout<<endl;
 }




int main()
{
    int t;
    cin>>t;
    while(t--)
 {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    func(arr,n);

    }
    return 0;
}
