#include <bits/stdc++.h>
  using namespace std;


  void powerSet(string str,int index=0,string curr ="")
  {
    int n = str.length();
    if(index == n){
      cout<<curr<<endl;
      return ;

    }
    powerSet(str,index+1,curr+str[index]);
    powerSet(str,index+1,curr);

  }
  int main()
  {

   string s;
   cin>>s;
   powerSet(s);
    return 0;
  }
