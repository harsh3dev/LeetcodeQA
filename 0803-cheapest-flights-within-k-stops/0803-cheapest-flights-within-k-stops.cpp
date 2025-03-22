class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n + 1);
        for(auto& i:flights){
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        set<pair<int, pair<int, int>>> st; //stops, cost, node
        st.insert({0, {0, src}});
        while(!st.empty()){
            auto curr = *st.begin();
            st.erase(curr);
            int stop = curr.first;
            int cost = curr.second.first;
            int node = curr.second.second;

            if(stop > k) continue;
            for(auto& it:adj[node]){
                int newnode = it[0];
                int newcost = it[1];

                if(cost+newcost<dist[newnode] && stop<=k){
                    dist[newnode] = cost + newcost;
                    st.insert({stop+1,{cost+newcost,newnode}});
                }
            }            
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};