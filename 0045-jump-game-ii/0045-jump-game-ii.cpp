class Solution {
public:
    int jump(vector<int>& nums) {
        int minR = 0;
        int maxR = 0;
        int jumps = 0;
        int sz = nums.size();

        while(maxR < sz-1){
            int farthest = 0;
            for(int i=minR; i<=maxR; i++){
                farthest = max(farthest, nums[i] + i);
            }

            jumps++;
            minR = maxR+1;
            maxR = farthest;
        }   

        return jumps;
    }
};