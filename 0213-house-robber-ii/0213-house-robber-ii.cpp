class Solution {
public:
    int t[101];
    int solve(int idx, vector<int>& nums, int n) {
        if (idx > n)
            return 0;
        if (t[idx] != -1)
            return t[idx];
        int steal = nums[idx] + solve(idx + 2, nums, n);
        int skip = solve(idx + 1, nums, n);

        return t[idx] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));
        int a = solve(0, nums, n-2);
        memset(t, -1, sizeof(t));
        int b = solve(1, nums, n-1);
        return max(a, b);
    }
};