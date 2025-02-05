class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if(s1==s2) return true;
        vector<int> map1(26,0);
        vector<int> map2(26,0);
        int diff = 0;

        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                diff++;
            }
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
            if(diff>2) return false;
        }

        for(int i = 0; i < 26; i++){
            if(map1[i]!=map2[i]){
                return false;
            }
        }

        return true;
    }
};