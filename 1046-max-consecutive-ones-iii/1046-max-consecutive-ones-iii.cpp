class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zeroCount = 0, maxLen = 0;

        while (r < nums.size()) {
            // checking value at r
            if (nums[r] == 0) zeroCount++;

            // update length only when zeroCount is valid and l <= r
            if(zeroCount <= k and l <= r) maxLen = max(maxLen, r - l + 1);

            // gonna move l only when zeroCount is more than "k"
            if (zeroCount > k) {
                if (nums[l] == 0) zeroCount--;
                l++;  
            }

            

            // at every condition keep moving r
            r++;  
        }

        return maxLen;
    }
};