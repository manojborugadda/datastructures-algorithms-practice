#include <bits/stdc++.h>
using namespace std;

/////          TC:O(N) SC:O(N) -----------Using HASHING ( Unordered_set )
int lenOfSubSequence(vector<int>&arr) {
    unordered_set<int>set(arr.begin(),arr.end());
    int maxLen = 0; //storing the maximum length of longest Subsequence
    int count = 0;
    for(auto x : set) {
            //if the previous element is not found in the SET
            //so we are checking if the current element 'x' is starting element of the sequence
        if(set.find(x-1) == set.end()) {
            int len = 1;                    // stores the length of the subsequence starting with the current element
            while( set.find(x+len) != set.end()){ //checking for the presence of later elements like x+1,x+2,x+3... so on
                len++;
            }
            maxLen = max(maxLen,len);
        }
    }
    return maxLen;
}

int main() {
    vector<int>input = {33,20,34,30,35};
    cout<<"The length of the maximum consecutive subsequence is"<<" "<<lenOfSubSequence(input);
    return 0;
}




