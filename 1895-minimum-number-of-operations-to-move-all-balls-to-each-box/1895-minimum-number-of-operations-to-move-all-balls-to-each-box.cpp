class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        int cumm = 0;
        int cummsumm = 0;

        for(int i = 0; i < n; i++){
            ans[i] += cummsumm;
            cumm += boxes[i]=='1'?1:0;
            cummsumm += cumm;
        }
        cumm = 0;
        cummsumm = 0;
        for(int i = n-1; i >= 0; i--){
            ans[i] += cummsumm;
            cumm += boxes[i]=='1'?1:0;
            cummsumm += cumm;
        }

        return ans;
    }
};