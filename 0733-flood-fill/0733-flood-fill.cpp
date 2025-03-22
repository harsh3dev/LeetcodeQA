class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& newvec, vector<vector<int>>& image, int inicolor, int newcolor){
        int dirR[] = {-1, 0, 1, 0};
        int dirC[] = {0, -1, 0, 1};
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++){
            newvec[sr][sc] = newcolor;
            int row = sr + dirR[i];
            int col = sc + dirC[i];
            if(row >= 0 && row < n && col >= 0 && col <= m && image[row][col] == inicolor && newvec[row][col] != newcolor){
                dfs(row, col, newvec, image, inicolor, newcolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        int newcolor = color;

        vector<vector<int>>& newvec = image;
        dfs(sr, sc, newvec, image, inicolor, newcolor);
        return newvec;
    } 
};