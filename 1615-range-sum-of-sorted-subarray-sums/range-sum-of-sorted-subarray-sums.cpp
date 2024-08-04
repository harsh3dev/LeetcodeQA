class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int newSize = n * (n + 1) / 2;
        long long sum = 0;
        vector<int> subarraySums;
        
        // Generate all subarray sums
        for (int i = 0; i < n; ++i) {
            long long currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                subarraySums.push_back(currentSum);
            }
        }
        
        // Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());
        
        // Sum the elements from 'left' to 'right' (1-based indexing)
        for (int i = left - 1; i < right; ++i) {
            sum = (sum + subarraySums[i]) % 1000000007;
        }
        
        return sum;
    }
};