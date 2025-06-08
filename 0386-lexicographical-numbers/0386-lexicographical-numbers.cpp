class Solution {
private:
    void solve(vector<int>& res, int i, int n){
        if(res.size() == n){
            return;
        }
        if(i > n) return;
        res.push_back(i);
        for(int k = 0; k <= 9; k++){
            int nextnum = i*10 + k;

            if(nextnum <= n){
                solve(res, nextnum, n);
            } else break;
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i <= 9; i++){
            solve(res, i, n);
        }
        return res;
    }
};