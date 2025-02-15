class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for(int i=1; i<sz; i++){
            int lastIdx = output.size() - 1;

            if(output[lastIdx][1] >= intervals[i][0]){
                output[lastIdx][1] = max(output[lastIdx][1], intervals[i][1]);
            } else {
                output.push_back(intervals[i]);
            }
        }

        return output;
    }
};