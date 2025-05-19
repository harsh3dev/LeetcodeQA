class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int ans = INT_MIN;
       int pdt = 1;
       int mul = 1;
       
       int n = nums.size();

       for(int i = 0; i < n; i++){
            if(pdt == 0){
                pdt = 1;
            }
            if(mul == 0){
                mul = 1;
            }

            pdt *= nums[i];
            mul *= nums[n - i - 1];

            ans = max(ans, max(pdt, mul));
       }

       return ans;
    }
};

// we have to find the subarray which will yeild the maximum pdt
// if there are even -ve integers then pdt will be max, else min
// so we have to remove one -ve int if there are odd ones
// so we will calculate the pdt from back and front and whichever is max we will update it
// if 0 is encountered then we have to reset the pdt to 1