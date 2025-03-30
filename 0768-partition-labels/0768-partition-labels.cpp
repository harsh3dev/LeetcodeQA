class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<char,int> mp;

        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }

        int last = -1;

        vector<int> temp;
        int prev = 0;

        for(int i = 0; i < n; i++){
            last = max(last, mp[s[i]]);
            if(last == i){
                temp.push_back(last - prev + 1);
                prev = last + 1;
            }
        }

        return temp;

    }
};