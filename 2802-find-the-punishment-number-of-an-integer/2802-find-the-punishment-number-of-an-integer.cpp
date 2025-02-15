class Solution {
private:
    bool getSum(string str, int num, int i, int sum){
        if (i >= str.length()){
            return sum == num;
        }

        if (sum > num){
            return false;
        }

        bool possible = false;
        for(int j = i; j < str.length(); j++){
            string sub = str.substr(i, j - i + 1);
            int val = stoi(sub);
            possible = possible || getSum(str, num, j+1, sum+val);
            if (possible == true){
                return true;
            }
        }

        return possible;
    }

public:
    int punishmentNumber(int n) {

        int totalSum = 0;
        
        for(int i = 1; i <= n; i++){
            int multiplication = i * i;
            if (getSum(to_string(multiplication), i, 0, 0)){
                totalSum += multiplication;
            }
        }

        return totalSum;
    }
};
