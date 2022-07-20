class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int sz = nums.size();
        
        if(sz == 1) return nums[0];
        
        for(int i=0; i<sz; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=sz-1) temp2.push_back(nums[i]);
        }
        
        int moneyExFirst = moneyFinder(temp1, sz-1);
        int moneyExLast = moneyFinder(temp2, sz-1);
        
        return max(moneyExFirst, moneyExLast);
    }
    
    int moneyFinder(vector<int> &arr, int sz){
        
        int prev2 = 0;
        int prev1 = arr[0];
        
        for(int i=1; i<sz; i++){
            int pick = arr[i] + prev2;
            int notPick = 0 + prev1;
            
            int cur = max(pick, notPick);
            prev2 = prev1;
            prev1 = cur;
        }
        
        return prev1;
    }
};