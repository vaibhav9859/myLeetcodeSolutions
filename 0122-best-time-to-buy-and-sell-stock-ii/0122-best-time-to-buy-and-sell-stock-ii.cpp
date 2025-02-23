class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        vector<vector<int>> dp(sz+1, vector<int>(2, -1));
        return profit(prices, 1, 0, dp);
    }

    int profit(vector<int>& prices, int buy, int curIdx, vector<vector<int>> &dp){
        if(curIdx >= prices.size()) return 0;

        int pr = INT_MIN;

        if(dp[curIdx][buy] != -1) return dp[curIdx][buy];
        
        if(buy){
            // Let's buy
            int bCase = -prices[curIdx] + profit(prices, 0, curIdx+1, dp);

            // Don't buy
            int dbCase = profit(prices, 1, curIdx+1, dp);
            pr = max(pr, max(bCase, dbCase));
        }
        else{
            // let's sell
            int sCase = prices[curIdx] + profit(prices, 1, curIdx+1, dp);

            // don't sell
            int dsCase = profit(prices, 0, curIdx+1, dp);

            pr = max(pr, max(sCase, dsCase));
        }

        return dp[curIdx][buy] = pr;
    }
};