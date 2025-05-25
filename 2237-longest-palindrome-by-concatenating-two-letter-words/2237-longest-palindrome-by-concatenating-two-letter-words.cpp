class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int n = words.size();
        int count = 0;
        int singlePal = 0;

        for (string word : words) {
            mp[word]++;
        }

        for (auto& [word, fr] : mp) {
            // check if the word is pal
            // then add it to count if its mul of 2 i.e. in pair
            // else if its in mul of 1 i.e. odd freq then add and count it for
            // middle else if the rev is in the map then update the count
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word == rev) {
                if (fr % 2) {
                    singlePal = 1;
                    count += fr - 1;
                } else{
                    count += fr;
                }
            } else {
                if (mp.count(rev)) {
                    // here *2 will not be there because it repeats for lc as well as cl
                    count += min(fr, mp[rev]);
                }
            }
        }

        return count * 2 + singlePal * 2;
    }
};