class Solution {
public:
    
    //Time Complexity: Generating n! permutation, for every permutation looping from 0 to n-1
    //Time Complexity: O(n! * n)
    //Space Complexity: O(n)-For map + O(n) for current vector/arrangement
    //There is one more solution where you don't need to use extra map, That is direclty by swapping 
    //swapping solution is also submitted
    vector<vector<int>> permute(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> output;
        
        permuteFinder(nums, sz, 0, output);
         
        return output;
    }
    
    
    void permuteFinder(vector<int> &nums, int &sz, int pos, vector<vector<int>> &output){
        if(pos == sz-1){
            output.push_back(nums);
            return;
        }
        
        for(int index=pos; index<sz; index++){
            swap(nums[pos], nums[index]);
            permuteFinder(nums, sz, pos+1, output);
            swap(nums[pos], nums[index]);
        }
 
    }
};