class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR = 0;
        int sz = nums.size();

        for(int i=0; i<sz and i<=maxR; i++){
            maxR = max(maxR, i + nums[i]);

            if(maxR >= sz-1) return true;
        }

        return maxR >= sz-1 ? true : false;
    }
};