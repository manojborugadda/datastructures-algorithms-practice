class Solution {//similar to AGGRESIVE COWS
public://TC:O(nlogn) SC:O(1)
    bool isPossible(vector<int>&position , int k , int mid) {
        int count = 1;
        int pos = position[0];
        for(int i = 0;i<position.size();i++) {
            if(position[i] - pos >= mid) {
                count++;
                pos = position[i];
            }
            if(count == k) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        int ans = 1;
        sort(begin(position),end(position));//logn
        int start = 1 , end = position[n-1];
        while(start <= end) {
            int mid = (start+end) >> 1;
            if(isPossible(position,m,mid)) {
                ans = mid;
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return ans;
    }
};
//find a slot such that minimum distance from other boy is maximized.
