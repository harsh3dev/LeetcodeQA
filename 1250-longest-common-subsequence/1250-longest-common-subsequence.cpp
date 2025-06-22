class Solution {
private:
    int dp(string& s1, string& s2, int i, int j){
        if(i == s1.size() || j == s2.size()) return 0;
        if(t[i][j] != -1) return t[i][j];
        if(s1[i] == s2[j]){
            t[i][j] = 1 + dp(s1, s2, i+1, j+1);
        } else {
           t[i][j] = max(dp(s1, s2, i+1,j), dp(s1, s2, i,j+1));
        } 

        return t[i][j];
    }
public:
    vector<vector<int>> t;
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        t.assign(m, vector<int>(n, -1));
        return dp(s1, s2, 0,0);
    }
};

// abcde
// facxe