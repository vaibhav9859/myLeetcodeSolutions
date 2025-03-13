class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int sz = nums.size();
        int maxLen = 0;
        int zeroCount = 0;

        while(r < sz){
            if(nums[r] == 1){
                maxLen = max(maxLen, r-l+1);
                r++;
            }
            else {
                zeroCount++;
                if(zeroCount <= k){
                    maxLen = max(maxLen, r-l+1);
                    r++;
                }
                else{
                    while(zeroCount > k and r < sz){
                        if(nums[l] == 0) zeroCount--;
                        l++;
                        r++;
                        if(r < sz and nums[r] == 0) zeroCount++;
                    }
                }
            }
        }

        return maxLen;
    }
};