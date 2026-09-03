class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // vector<int> nums;
        int m = matrix.size();
        int n = matrix[0].size();
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         nums.push_back(matrix[i][j]);
        //     }
        // }
        int s = m*n;
        int l = 0, r = s - 1;
        while(l <= r && r < s){
            int mid = l + (r-l) / 2;
            if(target == matrix[mid/n][mid%n]) {
                return true;
            } else if (target > matrix[mid/n][mid%n]){
                l = mid+1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};

// 1 3 5 7 10 11 16 20 23 30 34 60