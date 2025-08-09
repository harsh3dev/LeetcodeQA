class Solution {
    int n;
    vector<vector<int>> t;
private:
    int child2(vector<vector<int>>& fruits, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= n){
            return 0;
        }

        if(i == n-1 && j == n-1) return 0;

        if(i >= j){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int a1 = fruits[i][j] + child2(fruits, i+1, j-1);
        int a2 = fruits[i][j] + child2(fruits, i+1, j);
        int a3 = fruits[i][j] + child2(fruits, i+1, j+1);
        return t[i][j] = max({a1, a2, a3});
    }

    int child3(vector<vector<int>>& fruits, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= n){
            return 0;
        }

        if(i == n-1 && j == n-1) return 0;

        if(i <= j){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int a1 = fruits[i][j] + child3(fruits, i-1, j+1);
        int a2 = fruits[i][j] + child3(fruits, i, j+1);
        int a3 = fruits[i][j] + child3(fruits, i+1, j+1);
        return t[i][j] = max({a1, a2, a3});
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        t.assign(n, vector<int>(n, -1));
        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += fruits[i][i];
            fruits[i][i] = 0;
            t[i][i] = 0;
        }
        // calculate dp for 2 children
        // they will also have 3 possibilities so have to take the max of each;
        // collect from child2
        ans += child2(fruits, 0, n-1);
        // collect from child3
        ans += child3(fruits, n-1, 0);
        return ans;
    }
};