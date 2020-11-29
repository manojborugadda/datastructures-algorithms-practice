#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 void firstRepeatingElement(int arr[],int n)
 {
     // initializing first repeating element with "min"
     int min = -1;
      // creating empty hash set---------
      set<int>myset;
      // traversing the input element from RIGHT to LEFT ---------
      for(int i = n-1;i>0;i--)
      {
          if(myset.find(arr[i]) != myset.end()) // if element if already present in the set then update "min"
          {
              min = i;
          }
          else /////// if not then add that element in to the set
            {
            myset.insert(arr[i]);
          }
      }

      ////// printing the results--------
          if(min != -1)
          {
              cout<<" the first repeating element is :"<<arr[min];
          }
          else
          {
              cout<<"there is no repeating element"<<endl;

          }

          }

        int main()
        {
          int n;
          cin>>n;
          int arr[n];
            for(int i = 0;i<n;i++)
            {
                cin>>arr[i];
            }
            firstRepeatingElement(arr,n);
       //return 0;
        }


