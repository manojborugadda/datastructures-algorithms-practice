class Solution {//TC:O(nlogn)  SC:O(1)
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0 , j = nums.size()-1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n/2;i++) {
            int a = nums[i] + nums[n-1-i];
            if(ans < a) ans = a;
        }
        
        return ans;
    }
};
