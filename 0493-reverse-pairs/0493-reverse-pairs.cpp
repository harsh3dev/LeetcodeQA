class Solution {
private:
    int countPairs(vector<int> &nums, int low, int mid, int high){
        int count = 0;
        int j = mid+1;
        for(int i = low; i <= mid; i++){
            while(j <= high && (1LL * nums[i]) > (1LL * nums[j] * 2)){
                j++;
            }

            count += j - (mid + 1);
        }

        return count;
    }
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int i = low, j = mid+1;
        while(i <= mid && j <= high){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= high){
            temp.push_back(nums[j++]);
        }

        for(int i = 0; i < temp.size(); i++){
            nums[low + i] = temp[i];
        }
    }
    int mergeSort(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low >= high){
            return cnt;
        }

        int mid = low + (high - low)/2;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid+1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};