class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(begin(target), end(target));
        sort(begin(arr), end(arr));
        for(int u = 0; u < target.size(); u++)
            if(target[u]!=arr[u]) return false;

        return true;
    }
};