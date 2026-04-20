class Solution {
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int res = 1;
        for(int i = 0; i<4; i++){
            res += dfs(grid, r+dx[i], c+dy[i]);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
