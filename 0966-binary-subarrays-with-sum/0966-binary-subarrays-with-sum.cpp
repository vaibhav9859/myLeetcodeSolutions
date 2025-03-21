class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subArrays(nums, goal) - subArrays(nums, goal-1);
    }

    int subArrays(vector<int>& nums, int goal){
        if (goal < 0) return 0; 
        int sz = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        int oneCount = 0;

        while(right < sz){
            if(nums[right] == 1) oneCount++;

            while(oneCount > goal){
                if(nums[left] == 1) oneCount--;
                left++;
            }

            ans += (right-left+1);
            right++;
        }

        return ans;
    }
};