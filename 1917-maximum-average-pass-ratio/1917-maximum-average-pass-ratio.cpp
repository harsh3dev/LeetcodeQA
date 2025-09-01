class Solution {
private:
    double calcProfit(int pass, int total){
        return (double)(pass+1)/(total+1) - (double)pass/total;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // push initials to the pq
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < classes.size(); i++){
            pq.push(
                {
                    calcProfit(classes[i][0], classes[i][1]),
                    i
                }
            );
        }

        // update the classes with extrastudents
        for(int i = 0; i < extraStudents; i++){
            auto [gain, idx] = pq.top();
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;

            pq.push({
                calcProfit(classes[idx][0], classes[idx][1]),
                idx
            });
        }

        double avgsum = 0;
        for(int i = 0; i < classes.size(); i++){
            avgsum += (double)classes[i][0]/classes[i][1];
        }

        avgsum /= classes.size();

        return avgsum;
    }
};
// adding an extra student will increase both the total no and the pass
// adding more and more extra students to the same class will decrease the rate of increase eventually
// so we have to add in that class which will give more gain
// so we maintain a pq which will maintain the highest gain