class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int totalone = 0;
        int maxsum = INT_MIN;
        for(int i = 0; i < n; i++){
            totalone += s[i]=='0'?0:1;
        }
        int zeroes = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i]=='0'){
                zeroes++;
            } else {
                totalone--;
            }

            maxsum = max(maxsum, totalone+zeroes);
        }

        return maxsum;
    }
};