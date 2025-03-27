class Solution {
private:
    void dfs(vector<int>& edges, int node, vector<int>& pathvis, vector<int>& vis, vector<int>& count){
        if(node != -1){
            vis[node] = 1;
            pathvis[node] = 1;
            int adj = edges[node];

            if(adj != -1 && vis[adj] == 0){
                count[adj] = count[node] + 1;
                dfs(edges, adj, pathvis, vis, count);
            } else if(adj != -1 && pathvis[adj] == 1){
                length = max(length, count[node] - count[adj] + 1);
            }

            pathvis[node] = 0;
        }
    }
public:
    int length = -1;
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> count(n, 1);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfs(edges, i, pathvis, vis, count);
            }
        }

        return length;
    }
};