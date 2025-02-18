class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> dp(sz+1, -1);
        return min(minCost(cost, sz-1, dp), minCost(cost, sz-2, dp));
    }

    int minCost(vector<int> &cost, int curIdx, vector<int> &dp){
        if(curIdx == 0 or curIdx == 1) return cost[curIdx];

        if(dp[curIdx] != -1) return dp[curIdx];

        int oneStepCost = minCost(cost, curIdx-1, dp);
        int twoStepCost = minCost(cost, curIdx-2, dp);

        return dp[curIdx] = cost[curIdx] + min(oneStepCost, twoStepCost);
    }
};