class Solution {
private:
    int solve(int curr, int n){
        if(curr > n) {
            return 0;
        }

        if (curr == n){
            return 1;
        }

        if (m[curr] != -1) return m[curr];

        int two = solve(curr + 2, n);
        int one = solve(curr + 1, n);

        return m[curr] = two + one;
    }
public:
    int m[46];
    int climbStairs(int n) {
        int curr = 0;
        for(int i = 0; i < 46; i++){
            m[i] = -1;
        }
        return solve(curr, n);
    }
};

/*
1 + 1 + 1 + 1 + 1
1 + 1 + 1 + 2
1 + 1 + 2 + 1
1 + 2 + 1 + 1
2 + 1 + 1 + 1
1 + 2 + 2
2 + 1 + 2
2 + 2 + 1
*/