class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minEl = INT_MAX;
        int count = 0;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += abs(matrix[i][j]);
                minEl = min(minEl, abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    count++;
                } 
            }
        }
        
        if(count%2!=0) sum = sum - 2*minEl;
        
        return sum;
    }
};

// calculate absolute sum of the matrix
// number of -ve numbers
// if -ve numbers are odd then final ans will be absolute sum - 2 * min elem
// if -ve numbers are even then return the absolute sum 