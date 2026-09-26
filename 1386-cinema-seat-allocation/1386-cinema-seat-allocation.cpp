class Solution {
private:
    bool check(int seat, unordered_set<int>& st){
        if(st.find(seat) == st.end()){
            return true;
        }
        return false;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for(auto& seat: reservedSeats){
            int i = seat[0];
            int j = seat[1];

            mp[i].insert(j);
        }

        int ans = (n - mp.size()) * 2;
        for(auto& it:mp){
            // grA = 2345, grB = 4567, grC = 6789
            bool grA = check(2, it.second) && check(3, it.second) && check(4, it.second) && check(5, it.second);
            bool grB = check(4, it.second) && check(5, it.second) && check(6, it.second) && check(7, it.second);
            bool grC = check(6, it.second) && check(7, it.second) && check(8, it.second) && check(9, it.second);
            if(grA && grC){
                ans += 2;
            } else if(grA || grB || grC){
                ans += 1;
            }
        }

        return ans;
    }
};