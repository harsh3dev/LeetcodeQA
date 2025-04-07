class Solution {
public:
    int t[101];
    int solve(int idx, vector<int>& nums) {
        if (idx >= nums.size())
            return 0;
        if (t[idx] != -1)
            return t[idx];
        int steal = nums[idx] + solve(idx + 2, nums);
        int skip = solve(idx + 1, nums);

        return t[idx] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums);
    }
};