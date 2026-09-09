class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int n = nums.size();
        int candidate1 = 0;
        int candidate2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && nums[i] != candidate2){
                count1 = 1;
                candidate1 = nums[i];
            } else if(count2 == 0 && nums[i] != candidate1){
                count2 = 1;
                candidate2 = nums[i];
            } else if (nums[i] == candidate1){
                count1++;
            } else if (nums[i] == candidate2){
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            if(candidate1 == nums[i]){
                count1++;
            }
             else if(candidate2 == nums[i]){
                count2++;
            }
        }

        if(count1 > (n/3)){
            res.push_back(candidate1);
        }
        if(count2 > (n/3)){
            res.push_back(candidate2);
        }

        return res;
    }
};
// 1 1 2 2 1 2 1 0 2