class Solution {
private:
    bool isGreater(string curr, string next, unordered_map<char, int> mp){
        int n = min(curr.size(), next.size());

        for(int i = 0; i < n; i++){
            if(curr[i] != next[i])
                if(mp[curr[i]] > mp[next[i]])
                    return true;
                else
                    return false;
        }

        if(curr.size() > next.size()){
            return true;
        }

        return false;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
       unordered_map<char, int> mp;

       for(int i = 0; i < order.size(); i++){
        mp[order[i]] = i;
       }
        int n = words.size();

        for(int i = 0; i < n-1; i++){
            string curr = words[i];
            string next = words[i+1];

            if(isGreater(curr, next, mp)){
                return false;
            }
        }

        return true;
    }
};