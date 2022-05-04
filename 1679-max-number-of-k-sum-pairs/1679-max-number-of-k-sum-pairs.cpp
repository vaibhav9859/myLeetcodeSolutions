class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sz = nums.size();
        int ans = 0;
        
        for(int i=0; i<sz; i++){
            if(mp[k-nums[i]]){
                ans++; mp[k-nums[i]]--;
            }
            else{
                mp[nums[i]]++;
            }
        }
        
        return ans;
    }
};