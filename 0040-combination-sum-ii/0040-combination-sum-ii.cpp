class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> allComb;
        vector<int> curComb;
        sort(candidates.begin(), candidates.end());
        findAllComb(candidates, target, curComb, 0, allComb);

        return allComb;
    }

    void findAllComb(vector<int>& cand, int target, vector<int> &curComb, int curIdx, vector<vector<int>> &allComb){
        if(target == 0){
            allComb.push_back(curComb);
            return;
        }

        if(curIdx == cand.size() or target < 0){
            return;
        }

        curComb.push_back(cand[curIdx]);
        findAllComb(cand, target - cand[curIdx], curComb, curIdx+1, allComb);
        curComb.pop_back();

        while(curIdx+1 < cand.size() and cand[curIdx+1] == cand[curIdx]) curIdx++;

        findAllComb(cand, target, curComb, curIdx+1, allComb);
    }
};