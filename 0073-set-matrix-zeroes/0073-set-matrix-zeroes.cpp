class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowindex = matrix.size();
        int colindex = matrix[0].size();
        int col0 = 1;
        
        for (int i = 0; i < rowindex; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < colindex; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = rowindex - 1; i >= 0; i--) {
            for (int j = colindex - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};
