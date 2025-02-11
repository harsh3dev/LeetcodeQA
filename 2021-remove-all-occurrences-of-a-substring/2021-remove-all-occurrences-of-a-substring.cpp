class Solution {
private:
    bool checkMatch(stack<char>& stk, string& part, int k){
        string newstr = "";
        stack<char> stk1 = stk;

        for(int i = k-1; i >= 0; i--){
            if(stk1.top() != part[i]) return false;
            stk1.pop();
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int n = s.size();
        int k = part.size();
        for(int i = 0; i < n; i++){
            stk.push(s[i]);
            if(stk.size() >= k && checkMatch(stk, part, k)){
                for(int j = 0; j < k; j++){
                    stk.pop();
                }
            }
        }
        
        string result = "";
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};