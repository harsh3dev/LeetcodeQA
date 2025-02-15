class Solution {
private:
    bool getSum(string str, int num, int i, int sum, vector<vector<int>>& t) {
        if (i >= str.length()) {
            return sum == num;
        }

        if (sum > num) {
            return false;
        }

        if(t[i][sum] != -1){
            return t[i][sum];
        }

        bool possible = false;
        for (int j = i; j < str.length(); j++) {
            string sub = str.substr(i, j - i + 1);
            int val = stoi(sub);
            possible = possible || getSum(str, num, j + 1, sum + val, t);
            if (possible == true) {
                return true;
            }
        }

        return t[i][sum] = possible;
    }

public:
    int punishmentNumber(int n) {

        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            int multiplication = i * i;
            vector<vector<int>> t(to_string(multiplication).length(), vector<int>(i+1, -1));
            if (getSum(to_string(multiplication), i, 0, 0, t)) {
                totalSum += multiplication;
            }
        }

        return totalSum;
    }
};

// first take all the nums from 1 to n
// for each num check if its valid or not
// for a num there will be multiple combinations of substrings
// we have to check for all the combinations
// base case will be if a combination the sum > num
// then we return false else we return true
// to calculate the sum, we get the initial sum
// then we add the next number which comes from i to j
// if that is greater we return false
// else we continue to add more
// then we increment i and j
// if after adding we get more we return false we get same then we return true
// if we get less we return false