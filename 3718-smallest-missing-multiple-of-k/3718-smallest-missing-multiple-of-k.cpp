class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool missing = true;
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        int i = 1;
        int res = 0;
        int count = 0;
        while(missing){
            count++;
            if(st.find(k*i) == st.end()){
                missing = false;
                res = k*i;
            }
            i++;
        }

        cout << "final count: " << count << endl;

        return res;
    }
};