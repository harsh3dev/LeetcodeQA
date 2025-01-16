class Solution {
private:
int calculateXOR(const std::vector<int>& arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;
    }
    return result;
}

public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n%2 == 0 && m%2 == 0){
            return 0;
        }
        int num1xor = calculateXOR(nums1);
        int num2xor = calculateXOR(nums2);

        if(n%2 == 0 && m%2 != 0){
            return num1xor;
        } else if (n%2 != 0 && m%2 != 0){
            vector<int> vec(2, 0);
            vec[0] = num1xor;
            vec[1] = num2xor;
            return calculateXOR(vec);
        }
        else {
            return num2xor;
        }
    }
};

// case: even even --> ans = 0 
// case: even odd  --> 2ndxor + nums1[i] ans = xor: nums1
// case: odd odd   --> ans = xor:nums1 xor xor:nums2
// case: odd even  --> ans = xor:nums2