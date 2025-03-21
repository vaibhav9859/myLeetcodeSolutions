class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findSubArray(nums, k) - findSubArray(nums, k-1);
    }

    int findSubArray(vector<int>& nums, int k){
        int sz = nums.size();
        int ans = 0;
        int left = 0, right = 0;
        int countOdd = 0;

        while(right < sz){
            if(nums[right] % 2) countOdd++;

            while(countOdd > k and left <= right){
                if(nums[left] % 2) countOdd--;
                left++;
            }

            ans += (right-left+1);
            right++;
        }

        return ans;
    }
};