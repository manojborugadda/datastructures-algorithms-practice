// You are a lover of bacteria. You want to raise some bacteria in a box.

// Initially, the box is empty. Each morning, you can put any number of bacteria into the box. And each night, every bacterium in the box will split into two bacteria. You hope to see exactly x
//  bacteria in the box at some moment.

// What is the minimum number of bacteria you need to put into the box across those days?





// C++ program to convert a decimal
// number to binary number
#include <bits/stdc++.h>
using namespace std;

// func to convert decimal to binary
void decToBinary(int n,vector<int>&binaryNum)
{
	
	//counter for binary array
	int i = 0;
	while (n > 0) {
		// Storing remainder in binary
		// array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
}

// Driver code
int main()
{
	int n;
	cin>>n;
	vector<int>binaryNum(32,0);
	decToBinary(n,binaryNum);
	int count = 0;
	for(int i =0;i<binaryNum.size();i++) {
	    if(binaryNum[i] == 1) {
	        count++;
	    }
	}
	cout<<count<<endl;
	return 0;
}
