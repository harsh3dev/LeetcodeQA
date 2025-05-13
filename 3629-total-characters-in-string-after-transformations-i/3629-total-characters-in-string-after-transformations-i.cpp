class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int m = 1e9 + 7;

        vector<int> cnt(26,0);
        for(char ch:s){
            cnt[ch-'a']++;
        }

        string str = s;
        for(int i = 0; i < t; i++){
            vector<int> tmp(26,0);
            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    tmp[0] = (tmp[0] + cnt[i]) % m;
                    tmp[1] = (tmp[1] + cnt[i]) % m;
                } else {
                    tmp[i + 1] = (tmp[i + 1] + cnt[i]) % m;
                }
            }
            cnt = tmp;
        }

        int count = 0;
        for (int ch : cnt) {
            count = (count + ch) % m;
        }

        return count;
    }
};