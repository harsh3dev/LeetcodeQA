class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        vector<int> rowmatch(n, 0);
        vector<int> colmatch(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1){
                    rowmatch[i]++;
                    colmatch[j]++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1){
                    if(rowmatch[i]>1 || colmatch[j]>1){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};