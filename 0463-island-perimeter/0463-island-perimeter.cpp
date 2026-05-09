class Solution {
private:
    int bfs(int i, int j, vector<vector<int>>& grid, int pr, int n, int m){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;

        while(!q.empty()){
            int ix = q.front().first;
            int jx = q.front().second;

            q.pop();

            for(auto& d: dir){
                int ii = ix + d[0];
                int jj = jx + d[1];
                
                if(ii < 0 || jj < 0 || ii >= n || jj >= m || grid[ii][jj] == 0){
                    pr++;
                    continue;
                }
                if(grid[ii][jj] == -1){
                    continue;
                }
                q.push({ii, jj});
                grid[ii][jj] = -1;
            }
        }

        return pr;
    }
public:
    int dir[4][2] = {
        {1,0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int pr = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return bfs(i, j, grid, pr, n, m);
                }
            }
        }

        return -1;
    }
};