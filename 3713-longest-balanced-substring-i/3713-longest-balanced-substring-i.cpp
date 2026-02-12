class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            int maxf = 0;
            int uni = 0;
            int freq[26] = {};
            for(int j = i; j < n; j++){
                int idx = s[j] - 'a';

                uni += (freq[idx] == 0);

                maxf = max(maxf, ++freq[idx]);

                if(j - i + 1 == uni * maxf){
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

// zzabccy