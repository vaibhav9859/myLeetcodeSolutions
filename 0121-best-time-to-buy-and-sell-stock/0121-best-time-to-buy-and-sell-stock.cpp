class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyPrice = prices[0];
        int sz = prices.size();
        int maxProfit = 0;

        for(int i=1; i<sz; i++){
            maxProfit = max(maxProfit, prices[i] - minBuyPrice);
            minBuyPrice = min(prices[i], minBuyPrice);
        }

        return maxProfit;
    }
};