class Solution {
public:
    vector<int> dp;
    int climbStairs(int n, int flag = 0) {
        if(n==1 or n==2) return n;
        
        if(!flag){
            dp.resize(46, -1);
        }
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};