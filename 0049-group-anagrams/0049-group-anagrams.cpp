class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(string s: strs){
            string word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& [fir, sec]: mp){
            ans.push_back(sec);
        }

        return ans;
    }
};