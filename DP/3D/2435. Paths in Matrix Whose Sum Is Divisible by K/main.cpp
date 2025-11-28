class Solution {
public:
    const int mod = 1e9+7;
    int solve(int i, int j,int sum, vector<vector<int>>&grid, int k,vector<vector<vector<int>>>&dp) {
        int m = grid.size();
        int n = grid[0].size();
        //base
        if(i == m-1 and j == n-1) {
            sum = (sum + grid[i][j])%k;
            if( sum == 0) {
                return 1;
            }
            return 0;
        }

        if( i == m or j == n) {
            return 0;
        }

        if( dp[i][j][sum] != -1)  {
            return dp[i][j][sum];
        }

        int right = solve(i,j+1,(sum + grid[i][j])%k, grid, k, dp);
        int left = solve(i+1,j,(sum + grid[i][j])%k, grid, k, dp );

        return dp[i][j][sum]  = (right  + left )%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(0,0,0,grid,k,dp);
    }
};
