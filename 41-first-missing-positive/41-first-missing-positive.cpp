class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        
        int oneFlag = false;
        
        // Making out of range values = 1
        for(int i=0; i<sz; i++){
            if(nums[i] == 1) oneFlag = 1;
            else if(nums[i] < 1 or nums[i] > sz){
                nums[i] = 1;
            }
        }
        
        if(oneFlag == false) return 1;
        // for each in range value go to that index and make it -1
        // Each index which is -1 is showing the present of that value
        
        for(int i=0; i<sz; i++){
            int index = abs(nums[i]);
            nums[index-1] = -1 * abs(nums[index-1]);
        }
        
        // Now look for location where the value is positive
        for(int i=0; i<sz; i++){
            if(nums[i] > 0) return i+1;
        }
        
        return sz+1;
        
    }
};