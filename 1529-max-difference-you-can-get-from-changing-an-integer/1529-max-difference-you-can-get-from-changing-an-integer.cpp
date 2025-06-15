class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        char maxnum = '9';
        char minnum = '1';
        for (char ch : n) {
            if (ch - '0' < 9) {
                maxnum = ch;
                break;
            }
        }

        for (char ch : n) {
            if (ch - '0' > 1) {
                minnum = ch;
                break;
            }
        }

        string maxint = n;
        string minint = n;

        for (int i = 0; i < n.size(); i++) {
            if (maxint[i] == maxnum) {
                maxint[i] = '9';
            }
        }
        for (int i = 0; i < n.size(); i++) {
            if (n[0] == '1' && minnum != '1') {
                if (i > 0) {
                    if (minint[i] == minnum) {
                        minint[i] = '0';
                    }
                }
            } else {
                if (minint[i] == minnum) {
                    minint[i] = '1';
                }
            }
        }

        return stoi(maxint) - stoi(minint);
    }
};

// 111