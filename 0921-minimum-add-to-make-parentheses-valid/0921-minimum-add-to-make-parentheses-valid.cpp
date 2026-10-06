class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push('(');
            }
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                } else {
                   count++; 
                }
            }
        }

        if(!st.empty()){
            count += st.size();
        }

        return count;
    }
};