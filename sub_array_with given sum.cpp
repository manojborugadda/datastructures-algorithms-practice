// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//Find sub array with given sum
 int SubArraySum(int arr[],int sum,int n)
 {


     int curr_sum = arr[0],start = 0;
     for(int i = 1;i<n;i++)
     {

         while(curr_sum > sum && start < i-1)
         {
             curr_sum = curr_sum - arr[start];
             start++;
         }
         if(curr_sum == sum)
         {
             cout<<"sum has found between indexes "<< start<<"and"<<i-1;
             return 0;
         }
         if(i<n)
         {
             curr_sum = curr_sum+arr[i];
         }
     }
     cout<<"not found";
     return 0;

 }

 int main()
 {
     int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
     int sum = 23;
     SubArraySum(arr,sum,n);
     return 0;
 }


