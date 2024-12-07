class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Binary search bounds
        int left = 1;
        int right = 0;

        for (auto num : nums) {
            right = max(right, num);
        }

        // Perform binary search to find the optimal maxBallsInBag
        while (left < right) {
            int middle = (left + right) / 2;

            // Check if a valid distribution is possible with the current middle
            // value
            if (isPossible(middle, nums, maxOperations)) {
                right = middle;  // If possible, try a smaller value (shift
                                 // right to middle)
            } else {
                left = middle + 1;  // If not possible, try a larger value
                                    // (shift left to middle + 1)
            }
        }

        // Return the smallest possible value for maxBallsInBag
        return left;
    }

private:
    // Helper function to check if a distribution is possible for a given
    // maxBallsInBag
    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOperations) {
        int totalOperations = 0;

        // Iterate through each bag in the array
        for (int num : nums) {
            // Calculate the number of operations needed to split this bag
            int operations = ceil(num / (double)maxBallsInBag) - 1;
            totalOperations += operations;

            // Total operations exceed maxOperations, return false
            if (totalOperations > maxOperations) return false;
        }

        // We can split the balls within the allowed operations, return true
        return true;
    }
};

// to break the max numbers into 2 halves
// how to break?
// 9 can be broken into 8+1, 7+2, 6+3, 4+4
// so max it will be upto nums[i]/4
// sort in the reverse order highest to lowest
// take largest number 