class Solution {//TC:O(m*nlog(m*n)) SC:O(m*n)
public:
    #define pii pair<int,int>
    bool isValid(int r , int c , int n , int m) {
        if( r < m and c < n and r >=0 and c >= 0 ) {
            return true;
        }
        return false;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Directions corresponding to right, left, down, and up.
        vector<vector<int>>DIR =  { {0,1}, {0,-1}, {1,0}, {-1,0} };
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        // Minimum cost matrix to track the least cost to reach each cell.
        vector<vector<int>>minCost(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0}); // (cost, x, y)
        // Start at the top-left corner, with cost 0.
        minCost[0][0] = 0;
        while(!pq.empty()) {
            auto [cost,x,y] = pq.top();
            pq.pop();
            if(minCost[x][y] < cost) continue;
             // Check all 4 possible directions (right, left, down, up).
             // here 1 is RIGHT direction so we do plus 1 for setting the direction number correct
            for(int i =0;i<DIR.size();i++) {
                // Calculate the new cell's coordinates after moving in the given direction.
                int newX = x + DIR[i][0];
                int newY = y +  DIR[i][1];
                //checking if the coordinates are OUT of BOUND
                if(isValid(newX,newY,m,n)) {
                    // Determine the cost to move to the new cell.
                    // If the direction matches the sign at the current cell, no cost to move.
                    // here 1 is RIGHT direction so we do plus 1 for setting the direction number correct
                    int nextCellCost = ( i + 1 == grid[x][y] ) ? 0 : 1;
                    // Calculate the new cost to move to the new cell.
                    int newCost = cost + nextCellCost;
                    // If the new cost is better (lower), update the cost matrix and add the new cell to the priority queue.
                    if(newCost < minCost[newX][newY]) {
                        minCost[newX][newY] = newCost;
                        pq.push({newCost,newX,newY});
                    }
                }
            }
        }
        // Return the minimum cost to reach the bottom-right cell (m-1, n-1).
        return minCost[m-1][n-1];
    }
};
