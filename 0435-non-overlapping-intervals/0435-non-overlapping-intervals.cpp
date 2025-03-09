class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int endTime = intervals[0][1];
        int sz = intervals.size();

        for(int i=1; i<sz; i++){
            int startTime = intervals[i][0];

            if(endTime <= startTime){
                count++;
                endTime = intervals[i][1];
            }
        }
        
        return sz-count;
    }
};