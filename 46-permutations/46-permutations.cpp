class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output; set<vector<int>> s;
        helper(nums, 0, s);
        
        for(auto it: s){
            output.push_back(it);
        }
        
        return output;
    }
    
    void helper(vector<int> &nums, int curPos, set<vector<int>> &s){
        int sz = nums.size();
        if(curPos == sz-1){
            s.insert(nums); return;
        }
        
        for(int i=curPos; i<sz; i++){
            vector<int> temp = nums;
            swap(temp[curPos], temp[i]);
            helper(temp, curPos+1, s);
        }
    }
};