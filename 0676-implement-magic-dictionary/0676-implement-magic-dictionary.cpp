class MagicDictionary {
public:
    set<string> st;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string &word:dictionary){
            st.insert(word);
        }
    }
    
    bool search(string searchWord) {
        // if(st.count(searchWord)) return false;
        string newWord = searchWord;
        for(int j = 0; j < searchWord.size(); j++){
            for(char i = 'a'; i <= 'z'; i++){
                newWord[j] = i;
                if(st.count(newWord)>0 && searchWord[j]!=i){
                    return true;
                }
                newWord[j] = searchWord[j];
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