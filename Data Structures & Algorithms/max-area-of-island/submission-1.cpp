class Solution {
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col] == 0){
            return 0;
        }
        grid[row][col] = 0;
        int res = 1;
        for(int i = 0; i<4; i++){
            int r = row+dx[i];
            int c = col+dy[i];
            res += dfs(r, c, grid);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                   maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};
