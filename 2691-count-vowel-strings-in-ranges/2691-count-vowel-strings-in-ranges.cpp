class Solution {
private:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        else return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size()+1, 0);
        for(int i = 0; i < words.size(); i++){
            prefix[i+1] = prefix[i];
            string word = words[i];
            if(isVowel(word.front()) && isVowel(word.back())) prefix[i+1]++;
        }

        vector<int> ans;
        for(auto& query : queries){
            int l = query[0];
            int r = query[1];
            int currprefix = prefix[r+1] - prefix[l];
            ans.push_back(currprefix);
        }

        return ans;
    }
};

// first iterate through words array and mark the valid words
// then iterate through the queries array and get the l and r then count the
// number of valid words in that range
// for each query add the count in the ans

// --0-------1-------2--------3---------4----------5----------
//   |_______2_______|
//           |_____________3_____________|
// we use prefix sum
// for example: if 1 to 2 has 2 and 1 to 4 has 4 then 1 to 4 has 4-2 = 2
// so if the word is valid we add it to prefix array