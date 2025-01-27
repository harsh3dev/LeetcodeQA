class Solution {
private:
    bool checkReach(int a, int b, vector<vector<int>>& adjlist){
        vector<bool> visited(adjlist.size(), false);
        stack<int> stk;
        stk.push(a);

        while(!stk.empty()){
            int curr = stk.top();
            stk.pop();
            if(curr == b) return true;
            if(visited[curr] != true){
                visited[curr] = true;
                for(const auto& elem:adjlist[curr]){
                    if(!visited[elem]){
                        stk.push(elem);
                    }
                }
            }
        }

        return false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n = queries.size();

        vector<vector<int>> adjlist(numCourses);
        vector<bool> ans;

        for(const auto& edge:prerequisites){
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_back(v);
        }

        for(const auto& num:queries){
            int a = num[0];
            int b = num[1];
            int result = checkReach(a, b, adjlist);
            ans.push_back(result);
        }

        return ans;
    }
};

// [1, 2] [2, 3] [1, 0]
// [1, 3] [2, 0] [2, 3] [0, 3]
// true, false, true, false