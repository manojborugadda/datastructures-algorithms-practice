#include <bits/stdc++.h>
using namespace std;
/////////////////////time complexity is O(m+n) and space complexity is O(1) /////////////

/* Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1's.
Example:


Input matrix
0 1 1 1
0 0 1 1
1 1 1 1  // this row has maximum 1's
0 0 0 0

Output: 2

*/
int main()
{
 int t;
 cin>>t;
 int m,n;
 int arr[50][50];
 while(t--)
 {
     cin>>n>>m;
     for(int i =0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             cin>>arr[i][j];
         }
     }

     int j = m-1;
     while(j>=0 && arr[0][j]==1)
     {
         j--;
     }
     int row = 0;
     for(int i=1;i<n;i++)
     {
         while(j>=0 && arr[i][j]==1)
         {
             j--;
             row = i;
         }
     }
    int a = (j== m-1 ? -1 : row);
  cout<<a<<endl;
 }
return 0;
}
