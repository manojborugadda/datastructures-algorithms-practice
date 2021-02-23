#include<bits/stdc++.h>
using namespace std;
int main()
  {
    int length;
    string str;
    cin>>length;
    cin>>str;
    map<char,int>map;
    for(int i = 0;i<length;i++)
    {
        map[str[i]]++;
    }
    int gene;
    gene = length/4;
    if(map['A'] == gene && map['G'] == gene && map['T'] == gene && map['C'] == gene)
    {
        cout<<"0"<<endl;
        exit(0);
    }
    int right = 0,left = 0;
    int min = length;
    while(1)
    {
        while(map['A']>gene || map['C']>gene || map['T']>gene || map['G']>gene )
        {
            map[str[right]]--;
            right++;
            if(right==length)
            {
                break;
            }
        }
        if(right==length)
            {
                break;
            }

       while(map['A']<=gene && map['C']<=gene && map['T']<=gene && map['G']<=gene )
        {
            map[str[left]]++;
            left++;
        }

        if((right-left+1) < min)
        {
            min=right-left+1;
        }
    }
        cout<<min<<endl;
        return 0;
  }


