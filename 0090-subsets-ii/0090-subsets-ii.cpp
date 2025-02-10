class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> curSub;
        allSub(nums, allSubsets, curSub, 0);
        return allSubsets;
    }

    void allSub(vector<int> &nums, vector<vector<int>> &allSubsets, vector<int> &curSub, int curIdx){
        int sz = nums.size();

        // Everytime a new subset
        allSubsets.push_back(curSub);

        if(curIdx >= sz){
            return;
        }

        for(int idx = curIdx; idx < sz; idx++){
            if(idx > curIdx and nums[idx] == nums[idx-1]) continue;

            curSub.push_back(nums[idx]);
            allSub(nums, allSubsets, curSub, idx+1);
            curSub.pop_back();
        }
    }
};