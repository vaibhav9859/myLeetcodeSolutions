class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curVec;
        vector<vector<int>> combSet;
        allCombi(k, n, 1, curVec, combSet);
        
        return combSet;
    }
    
    void allCombi(int k, int n, int index, vector<int> &curVec, vector<vector<int>> &combSet){
 
        if(curVec.size() == k and n==0){
            combSet.push_back(curVec);
            return;
        }
        
        // if(curVec.size() > k or n < 0 or index > 9) return;
        
        
        for(int i=index; i<=9; i++){
            
            n -= i;
            curVec.push_back(i);
            if(curVec.size() <= k and n>=0) allCombi(k, n, i+1, curVec, combSet);
                
            n += i;
            curVec.pop_back();
        }
    }
};