class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int> st;
        vector<int> ans(boxes.length(), 0);

        for(int i = 0; i < boxes.length(); i++){
            if(boxes[i]=='1') st.insert(i);
        }

        for(int i = 0; i < boxes.length(); i++){
            for(const auto& j:st){
                ans[i] += abs(j-i);
            }
        }

        return ans;
    }
};