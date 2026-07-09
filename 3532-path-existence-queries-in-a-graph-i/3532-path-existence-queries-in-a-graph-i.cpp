class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        vector<bool> res(queries.size(), 0);

        int c = 0;
        comp[0] = c;

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] > maxDiff) {
                c++;
            }
            comp[i] = c;
        }

        for(int i = 0; i < queries.size(); i++){
            int x = queries[i][0];
            int y = queries[i][1];

            if(comp[x] == comp[y]){
                res[i] = 1;
            }
        }

        return res;
    }
};