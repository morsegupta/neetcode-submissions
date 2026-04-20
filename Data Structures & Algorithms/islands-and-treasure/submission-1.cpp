class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dx[4] = {0, +1, 0, -1};
        int dy[4] = {-1, 0, +1, 0};

        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = row + dx[i];
                int mcol = col + dy[i];

                if(nrow<0 || mcol <0 || nrow>=n || mcol >=m || grid[nrow][mcol] != INT_MAX) continue;
                grid[nrow][mcol] = grid[row][col] + 1;
                q.push({nrow, mcol});
            }
        }
    }
};
