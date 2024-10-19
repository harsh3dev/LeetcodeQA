class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        int n1 = nums1.size();
        int n = nums2.size();

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums2[i]] = i;
        }

        for(int i = 0; i < n1; i++){
            int idx = mp[nums1[i]];
            bool found = false;
            for (int j = idx + 1; j < n; j++){
                if(nums2[j]>nums1[i]){
                    ans.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }

            if(!found) ans.push_back(-1);
        }

        return ans;
    }
};

/*
* store the elem of nums2 and their corres ind in nums2 in a map
* iterate through elem of nums1 then we know the index of each elem
* iterate in the array from index to n-1 to find the next greater elem
* then add the next greater elem in the ans array
*/