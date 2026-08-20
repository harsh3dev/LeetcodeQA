class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2, res;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n = nums.size();
        for(int i = 2; i < n; i++){
            if(arr1.back() < arr2.back()){
                arr2.push_back(nums[i]);
            } else {
                arr1.push_back(nums[i]);
            }
        }

        for(int i = 0; i < arr1.size(); i++){
            res.push_back(arr1[i]);
        }
        for(int i = 0; i < arr2.size(); i++){
            res.push_back(arr2[i]);
        }

        return res;
    }
};