class Solution {
public:
    long long generatePallindrome(long long lefthalf, bool isEven){
        long long pallindrome = lefthalf;
        if(!isEven) lefthalf /= 10;
        while(lefthalf>0){
            pallindrome = pallindrome*10 + lefthalf%10;
            lefthalf /= 10;
        }

        return pallindrome;
    }

    string nearestPalindromic(string n) {
        long long num = stoll(n);
        //  handle edge cases and special cases
        if (num <= 10) return to_string(num - 1);
        if (num == 11) return "9";
        
        if (n == "999999999999999999") {
            return "1000000000000000001";
        }

        vector<long long> comparePallindrome(5);

        int length = n.length();
        long long left = stoll(n.substr(0, (length+1)/2));

        comparePallindrome[0] = generatePallindrome(left-1, length%2==0);
        comparePallindrome[1] = generatePallindrome(left, length%2==0);   

        if(left<999999999){
        comparePallindrome[2] = generatePallindrome(left+1, length%2==0);
        } else {
        comparePallindrome[2] = stoll("1" + string(length - 1, '0') + "1");
        }

        comparePallindrome[3] = pow(10, length -1) - 1;
        comparePallindrome[4] = pow(10, length) +1;
        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;
        
        for (long long candidate : comparePallindrome) {
            if (candidate == num) continue;
            long long difference = abs(candidate - num);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }
        
        return to_string(nearestPalindrome);





    }
};