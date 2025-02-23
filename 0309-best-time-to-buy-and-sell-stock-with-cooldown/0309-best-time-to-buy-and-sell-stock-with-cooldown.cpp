class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz= prices.size();
        vector<vector<int>> dp(sz+1, vector<int>(2, -1));
        return profit(prices, 0, 1, dp);
    }

    int profit(vector<int>& prices, int curDay, int buy, vector<vector<int>> &dp){
        if(curDay >= prices.size()) return 0;

        if(dp[curDay][buy] != -1) return dp[curDay][buy];
        int prft = INT_MIN;

        if(buy) {
            // buy
            prft = max(prft, -prices[curDay] + profit(prices, curDay+1, 0, dp));

            // don't buy
            prft = max(prft, profit(prices, curDay+1, 1, dp));
        }
        else {
            // sell
            prft = max(prft, prices[curDay] + profit(prices, curDay+2, 1, dp));

            // don't sell
            prft = max(prft, profit(prices, curDay+1, 0, dp));
        }

        return dp[curDay][buy] = prft;
    }
};