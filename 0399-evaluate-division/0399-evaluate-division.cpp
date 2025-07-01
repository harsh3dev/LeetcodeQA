class Solution {
unordered_map<string, vector<pair<string, double>>> mp;
unordered_map<string, bool> vis;
double calc;
private:
    bool dfs(string src, string dst, double val){
        // if the map doesnt have that node, return -1.0
        // if both num, den are same return 1.0

        // mark the node(num) vis
        // for every neighbour of curr node, we will visit
        // we will again check the base cases, and when the src dst eq we return
        // the main thing is that we need to maintain the final den as the dest
        // and not the next nei; it will become src
        if(mp.find(src) == mp.end() || mp.find(dst) == mp.end()){
            return false;
        }

        if(src == dst && mp.find(src) != mp.end()){
            calc = val;
            return true;
        }

        bool found = false;

        vis[src] = 1;
        for(int i = 0; i < mp[src].size(); i++){
            if(!vis[mp[src][i].first]){
                found = dfs(mp[src][i].first, dst, val * mp[src][i].second);
                if(found) break;
            }
        }

        vis[src] = 0;

        return found;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // main idea is that for every  a/b = x
        // we can have nodes a and b whose weight from a -> b = x
        // and weight b -> a =  1/x
        // for that we need weighted directed graph
        vector<double> ans(queries.size());
        for(int i = 0; i < equations.size(); i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            vis[equations[i][0]] = 0;
            vis[equations[i][1]] = 0;
        }

        for(int i = 0; i < queries.size(); i++){
            bool is = dfs(queries[i][0], queries[i][1], 1);
            if(is) ans[i] = calc;
            else ans[i] = -1;
        }

        return ans;
    }
};