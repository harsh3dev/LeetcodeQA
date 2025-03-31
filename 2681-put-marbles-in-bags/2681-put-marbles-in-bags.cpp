class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1) return 0;
        vector<long long> splits;

        for(int i = 0; i < n - 1; i++){
            splits.push_back((long long)(weights[i] + weights[i+1]));
        }

        sort(splits.begin(),  splits.end());

        long long res = 0;

        for (int i = 0; i < k - 1; i++) {
            res += splits[splits.size() - 1 - i];
            res -= splits[i];
        }

        return res;
    }
};