class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }

        freeTime.push_back(eventTime - endTime[endTime.size() - 1]);

        int n = freeTime.size();

        vector<int> maxRFre(n, 0);
        vector<int> maxLFre(n, 0);

        for(int i = n-2; i >= 0; i--){
            maxRFre[i] = max(maxRFre[i+1], freeTime[i+1]);
        }

        for(int i = 1; i < n; i++){
            maxLFre[i] = max(maxLFre[i-1], freeTime[i-1]);
        }

        int res = 0;

        for(int i = 1; i < n; i++){
            int prt = endTime[i-1] - startTime[i-1];
            if(prt <= max(maxRFre[i], maxLFre[i-1])){
                res = max(res, freeTime[i-1] + prt + freeTime[i]);
            }

            res = max(freeTime[i] + freeTime[i-1], res);
        }
        return res;
    }
};