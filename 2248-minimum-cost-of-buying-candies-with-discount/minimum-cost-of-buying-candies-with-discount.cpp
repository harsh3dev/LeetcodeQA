class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int ans = 0;
        int c=0;
        for(int i = 0; i<cost.size(); i++){
            if(c<2){
                ans+=cost[i];
                c++;
            } else c=0;
        }
        return ans;
    }
};