class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> dp(sz+1, vector<int>(sz+2, -1));
        return maxLen(nums, 0, -1, dp);
    }

    int maxLen(vector<int>& nums, int curIdx, int prevIdx, vector<vector<int>> &dp){
        if(curIdx == nums.size()) return 0;

        int len = INT_MIN;

        if(dp[curIdx][prevIdx+1] != -1) return dp[curIdx][prevIdx+1];

        if(prevIdx == -1 or nums[curIdx] > nums[prevIdx]){
            // consider present element in seq
            len = max(len, 1 + maxLen(nums, curIdx+1, curIdx, dp));
        } 

        // don't consider present element in seq
        len = max(len, maxLen(nums, curIdx+1, prevIdx, dp));

        return dp[curIdx][prevIdx+1] = len;
    }
};