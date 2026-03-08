class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string ans = "";

        for(int i = 0; i < n; i++){
            // we ensure that i index of ans is diff from i index of string i
            // this way its diff from all the strings in the array with atleast 1 diff index
            if(nums[i][i] == '0'){
                ans += '1';
            } else {
                ans += '0';
            }
        }

        return ans;
    }
};