/**
Sherlock and Watson are playing a swapping game. Watson gives to Sherlock a string S on which he has performed K swaps. You need to help Sherlock in finding the original string.
One swap on a string is performed in this way:

Assuming 1 indexing, the i'th letter from the end is inserted between i'th and (i+1)'th letter from the starting.
For example, we have "contest". After one swap, it would change to "ctosnet"

Input:
First line contains K, the number of swaps performed by Watson. Next line contains S, the string Watson gives to Sherlock.

Output:
You have to print in one line the original string with which Watson had started.

Constraints:
1 ≤ K ≤ 109
3 ≤ Length(S) ≤ 1000
All characters in S will be small English alphabets.
*/


#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int num;
	cin >> num;    //Reading input from STDIN
	string s;
	cin>>s;
	while(num--) {
		string temp = "";
		string temp2;
		for(int i = 0;i<s.length();i++) {
			if(i%2 == 0) {
				temp = temp + s[i];
			}else {
				temp2 += s[i];
			}
		}

		reverse(begin(temp2),end(temp2));

		for(auto ch : temp2) {
			temp = temp+ch;
		}

		s = temp;//re-assigning 'temp' to input string 's'
	}
	cout<<s<<endl;
}

