#include <bits/stdc++.h>
using namespace std;       ///TC:O(NlogN) SC:O(1)

int lenOfSubSequence(vector<int>&arr , int n) {
    //sorting the input array
    sort(begin(arr),end(arr));

    int maxLen = 0; //storing the maximum length of longest Subsequence
    int count = 0;
    for(int i = 0;i<n; i++ ){
        if(i > 0 and (arr[i+1] -  arr[i] == 1) ){
            count++;
        }else if(arr[i+1] == arr[i] ) continue;
        else{
            count = 1;
        }
        maxLen = max(maxLen , count);
    }

    return maxLen;
}

int main() {
    vector<int>input = {33,20,34,30,35};
    int n = 5;
    cout<<"The length of the maximum consecutive subsequence is"<<" "<<lenOfSubSequence(input,n);
    return 0;
}
