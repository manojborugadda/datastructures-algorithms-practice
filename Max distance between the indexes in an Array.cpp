
//              ******Given an array arr[], find the maximum j – i such that arr[j] > arr[i] *****************

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  int maxDiffBetweenIndexes(int arr[],int n)
  {
      int maxDiff,i,j;
      int *Lmin = new int[n]; //declares a pointer to a dynamic array of "type int and size n".
      //"new" allocates memory of size equal to (sizeof(int) * n ) bytes and return the memory which is stored by the variable array
      int *Rmax = new int[n];
      // construction of the Lmin array which contains  the minimum value from left side of the array
      Lmin[0] = arr[0];
      for(int i=1;i<n;++i)
      {
          Lmin[i] = min(Lmin[i-1],arr[i]);
      }
      Rmax[n-1] = arr[n-1];
      for(int j = n-2;j>=0;--j)
       {
           Rmax[j] = max(Rmax[j+1],arr[j]);
       }
       // traversing the both arrays from left to right to find the maximum (j-i)
       i=0,j=0,maxDiff = -1;
       while(i<n && j<n) {
           if(Lmin[i]<Rmax[j])
           {
               maxDiff = max(maxDiff,j-i);
               j += 1;
           }
           else
           {
           i += 1;
           }

        }
       return maxDiff;
  }

  int main()
  {
      int arr[] = {9,2,3,4,5,6,7,8,18,0};
      int n = sizeof(arr)/sizeof(arr[0]);
      int maxDiff = maxDiffBetweenIndexes(arr,n);
      cout<<maxDiff;
      return 0;
  }
