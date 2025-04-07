class Solution {
public:
    int m[46];
    int solve(int n) {
        // base cases
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (m[n] != -1) {
            return m[n];
        }
        int step1 = solve(n - 1);
        int step2 = solve(n - 2);

        return m[n] = step1 + step2;
    }

    int climbStairs(int n) {
        memset(m, -1, sizeof(m));
        return solve(n);
    }
};