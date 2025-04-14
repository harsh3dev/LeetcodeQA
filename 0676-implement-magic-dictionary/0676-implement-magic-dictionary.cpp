class MagicDictionary {
public:
    unordered_map<string, char> mp;
    char replace = '1';
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string &word : dictionary){
            for(int i = 0; i < word.size(); i++){
                string newword = word;
                newword[i] = replace;
                if(!mp.count(newword)){
                    mp[newword] = word[i];
                } else if(mp[newword] != word[i]){
                    mp[newword] = replace;
                }
            }
        }
    }
    
    bool search(string word) {
        for(int i = 0; i < word.size(); i++){
            string newword = word;
            newword[i] = replace;
            if(mp.count(newword) && mp[newword] != word[i]){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */