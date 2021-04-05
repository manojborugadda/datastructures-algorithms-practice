#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int low,int high,int key)
{
    if(high <low)
        return -1;
    int mid = low+(high-low)/2;          // mid = (high+low)/2
    if(arr[mid] == key)
        return mid;
    if(key < arr[mid])
        return binarySearch(arr,low,(mid-1),key);
    else
        return binarySearch(arr,(mid+1),high,key);
}

int findPivot(int arr[],int low,int high)
{
     if(high < low) /// base case for this recursion problem
        return -1;
    if(high == low)
        return low;
     int mid = low+(high-low)/2;

    /// first condition
    if(mid < high && arr[mid] > arr[mid+1])
        return mid;
    /// second condition
    if(mid > low && arr[mid] < arr[mid-1])
        return (mid-1);
    /// third condition for finding pivot element.
    /// pivot element is the only element for which next element to it is smaller than it.
    if(arr[low] >= arr[mid])
        return findPivot(arr,low,mid-1);
    return findPivot(arr,mid+1,high);
}

int pivotedBinarysearch(int arr[],int n,int key)
{
    int pivot = findPivot(arr,0,n-1);
    if(pivot == -1) /// If we did not find a pivot then array is not rotated at all
        return binarySearch(arr,0,n-1,key);
    if(arr[pivot] == key)   ///If we found a pivot, then first compare with pivot and then search in two sub arrays around pivot
        return pivot;
    if(arr[0] <=  key)
        return binarySearch(arr,0,pivot-1,key);

    return binarySearch(arr,pivot+1,n-1,key);

}

//////////////////////////////////////////////////
 int main()
{
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
       int key;cin>>key;
      cout << "Index of the element is : "<<pivotedBinarysearch(arr,n,key)<<endl;
        return 0;
}
