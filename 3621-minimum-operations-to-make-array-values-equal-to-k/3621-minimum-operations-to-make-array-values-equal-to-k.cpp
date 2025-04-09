class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        set<int> st;
        for(int i = 0; i < n; i++){
            if(nums[i] < k) return -1;
            st.insert(nums[i]);
        }
        int count = 0;
        
        for (int x : st) {
            if(x > k) count++;
        }

        return count;
    }
};