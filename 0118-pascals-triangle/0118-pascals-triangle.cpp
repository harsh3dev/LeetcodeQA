class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        if(numRows>1)
            ans[1] = {1,1};

        for(int i = 2; i < numRows; i++){
            ans[i].resize(i+1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            for(int j = 1; j < i; j++){
                int curr = ans[i-1][j-1] + ans[i-1][j];
                
                ans[i][j]= curr;
            }
        }

        return ans;
    }
};