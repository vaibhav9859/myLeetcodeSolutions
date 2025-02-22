class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, -1);
        return maxAmt(nums, sz-1, dp);
    }

    int maxAmt(vector<int>& nums, int curIdx, vector<int> &dp){
        if(curIdx < 0) return 0;

        if(dp[curIdx] != -1) return dp[curIdx];

        // pick the current house
        int pick = nums[curIdx] + maxAmt(nums, curIdx-2, dp);

        // don't pick currect house
        int notPick = maxAmt(nums, curIdx-1, dp);

        return dp[curIdx] = max(pick, notPick);
    }
};