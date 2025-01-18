class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i =0; i<n; i++){
            mp[nums[i]] = i;
        }
        for(int i = 0; i < n; i++){
            sum = target - nums[i];
            if(mp.count(sum) && mp[sum]!=i){
                return {i, mp[sum]};
            }
        }
        return {};
    }
};