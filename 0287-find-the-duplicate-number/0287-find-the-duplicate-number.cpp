class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;
        int count = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                ans = nums[i];
                count++;
            }
        }

        return ans;
    }
};

// [7,9,7,4,2,8,7,7,1,5]
// 1 2 4 5 7 7 7 7 8 9