class Solution {
private:
    bool isTriangle(vector<int>& nums){
        if(
            nums[0] + nums[1] > nums[2] &&
            nums[1] + nums[2] > nums[0] &&
            nums[0] + nums[2] > nums[1]
        ) {
            return true;
        }
        return false;
    }
public:
    string triangleType(vector<int>& nums) {
        if(isTriangle(nums)){
            if(nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2]){
                return "scalene";
            }

            if(nums[0] == nums[1] && nums[0] == nums[2]){
                return "equilateral";
            }

            if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]){
                return "isosceles";
            }
        }

        return "none";
    }
};