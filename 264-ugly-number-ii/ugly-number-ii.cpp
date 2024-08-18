class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyset;
        long curr = 1;
        uglyset.insert(1);
        
        for(int i = 0; i < n; i++){
            curr = *uglyset.begin();
            uglyset.erase(uglyset.begin());
            uglyset.insert(curr*2);
            uglyset.insert(curr*3);
            uglyset.insert(curr*5);
        }

        return static_cast<int>(curr);
    }
};