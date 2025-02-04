class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int currsum = nums[0];
        int maxsum = currsum;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                currsum += nums[i];
            } else{
                currsum = nums[i];
            }
            maxsum = max(maxsum, currsum);
        }

        return maxsum;
    }
};