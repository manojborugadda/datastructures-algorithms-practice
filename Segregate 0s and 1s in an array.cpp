#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,m,arr[100][100];
int t;
cin>>t;
while(t--)
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
      int j = m-1;
    while(j>=0 && arr[0][j]==1){
        j--;
    }
    int row = 0;

    for(int i=1;i<n;i++){

        while(j>=0 && arr[i][j]==1){
            j--;
            row = i;
        }
    }
    int a = (j == m-1 ? -1 : row);
    cout<<a;

    }

return 0;
}
