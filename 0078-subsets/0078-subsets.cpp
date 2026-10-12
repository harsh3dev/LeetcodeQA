class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        findSubsets(nums, 0, nums.size(), arr);
        return res;
    }

    void findSubsets(vector<int>& nums, int i, int n, vector<int> &arr){
        if(i >= n){
            res.push_back(arr);
            return;
        }

        arr.push_back(nums[i]);

        findSubsets(nums, i+1, n, arr);

        arr.pop_back();
        findSubsets(nums, i+1, n, arr);
    }
};