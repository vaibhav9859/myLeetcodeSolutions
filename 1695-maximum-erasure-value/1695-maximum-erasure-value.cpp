class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> val_set;
        int sz = nums.size();
        int localSum = 0, globalSum = 0;
        
        for(int i=0, j=0; j<sz; ){
            if(val_set.find(nums[j]) == val_set.end()){
                localSum += nums[j];
                val_set.insert(nums[j]);
                globalSum = max(globalSum, localSum);
                j++;
          
            }
            else{
                val_set.erase(nums[i]);
                localSum -= nums[i]; i++;
               
            }
        }
        
        return globalSum;
    }
};