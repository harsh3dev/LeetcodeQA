class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        long long currSum = 0;
        int split = 0;
        for(int i = 0; i < n-1; i++){
            currSum += nums[i];
            if(currSum >= sum-currSum) split++;
        }

        return split;
    }
};