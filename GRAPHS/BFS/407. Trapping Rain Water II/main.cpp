class Solution {//TC:O(M*N*LOGN(M*N))  SC:O(m*n)
public:
    bool isValid(int r,int c,int m,int n) {
        return r < m and r >= 0 and c < n and c >=0;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if( m < 3 or n < 3) return 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>dir = { {1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        int totalUnvisitedCells = m*n;
        //inserting the borders elements into the PRIORITY QUEUE
        for(int i =0;i<m;i++) {//inserting 1st column and last columns values
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][n-1],i,n-1});
            vis[i][0] = true;
            vis[i][n-1] = true;
            totalUnvisitedCells -= 2;
        }

        for(int i =1;i<n-1;i++) {//inserting 1st row and last row values which starts from indx 1
            pq.push({heightMap[0][i],0,i});
            pq.push({heightMap[m-1][i],m-1,i});
            vis[0][i] = true;
            vis[m-1][i] = true;
            totalUnvisitedCells -= 2;
        }

        int trappedWater = 0;
        int currWaterLevel = 0;

        while(!pq.empty() or totalUnvisitedCells > 0) {
            auto [height,x,y] = pq.top();
            pq.pop();
            currWaterLevel = max(currWaterLevel,height);
            //traverse all 4 directions
            for(int i =0;i<4;i++) {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(isValid(newX,newY,m,n) and !vis[newX][newY]) {
                    int newHeight = heightMap[newX][newY];
                    if(newHeight < currWaterLevel) {
                        trappedWater += (currWaterLevel - newHeight);
                    }
                    pq.push({newHeight,newX,newY});
                    vis[newX][newY] = true;
                    totalUnvisitedCells--;
                }
            }
        }
        return trappedWater;
    }
};
