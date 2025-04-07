class Solution {
public:
    int n;
    long long t[100001][2];
    long long solve(vector<int>& nums, bool flag, int i) {
        if (i >= n) {
            return 0;
        }

        if (t[i][flag] != -1){
            return t[i][flag];
        }
        long long skip = solve(nums, flag, i + 1); // when we skip then we do not take
                                             // the curr value from the list

        long long val = nums[i];
        if (!flag) {
            val = -val;
        }

        long long take = solve(nums, !flag, i + 1) +
                   val; // when we take we both add the value to the ans and
                        // swap the flag

        return t[i][flag] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();

        return solve(nums, true,
                     0); // since true means num will be added and false means
                         // num will be subtracted, as alternating nums
    }
};