class Solution {
public:
    struct Cmp{
        bool operator()(vector<long long> v1, vector<long long> v2){
            if(v1[0] > v2[0]) return true;
            else if(v1[0] == v2[0] and v1[1] > v2[1]) return true;

            return false;
        }
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int sz = meetings.size();

        priority_queue<int, vector<int>, greater<int>> minHeapRoom;
        priority_queue<vector<long long>, vector<vector<long long>>, Cmp> minHeapEndTimeRoom;

        unordered_map<int, long long> freqRoom;
        int bestRoom = -1;

        for(int i=0; i<n; i++){
            minHeapRoom.push(i);
        }

        for(int i=0; i<sz; i++){
            long long curMeetStart = meetings[i][0];
            long long curMeetEnd = meetings[i][1];

            while(!minHeapEndTimeRoom.empty() and minHeapEndTimeRoom.top()[0] <= curMeetStart){
                minHeapRoom.push(minHeapEndTimeRoom.top()[1]);
                minHeapEndTimeRoom.pop();
            }
            
            // check for free room
            if(minHeapRoom.size() > 0){
                long long pickRoom = minHeapRoom.top();
                minHeapRoom.pop();

                minHeapEndTimeRoom.push(vector<long long>{curMeetEnd, pickRoom});
                freqRoom[pickRoom]++;
                
                if(freqRoom[pickRoom] > freqRoom[bestRoom]) bestRoom = pickRoom;
                // freq same ho jae then we want smaller number room
                else if(freqRoom[pickRoom] == freqRoom[bestRoom] and pickRoom < bestRoom) bestRoom = pickRoom;
            }
            // room not free
            else {
                long long recentComingEndTime = minHeapEndTimeRoom.top()[0];
                long long recentRoom = minHeapEndTimeRoom.top()[1];

                minHeapEndTimeRoom.pop();

                long long newEndTime = recentComingEndTime + (curMeetEnd - curMeetStart);
                minHeapEndTimeRoom.push(vector<long long>{newEndTime, recentRoom});

                freqRoom[recentRoom]++;
                if(freqRoom[recentRoom] > freqRoom[bestRoom]) bestRoom = recentRoom;
                else if(freqRoom[recentRoom] == freqRoom[bestRoom] and recentRoom < bestRoom) bestRoom = recentRoom;
            }
        }

        return bestRoom;
    }
};