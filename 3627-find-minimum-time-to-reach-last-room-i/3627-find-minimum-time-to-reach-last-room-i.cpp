class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m, -1));
        dis[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
 // {val, {i, j}}

        pq.push({moveTime[0][0], {0, 0}});

        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int val = top.first;
            int indi = top.second.first;
            int indj = top.second.second;

            if (vis[indi][indj] == 1) {
                continue;
            }

            vis[indi][indj] = 1;

            for (int i = 0; i < 4; i++) {
                int ny = indj + dj[i];
                int nx = indi + di[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int dist = max(dis[indi][indj], moveTime[nx][ny]) + 1;

                if (dis[nx][ny] > dist) {
                    dis[nx][ny] = dist;
                    pq.push({dist, {nx, ny}});
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};