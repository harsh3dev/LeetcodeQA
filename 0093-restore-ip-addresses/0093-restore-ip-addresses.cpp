class Solution {
    int n;
    vector<string> res;
private:
    bool isValid(string a){
        if(a.size() > 1 && a[0] == '0') return false;
        if(0 > stoi(a) || stoi(a) > 255) return false;
        return true;
    }
    void solve(int i, string s, int parts, string curr){
        // base case
        if(i == n && parts == 4){
            curr.pop_back();
            res.push_back(curr);
            return;
        }

        if(i+1 <= n)
            solve(i+1, s, parts+1, curr + s.substr(i, 1) + ".");

        if(i+2 <= n && isValid(s.substr(i, 2)))
            solve(i+2, s, parts+1, curr + s.substr(i, 2) + ".");

        if(i+3 <= n && isValid(s.substr(i, 3)))
            solve(i+3, s, parts+1, curr + s.substr(i, 3) + ".");

    }
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        if(n>12) return {};
        // track the parts and pass the initial string
        int parts = 0;
        string curr = "";

        solve(0, s, parts, curr);

        return res;
    }
};
// 25525511135