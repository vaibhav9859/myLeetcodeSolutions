class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int l = 0, r = 0;
        int sz = nums.size();
        int ans = 0;

        while(r < sz){
            while(zeroCount <= k and r < sz){
                if(nums[r] == 0) zeroCount++;
                if(zeroCount <= k) ans = max(r-l+1, ans);
                r++;

            }

            while(zeroCount > k){
                if(nums[l] == 0) zeroCount--;
                l++;
            }
        }

        return ans;
    }
};