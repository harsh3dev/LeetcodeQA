class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n - 1; i++) {
            total += abs(nums[i] - nums[i + 1]);
        }

        int gain = 0;

        for (int i = 0; i < n - 1; i++) {
            gain = max(gain,
                abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            gain = max(gain,
                abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
        }

        int min_max = INT_MAX;
        int max_min = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            min_max = min(min_max, max(nums[i], nums[i + 1]));
            max_min = max(max_min, min(nums[i], nums[i + 1]));
        }

        gain = max(gain, 2 * (max_min - min_max));

        return total + gain;
    }
};