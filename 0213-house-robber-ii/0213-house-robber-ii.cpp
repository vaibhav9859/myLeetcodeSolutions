class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        
        if(sz == 1) return nums[0];
        else if(sz == 2) return max(nums[0], nums[1]);

        vector<int> dp(sz+1, -1);
        int firstNotConsider = maxMoney(nums, sz-1, 1, dp);

        fill(dp.begin(), dp.end(), -1);
        int lastNotConsider = maxMoney(nums, sz-2, 0, dp);

        return max(firstNotConsider, lastNotConsider);
    }

    int maxMoney(vector<int>& nums, int curIdx, int startIdx, vector<int> &dp){
        if(curIdx < startIdx) return 0;

        if(dp[curIdx] != -1) return dp[curIdx];
        
        // Pick the element
        int pickSum = nums[curIdx] + maxMoney(nums, curIdx-2, startIdx, dp);

        // Not pick the element
        int notPickSum = maxMoney(nums, curIdx-1, startIdx, dp);

        return dp[curIdx] = max(pickSum, notPickSum);
    }
};