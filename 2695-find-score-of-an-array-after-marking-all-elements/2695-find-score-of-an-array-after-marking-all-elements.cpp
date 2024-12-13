class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> marked(n);
        long long sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(!pq.empty()){
            pair<int, int> top = pq.top();
            if(marked.find(top.second) == marked.end()){
                sum += top.first;
                if(top.second<1){
                    marked.insert(top.second+1);
                } else if(top.second==n-1){
                    marked.insert(top.second-1);
                } else{
                    marked.insert(top.second+1);
                    marked.insert(top.second-1);
                }
            }
            pq.pop();
        }

        return sum;
    }
};

// store the array elements in the min heap with the index
// get the top of the heap and find its index whether it is in the marked or not
// if it is not in the marked then add it and mark it and mark +1 and -1 if exist
// run until the pq is empty