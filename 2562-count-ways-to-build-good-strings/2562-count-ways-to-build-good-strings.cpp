class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1000000007;
        vector<int> dp(high+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= high; i++){
            if(i>=zero){
                dp[i] += dp[i-zero];
            }
            if(i>=one){
                dp[i] += dp[i-one];
            }

            dp[i] %= mod;
        }

        int count = 0;
        for(int i = low; i <= high; i++){
            count += dp[i];
            count %= mod;
        }

        return count;
    }
};