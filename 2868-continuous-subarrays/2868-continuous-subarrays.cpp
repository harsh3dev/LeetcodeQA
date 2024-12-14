class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int left = 0, right = 0;
        map<int, int> mp;

        while(right<n){
            // add the elem to map
            mp[nums[right]]++;
            
            while(mp.rbegin()->first - mp.begin()->first > 2){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }

            count += right - left + 1;
            right++;
        }
        
        return count;
    }
};

// Brute Force thinking
// make 2 for loops i and j
// check if |arr[j] - arr[i]| > 3
// then break else count++
// turns out to be WRONG because even if any element diff is invalid then it cant be evaluated

// another idea
// implement the above approach using 2 pointer but check for the invalid
// maintain a max and min elem within the window and if it exeeds the diff of 2
// then shrink the window
// shrink untill the window is valid --> while(max-min>2)
// WE HAVE TO CHANGE THE WAY OF COUNTING THE SUBARRAY
// number of subarrays will be right - left + 1
