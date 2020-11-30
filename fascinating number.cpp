#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 int main()
  {
    int a,d,n,i,j,f,s,t,fr;
    cin>>a;
    while(a--)
    {
      cin>>n;
      n=n+1;
      do{
      d=n++;
      f=d%10;
      d=d/10;
      s=d%10;
      d=d/10;
      t=d%10;
      d=d/10;
      fr=d%10;
      d=d/10;
      }
      while(f==s||s==t||t==fr||f==t||f==fr||s==fr);
      {
      cout<<fr<<t<<s<<f<<"\n";
      }

    }
    return 0;
  }




