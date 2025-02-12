class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPer;
        int sz = nums.size();
        allPermute(nums, sz, 0, allPer);
        return allPer;
    }

    void allPermute(vector<int> &nums, int &sz, int curIdx, vector<vector<int>> &allPer){
        if(curIdx >= sz){
            allPer.push_back(nums);
            return;
        }

        for(int itr=curIdx; itr<sz; itr++){
            swap(nums[curIdx], nums[itr]);
            allPermute(nums, sz, curIdx+1, allPer);
            swap(nums[curIdx], nums[itr]);
        }
    }
};