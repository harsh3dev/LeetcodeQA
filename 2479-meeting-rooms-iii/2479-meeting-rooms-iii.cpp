class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sort the meetings in asc order according to start time
        sort(meetings.begin(), meetings.end());

        // we need 2 priority queues: one for free rooms, one for occupied rooms
        // free rooms will be sorted ascending by room index
        // occupied rooms will be sorted ascending by end time
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        vector<int> freq(n, 0); // to track frequency of meetings per room

        // init: all rooms are free so push room numbers in pq
        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];

            // add free rooms from busy set to free set
            while (!busy.empty() && busy.top().first <= start) {
                int room = busy.top().second;
                busy.pop();
                free.push(room);
            }

            // assign a room to current meeting
            // case 1: if there is a free room
            if (!free.empty()) {
                int room = free.top();
                free.pop();
                freq[room]++;
                // push the end time and the room in occupied
                busy.push({end, room});
            } else {
                // case 2: if no free room available
                // then take the earliest finishing room and adjust the time
                auto [endTime, room] = busy.top();
                busy.pop();
                freq[room]++;
                long long newEnd = endTime + (end - start);
                busy.push({newEnd, room});
            }
        }

        // calculate room with max meetings
        int maxmeet = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] > maxmeet) {
                maxmeet = freq[i];
                maxi = i;
            }
        }

        return maxi;
    }
};
