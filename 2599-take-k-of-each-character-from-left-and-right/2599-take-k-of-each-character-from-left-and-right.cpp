class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;

        unordered_map<char, int> window;
        int l = 0, maxwin = 0;

        for(int r = 0; r < s.size(); r++){
            window[s[r]]++;
            // check if the outer window is valid or not
            // and move the left pointer accordingly

             while(l <= r && (mp['a'] - window['a'] < k || mp['b'] - window['b'] < k || mp['c'] - window['c'] < k)) {
                window[s[l]]--;
                l++;
            }

            maxwin = max(maxwin, r-l+1);
        }

        return s.size() - maxwin;
    }
};