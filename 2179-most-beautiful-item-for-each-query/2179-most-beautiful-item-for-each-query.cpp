class Solution {
public:
    int custombs(int key, vector<vector<int>>& items){
        int left = 0;
        int right = items.size() - 1;
        int mid;

        int maxvalue = 0;

        while(left<=right){
            mid = left + (right-left)/2;

            if(items[mid][0] > key){
                right = mid-1;
            } else{
                left = mid+1;
                maxvalue = max(items[mid][1], maxvalue);
            }
        }

        return maxvalue;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        sort(items.begin(), items.end());

        int maxtill = items[0][1];

        for(int i = 1; i < n; i++){
            maxtill = max(maxtill, items[i][1]);
            items[i][1] = maxtill;
        }

        vector<int> ans(m);

        for(int i = 0; i < m; i++){
            int currkey = queries[i];
            ans[i] = custombs(currkey, items);
        }

        return ans;
    }
};