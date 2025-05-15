class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev = 1;
        int back = 1;

        int ans = INT_MIN;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(prev == 0){
                prev = 1;
            }
            if(back == 0){
                back = 1;
            }

            prev *= nums[i];
            back *= nums[n-i-1];

            ans = max(ans, max(prev, back));
        }

        return ans;
    }
};