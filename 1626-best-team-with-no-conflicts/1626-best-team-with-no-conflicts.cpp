class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int sz = scores.size();
        vector<pair<int, int>> arr; vector<vector<int>> dp(sz+1, vector<int>(sz+1, -1));
        for(int i=0; i<sz; i++){
            arr.push_back({ages[i], scores[i]});
        }
        sort(arr.begin(), arr.end());
        
        
        return helper(arr, sz, -1, 0, dp);
    }
    
    int helper(vector<pair<int, int>> &arr, int sz, int prevPos, int curPos, vector<vector<int>> &dp){
        if(curPos == sz) return 0;
        
        if(prevPos != -1 and dp[prevPos][curPos] != -1) return dp[prevPos][curPos];
        
        if(prevPos == -1 or arr[prevPos].second <= arr[curPos].second){
            int ans = max(arr[curPos].second + helper(arr, sz, curPos, curPos+1, dp),
                      helper(arr, sz, prevPos, curPos+1, dp));
            if(prevPos != -1) dp[prevPos][curPos] = ans;
            
            return ans;
        }
        else{
            return dp[prevPos][curPos] = helper(arr, sz, prevPos, curPos+1, dp);
        }
    }
};