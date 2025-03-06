class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> count;
        int n = grid[0].size();
        for(int i = 1; i <= n*n; i++){
            count[i] = 0;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j <n; j++){
                count[grid[i][j]]++;
            }
        }
        vector<int> ans(2,0);
        for(auto& el:count){
            if(el.second == 2){
                ans[0] = el.first;
            }
            if(el.second == 0){
                ans[1] = el.first;
            }
        }
        return ans;
    }
};