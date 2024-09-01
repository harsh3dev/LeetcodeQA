class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        vector<int> ans;

        for(int u = 0; u < k; u++){
            auto res = pq.top();
            ans.push_back(res.second);
            pq.pop();
        }

        return ans;
    }
};