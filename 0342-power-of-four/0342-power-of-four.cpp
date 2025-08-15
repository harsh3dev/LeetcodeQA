class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if(n < 2) return true;
        int ones = __builtin_popcount(n);
        int total = 0;
        int temp = n;
        while(temp>0){
            total++;
            temp = temp >> 1;
        }

        int zero = total - ones;

        cout << "ones " << ones << endl;
        cout << "zeroes" << zero << endl;

        if(ones == 1 && pow(4, zero/2) == n) return true;
        return false;
    }
};