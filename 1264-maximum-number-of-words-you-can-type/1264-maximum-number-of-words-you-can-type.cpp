class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool curr=true;
        int count = 0;
        for(int i = 0; i < text.size(); i++){
            if(text[i]==' '){
                if(curr) count++;
                curr = true;
            }
            
            if(brokenLetters.find(text[i]) != string::npos){
                curr = false;
            }
        }

        if(curr) count++;
        return count;
    }
};