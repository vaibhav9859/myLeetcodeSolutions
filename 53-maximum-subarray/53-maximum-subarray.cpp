class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lMax = nums[0], gMax = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i] + lMax){
                lMax = nums[i];
            }
            else{
                lMax += nums[i];
            }
            
            gMax = max(gMax, lMax);
        }
        
        return gMax;
    }
};