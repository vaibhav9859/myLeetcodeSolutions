class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 1;
        int sz = nums.size();

        vector<int> dp(sz, 1);

        for(int curIdx = 1; curIdx < sz; curIdx++){
            for(int fromStart=0; fromStart < curIdx; fromStart++){
                if(nums[curIdx] > nums[fromStart]){
                    dp[curIdx] = max(dp[curIdx], 1 + dp[fromStart]);

                    maxLen = max(maxLen, dp[curIdx]);
                }
            }
        }

        return maxLen;
    }
};