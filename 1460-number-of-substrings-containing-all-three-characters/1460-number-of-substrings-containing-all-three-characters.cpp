class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;

        vector<int> mp(3, 0);
        int result = 0;
        while (j < n) {
            mp[s[j] - 'a']++;

            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0 && i < n) {
                result += n - j;
                mp[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return result;
    }
};