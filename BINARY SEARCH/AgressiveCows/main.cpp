//https://www.geeksforgeeks.org/problems/aggressive-cows/0

class Solution {
public:
    
    bool isPossible(vector<int>& stalls, int k, int mid){
        int pos = stalls[0];
        int c = 1;
        for(int i= 0; i< stalls.size(); i++){
            if(stalls[i] - pos >= mid){
                c++;
                pos = stalls[i];
            }
            if(c == k) return true;
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int start = 0;
        int end = stalls[stalls.size() -1] - stalls[0];
        int ans = -1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(stalls, k, mid)){
                ans = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};
