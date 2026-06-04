class Solution {
private:
    int count(int num){
        string n = to_string(num);
        int res = 0;

        for(int i = 1; i < n.size() - 1; i++){
            bool isPeak = n[i] > n[i-1] && n[i] > n[i+1];
            bool isVal = n[i] < n[i-1] && n[i] < n[i+1];

            if(isPeak || isVal){
                res++;
            }
        }

        return res;
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(int i = num1; i <= num2; i++){
            ans += count(i);
        }

        return ans;
    }
};