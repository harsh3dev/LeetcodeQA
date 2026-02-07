class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int cb = 0;
        for(int i = 0; i < n; i++){
            left[i] = cb;
            if(s[i] == 'b'){
                cb++;
            }
        }
        int ca = 0;
        for(int i = n-1; i >= 0; i--){
            right[i] = ca;
            if(s[i] == 'a'){
                ca++;
            }
        }

        int count = INT_MAX;

        for(int i = 0; i < n; i++){
            count = min(count, left[i] + right[i]);
        }
        return count;
    }
};