class Solution {
public:
    int climbStairs(int n) {
        if(n==1 or n==2) return n;
        vector<int> dp(n+1, -1);
        dp[1] = 1; dp[2] = 2;
        countWays(n, dp);
        return dp[n];
    }

    int countWays(int n, vector<int> &dp){
        if(n==1 or n==2) return n;
        if(dp[n] != -1) return dp[n];

        return dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
    }
};