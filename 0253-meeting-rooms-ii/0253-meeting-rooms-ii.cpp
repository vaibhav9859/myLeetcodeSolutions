class Solution {
public:

    struct compare{
        bool operator()(vector<int> int1, vector<int> int2){
            return int1[1] > int2[1];
        }
    }; 

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        priority_queue<vector<int>, vector<vector<int>>, compare> minHeap; 

        int minRooms = 1;

        for(int i=0; i < sz; i++){
            if(minHeap.empty())
            {
                minHeap.push(intervals[i]);
            } 
            else if(!minHeap.empty())
            {
                int endTime = minHeap.top()[1];
                if(endTime <= intervals[i][0])
                {
                    minHeap.pop();
                    minHeap.push(intervals[i]);
                } else 
                {
                    minHeap.push(intervals[i]);
                    int sz1 = minHeap.size();
                    minRooms = max(minRooms, sz1);
                }
            }
        }

        return minRooms;
    }
};