class Solution {//TC:O(nlogn)  sc:o(1)
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr),end(arr));
        arr[0] = 1;//first condition
        for(int i = 1;i<arr.size();i++) {
            if(abs(arr[i]-arr[i-1]) <= 1) {
                continue;
            }
            arr[i] = arr[i-1] + 1; //second condition
        }
        return arr.back();
    }
};
