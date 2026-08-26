class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        string ans = "";
        int count1 = 0;

        for(int r = 0; r < n; r++){
            if(s[r] == '1') count1++;

            while(count1 > k){
                if(s[l] == '1'){
                    count1--;
                }
                l++;
            }

            if(count1 == k){
                while(l < r && s[l] == '0'){
                    l++;
                }

                string curr = s.substr(l, r-l+1);

                if(ans == "" || curr.size() < ans.size() || (curr.size() == ans.size() && curr < ans)){
                    ans = curr;
                }
            }
        }

        return ans;
    }
};