class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<int> curVec;
        vector<vector<int>> output;
        
        subHelper(nums, sz, 0, curVec, output);
        return output;
    }
    
    void subHelper(vector<int> &nums, int sz, int index, vector<int> &curVec, vector<vector<int>> &output){
        if(index == sz){
            output.push_back(curVec);
            return;
        }
        if(index<sz){
            output.push_back(curVec);
        }

        for(int i=index; i<sz; i++){
            if(i != index and nums[i-1] == nums[i]) continue;
            
            curVec.push_back(nums[i]);
            
            subHelper(nums, sz, i+1, curVec, output);
            curVec.pop_back();
        }
    }
};