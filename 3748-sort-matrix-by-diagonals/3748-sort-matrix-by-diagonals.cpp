class Solution {
private:
    void process(int r, int c, vector<vector<int>>& grid, bool asc){
        vector<int> diagonal;
        int i = r, j = c;
        while(i < grid.size() && j < grid.size()){
            diagonal.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc){
            sort(diagonal.begin(), diagonal.end());
        } else{
            sort(diagonal.rbegin(), diagonal.rend());
        }

        for(int k = 0; k < diagonal.size(); k++){
            if(r < grid.size() && c < grid.size())
                grid[r++][c++] = diagonal[k];
        }
    }
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // left down
        for(int r = 0; r < n; r++){
            process(r,0,grid, false);
        }
        // right up
        for(int c = 1; c < n; c++){
            process(0,c,grid, true);
        }

        return grid;
    }
};