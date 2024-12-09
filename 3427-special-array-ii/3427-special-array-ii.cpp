class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<bool> result(m, false);

        
        vector<int> invalid(n, 0);
        invalid[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i]%2 == nums[i-1]%2){
                invalid[i] = invalid[i-1] + 1;
            }
            else invalid[i] = invalid[i-1];
        }
        int i = 0;
        for(vector<int>& num:queries){
            int start = num[0];
            int end = num[1];
            if(invalid[end] - invalid[start] == 0){
                result[i] = true;
            }
            i++;
        }

        return result;
    }
};

// if every num is of diff parity then it means that if any number is out of parity
// then it is invalid array
// so we store the number of invalid nums in array
// first iterate through the array nums and then match if the i and i-1 are of diff
// parity then store it
// at end check if the in between queries any invalid is there then
// store false in the boolean array