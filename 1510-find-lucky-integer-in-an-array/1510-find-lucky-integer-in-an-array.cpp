class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        int res = -1;
        for (const auto& [num, count] : mp) {
            if (num == count) {
                res = max(res, num);
            }
        }

        return res;
    }
};