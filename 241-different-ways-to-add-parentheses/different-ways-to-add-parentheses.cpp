class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> res;

        for(int i = 0; i < n; i++){
            char ch = expression[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int> a = diffWaysToCompute(expression.substr(0, i));
                vector<int> b = diffWaysToCompute(expression.substr(i+1));
                for(int m:a){
                    for(int k:b){
                        if(ch=='+') res.push_back(m+k);
                        else if(ch=='-') res.push_back(m-k);
                        else if(ch=='*') res.push_back(m*k);
                    }
                }
            }
        }

        if(res.empty()) res.push_back(stoi(expression));
        return res;
    }
};