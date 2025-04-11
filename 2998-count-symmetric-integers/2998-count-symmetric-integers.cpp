class Solution {
private:
    bool isSymetric(int n){
        
        string num = to_string(n);
        if(num.size()%2 != 0) return false;

        int num1 = stoi(num.substr(0, num.size()/2));
        int num2 = stoi(num.substr(num.size()/2));      

        int sum1 = 0, sum2 = 0;

        while(num1>0){
            int d = num1%10;
            sum1 += d;
            num1 /= 10;
        }

        while(num2>0){
            int d = num2%10;
            sum2 += d;
            num2 /= 10;
        }
        return sum1 == sum2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++){
            if(isSymetric(i)) count++;
        }

        return count;
    }
};