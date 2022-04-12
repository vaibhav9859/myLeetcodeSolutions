class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0; int ans;
        
        for(auto &val: nums){
            if(count == 0) ans = val;
            
            if(ans == val) count++;
            else count--;
        }
        
        return ans;
    }
};