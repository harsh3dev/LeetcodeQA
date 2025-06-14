class Solution {
public:
    int minMaxDifference(int num) {
        int targetmax = 0;
        int targetmin = 0;
        int maxnum = 0;
        int minnum = 0;

        string n = to_string(num);

        for(int i = 0; i < n.size(); i++){
            if(n[i]-'0' < 9){
                targetmax = n[i]-'0';
                break;
            }
        }

        for(int i = 0; i < n.size(); i++){
            if(n[i]-'0' > 0){
                targetmin = n[i]-'0';
                break;
            }
        }

        for(int i = 0; i < n.size(); i++){
            if(n[i] == '0'+targetmax){
                maxnum = maxnum*10 + 9;
            } else{
                maxnum = maxnum*10 + n[i]-'0';
            }
        }

        for(int i = 0; i < n.size(); i++){
            if(n[i] == '0'+targetmin){
                minnum = minnum*10;
            } else{
                minnum = minnum*10 + n[i]-'0';
            }
        }

        return maxnum - minnum;        
    }
};

// 122829
// 922829
// 022829
// 978859
// 998859
// 078850
