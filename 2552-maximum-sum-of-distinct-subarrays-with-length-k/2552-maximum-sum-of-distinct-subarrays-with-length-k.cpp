class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long maxSum = 0;
        long long sum = 0;

        unordered_set<int> st;

        while( j<n ){

            while(st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);


            if(j == i+k-1){
                maxSum = max(maxSum, sum);
                sum -= nums[i];
                st.erase(nums[i++]);
            }

            j++;
        }

        return maxSum;
    }
};