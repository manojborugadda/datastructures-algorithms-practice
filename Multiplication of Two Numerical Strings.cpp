#include <bits/stdc++.h>
  using namespace std;
  string multiply(string num1,string num2)
  {
    string ans = "";
    int n = num1.length();
    int m = num2.length();
    if(num1 == "0"||num2=="0")
      return "0";
    vector<int >n1;
    vector<int>n2;
    vector<int> vec(501,0);
    for(int i=0;i<n;i++)
        {
            n1.push_back(num1[i]-'0');
        }
    for(int i=0;i<m;i++)
        {
            n2.push_back(num2[i]-'0');
        }
    for(int i= m-1;i>=0;i--)
        {
            for(int j= n-1;j>=0;j--)
            {
                int num = vec[500 -(m-1-i)-(n-1-j)] + (n1[j]* n2[i]);
                vec[500 - (m-1-i) -(n-1-j)] = num%10;
                vec[500 - (m-1-i) -(n-1-j)-1] += num/10;
            }
        }
        for(int x : vec)
            ans+= to_string(x);
        for(int i=0; i<=500;i++)
        {
            if(ans[i]!='0')
            {
                ans = ans.substr(i);
                break;
            }
        }
        cout<<ans;
        return ans;
    }
////////main function-----------------------
  int main()
  {
     long int t;
     cin>>t;
     while(t--)
     {
       string n1,n2;
       cin>>n1>>n2;
        multiply(n1,n2);
        //cout<<ans<<endl;
     }
     cout<<endl;

    return 0;
  }
