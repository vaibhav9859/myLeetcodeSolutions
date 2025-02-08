class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sz = candidates.size();
        vector<int> curComb;
        vector<vector<int>> comb;
        allComb(candidates, target, 0, sz, comb, curComb);

        return comb;
    }

    void allComb(vector<int> &cand, int target, int idx, int &sz, vector<vector<int>> &comb, vector<int> &curComb){
        // if(idx >= sz) return;
        if(target < 0) return;

        if(target == 0){
            comb.push_back(curComb);
            return;
        }

        for(int i=idx; i<sz; i++){
            if(i != idx and cand[i] == cand[i-1]) continue;
            if(cand[i] > target) break;
            curComb.push_back(cand[i]);
            allComb(cand, target - cand[i], i+1, sz, comb, curComb);
            curComb.pop_back();
        }
    }
};