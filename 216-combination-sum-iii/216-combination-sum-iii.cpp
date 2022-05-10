class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curVec; 
        set<vector<int>> ansSet;
        
        vector<vector<int>> output;
        
        combFinder(k, n, curVec, 0, ansSet, 1);
        
        for(auto &val: ansSet){
            output.push_back(val);
        }
        
        return output;
    }
    
    void combFinder(int k, int n, vector<int> curVec, int curSum, set<vector<int>> &ansSet, int curVal){
        if(k==0 and curSum == n){
            ansSet.insert(curVec); return;
        }
        if(k==0 or curVal == 10) return;
        
        combFinder(k, n, curVec, curSum, ansSet, curVal+1);
        
        curVec.push_back(curVal);
        combFinder(k-1, n, curVec, curSum+curVal, ansSet, curVal+1);
    }
};