class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; 
        if (N < 0){
            N = -N;
            x = 1/x;
        }

        double r = 1;
        while(N > 0){
            if(N%2 == 1){
                r *= x;
            }

            x *= x;
            N /= 2;
        }

        return r;
    }
};