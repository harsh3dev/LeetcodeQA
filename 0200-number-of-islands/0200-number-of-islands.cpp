class Solution {
private:
    void dfs(vector<vector<bool>>& vis, int i, int j, vector<vector<char>>& grid){
        vis[i][j]=1;
        // urdl
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        int n = grid.size();
        int m = grid[0].size();

        for(int u = 0; u < 4; u++){
            int ni = i + dx[u];
            int nj = j + dy[u];
            if(ni < n && ni >= 0 && nj < m && nj >= 0 && !vis[ni][nj] && grid[ni][nj] == '1'){
                dfs(vis, ni, nj, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(vis,i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};