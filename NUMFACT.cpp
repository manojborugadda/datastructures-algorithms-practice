#include <iostream>
#include<map>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    map<ll , ll> primepower;
	    while(n--){
	    ll t;  cin>>t;

	    for(int i=2;i*i<=t;i++){
	        while(t%i==0){
	            primepower[i]++;
	            t/=i;
	        }
	    }
	    if(t>1){
	        primepower[t]++;
	        t=1;
	    }

	 }
	 ll fact=1;
	 map<ll, ll>::iterator itr;
	 for(itr = primepower.begin() ; itr != primepower.end() ; itr++)
	 {
	     fact*=(itr->second+1);
	 }
	 cout<<fact<<endl;

	}

	return 0;
}


