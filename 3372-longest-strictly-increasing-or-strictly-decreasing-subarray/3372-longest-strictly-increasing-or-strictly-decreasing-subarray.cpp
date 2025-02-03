class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int currcount_increasing = 0;
        int currcount_decreasing = 0;
        int max_inc = 0;
        int max_dec = 0;
        int maxcount = 0;
        for(int i = 1; i < n; i++){
            if(nums[i]>nums[i-1]){
                currcount_increasing++;
                max_inc = max(currcount_increasing, max_inc);
            } else {
                max_inc = max(currcount_increasing, max_inc);
                currcount_increasing = 0;
            }
        }
        for(int i = 1; i < n; i++){
            if(nums[i]<nums[i-1]){
                currcount_decreasing++;
                max_dec = max(currcount_decreasing, max_dec);
            } else {
                max_dec = max(currcount_decreasing, max_dec);
                currcount_decreasing = 0;
            }
        }

        maxcount = max(max_inc, max_dec);
        return maxcount + 1;
    }
};