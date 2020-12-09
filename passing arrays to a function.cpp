#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//defining the function-----------------------
int add(int b[],int len)
 {
     int sum = 0,i;
     for(int i = 0;i<len;i++)
     {
         sum = sum + b[i];
     }
      return sum;
 }

 // calling the function---------------------
 int main()
{
    int a[] = {1,2,3,4};
    int len = sizeof(a)/sizeof(a[0]);
    cout<< add(a,len);
    return 0;

  }
/////////// passing arrays as arguments to a function ....
