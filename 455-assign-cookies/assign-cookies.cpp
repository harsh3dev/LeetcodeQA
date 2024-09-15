class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int l = 0; 
        int r = 0;
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        while(l<n && r<m){
            if(g[l]<=s[r]) l++;
            r++;
        }
        return l;
    }
};