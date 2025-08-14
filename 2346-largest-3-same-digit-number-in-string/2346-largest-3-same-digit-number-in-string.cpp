class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> match = {
            "999",
            "888",
            "777",
            "666",
            "555",
            "444",
            "333",
            "222",
            "111",
            "000"
        };

        int n = num.size();
        string ans = "";

        for(int j = 0; j < match.size(); j++){
            if(num.find(match[j]) != string::npos){
                ans = match[j];
                break;
            }
        }
        return ans;
    }
};