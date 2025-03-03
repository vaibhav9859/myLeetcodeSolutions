class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        int sz = rides.size();
        vector<long long> dp(sz+3, -1);
        return maxEarnings(rides, sz, 0, dp);
    }

    int binarySearch(vector<vector<int>>& rides, int curIdx){
        int start = curIdx, end = rides.size()-1;
        int sz = rides.size();
        int newRideIdx = sz;

        while(start<=end){
            int mid = (start+end)/2;

            if(rides[mid][0] >= rides[curIdx][1]){
                newRideIdx = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }

        return newRideIdx;
    }

    long long maxEarnings(vector<vector<int>>& rides, int sz, int curIdx, vector<long long> &dp){
        if(curIdx >= sz) return 0;

        int newRideIdx = curIdx+1;

        if(dp[curIdx] != -1) return dp[curIdx];

        // for(newRideIdx = curIdx+1; newRideIdx < sz; newRideIdx++){
        //     if(rides[newRideIdx][0] >= rides[curIdx][1]) break;
        // }

        newRideIdx = binarySearch(rides, curIdx);

        long long pick = (rides[curIdx][1] - rides[curIdx][0] + rides[curIdx][2]) + maxEarnings(rides, sz, newRideIdx, dp);
        long long notPick = maxEarnings(rides, sz, curIdx+1, dp);

        return dp[curIdx] = max(pick, notPick);
    }
};