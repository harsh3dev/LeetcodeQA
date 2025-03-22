class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int el = q.front();
            q.pop();

            for(auto& node:graph[el]){
                if(color[node] == -1){
                    color[node] = !color[el];
                    q.push(node);
                }

                if(color[node] == color[el]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(check(i, graph, color) == false){
                    return false;
                }
            }
        }

        return true;
    }
};