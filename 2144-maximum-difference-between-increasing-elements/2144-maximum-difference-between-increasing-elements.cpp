class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int dif = -1;
        int n = nums.size();

        int mn = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] > mn){
                dif = max({nums[i] - mn, dif});
            }

            if(nums[i] < mn){
                mn = nums[i];
            }
        }

        return dif;
    }
};