class Solution {
private:
    int solve(vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2) {
        int minfin1 = INT_MAX;
        int n = start1.size();
        for(int i = 0; i < n; i++){
            minfin1 = min(minfin1, start1[i] + dur1[i]);
        }

        int minfin2 = INT_MAX;
        int m = start2.size();
        for(int i = 0; i < m; i++){
            minfin2 = min(minfin2, max(start2[i], minfin1) + dur2[i]);
        }

        return minfin2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(land_water, water_land);
    }
};