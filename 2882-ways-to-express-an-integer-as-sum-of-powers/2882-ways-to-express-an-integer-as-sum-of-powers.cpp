class Solution {
    int n, x;
    vector<vector<int>> t;
    int mod = 1e9+7;

    int dp(vector<int>& limit, int i, int sum) {
        if (sum == n) return 1;
        if (i < 0 || sum > n) return 0;

        if (t[i][sum] != -1) return t[i][sum];

        long long ans = 0;
        // Option 1: skip current power
        ans += dp(limit, i - 1, sum);
        // Option 2: take current power
        ans += dp(limit, i - 1, sum + limit[i]);

        return t[i][sum] = ans % mod;
    }

public:
    int numberOfWays(int num, int p) {
        n = num;
        x = p;

        vector<int> limit;
        int i = 1;
        int power = pow(i, x);
        while (power <= n) {
            limit.push_back(power);
            power = pow(++i, x);
        }

        t.assign(limit.size(), vector<int>(n + 1, -1));

        return dp(limit, limit.size() - 1, 0);
    }
};
