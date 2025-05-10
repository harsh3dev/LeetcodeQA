class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        int count1 = 0;
        int count2 = 0;

        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++) {
            if (nums1[i] == 0) {
                sum1 += 1;
                count1++;
            }
            sum1 += nums1[i];
            
        }
        for (int i = 0; i < m; i++) {
            if (nums2[i] == 0) {
                sum2 += 1;
                count2++;
            }
            sum2 += nums2[i];
            
        }
        if (sum1 == sum2)
            return sum1;
        if (sum1 < sum2 && count1 < 1 || sum2 < sum1 && count2 < 1) {
            return -1;
        }

        return sum1 > sum2 ? sum1 : sum2;
    }
};