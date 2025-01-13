class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int len = 0;
        for (auto& itr : mp) {
            while (itr.second >= 3) {
                len += 2;
                itr.second -= 2;
            }
        }

        return s.length() - len;
    }
};