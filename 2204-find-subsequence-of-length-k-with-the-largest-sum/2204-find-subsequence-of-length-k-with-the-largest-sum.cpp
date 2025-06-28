class Solution {
private:
    struct comp {
        constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
            const noexcept
        {
            return a.second > b.second;
        }
    };

public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> p1;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        for(int i = 0; i < k; i++){
            auto it = pq.top();
            int num = it.first;
            int idx = it.second;
            pq.pop();
            p1.push({num, idx});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            int num = p1.top().first;
            p1.pop();
            ans.push_back(num);
        }

        return ans;
    }
};