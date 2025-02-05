class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int m1 = -1;

        for(int i = n-1; i > 0; i--){
            if(nums[i]>nums[i-1]){
                m1 = i - 1;
                break;
            }
        }

        int m2 = m1;

        if(m1 != -1){
            for(int i = n-1; i >= m1; i--){
                if(nums[i] > nums[m1]){
                    m2 = i;
                    break;
                }
            }

            swap(nums[m1], nums[m2]);
        }

        reverse(nums.begin() + m1 + 1, nums.end());
    }
};