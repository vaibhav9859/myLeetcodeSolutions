class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sz = candidates.size();
        vector<int> curComb;
        vector<vector<int>> output;
        
        sort(candidates.begin(), candidates.end());
        combFinder(candidates, target, sz, 0, curComb, output);
        
        return output;
    }
    
    void combFinder(vector<int> &cand, int target, int &sz, int index, vector<int> &curComb, vector<vector<int>> &output){
        // if(sz == index){
            if(target == 0){
                output.push_back(curComb);
                return;
            }
            // return;
        // }
        else{
            
            for(int i=index; i<sz; i++){
                if(i != index and cand[i] == cand[i-1]) continue;
                
                target -= cand[i];
                curComb.push_back(cand[i]);
                if(target >= 0) combFinder(cand, target, sz, i+1, curComb, output);
                target += cand[i];
                curComb.pop_back();    
            }
        }
        
    }
};