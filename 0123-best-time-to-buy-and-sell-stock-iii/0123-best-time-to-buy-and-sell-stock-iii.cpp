class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        // vector<vector<int>> dp(sz+1, vector<int>(2, -1));
        vector<vector<vector<int>>> dp(sz+1, vector<vector<int>>(2, vector<int>(4, -1)));
        return profit(prices, 0, 2, 1, dp);
    }

    int profit(vector<int>& prices, int curIdx, int tranLeft, int buy, vector<vector<vector<int>>> &dp){
        if(curIdx >= prices.size() or tranLeft <= 0) return 0;

        int prt = INT_MIN;

        if(dp[curIdx][buy][tranLeft] != -1) return dp[curIdx][buy][tranLeft];

        if(buy) {
            // buy
            prt = max(prt, -prices[curIdx] + profit(prices, curIdx+1, tranLeft, 0, dp));

            // dont buy
            prt = max(prt, profit(prices, curIdx+1, tranLeft, 1, dp));
        }
        else {
            // sell
            prt = max(prt, prices[curIdx] + profit(prices, curIdx+1, tranLeft-1, 1, dp));

            // dont sell
            prt = max(prt, profit(prices, curIdx+1, tranLeft, 0, dp));
        }

        return dp[curIdx][buy][tranLeft] = prt;
    }
};