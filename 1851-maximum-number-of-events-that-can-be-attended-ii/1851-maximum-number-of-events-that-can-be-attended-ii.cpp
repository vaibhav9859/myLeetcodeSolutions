
class Solution {
public:
    int maxValue(vector<vector<int>>& times, int k) {
        int sz = times.size();
        // vector<int> dp(sz+2, -1);
        vector<vector<int>> dp(sz+1, vector<int>(k+1, -1));

        // vector<vector<int>> times;
        // for(int i=0; i<sz; i++){
        //     times.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        // }

        sort(times.begin(), times.end());
        return profitCal(times, 0, sz, dp, k);
    }

    int binarySearch(vector<vector<int>> &times, int curIdx){
        int sz = times.size();
        int nextIdx = sz;
        int start = curIdx, end = sz-1;

        while(start <= end){
            int mid = (start + end)/2;

            if(times[mid][0] > times[curIdx][1]){
                nextIdx = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }

        return nextIdx;
    }

    int profitCal(vector<vector<int>> &times, int curIdx, int sz, vector<vector<int>> &dp, int k){
        if(curIdx >= sz or k <= 0) return 0;
        
        if(dp[curIdx][k] != -1) return dp[curIdx][k];

        //let's find next valid time to consider
        // int nextIdx = sz;
        // for(int i=curIdx+1; i<sz; i++){
        //     if(times[i][0] >= times[curIdx][1]){
        //         nextIdx = i;
        //         break;
        //     }
        // }

        int nextIdx = binarySearch(times, curIdx);

        // pick the new time
        int pick = times[curIdx][2] + profitCal(times, nextIdx, sz, dp, k-1);

        // don't pick the new time
        int notPick = profitCal(times, curIdx + 1, sz, dp, k);

        return dp[curIdx][k] = max(pick, notPick);
    }
};
