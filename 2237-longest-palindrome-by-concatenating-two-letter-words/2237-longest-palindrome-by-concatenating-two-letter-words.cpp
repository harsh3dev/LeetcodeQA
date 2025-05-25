class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int n = words.size();
        int count = 0;
        int isPal = 0;

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
                count += (fr / 2);
                if (fr % 2) {
                    isPal = 1;
                }
            } else {
                if (rev < word && mp.count(rev)) {
                    count += min(fr, mp[rev]);
                }
            }
        }

        return count * 4 + isPal * 2;
    }
};