class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();  // Number of rows
        int n = grid[0].size();  // Number of columns

        // Directions corresponding to right, left, down, and up.
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        // Minimum cost matrix to track the least cost to reach each cell.
        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));

        // Priority queue to process the cell with the least cost first (min-heap).
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        // Start at the top-left corner, with cost 0.
        pq.emplace(0, 0, 0);  // (cost, x, y)
        minCost[0][0] = 0;

        // Process the grid using a modified Dijkstra's algorithm
        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();  // Get the current cell and its cost
            pq.pop();

            // If the cost to reach this cell is already higher than a previously found cost, skip it.
            if (minCost[x][y] < cost) continue;

            // Check all 4 possible directions (right, left, down, up).
            for (int dir = 0; dir < 4; ++dir) {
                // Calculate the new cell's coordinates after moving in the given direction.
                int new_x = x + directions[dir][0];
                int new_y = y + directions[dir][1];

                // Check if the new coordinates are within bounds of the grid.
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    // Determine the cost to move to the new cell.
                    // If the direction matches the sign at the current cell, no cost to move.
                    int nextCellCost = (dir + 1 == grid[x][y]) ? 0 : 1;

                    // Calculate the new cost to move to the new cell.
                    int newCost = cost + nextCellCost;

                    // If the new cost is better (lower), update the cost matrix and add the new cell to the priority queue.
                    if (newCost < minCost[new_x][new_y]) {
                        minCost[new_x][new_y] = newCost;
                        pq.emplace(newCost, new_x, new_y);
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right cell (m-1, n-1).
        return minCost[m-1][n-1];
    }
};
