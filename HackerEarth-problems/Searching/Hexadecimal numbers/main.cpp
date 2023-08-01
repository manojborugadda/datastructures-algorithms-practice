#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int num) {
	int sum  = 0;
	while(num >= 16) {
		int a = num/16;
		sum += num%16;
		num = a;
	}
	sum += num;
	return sum;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int l , r;
		cin>>l>>r;
		int count = 0;
		while(l <= r) {
			int HexSum = sumOfDigits(l);
			int calGCD = __gcd(HexSum,l);//equal to the sum of digits of 'l' in its hexadecimal (or base 16) representation.
			if(calGCD > 1) {
				count++;
			}
			l++;
		}
		cout<<count<<endl;
		count = 0;
	}
	return 0;
}
