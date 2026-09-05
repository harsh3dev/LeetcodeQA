class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> mp = {1, nums[0]};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < n-1; i++) {
            count++;
            if(nums[i] != nums[i+1]){
                if(mp.first < count){
                    mp.first = count;
                    mp.second = nums[i];
                }
                count = 0;
            }
        } count++;

        if(mp.first < count){
            mp.first = count;
            mp.second = nums.back();
        }

        return mp.second;
    }
};