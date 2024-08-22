class Solution {
public:
    string addStrings(string num1, string num2) {
        // traverse from back of each string and add each element along with the carry
        // initially the carry would be empty
        // calculate the last and first index of the sum
        // i.e the remainder and the carry
        // then append the remainder to the new string and calculate the carry
        // the carry would either be 1 or 0 depending upon whether the sum is > 10 or not
        // then reverse the string and return it

        int i = num1.length()-1, j = num2.length()-1, carry = 0, rem = 0;
        string result = "";
        while(i>=0 && j>=0){
            int n1 = (num1[i] - '0');
            int n2 = (num2[j] - '0');
            int ans = n1 + n2 + carry;
            rem = ans%10;
            carry = ans/10;
            result += (rem + '0');
            i--; j--;
        }

        while(i>=0){
            int sum = (num1[i] - '0') + carry;
            result += (sum%10) + '0';
            carry = sum/10;
            i--;
        }

        while(j>=0){
            int sum = (num2[j] - '0') + carry;
            result += (sum%10) + '0';
            carry = sum/10;
            j--;
        }

        if(carry) result += '1';

        reverse(result.begin(), result.end());

        return result;

    }
};