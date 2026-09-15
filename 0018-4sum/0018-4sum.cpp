class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 4) return ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1])continue;
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }

                        while(l > k && nums[l+1] == nums[l]){
                            l--;
                        }
                    }

                    else if(sum < target){
                        k++;
                    } else l--;
                }
            }
        }

        return ans;
    }
};

// run 2 loops i and j
// i start from 0, j start from i+1
// have 2 pointers k, l
// k will be from j+1, l = n-1
// now check if i+j+k+l == target
// ans.push_back(i,j,k,l), move k++, l-- while skipping duplicates
// if sum < target means move k to right until prev += curr
// if sum > target means move l to left until prev != next

// only works in sorted array, so sort the array