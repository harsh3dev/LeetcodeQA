class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minnum = INT_MAX;
        int maxp = INT_MIN;

        for(int i = 0; i < prices.size(); i++){
            minnum = min(minnum, prices[i]);
            maxp = max(maxp, prices[i] - minnum);
        }

        return maxp;
    }
};