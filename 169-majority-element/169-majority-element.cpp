class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0]; int count = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(count == 0){
                ans = nums[i]; count = 1;
            }
            else{
                if(ans == nums[i]) count++;
                else count--;
            }
        
        }
        
        return ans;
    }
};