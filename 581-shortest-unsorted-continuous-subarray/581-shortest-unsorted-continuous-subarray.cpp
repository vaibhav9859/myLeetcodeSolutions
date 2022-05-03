class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        int sz = nums.size();
        int flag = 0;
        
        for(int i=1; i<sz; i++){
            if(nums[i] < nums[i-1]){
                flag = 1;
            }    
            if(flag){
                minVal = min(minVal, nums[i]);
            }
        }
        
        flag = 0;
        for(int i=sz-2; i>=0; i--){
            if(nums[i] > nums[i+1]) flag = 1;
            
            if(flag){
                maxVal = max(maxVal, nums[i]);
            }
        }
        
        int left, right;
        
        for(left = 0; left<sz; left++){
            if(nums[left]>minVal) break;
        }
        
        for(right = sz-1; right>=0; right--){
            if(nums[right] < maxVal) break;
        }
        
        return (right-left > 0) ? right-left+1 : 0;
    }
};