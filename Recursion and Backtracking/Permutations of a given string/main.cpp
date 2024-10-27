// Given a string s. The task is to return a vector of string of all unique permutations of the given string, s that may contain dulplicates in lexicographically sorted order. 

// Examples:

// Input: ABC
// Output: [ABC, ACB, BAC, BCA, CAB, CBA]
// Explanation: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {//TC:O(N! * N)  SC:O(N! * N)
  public:
    void permutations(string s,int idx, set<string>&set) {
        int n  = s.length();
        //base case
        if(idx == n) {
            set.insert(s);
            return;
        }
        
        for(int i =idx;i<n;i++) {
            swap(s[i],s[idx]);
            permutations(s,idx+1,set); //recursive calling
            swap(s[i],s[idx]); //backtracking
        }
    }
    vector<string> find_permutation(string s) {
        set<string>st;//used to store all unique permutations
        permutations(s,0,st);
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
