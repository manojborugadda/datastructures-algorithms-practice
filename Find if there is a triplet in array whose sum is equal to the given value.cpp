#include <iostream>
#include <algorithm>
using namespace std;
///Find a triplet that sum to a given value

/* Given an array and a value, find if there is a triplet in array whose sum is equal to the given value.
   If there is such a triplet present in array, then print the triplet and return true. Else return false.
Example:
        Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
        Output: 12, 3, 9
 There is a triplet (12, 3 and 9) present in the array whose sum is 24.
     */

bool find3Numbers(int arr[],int n,int sum)
{
    int l,r;
  sort(arr,arr+n);

    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < n - 2; i++) {

        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements

        r = n - 1; // index of the last element
        while (l < r) {
            if (arr[i] + arr[l] + arr[r] == sum)
            {
               cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                return true;
            }
            else if (arr[i] + arr[l] + arr[r] < sum)
                l++;
            else
                r--;
        }
    }

    // If we reach here, then no triplet was found
    return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    int arr[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }

    find3Numbers(arr,n,sum);
  }
  return 0;
}
