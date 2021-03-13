/*You are given an array of 0's and 1's in random order.
Segregate 0's on left side and 1's on right side of the array.
Traverse array only once.
 */

#include <bits/stdc++.h>
using namespace std;
void segregate0and1(int arr[],int n)
{
    int left = 0;
    int right = n-1;
    while(left < right)
    {
        if(arr[left] == 1)
        {
            swap(arr[left],arr[right]);
            right--;
        }
        else
        {
            left++;
        }

    }

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
    segregate0and1(arr,n);
    cout<<"after segregating of 0's and 1's  : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

return 0;
}
