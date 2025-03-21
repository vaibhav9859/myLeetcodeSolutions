class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArrays(nums, k) - subArrays(nums, k-1);
    }

    int subArrays(vector<int>& nums, int k){
        int ans = 0;
        int sz = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> mp;

        while(right < sz){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }

            ans += (right-left+1);
            right++;
        }

        return ans;
    }
};