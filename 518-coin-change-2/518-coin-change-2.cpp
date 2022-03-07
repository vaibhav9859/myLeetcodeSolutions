class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for(int cIt=0; cIt < coins.size(); cIt++){
            for(int dpIt = coins[cIt]; dpIt <= amount; dpIt++){
                if(dpIt - coins[cIt] >= 0) dp[dpIt] += dp[dpIt - coins[cIt]];
            }
        }
        
        return dp[amount];
    }
};