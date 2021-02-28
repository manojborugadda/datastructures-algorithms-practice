#include<cstring>
#include<iostream>
#include<string>
#include<bits/stdc++.h>
  using namespace std;
   //Leetcode's **********Longest substring without repeated characters **********form ""Take u forward""---Raj VikramAditya--------
  int lengthOfLongestSubstring(string s)
    {
        vector<int>mp(256,-1);
        int right =0,left = 0;
        int len =0;
        int n = s.length();
        while(right < n)
        {
            if(mp[s[right]] != -1)
            {
              left = max(mp[s[right]]+1,left);
            }
            mp[s[right]] = right;
            len = max(len,right-left+1);
            right++;
        }
        cout<<len<<endl;
        return len;

    }

  //////////main function
  int main()
  {
   int t;
   cin>>t;
   while(t--)
   {
     string s;
     cin>>s;
     lengthOfLongestSubstring(s);
   }
    return 0;
  }
