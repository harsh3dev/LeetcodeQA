class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> res;
        int i = 0;
        while(i<n){
            int j = (i+k-1) < n ? i+k-1 : n-1;
            string temp = s.substr(i, j-i+1);

            if(j-i+1 < k){
                temp += string(k - (j-i+1), fill);
            }

            res.push_back(temp);
            i += k;
        }

        return res;
    }
};