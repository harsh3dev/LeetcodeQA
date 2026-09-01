class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int currSum = 0;

        for(auto &num: nums){
            currSum = max(num, currSum+num);
            sum = max(sum, currSum);
        }
        return sum;
    }
};