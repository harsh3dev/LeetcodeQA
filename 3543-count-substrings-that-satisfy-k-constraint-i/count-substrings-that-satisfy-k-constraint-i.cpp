class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        // start i = 0, j = 0
        // iterate through string
        // maintain a count of zero and one
        // if both condition not satisfy then i++
        // else j++
        // increment count
        int n = s.size();
        int count = 0, i = 0, j = 0, c0=0, c1=0, ans = 0;
        while(j < n){
            if(s[j]=='0') c0++;
            else c1++;
            while(c0>k && c1>k){
                if(s[i]=='0') c0--;
                else c1--;
                i++;
            }

            ans += (j-i+1);
            j++;
        }

        return ans;
    }
};