class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }

        for(const auto& m:mp){
            pq.push({m.first, m.second});
        }

        while(!pq.empty()){
            pair<int, int> t = pq.top();
            pq.pop();
            if(t.first == t.second) return t.first;
        }

        return -1;
    }
};