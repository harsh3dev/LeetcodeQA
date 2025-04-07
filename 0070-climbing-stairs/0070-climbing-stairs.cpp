class Solution {
public:
    int climbStairs(int n) {
        vector<int> m(n + 1, -1);
        if (n <= 3)
            return n;
        m[0] = 0;
        m[1] = 1;
        m[2] = 2;

        for (int i = 3; i <= n; i++) {
            m[i] = m[i - 1] + m[i - 2];
        }
        return m[n];
    }
};