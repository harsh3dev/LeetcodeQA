class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pll;
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        int src = 0;
        int dst = n-1;
        vector<vector<pll>> adj(n);

        for(auto& it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<ll> res(n, LLONG_MAX), ways(n,0);
        res[src]=0;
        ways[src]=1;
        set<pair<ll, int>> st;
        st.insert({0LL, src});
        
        while(!st.empty()){
            auto it = *st.begin();
            st.erase(it);

            ll currtime = it.first;
            ll node = it.second;

            for(auto& nei:adj[node]){
                int nextnode = nei.first;
                ll cost = nei.second;

                ll newtime = currtime + cost;

                if(newtime < res[nextnode]){
                    res[nextnode] = newtime;
                    st.insert({newtime, nextnode});
                    ways[nextnode] = ways[node];
                } else if(newtime == res[nextnode]){
                    ways[nextnode] = (ways[nextnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }   
};