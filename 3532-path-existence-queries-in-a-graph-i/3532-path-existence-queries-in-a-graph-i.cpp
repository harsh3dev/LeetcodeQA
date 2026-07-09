class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV)
            return;

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        }
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res(queries.size(), 0);
        parent.resize(n);
        rank.assign(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(int i = 0; i < n-1; i++){
            int x = nums[i];
            int y = nums[i+1];
            int diff = y - x;
            if(diff <= maxDiff){
                unionSet(i, i+1);
            }
        }

        for(int i = 0; i < queries.size(); i++){
            int p1 = find(queries[i][0]);
            int p2 = find(queries[i][1]);

            if (p1 == p2){
                res[i] = 1;
            }
        }

        return res;
    }
};

// first make rank of every node 0, and parent = self
// then do union if condition satisfies
// then for each pair find if parent is same