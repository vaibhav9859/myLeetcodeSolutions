class Solution {
public:

    struct Compare {
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            return p1.first > p2.first;
        }
    };

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

        int ans = 1;
        minHeap.push({intervals[0][1], intervals[0][0]});

        for(int i=1; i < sz; i++){
            if(intervals[i][0] >= minHeap.top().first){
                minHeap.pop();
                minHeap.push({intervals[i][1], intervals[i][0]});
            }
            else {
                ans++;
                minHeap.push({intervals[i][1], intervals[i][0]});
            }
        }

        return ans;
    }
};