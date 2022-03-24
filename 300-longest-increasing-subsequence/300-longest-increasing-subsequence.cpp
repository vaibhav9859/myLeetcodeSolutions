class Solution {
public:
    int dp[2502][2502];
    int lengthOfLIS(vector<int>& nums, int prev = -1, int i=0, int flag = 1) {
        if(flag){ memset(dp, -1, sizeof(dp)); flag = 0;}
        if(i == nums.size()) return 0;
        
        if(prev!= -1 and dp[prev][i] != -1) return dp[prev][i];
        
        if(prev == -1 or nums[prev] < nums[i]){
            int x = max(1 + lengthOfLIS(nums, i, i+1, 0), lengthOfLIS(nums, prev, i+1, 0));
            if(prev != -1){
                dp[prev][i] = x;
            }
            return x;
        }
        else{
            int y = lengthOfLIS(nums, prev, i+1, 0);
            if(prev != -1){
                dp[prev][i] = y;
            }
            return y;
        }
        
    }
};