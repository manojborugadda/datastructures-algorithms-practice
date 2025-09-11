class Solution {
  public:
    bool isEatingSpeedValid(vector<int>& arr, int k,int speed) {
        int n = arr.size();
        int hrspent = 0;
        for(int i = 0;i<n;i++) {
            hrspent += arr[i]/speed;
            if(arr[i]%speed != 0 ) {
                hrspent += 1;
            }
            if(hrspent > k) return false;
        }
        
        return true;
    }
    
    int kokoEat(vector<int>& arr, int k) {
        int ans =-1;
        int low = 1;
        int high = *max_element(arr.begin(),arr.end());
        while(low <= high) {
            int mid = low  + (high-low)/2;
            if(isEatingSpeedValid(arr,k,mid)) {
                ans = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};
