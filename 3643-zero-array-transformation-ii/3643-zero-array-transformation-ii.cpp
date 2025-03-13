class Solution {
private:
    bool diffCheck(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(nums.size(), 0);

        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];

            diff[l] += v;
            if (r + 1 < diff.size()) {
                diff[r + 1] -= v;
            }
        }

        int sum = 0;

        for (int i = 0; i < diff.size(); i++) {
            sum += diff[i];

            diff[i] = sum;

            if (nums[i] - diff[i] > 0) {
                return false;
            }
        }

        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                c++;
        }
        if (c == n)
            return 0;

        int l = 0;
        int r = q - 1;
        int k = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (diffCheck(nums, queries, m) == true) {
                k = m + 1;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return k;
    }
};

// [0,2,0,4]
// [[3,3,3],[0,0,5]]
