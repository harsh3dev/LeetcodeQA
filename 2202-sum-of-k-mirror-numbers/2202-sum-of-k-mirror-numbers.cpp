class Solution {
private:
    bool isPal(const string& p){
        int i = 0, j = p.size() - 1;
        while(i < j){
            if(p[i] != p[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool isK(int k, long long num){
        string digs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // handles base up to 36
        string knum = "";

        while(num > 0){
            knum += digs[num % k];
            num /= k;
        }

        reverse(knum.begin(), knum.end());
        return isPal(knum);
    }
public:
    long long kMirror(int k, int n) {
        int count = 0;
        long long sum = 0;

        int l = 1;
        
        while(count < n){
            int r = l * 10;
            for(int t = 0; t < 2; t++){
                for(int i = l; i < r && count < n; i++){
                    long long num = i;
                    long long x = (t == 0) ? (i / 10) : i;

                    while(x){
                        num = num * 10 + x % 10;
                        x /= 10;
                    }

                    if(isK(k, num)){
                        count++;
                        sum += num;
                    }
                }
            }

            l = r;            
        }

        return sum;
    }
};
