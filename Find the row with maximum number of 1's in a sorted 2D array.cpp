//*******Length of the Longest Consecutive 1's in Binary Representation
#include <bits/stdc++.h>
using namespace std;
/////////////////////time complexity is O(k) and space complexity is O(1) where k is the count  ////////////////
int Maxconsec(int x)
{
    int count =0;
    while(x!= 0)
       {
           x = (x&(x << 1));
           count++;
       }
    return count;
}
int main()
{
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    cout<< Maxconsec(n)<<endl;
}
return 0;
}
