class Solution {
public:
    int findClosest(int x, int y, int z) {
        int res = 0;
        if(abs(x-z) < abs(y-z)) res = 1;
        else if(abs(x-z) > abs(y-z)) res = 2;
        
            return res;
    }
};