class Solution {
public:
    int s2n0(char a){
        return a=='0'?1:0;
    }
    int s2n1(char a){
        return a=='0'?0:1;
    }
    int maxScore(string s) {
        int maxsum = INT_MIN;
        int n = s.length();
        int sumi = 0;
        for(int i = 0; i < n-1; i++){
            sumi += s2n0(s[i]);
            int sumj = 0;
            for(int j = i+1; j < n; j++){
                sumj += s2n1(s[j]);
            }
            maxsum = max(maxsum, sumi+sumj);
        }
        return maxsum;
    }
};