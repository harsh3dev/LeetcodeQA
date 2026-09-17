class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> count;

        for (int right = 0; right < s.length(); right++) {
            count[s[right]]++;

            while (count[s[right]] > 1) {
                count[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};