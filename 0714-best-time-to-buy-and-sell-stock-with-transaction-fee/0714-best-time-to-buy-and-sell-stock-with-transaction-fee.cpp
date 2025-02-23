class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sz= prices.size();
        vector<vector<int>> dp(sz+1, vector<int>(2, -1));
        return profit(prices, 0, 1, dp, fee);
    }

    int profit(vector<int>& prices, int curDay, int buy, vector<vector<int>> &dp, int fee){
        if(curDay >= prices.size()) return 0;

        if(dp[curDay][buy] != -1) return dp[curDay][buy];
        int prft = INT_MIN;

        if(buy) {
            // buy
            prft = max(prft, -prices[curDay] + profit(prices, curDay+1, 0, dp, fee));

            // don't buy
            prft = max(prft, profit(prices, curDay+1, 1, dp, fee));
        }
        else {
            // sell
            prft = max(prft, -fee + prices[curDay] + profit(prices, curDay+1, 1, dp, fee));

            // don't sell
            prft = max(prft, profit(prices, curDay+1, 0, dp, fee));
        }

        return dp[curDay][buy] = prft;
    }
};