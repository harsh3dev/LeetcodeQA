class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n+1;

        deque<int> q;

        for(int i = 0; i < n; i++){
            if(i > 0){
                nums[i] += nums[i-1];
            }
            if(nums[i] >= k){
                ans = min(ans, i+1);
            }
            while(q.size() > 0 && nums[i] - nums[q.front()] >= k){
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while(q.size() > 0 && nums[i] < nums[q.back()]){
                q.pop_back();
            }

            q.push_back(i);
        }

        return ans <= n ? ans : -1;
    }
};