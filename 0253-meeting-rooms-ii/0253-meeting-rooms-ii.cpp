class Solution {
public:

    struct Compare {
        bool operator()(vector<int> v1, vector<int> v2){
            return v1[1] >= v2[1];
        }
    };

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        
        priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;

        int ans = 1;
        minHeap.push(intervals[0]);

        for(int i=1; i < sz; i++){
            if(intervals[i][0] >= minHeap.top()[1]){
                minHeap.pop();
                minHeap.push(intervals[i]);
            }
            else {
                ans++;
                minHeap.push(intervals[i]);
            }
        }

        return ans;
    }
};