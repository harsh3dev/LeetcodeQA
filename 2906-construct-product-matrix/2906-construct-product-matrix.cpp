class Solution {
public:
    int M = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> a;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a.push_back(grid[i][j]);
            }
        }

        vector<int> prev(n*m, 1);
        vector<int> pro(n*m, 1);

        for(int i = 1; i < n*m; i++){
            prev[i] = (1LL * prev[i-1] * a[i-1]) % M;
        }

        for(int i = n*m - 2; i >= 0; i--){
            pro[i] = (1LL * pro[i+1] * a[i+1]) % M;
        }


        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int idx = i * m + j;
                ans[i][j] = (prev[idx] * pro[idx]) % M;
            }
        }

        return ans;
    }
};