class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();

        vector<int> output;

        for(int start = 0, end = sz-1; start < end; ){
            int curSum = nums[start] + nums[end];

            if(curSum == target){
                return vector<int>{start+1, end+1};
            } 
            else if(target > curSum){
                start++;
            } 
            else {
                end--;
            }
        }

        return output;
    }
};