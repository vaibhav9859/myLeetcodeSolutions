class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyVal = prices[0];
        int sz = prices.size();
        int profit = 0;
        
        for(int i=1; i<sz; i++){
            profit = max(prices[i]-buyVal, profit);
            
            if(buyVal > prices[i]) buyVal = prices[i];
        }
        
        // if(profit < 0) return 0;
        return profit;
    }
};