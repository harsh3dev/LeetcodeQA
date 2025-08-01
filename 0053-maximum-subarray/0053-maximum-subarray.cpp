class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int ans = nums[0];
        int sum = 0;
        int i = 0, j = 0;

        while(j < n){
            sum += nums[j++];
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
                i = j;
            }
        }

        return ans;
    }
};