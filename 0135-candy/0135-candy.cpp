class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;

        vector<int> cand(n, 1);

        for(int i = 0; i < n-1; i++){
            if(ratings[i] < ratings[i+1]){
                cand[i+1] = cand[i] + 1;
            }
        }

        for(int i = n-1; i > 0; i--){
            if(ratings[i] < ratings[i-1]){
                cand[i-1] = max(cand[i-1], cand[i] + 1);
            }
            ans += cand[i];
        }
        
        return ans + cand[0];
    }
};