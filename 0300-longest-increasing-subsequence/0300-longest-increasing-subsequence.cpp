class Solution {
private:
    vector<vector<int>> t;
    int solve(vector<int>& nums, int i, int prev) {
        if (i == nums.size())
            return 0;
        if (t[i][prev+1] != -1) {
            return t[i][prev+1];
        }
        int take = 0;
        int skip = solve(nums, i + 1, prev);

        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i);
        }

        return t[i][prev+1] = max(take, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        t.resize(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1);
    }
};