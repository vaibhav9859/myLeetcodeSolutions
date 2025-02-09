class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSub;
        vector<vector<int>> allSub;
        allSubsets(nums, allSub, curSub, 0);

        return allSub;
    }

    void allSubsets(vector<int>& nums, vector<vector<int>> &allSub, vector<int> &curSub, int curIdx){
        if(curIdx == nums.size()){
            allSub.push_back(curSub);
            return;
        }

        curSub.push_back(nums[curIdx]);
        allSubsets(nums, allSub, curSub, curIdx+1);
        curSub.pop_back();

        allSubsets(nums, allSub, curSub, curIdx+1);
    }
};