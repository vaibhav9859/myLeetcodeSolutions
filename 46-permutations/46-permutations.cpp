class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int, int> presentMap;
        vector<int> curVec;
        vector<vector<int>> output;
        
        permuteFinder(nums, sz, 0, presentMap, curVec, output);
         
        return output;
    }
    
    
    void permuteFinder(vector<int> &nums, int &sz, int pos, unordered_map<int, int> &presentMap, vector<int> &curVec, vector<vector<int>> &output){
        if(sz == pos){
            output.push_back(curVec);
            return;
        }
        
        for(int index=0; index<sz; index++){
            if(!presentMap[index]){
                
                presentMap[index] = 1;
                curVec.push_back(nums[index]);
                
                permuteFinder(nums, sz, pos+1, presentMap, curVec, output);
                
                presentMap[index] = 0;
                curVec.pop_back();
            }
        }
 
    }
};