class Solution {
private:
    long long sol(string str, int& limit, string& s){
        if(str.size() < s.size()) return 0;
        
        int remlen = str.size() - s.size();
        // take the last digits of str which will be fixed
        string laststr = str.substr(remlen); // e.g. "6000" & "00" --> 4 - 2 = 2 --> "00"
        long long count = 0;
        for(int i = 0; i < remlen; i++){
            int digit = str[i] - '0';
            if(digit <= limit){
                count += digit * pow(limit+1, remlen-(i+1));
                // digit = num of possibilities for that place 
            } else{
                count += pow(limit+1, remlen-i);
                return count;
            }
        }

        if(laststr >= s) count++;

        return count;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string initialNum = to_string(start-1);
        string finalNum = to_string(finish);     

        return sol(finalNum, limit, s) - sol(initialNum, limit, s);
    }
};