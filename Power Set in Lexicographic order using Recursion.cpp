#include <bits/stdc++.h>
using namespace std;

void recurSet(string st,int n,int index = -1,string curr = "")
{
    if(index == n)
        return;
    cout<<curr;
    cout<<"\n";
    for(int i = index+1;i< n;i++)
    {
        curr = curr+st[i];
        recurSet(st,n,i,curr);
        curr = curr.erase(curr.length()-1);
    }
    return;
}
void powerSet(string str)
{
   sort(str.begin(),str.end());
   int len = str.length();
   recurSet(str,len);
}
int main()
{
    string s;
    cin>>s;
    powerSet(s);
    return 0;
}
