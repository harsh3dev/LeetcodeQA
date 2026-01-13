class Solution {
private:
    bool check(long double y, vector<vector<int>>& squares, long double totalArea){
        long double part2 = 0;

        for (auto &i : squares) {

            long double Y = i[1];
            long double side =i[2];

            if (Y >= y) {

            } else {
                long double finalY = Y + i[2];

                if (finalY <= y) {
                    part2 += side*side;
                } else {

                    part2 += (y - Y) *side;
                }
            }
        }
        return part2 < totalArea / 2;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double l = 0;
        long double h = 0;

        long double totalArea = 0;

        for(auto& i: squares){
            int y = i[1];
            long double side = i[2];

            totalArea += side*side;
            h = max(h, y+side);
        }
        int count = 0;
        while(h - l >= 1e-6 && count < 60){
            long double mid = (l + h)/2;
            count++;

            if(check(mid, squares, totalArea)){
                l = mid;
            } else {
                h = mid;
            }
        }

        return l;
    }
};