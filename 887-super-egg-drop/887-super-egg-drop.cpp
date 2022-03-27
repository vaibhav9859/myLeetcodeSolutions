class Solution {
public:
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return helper(k, n, dp);
    }
    
    int helper(int eggs, int floors, vector<vector<int>> &dp){
       if(eggs == 1 or floors == 1 or floors == 0) return floors;
        
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        int ans = INT_MAX;
//         for(int k=1; k<=floors; k++){
//             int temp = 1 + max(helper(eggs-1, k-1, dp), helper(eggs, floors-k, dp));
            
//             ans = min(ans, temp);
//         }
        int l = 1, h = floors;
        while(l<=h){
            int mid = (l+h)/2;
            int bottomSide = helper(eggs-1, mid-1, dp);
            int topSide  = helper(eggs, floors-mid, dp);
            
            if(bottomSide < topSide){
                l = mid+1;
            }
            else h = mid-1;
            
            ans = min(ans, 1 + max(bottomSide, topSide));
        }
        
        return dp[eggs][floors] = ans;
    }
};