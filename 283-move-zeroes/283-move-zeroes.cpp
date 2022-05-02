class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int i = 0, j = 0;
        
        for(; i<sz and j<sz;){
            if(nums[j] != 0){
                swap(nums[i], nums[j]); i++;
            }
            j++;
        }
        
    }
};