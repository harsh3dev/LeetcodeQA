class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < target){
                less++;
            } else if (nums[i] == target){
                count++;
            }
        }
        vector<int> ans;

        for(int i = less; i < less + count; i++){
            ans.push_back(i);
        }

        return ans;
    }
};