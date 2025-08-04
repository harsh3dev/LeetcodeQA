class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int l = 0;

        for (int i = 0; i < n; i++) {
            mp[fruits[i]]++;

            while (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};
