class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for(auto& reservedSeat: reservedSeats){
            int i = reservedSeat[0];
            int j = reservedSeat[1];

            mp[i].insert(j);
        }

        int res = (n - mp.size()) * 2;
        for(auto& [row, rseat]: mp){
            auto isAvailable = [&](int seat) {
                return rseat.find(seat) == rseat.end();
            };
            bool grA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool grB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool grC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);
            if(grA && grC) {
                res += 2;
            } else if (grA || grB || grC){
                res += 1;
            }
        }

        return res;
    }
};