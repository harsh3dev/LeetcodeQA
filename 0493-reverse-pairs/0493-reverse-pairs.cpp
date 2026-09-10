class Solution {
private:
    int countEl(vector<int>& nums, int low, int mid, int high){
        int count = 0;
        int t = mid+1;
        for(int i = low; i <= mid; i++){
            while(t <= high && ((1LL * nums[i]) > (1LL * 2 * nums[t]))){
                t++;
            }
            count += t - (mid+1);
        }
        return count;
    }
    void merge(vector<int>& nums, int low, int mid, int high){
        int i = low;
        int j = mid+1;

        vector<int> temp;

        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = 0; i < temp.size(); i++){
            nums[low + i] = temp[i];
        }
    }
    int mergeSort(vector<int>& nums, int low, int high){
        if(low >= high){
            return 0;
        }

        int count = 0;

        int mid = low + (high - low)/2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        count += countEl(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};