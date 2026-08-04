class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }

        int start = *s.begin();
        int end = *s.rbegin();
        vector<int> res;
        for(int i = start; i <= end; i++) {
            if(s.find(i) == s.end()){
                res.push_back(i);
            }
        }

        return res;
    }
};