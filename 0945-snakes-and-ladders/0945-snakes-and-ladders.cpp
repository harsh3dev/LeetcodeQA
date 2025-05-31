class Solution {
private:
    pair<int, int> getrc(int target, int n){
        int row = n - 1 - (target - 1) / n;
        int col = (target - 1) % n;

        if ((n - 1 - row) % 2 == 1) {
            col = n - 1 - col;
        }

        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        q.push(1);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int count = 0;
        vis[n-1][0] = true;

        while(!q.empty()){
            int N = q.size();

            while(N--){
                int x = q.front();
                q.pop();

                if(x == n*n){
                    return count;
                }

                for(int i = 1; i <= 6; i++){
                    if(x+i > n*n){
                        continue;
                    }
                    
                    pair<int, int> coord = getrc(x+i, n);
                    int r = coord.first;
                    int c = coord.second;
                    if(vis[r][c]){
                        continue;
                    }

                    vis[r][c] = true;
                    if(board[r][c] != -1){
                        q.push(board[r][c]);
                    } else{
                        q.push(x+i);
                    }
                }
            }
            count++;
        }

        return -1;
    }
};