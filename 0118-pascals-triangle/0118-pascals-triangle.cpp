class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        arr.push_back({1});
        for(int i = 1; i < numRows; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < i; j++){
                row.push_back(arr[i-1][j] + arr[i-1][j-1]);
            }
            row.push_back(1);
            arr.push_back(row);
        }

        return arr;
    }
};