class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        int ans = 1;
        int el = INT_MIN;
        int curr = 0;

        for(auto it:st){
            if(st.find(it - 1) == st.end()){
                curr = 1;
                el = it;
                while(st.find(el+1) != st.end()){
                    curr++;
                    el++;
                }
                ans = max(ans, curr);
            }
        }

        return ans;
    }
};