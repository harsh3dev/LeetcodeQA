class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int minLength = INT_MAX;
        int currSum = 0;
        while(i <= j && j < n){
            currSum += nums[j];

            while(currSum >= target){
                minLength = min(minLength, j - i + 1);
                currSum = currSum - nums[i++];
            }

            j++;
        }

        return minLength <= n ? minLength : 0;
    }
};