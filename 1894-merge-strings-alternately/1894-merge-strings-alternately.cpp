class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;

        int n1 = word1.size();
        int n2 = word2.size();

        string res = "";
        bool flag = true;
        while(i < n1 && j < n2){
            res += flag ? word1[i++] : word2[j++];
            flag = flag ? false : true;
        }

        while(i < n1){
            res += word1[i++];
        }

        while(j < n2){
            res += word2[j++];
        }

        return res;
    }
};