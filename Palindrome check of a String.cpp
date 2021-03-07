#include <bits/stdc++.h>
  using namespace std;
  bool isrecursion(string st,int start,int end)
  {
    if(start == end)
      return true;
    if(st[start]!=st[end])
      return false;
   if(start <end+1)
      return isrecursion( st,start+1,end-1);
  }

  bool ispalindrome(string s)
  {
    int n = s.length();
    if(n==0)
      return true;
    return isrecursion(s,0,n-1);
  }
  int main()
  {
    int t;
    cin>>t;
    string s;
    while(t--)
    {
      cin>>s;
      if( ispalindrome(s) )
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    }

    return 0;
  }
