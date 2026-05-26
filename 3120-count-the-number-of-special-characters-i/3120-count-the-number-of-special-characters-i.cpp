class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> sm(26, 0);
        vector<int> lg(26, 0);

        for(int i = 0; i < n; i++){
            char ch = word[i];
            if((int)ch < 97){
                lg[ch - 'A']++;
            } else {
                sm[ch - 'a']++;
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++){
            if(sm[i] > 0 && lg[i] > 0){
                count++;
            }
        }

        return count;
    }
};