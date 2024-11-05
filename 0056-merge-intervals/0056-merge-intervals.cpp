class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for(auto arr : intervals){
            if(merged.empty() || merged.back()[1] < arr[0]){
                merged.push_back(arr);
            } else{
                merged.back()[1] = max(merged.back()[1], arr[1]);
            }
        }

        return merged;
    }
};

/*
* first sort the array
* create new array
* if thats empty or last elem end < new elem start then insert
* else prevend = max(prevend, currend)
*/