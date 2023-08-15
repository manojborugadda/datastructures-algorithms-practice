//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/speed-7/


#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n , ans = 1;
		cin>>n;
		int arr[n];
		for(int i = 0;i<n;i++) {
			cin>>arr[i];
		}

		int maxi = arr[0];
		for(int i = 1;i<n;i++) {
			if(arr[i] < maxi) {
				maxi = arr[i];
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
