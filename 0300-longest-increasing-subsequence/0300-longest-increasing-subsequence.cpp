class Solution {
private:
    int dp(vector<int>& nums, int i, int pr){
        if(i == nums.size()){
            return 0;
        }

        if(t[i][pr+1] != -1){
            return t[i][pr+1];
        }

        int take = 0;
        int skip = dp(nums, i+1, pr); // prev doesnt change when skipping

        if(pr == -1 || nums[i] > nums[pr]){
            take = 1 + dp(nums, i+1, i);
        }

        return t[i][pr+1] = max(take, skip);
    }
public:
    vector<vector<int>> t;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        t.resize(n, vector<int>(n+1,-1));
        
        return dp(nums, 0, -1);
    }
};
// start from i
// take next el if > else skip
// res will be max take, skip