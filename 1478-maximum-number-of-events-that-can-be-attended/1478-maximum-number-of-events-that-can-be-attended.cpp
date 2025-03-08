class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // sort events
        int sz = events.size();
        int count = 0;
        sort(events.begin(), events.end());

        // create min heap and put only end day
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // get the max days possible
        int maxDays = 0;
        for(auto &val: events){
            maxDays = max(maxDays, val[1]);
        }

        // run a loop starting from day 1 till max days
        
        // IMP: FIRST make sure to get out the events jiske end day < curday
        // make sure to push events which start on this current day

        // MAIN LOGIC: Now choose top from heap for the current day
        // pop that from heap... keep running the loop
        int curEvent = 0;

        for(int day=1; day<=maxDays; day++){
            
            
            while(curEvent<sz and events[curEvent][0] <= day){
                minHeap.push(events[curEvent][1]);
                curEvent++;
            }

            while(!minHeap.empty() and minHeap.top() < day){
                minHeap.pop();
            }

            if(!minHeap.empty()){
                count++;
                minHeap.pop();
            }

        }

        return count;
    }
};