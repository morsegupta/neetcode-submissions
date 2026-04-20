class Solution {
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || c<0 || c>=grid[0].size() || r>=grid.size() || grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        for(int i = 0; i<4; i++){
            dfs(grid, r+dx[i], c+dy[i]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
