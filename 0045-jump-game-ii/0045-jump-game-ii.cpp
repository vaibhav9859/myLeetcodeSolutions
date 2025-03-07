class Solution {
public:
    int jump(vector<int>& nums) {
        int minR = 0;
        int maxR = 0;
        int jumps = 0;
        int sz = nums.size();

        while(maxR < sz-1){
            int newMaxR = maxR;
            for(int i=minR; i<=maxR; i++){
                newMaxR = max(newMaxR, nums[i] + i);
            }

            jumps++;
            minR = maxR+1;
            maxR = newMaxR;
        }   

        return jumps;
    }
};