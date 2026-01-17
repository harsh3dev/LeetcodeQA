class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxW = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int w = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);

                maxW = max(maxW, min(w, h));
            }
        }

        return 1LL * maxW * maxW;
    }
};

// for every 2 rectangle we will calculate both x and y overlapping
// if rect dont overlap there will be neg value
// we always want to take the max length
// max length can be uneven for square as it might not create a square
// so we will take min of the overlapping width and height
// this way we will maintain an overall max length
// finally return the area