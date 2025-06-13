class Solution {
private:
    bool valid(int mid, vector<int>& nums, int p) {
        int count = 0;
        int i = 0;

        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    }

public:
    int n;
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        int ans = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (valid(mid, nums, p)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};