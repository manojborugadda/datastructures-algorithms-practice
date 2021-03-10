//*******Length of the Longest Consecutive 1's in Binary Representation
#include <bits/stdc++.h>
using namespace std;
/////////////////////time complexity is O(k) and space complexity is O(1) where k is the count  ////////////////
int Maxconsec(int x)
{
    int count = 0;
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


/*Using BIT MAGIC---: The idea is based on the concept that if we AND a bit sequence with a
 shifted version of itself, we’re effectively removing the trailing 1 from every sequence of consecutive 1's.

      11101111   (x)
    & 11011110   (x << 1)
    ----------
      11001110   (x & (x << 1))
        ^    ^
        |    |
   trailing 1 removed

So the operation x = (x & (x << 1)) REDUCES length of every sequence of 1's by one in binary representation of x.
 If we keep doing this operation in a loop, we end up with x = 0.
  The number of iterations required to reach 0 is actually length of the longest consecutive sequence of 1's.*/
