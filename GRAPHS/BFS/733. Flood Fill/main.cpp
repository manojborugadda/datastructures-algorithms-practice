class Solution {//TC:O(M*N)  SC:O(M*N)
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>>q;
        int oldcolor = image[sr][sc];
        q.push({sr,sc});
        image[sr][sc] = color;
        int x_row[] = {-1,0,1,0};
        int y_col[] = {0,1,0,-1};
        while(!q.empty()) {
            auto a = q.front();
            q.pop();
            int row = a.first;
            int col = a.second;
            for(int i = 0;i<4;i++) {
                int newX = row + x_row[i];
                int newY = col + y_col[i];
                if(newX < 0 or newX >= m or newY >= n or newY < 0 or image[newX][newY] != oldcolor) {
                    continue;
                }
                image[newX][newY] = color;
                q.push({newX,newY});
            }
        }
        return image;
    }
};
