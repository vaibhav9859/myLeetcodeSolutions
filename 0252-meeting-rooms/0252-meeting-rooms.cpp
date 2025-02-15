class Solution {
public:

    static bool compare(vector<int> int1, vector<int> int2){
        return int1[0] <= int2[0];
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);

        for(int i=0; i<sz-1; i++){
            if(intervals[i][1] > intervals[i+1][0]) return false;
        }

        return true;
    }
};