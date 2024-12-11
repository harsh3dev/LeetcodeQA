class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> ranges;
        for(int num:nums){
            ranges.push_back({num-k, num+k});
        }

        sort(ranges.begin(), ranges.end());
        int maxbeauty = 0;
        deque<int> dq;

        for(const auto& range:ranges){
            // to check if the dq is not empty, and overlapping
            // if dq.front < range.first
            while(!dq.empty() && dq.front() < range.first){
                dq.pop_front();
            }

            dq.push_back(range.second);

            maxbeauty = max(maxbeauty, (int)dq.size());
        }

        return maxbeauty;
    }
};