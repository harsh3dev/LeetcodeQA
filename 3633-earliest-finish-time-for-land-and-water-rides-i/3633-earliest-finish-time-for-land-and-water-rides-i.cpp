class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int landTime = landStartTime[i] + landDuration[i];
                int landWater = max(landTime, waterStartTime[j]) + waterDuration[j];

                ans = min(ans, landWater);

                int waterTime = waterStartTime[j] + waterDuration[j];
                int waterLand = max(waterTime, landStartTime[i]) + landDuration[i];

                ans = min(ans, waterLand);
            }
        }

        return ans;
    }
};