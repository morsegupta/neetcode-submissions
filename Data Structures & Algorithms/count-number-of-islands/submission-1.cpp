class Solution {
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};
public:
    void dfs(int row, int col, vector<vector<char>>& grid){
        if(row < 0 || col <0 || row>=grid.size() || col>=grid[0].size() || grid[row][col] == '0'){
            return;
        }
        grid[row][col] = '0';
        for(int i = 0; i<4; i++){
            int r = row + dx[i];
            int c = col + dy[i];
            dfs(r, c, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};
